#ifndef TOWER_OF_HANOI_H_
#define TOWER_OF_HANOI_H_

#include <stack>

void moveTowers(int layer, std::stack<int> &towerFrom,
                std::stack<int> &towerBuffer, std::stack<int> &towerTo);

#endif  // ! TOWER_OF_HANOI_H_