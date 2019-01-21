
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
  return (xIndex - xTarget)*(xIndex - xTarget) + (yIndex - yTarget)*(yIndex - yTarget);
}


void node::gValueCalculation(int xStart, int yStart){
    gValue = (xIndex - xStart)*(xIndex - xStart) + (yIndex - yStart)*(yIndex - yStart)
}

node::~node(){}
