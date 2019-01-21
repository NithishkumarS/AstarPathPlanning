#include <cmath>
#include "node.hpp"


node::node(int x, int y){
  xIndex = x;
  yIndex = y;
  gValue = 0;
  fValue = 0;
}

int node::getxIndex(){
  return xIndex;
}

int node::getyIndex(){
  return yIndex;
}

void node::setxIndex(int _xIndex_){
  xIndex = _xIndex_;
}

void node::setyIndex(int _yIndex_){
  yIndex = _yIndex_;
}

int node::getgValue(){
  return gValue;
}
int node::getfValue(){
  return fValue;
}

void node::fValueCalculation(int xTarget, int yTarget){
    fValue =  gValue + hValueCalculation(xTarget, yTarget);
}

int node::hValueCalculation(int xTarget,int yTarget){
  return sqrt((xIndex - xTarget)*(xIndex - xTarget) + (yIndex - yTarget)*(yIndex - yTarget))*10;
}


void node::gValueCalculation(int xStart, int yStart){
    gValue = sqrt((xIndex - xStart)*(xIndex - xStart) + (yIndex - yStart)*(yIndex - yStart))*10;
}

node::~node(){}
