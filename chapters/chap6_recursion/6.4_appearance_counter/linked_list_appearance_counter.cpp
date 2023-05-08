#include <iostream>
using namespace std;

struct numNode{
  int n;
  numNode *next;
};

typedef numNode *numList;

void addNode(int num, numList &head){
  numList newNode = new numNode;
  newNode->n = num;
  newNode->next = head;
  head = newNode;
}

int recursiveTargNum(int target, numList head){
  if (!head) return 0;
  return (target == head->n) + recursiveTargNum(target, head->next);
}

int main(){
  numList head = new numNode;
  head->n = 3;
  head->next = NULL;
  for (int i = -4; i <= 3; i++) addNode(i, head);
  addNode(10, head);
  addNode(-100, head);
  cout << recursiveTargNum(3, head);
}

// Counts the amount of times a target number appears in a linked list. Done recursively.