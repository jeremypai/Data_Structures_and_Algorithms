#ifndef FLOYD_CYCLE_FINDING_ALGORITHM_H_
#define FLOYD_CYCLE_FINDING_ALGORITHM_H_

#include "linked_list.h"

// Floyd's Cycle Finding Algorithm
// Also known as Hare-Tortoise algorithm

inline bool isLinkedListHasCycle(Node* node) {
  Node* slow = node;
  Node* fast = node;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      // There is a cycle
      return true;
    }
  }

  // No cycle
  return false;
}

#endif  //! FLOYD_CYCLE_FINDING_ALGORITHM_H_