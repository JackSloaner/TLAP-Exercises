#include <iostream>
#include <math.h> 
#include <time.h>
#include <unistd.h>
using namespace std;

class bSearchTree{
  private: 
    struct treeNode{
      treeNode *LeftSide;
      int n;
      treeNode *RightSide;
    };

    typedef treeNode *tree;

    struct ptrNode{
    treeNode *current;
    ptrNode *next;
  };

typedef ptrNode *ptrList;

  public:
    ~bSearchTree();
    bSearchTree();
    bSearchTree(int levels);
    bSearchTree(int levels, bool isRand);
    tree makeRandTree(int levels);
    void printTree();
    void makeBS(int levels);
    bool isBinarySearch();
    void insertNum(int num);
    void primitivePrint();
  private: 
    void insertNumber(int num);
    void primitivePrint(tree head);
    int insertNum(int num, tree head);
    bool isBinarySearch(tree head);
    void deleteTree(tree head);
    void makeBS(tree head, int lower, int upper);
    tree makeSkeleton(int levels);
    void deleteList(ptrList head);
    void printList(ptrList head); 
    void printNums(ptrList head, int spacesBetween);
    ptrList newLevel(ptrList oldLevel);
    tree _head;
    int _levels;
};

bSearchTree::tree bSearchTree::makeRandTree(int levels){
  if (!levels) return NULL;
  tree newNode = new treeNode;
  newNode->n = rand() % 25;
  usleep(rand() % 100 + 100000);
  newNode->LeftSide = makeRandTree(levels - 1);
  newNode->RightSide = makeRandTree(levels - 1);
  return newNode;
}

void bSearchTree::deleteTree(tree head){
  if (!head) return;
  deleteTree(head->RightSide);
  deleteTree(head->LeftSide);
  delete head;
}

bSearchTree::~bSearchTree(){
  deleteTree(_head);
}

bSearchTree::bSearchTree(){
  _head = NULL;
  _levels = 0;
}

bSearchTree::bSearchTree(int levels, bool isRand) {
  _levels = levels;
  _head = makeRandTree(levels);
}

bSearchTree::bSearchTree(int levels){
  makeBS(levels);
}

void bSearchTree::printList(ptrList head){
  ptrList loopPtr = head;
  int count = 0;
  while (loopPtr){
    count += 1;
    loopPtr = loopPtr->next;
  }
  int curLevel = log2(count);
  int multiplier = 4;
  int spacesBtwn = 2;

  for (int i = 0, n = (_levels - 1) - curLevel; i < n; i++){
    spacesBtwn += multiplier;
    multiplier *= 2;
  }
  int spacesBefore = spacesBtwn - (multiplier/2);
  for (int i = 0; i < spacesBefore; i++){
    cout << " ";
  }
  printNums(head, spacesBtwn);
}

void bSearchTree::printNums(ptrList head, int spacesBetween){
  if (!head) return;
  if (head->current){
    cout << head->current->n;
    if (head->current->n < 10) cout << " ";
  } else {
    cout << "  ";
  }
  for (int i = 0; i < spacesBetween; i++) cout << " ";

  printNums(head->next, spacesBetween);
}

void bSearchTree::deleteList(ptrList head){
  if (!head) return;
  deleteList(head->next);
  delete head;
}

bSearchTree::ptrList bSearchTree::newLevel(ptrList oldLevel){
  if (!oldLevel) return NULL;
  ptrList leftSide = new ptrNode;
  ptrList rightSide = new ptrNode;
  if (oldLevel->current) {
    leftSide->current = oldLevel->current->LeftSide;
    rightSide->current = oldLevel->current->RightSide;
  } else {
    leftSide->current = NULL;
    rightSide->current = NULL;
  }
  leftSide->next = rightSide;
  rightSide->next = newLevel(oldLevel->next);
  return leftSide;
}

void bSearchTree::printTree(){
  if (!_head) return;
  ptrList curLevel = new ptrNode;
  curLevel->current = _head;
  curLevel->next = NULL;
  for (int i = 0; i < _levels; i++){
    printList(curLevel);
    
    cout << "\n";

    ptrList nextLevel = newLevel(curLevel);
    deleteList(curLevel);
    curLevel = nextLevel;
  }
  deleteList(curLevel);
}

void bSearchTree::makeBS(int levels){
  _levels = levels;
  _head = makeSkeleton(levels);
  int initialUpper = pow(2, levels);
  makeBS(_head, 0, initialUpper);
}

void bSearchTree::makeBS(tree head, int lower, int upper){
  if (!head) return;
  int curNum = (upper + lower) / 2;
  head->n = curNum;
  makeBS(head->LeftSide, lower, curNum);
  makeBS(head->RightSide, curNum, upper);
}

bSearchTree::tree bSearchTree::makeSkeleton(int levels){
  if (!levels) return NULL;
  tree newNode = new treeNode;
  newNode->LeftSide = makeSkeleton(levels - 1);
  newNode->RightSide = makeSkeleton(levels - 1);
  return newNode;
}

bool bSearchTree::isBinarySearch(){
  if (!_head) return false;
  return isBinarySearch(_head);
}

bool bSearchTree::isBinarySearch(tree head){
  if (!head) return true;
  bool leftCheck = true;
  if (head->LeftSide) {
    leftCheck = head->n > head->LeftSide->n;
  }
  bool rightCheck = true;
  if (head->RightSide) {
    rightCheck = head->n < head->RightSide->n;
  }
  bool currentNode = rightCheck && leftCheck;
  leftCheck = isBinarySearch(head->LeftSide);
  rightCheck = isBinarySearch(head->RightSide);
  return currentNode && leftCheck && rightCheck;
}

void bSearchTree::insertNum(int num){
  if (!_head) {

    _head = new treeNode;
    _head->n = num;
    _head->RightSide = NULL;
    _head->LeftSide = NULL;
    _levels = 1;
    cout << "Number successfully inserted\n";
    return;
  }

  if (!isBinarySearch()){
    cout << "Tree is not binary search\n";
    return;
  }
  
  int newLevels = insertNum(num, _head);
  if (newLevels > _levels){
    _levels = newLevels;
    cout << "Number successfully inserted\n";
  } else if (newLevels){
    cout << "Number successfully inserted, new level\n";
  } else {
    cout << "Number already exists in tree\n";
  }
}

int bSearchTree::insertNum(int num, tree head){
  if (num == head->n) return false;
  tree *next;
  bool isRightSide;
  (num > head->n) ? next = &(head->RightSide) : next = &(head->LeftSide);
  if (!*next){
    *next = new treeNode;
    (*next)->n = num;
    (*next)->RightSide = NULL;
    (*next)->LeftSide = NULL;
    return 2;
  }
  int levelsAfter = insertNum(num, *next);
  if (levelsAfter){
    return levelsAfter + 1;
  } 
  return false;
}

void bSearchTree::primitivePrint(){
  primitivePrint(_head);
  cout << "Levels: " << _levels;
}

void bSearchTree::primitivePrint(tree head){
  if (!head) return;
  cout << head->n << " ";
  primitivePrint(head->LeftSide);
  primitivePrint(head->RightSide);
}

int main(){
  srand((unsigned) time(NULL));
  bSearchTree firstTree;
  firstTree.insertNum(15);
  firstTree.insertNum(6);
  firstTree.insertNum(18);
  firstTree.insertNum(40);
  firstTree.insertNum(8);
  firstTree.insertNum(1);
  firstTree.insertNum(23);
  firstTree.insertNum(15);
  firstTree.insertNum(19);
  firstTree.insertNum(17);
  firstTree.printTree();
}

// Class for binary search tree.
// contains methods for:
// - Making a basic binary search tree given number of levels
// - verifying if tree is in fact binary search (isBinarySearch())
// - Making random tree given a number levels (to test isBinarySearch())
// - inserting any given number into tree at the proper place to maintain binary search (main use of recursion)
// - printing numbers in tree in a sequence (primitivePrint())
// - printing tree visually (printTree())
// - constructor and destructor
