#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
using namespace std;

struct treeNode{
  treeNode *left;
  int n;
  treeNode *right;
};

typedef treeNode *tree;

struct ptrNode{
  treeNode *current;
  ptrNode *next;
};

typedef ptrNode *ptrList;

tree makeHeap(int levels){
  if (!levels) return NULL;
  tree newNode = new treeNode;
  newNode->n = levels;
  newNode->left = makeHeap(levels - 1);
  newNode->right = makeHeap(levels - 1);
  return newNode;
}

void deleteTree(tree head){
  if (!head) return;
  deleteTree(head->right);
  deleteTree(head->left);
  delete head;
}

void deleteList(ptrList head){
  if (!head) return;
  deleteList(head->next);
  delete head;
}

tree makeTree(int levels){
  if (!levels) return NULL;
  tree newNode = new treeNode;
  newNode->n = rand() % 25;
  usleep(rand() % 100 + 100000);
  newNode->left = makeTree(levels - 1);
  newNode->right = makeTree(levels - 1);
  return newNode;
}

void printDownLeft(tree head){
  if (!head) return;
  cout << head->n;
  printDownLeft(head->left);
}

void printList(ptrList head){
  if (!head) return;
  cout << head->current->n << " ";
  printList(head->next);
}

ptrList newLevel(ptrList oldLevel){
  if (!oldLevel) return NULL;
  ptrList leftSide = new ptrNode;
  leftSide->current = oldLevel->current->left;
  ptrList rightSide = new ptrNode;
  rightSide->current = oldLevel->current->right;

  leftSide->next = rightSide;
  rightSide->next = newLevel(oldLevel->next);
  return leftSide;
}

void printTree(tree head, int levels){
  ptrList curLevel = new ptrNode;
  curLevel->current = head;
  curLevel->next = NULL;
  for (int i = 0; i < levels; i++){
    printList(curLevel);
    cout << "\n";
    ptrList nextLevel = newLevel(curLevel);
    deleteList(curLevel);
    curLevel = nextLevel;
  }
  deleteList(curLevel);
}

bool isHeap(tree head) {
  if (!head->left && !head->right) return true;
  bool curLargest = true;
  if (head->n <= head->right->n || head->n <= head->left->n) curLargest = false;
  bool rightSide = isHeap(head->left);
  bool leftSide = isHeap(head->right);
  return curLargest && rightSide && leftSide;
}

int main(){
  tree heapOne = makeHeap(5);
  printTree(heapOne, 5);
  cout << isHeap(heapOne) << "\n";
  srand((unsigned) time(NULL));
  tree randTree = new treeNode;
  randTree->n = 30;
  randTree->left = makeTree(2);
  randTree->right = makeTree(2);
  printTree(randTree, 3);
  cout << "\n" << isHeap(randTree);
  deleteTree(heapOne);
}

// Binary Tree Heap program, includes functions to check if a tree is a heap, make a heap, print binary tree, and make a random binary tree