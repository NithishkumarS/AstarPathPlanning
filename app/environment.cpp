/**
 * MIT License

 * Copyright (c) 2019 Nithish Sanjeev Kumar, Nantha Kumar Sunder

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "environment.hpp"


int environment::getGrid(int x, int y){
  return grid[x][y];
}
 /**@brief class constructor
   * @param _size_ to send the size information of the grid
   * @param _movementCost_ has the movementCost for the grid
   * @return none
   */
environment::environment(std::vector<int> _size_, std::vector<int> _movementCost_){
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
void environment::setGrid(int x, int y){
  grid[x][y] = 2;
}

environment::~environment(){}
