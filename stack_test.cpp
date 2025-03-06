#include "stack.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[]){
  Stack<int> s = Stack<int>();

  s.push(1);
  s.push(4);
  cout<<s.top()<<endl;
  s.pop();
  cout<<s.top()<<endl;
  s.push(3);
  cout<<s.top()<<endl;
  s.pop();
  cout<<s.top()<<endl;
  s.pop();
  cout<<s.top()<<endl;
}