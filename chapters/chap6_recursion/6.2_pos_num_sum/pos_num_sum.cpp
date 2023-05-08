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

void deleteList(numList &list){
  while (list){
    numList placeHold = list;
    list = list->next;
    delete placeHold;
  }
  list = NULL;
}

void printList(numList head){
  if (head == NULL) return;
  cout << head->n << " ";
  printList(head->next);
}

numList deleteNum(int num, numList head){
  if (!head) return NULL;
  if (head->n == num){
    numList placeHold = head->next;
    delete head;
    return deleteNum(num, placeHold);
  } else {
    head->next = deleteNum(num, head->next);
    return head;
  }
}

int addPosNums(numList head){
  if (!head) return 0;
  int addThis = 0;
  if (head->n > 0) addThis += head->n;
  return addThis + addPosNums(head->next);
}

int main(){
  numList head = new numNode;
  head->n = 3;
  head->next = NULL;
  for (int i = -4; i <= 3; i++) addNode(i, head);
  addNode(10, head);
  addNode(-100, head);
  head = deleteNum(3, head);
  cout << addPosNums(head) << endl;
  printList(head);
  deleteList(head);
}

// Program to recursively sum all of the positive numbers in a linked list