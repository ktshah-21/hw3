#include "llrec.h"
#include <iostream>
//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
  if(head!=nullptr){
    if(head->val<=pivot){
      //std::cout<<head->val<<std::endl;
      smaller=head;
      head=head->next;
      //smaller->next=nullptr;
      // head=head->next;
      llpivot(head, smaller->next, larger, pivot);
    }else{
      larger=head;
      head=head->next;
      //larger->next=nullptr;
      // head=head->next;
      llpivot(head, smaller, larger->next, pivot);
    }
  }else{
    if(smaller!=nullptr){
      smaller = nullptr;
    }
    if(larger!=nullptr){
      larger = nullptr;
    }
  }
}