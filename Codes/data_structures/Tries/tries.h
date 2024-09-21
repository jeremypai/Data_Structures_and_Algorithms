#ifndef TRIES_H_
#define TRIES_H_

#include <string>

constexpr static int ALPHABET_SIZE = 26;

struct TrieNode {
  // Pointer array for child nodes of each node
  TrieNode* child[ALPHABET_SIZE];

  // Used for indicating ending of string
  bool isWordEnd;

  // Constructor
  TrieNode() {
    isWordEnd = false;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
      child[i] = nullptr;
    }
  }
};

inline void insertKey(TrieNode* root, const std::string& key) {
  TrieNode* cur = root;
  for (const char& c : key) {
    int index = c - 'a';

    // Check if the node exists for the current character in the Trie
    if (cur->child[index] == nullptr) {
      // If node for current character does not exist then make a new node
      cur->child[index] = new TrieNode();
    }

    // Move the cur pointer to the newly created node
    cur = cur->child[index];
  }

  // Mark the end of the word
  cur->isWordEnd = true;
}

inline bool searchKey(TrieNode* root, const std::string& key) {
  // Initialize the cur pointer with the root node
  TrieNode* cur = root;
  for (const char& c : key) {
    int index = c - 'a';

    // Check if the node exists for the current character in the Trie
    if (cur->child[index] == nullptr) {
      return false;
    }

    // Move the cur pointer to the already existing node for the current
    // character
    cur = cur->child[index];
  }

  // Return true if the word exists and is marked as ending
  return cur->isWordEnd;
}

// Returns true if root has no children, else false
inline bool isEmpty(TrieNode* root) {
  for (int i = 0; i < ALPHABET_SIZE; ++i) {
    if (root->child[i]) {
      return false;
    }
  }
  return true;
}

inline TrieNode* deleteKey(TrieNode* root, const std::string& key, int depth) {
  if (root == nullptr) {
    return nullptr;
  }

  // If last character of key is being processed
  if (depth == key.length()) {
    // This node is no more end of word after removal of given key
    root->isWordEnd = false;

    // If given is not prefix of any other word
    if (isEmpty(root)) {
      delete root;
      root = nullptr;
    }

    return root;
  }

  // If not last character, recur for the child obtained using ASCII value
  int index = key[depth] - 'a';
  root->child[index] = deleteKey(root->child[index], key, depth + 1);

  // If root does not have any child (its only child got deleted), and it is not
  // end of another word.
  if (isEmpty(root) && root->isWordEnd == false) {
    delete root;
    root = nullptr;
  }

  return root;
}

#endif  // !TRIES_H_