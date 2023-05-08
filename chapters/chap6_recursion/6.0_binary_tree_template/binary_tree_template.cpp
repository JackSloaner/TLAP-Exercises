#include <iostream>
#include <math.h> 
#include <time.h>
#include <unistd.h>
using namespace std;

class binaryTree{
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
    struct boolNode{
      bool left;
      boolNode *next;
    };

typedef boolNode *boolList;

  public:
    ~binaryTree();
    binaryTree();
    binaryTree(int levels);
    tree makeNewTree(int levels);
    void printTree();
    void insertNum(int num);
    void primitivePrint();
    binaryTree& operator=(const binaryTree &rhs);
  private: 
    tree deepCopy(tree head);
    void primitivePrint(tree head);
    int findPath(tree head, boolList &pathTail);
    void printPath(boolList pathHead);
    void insertNum(tree head, boolList nextDirection, int num);
    void deleteTree(tree head);
    void deleteList(ptrList head);
    void deleteList(boolList head);
    void printList(ptrList head); 
    void printNums(ptrList head, int spacesBetween);
    ptrList newLevel(ptrList oldLevel);

    tree _head;
    int _levels;
};

void binaryTree::deleteTree(tree head){
  if (!head) return;
  deleteTree(head->RightSide);
  deleteTree(head->LeftSide);
  delete head;
}

binaryTree::~binaryTree(){
  deleteTree(_head);
  _head = NULL;
}

binaryTree::binaryTree(){
  _head = NULL;
  _levels = 0;
  srand((unsigned) time(NULL));
}

binaryTree::binaryTree(int levels) {
  srand((unsigned) time(NULL));
  _levels = levels;
  _head = makeNewTree(levels);
  
}

binaryTree& binaryTree::operator=(const binaryTree &rhs){
  if (this != &rhs){
    deleteTree(_head);
    _head = NULL;
    _head = deepCopy(rhs._head);
    _levels = rhs._levels; //Maybe needed
  }
  return *this;
}

binaryTree::tree binaryTree::deepCopy(tree original){
  if (!original) return NULL;
  tree newTree = new treeNode;
  newTree->n = original->n;
  newTree->LeftSide = deepCopy(original->LeftSide);
  newTree->RightSide = deepCopy(original->RightSide);
  return newTree;
}

binaryTree::tree binaryTree::makeNewTree(int levels){
  if (!levels) return NULL;
  tree newNode = new treeNode;
  newNode->n = rand() % 25;
  usleep(rand() % 100 + 100000);
  newNode->LeftSide = makeNewTree(levels - 1);
  newNode->RightSide = makeNewTree(levels - 1);
  return newNode;
}

void binaryTree::printList(ptrList head){
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

void binaryTree::printNums(ptrList head, int spacesBetween){
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

void binaryTree::deleteList(ptrList head){
  if (!head) return;
  deleteList(head->next);
  delete head;
}

void binaryTree::deleteList(boolList head){
  if (!head) return;
  deleteList(head->next);
  delete head;
}

binaryTree::ptrList binaryTree::newLevel(ptrList oldLevel){
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

void binaryTree::printTree(){
  if (!_head) return;
  ptrList curLevel = new ptrNode;
  curLevel->current = _head;
  curLevel->next = NULL;
  for (int i = 0; i < _levels; i++){
    printList(curLevel);
    
    cout << "\n";

    ptrList nextLevel = newLevel(curLevel); // Check here for bug
    deleteList(curLevel);
    curLevel = nextLevel;
  }
  deleteList(curLevel);
}

void binaryTree::insertNum(int num){
  if (!_head){
    tree newHead = new treeNode;
    newHead->n = num;
    newHead->LeftSide = NULL;
    newHead->RightSide = NULL;
    _head = newHead;
    _levels = 1;
    return;
  }
  
  boolList path = NULL;
  int shortestLength = findPath(_head, path);
  if (shortestLength == _levels){
    _levels++;
  }

  insertNum(_head, path, num);

  deleteList(path);
}

void binaryTree::printPath(boolList pathHead){
  if (!pathHead) return;
  (pathHead->left) ? cout << "left\n" : cout << "right\n";
  printPath(pathHead->next);
}

void binaryTree::insertNum(tree head, boolList nextDirection, int num){
  if (!nextDirection) {
    _head = new treeNode;
    _head->n = num;
    _head->RightSide = NULL;
    _head->LeftSide = NULL;
    return;
  }
  tree nextNode;
  (nextDirection->left) ? nextNode = head->LeftSide : nextNode = head->RightSide;
  if (!nextNode) {
    tree newNode = new treeNode;
    newNode->n = num;
    newNode->LeftSide = NULL;
    newNode->RightSide = NULL;
    (nextDirection->left) ? head->LeftSide = newNode : head->RightSide = newNode;
    return;
  }
  insertNum(nextNode, nextDirection->next, num);
}

int binaryTree::findPath(tree head, boolList &pathTail){
  if (!head){
    pathTail->next = NULL;
    return 0;
    // Fix segmentation fault here, pathTail doesn't exist in the first call
  }
  boolList currentLeft = new boolNode;
  currentLeft->left = 1;
  boolList currentRight = new boolNode;
  currentRight->left = 0;
  int smallestLeft = findPath(head->LeftSide, currentLeft);
  int smallestRight = findPath(head->RightSide, currentRight);
  int smallestNum;
  if (smallestLeft <= smallestRight) {
    (pathTail) ? pathTail->next = currentLeft : pathTail = currentLeft;
    smallestNum = smallestLeft;
    deleteList(currentRight);
  } else {
    (pathTail) ? pathTail->next = currentRight : pathTail = currentRight; 
    smallestNum = smallestRight;
    deleteList(currentLeft);
  }
  return smallestNum + 1;
}

void binaryTree::primitivePrint(){
  primitivePrint(_head);
  cout << "Levels: " << _levels;
}

void binaryTree::primitivePrint(tree head){
  if (!head) return;
  cout << head->n << " ";
  primitivePrint(head->LeftSide);
  primitivePrint(head->RightSide);
}

int main (){
  binaryTree firstTree;
  firstTree.insertNum(1);
  firstTree.insertNum(2);
  firstTree.insertNum(3);
  firstTree.insertNum(4);
  firstTree.insertNum(5);
  firstTree.insertNum(6);
  firstTree.insertNum(7);
  firstTree.insertNum(8);
  firstTree.insertNum(9);
  binaryTree secondTree;
  secondTree = firstTree;
  secondTree.printTree();
}

// My template for basic binary tree. Includes methods for making a new tree given amount of levels, printing the tree, inserting a number, and deleting the tree