#include <iostream>
using namespace std;

struct boolNode{
  bool b;
  boolNode *next;
};

typedef boolNode *boolList;

void addNode(bool tf, boolList &head){
  boolList newNode = new boolNode;
  newNode->b = tf;
  newNode->next = head;
  head = newNode;
}

void printList(boolList head){
  if (head == NULL) return;
  cout << head->b;
  printList(head->next);
}

bool evenOdd(boolList head){
  if (head == NULL) return false;
  bool cur = head->b;
  bool next = evenOdd(head->next);
  if (!cur) return cur + next;
  if (next) return false;
  return true;
}

int main(){
  boolList head = new boolNode;
  head->b = 1;
  head->next = NULL;
  addNode(0, head);
  addNode(1, head);
  addNode(1, head);
  cout << evenOdd(head);
}

// Store string of boolean values in a linked list, return true if there are an even number of true values, false otherwise, using recursion