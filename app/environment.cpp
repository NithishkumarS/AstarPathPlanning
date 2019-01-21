#include "environment.hpp"

void environment::environment(std::vector<int> _size_, std::vector<int> _movementCost_){
  size = _size_;
  movementCost = _movementCost_;
  std::vector<std::vector<int>> grid;
  int rows = _size_[0];
  int cols  = _size_[1];
  grid.resize(5);
  for (auto& i : grid) {
    i.resize(cols);
  }
  std::vector<int> values = {0,0,0,0,0
                            ,0,0,0,0,0
                            ,1,1,1,1,0
                            ,0,1,0,0,0
                            ,0,0,0,1,0};
  int a = 0;
  for (auto& i : grid) {
    for (auto& j : i) {
      j = values[a];
      a++;
    }
  }
}
