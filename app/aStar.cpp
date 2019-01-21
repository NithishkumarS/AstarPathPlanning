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

#include "aStar.hpp"

void aStar::setStart(int _xStart_, int _yStart_) {
  xStart = _xStart_;
  yStart = _yStart_;
}

void aStar::setGoal(int _xGoal_, int _yGoal_) {
  xGoal = _xGoal_;
  yGoal = _yGoal_;
}
int aStar::getxStart() {
  return xStart;
}
int aStar::getyStart() {
  return yStart;
}
int aStar::getxGoal() {
  return xGoal;
}

int aStar::getyGoal() {
  return yGoal;
}

void aStar::pathPlanning() {
}

void aStar::aStar() {
}
aStar::~aStar() {
}
