#include "heap.h"
#include <iostream>


int main(){
  Heap<int> h1;

  //h1.push(1);
  h1.push(2);
  h1.push(4);
  std::cout<<h1.top()<<std::endl;
  h1.pop();
  std::cout<<h1.top()<<std::endl;
  //h1.pop();
  h1.push(3);
  std::cout<<h1.top()<<std::endl;
  h1.pop();
  h1.push(5);
  std::cout<<h1.top()<<std::endl;
  h1.pop();
}