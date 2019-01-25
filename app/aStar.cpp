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

#include <iostream>
#include <list>
#include <cmath>
#include <vector>
#include <iterator>
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
std::vector<int> aStar::minOpenList(std::vector<std::vector<int>> costMap){
  std::vector<int> minVector, tempVector, min;
  std::list<std::vector<int>>::iterator it = openList.begin();
  tempVector = *it;
  int minCostValue = tempVector[2];
  minVector = tempVector;
  for (auto & i:openList){
    tempVector = i;
    if (costMap[i[0]][i[1]] <= minCostValue){
      minCostValue = tempVector[2];
      minVector = tempVector;
    }
  }
  min.push_back(minVector[1]);
   min.push_back(minVector[1]);
  return min;
}
bool aStar::checkNeighbour(std::vector<int> npoint,std::vector<int> curPos){
  if ((npoint[0] - curPos[0] == -1 || npoint[0] - curPos[0] == 0 || npoint[0] - curPos[0] == 1) &&
      (npoint[1] - curPos[1] == -1 || npoint[1] - curPos[1] == 0 || npoint[1] - curPos[1] == 1)){
    return true;
  }else{
    return false;
  }
}

bool aStar::checkOpenList(std::vector<int> point){
  for (auto & i : openList){
    if (i == point){
      return true;
    }
  }
  return false;
}
bool aStar::checkClosedList(std::vector<int> point){
  for (auto & i : closedList){
    if (i == point){
      return true;
    }
  }
  return false;
}

int movementCost(std::vector<int> point, std::vector<int> curPos){
  return sqrt((point[0] - curPos[0])*(point[0] - curPos[0]) + (point[1] - curPos[1])*(point[1] - curPos[1]))*10;

}

void aStar::pathPlanning(environment& envObj, node& nodeObj) {
 int xIndex = nodeObj.getxIndex();
 int yIndex = nodeObj.getyIndex();
 std::vector<std::vector<int>> fCostMat;
 std::vector<std::vector<std::vector<int>>> parentNode;
 std::vector<int> temp,start;
 fCostMat.resize(5);

 for (auto & i : parentNode){
   i.resize(5);
   for (auto & j :i){
     j.resize(2);
   }
 }
 fCostMat.resize(5);
 for (auto & i : fCostMat){
   i.resize(5);
 }
 for (auto & i : fCostMat){
    for (auto & j:i)
      j = 100;
 }
 std::vector<int> tempVector, curVector;
 nodeObj.gValueCalculation(xIndex,yIndex);
 nodeObj.fValueCalculation(xGoal,yGoal);
 tempVector.push_back(yIndex);
 tempVector.push_back(xIndex);
 fCostMat[xIndex][yIndex] = nodeObj.getfValue();
 openList.push_back(tempVector);

 while (!openList.empty()){
   curVector = minOpenList(fCostMat);
   openList.remove(curVector);
   closedList.push_back(curVector);

   if ((curVector[0] == xGoal) && (curVector[1] == yGoal)){
     //display();

     temp.push_back(yGoal);

     temp.push_back(xGoal);

     start.push_back(yStart);
     start.push_back(xStart);
     while (temp != start )
     {
       envObj.setGrid(temp[0], temp[1]);
       temp = parentNode[temp[0]][temp[1]];
         std::cout<<"end";}

     break;
   }
   for ( auto & i : openList){
     if (checkNeighbour(i,curVector)){
       if (!(envObj.getGrid(curVector[0],curVector[1]) == 1 || checkClosedList(curVector) )){
         if (fCostMat[curVector[0]][curVector[1]] + movementCost(i,curVector) < fCostMat[i[0]][i[1]]
               || !checkOpenList(i)){
           nodeObj.setxIndex(i[0]);
           nodeObj.setyIndex(i[1]);
           nodeObj.gValueCalculation(xStart,yStart);
           nodeObj.fValueCalculation(xGoal,yGoal);
           fCostMat[i[0]][i[1]] = nodeObj.getfValue();
           parentNode[i[0]][i[1]] = curVector;
           if (!checkOpenList(i)){
             openList.push_back(i);
           }
         }
       }
     }
   }

 }



}

aStar::aStar() {
}
aStar::~aStar() {
}
