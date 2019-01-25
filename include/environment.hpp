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
/** @file node.hpp
 *
 * @brief Class declaration for environment
 *
 * @author Nithish Sanjeev Kumar
 * @navigator Nantha Kumar Sunder
 * @copyright 2019 , Nithish Sanjeev Kumar, Nantha Kumar Sunder All rights reserved

 */
#pragma once
#include <vector>

/** @brief class that stores and create the grid and its paramters
 *
 *  @param size           size of the grid
 *  @param grid           contains the map
 *  @param movementCost   contains movement cost
 *
 *  @return none
 */

class environment {
 private:
  std::vector<int> size;
  std::vector<std::vector<int>> grid;
  std::vector<int> movementCost;
 public:
  int getGrid(int, int);
  /**@brief constructor function
 * @param vector
 * @param vector
 * @return none
 */
  void setGrid(int , int );
  environment(std::vector<int>, std::vector<int>);
  ~environment();
};
