#include "tower_of_hanoi.h"
#include <iostream>

void moveTowers(int layer, std::stack<int> &towerFrom,
                std::stack<int> &towerBuffer, std::stack<int> &towerTo) {
  if (layer <= 0) {
    std::cout << "Error of layer number to solve Tower of Hanoi" << std::endl;
    return;
  }

  if (layer == 1) {
    // Base case
    int val = towerFrom.top();
    towerFrom.pop();
    towerTo.push(val);
    return;
  }

  // Move top n - 1 disks from towerFrom to towerBuffer, using towerTo as a
  // buffer
  moveTowers(layer - 1, towerFrom, towerTo, towerBuffer);

  // Move top from towerFrom to towerTo
  moveTowers(1, towerFrom, towerBuffer, towerTo);

  // Move top n - 1 disks from towerBuffer to towerTo, using towerFrom as a
  // buffer
  moveTowers(layer - 1, towerBuffer, towerFrom, towerTo);
}