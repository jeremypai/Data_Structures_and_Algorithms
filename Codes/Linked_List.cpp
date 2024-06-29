struct Node {
  int val;
  Node *next;
  Node() : val(0), next(nullptr) {}
  Node(int v) : val(v), next(nullptr) {}
  Node(int v, Node *next) : val(v), next(next) {}
};