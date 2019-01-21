#pragma once

#include <vector>

class environment {
 private:
  std::vector<int> size;
  std::vector<std::vector<int>> grid;
  std::vector<int> movementCost;
 public:
  environment(std::vector<int>, std::vector<int>);
};
