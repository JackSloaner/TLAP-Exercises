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

struct modeNode{
  int num;
  int reps;
  modeNode *next;
};

typedef modeNode *modeList;

  public:
    ~binaryTree();
    binaryTree();
    binaryTree(int levels);
    void printTree();
    void insertNum(int num);
    void primitivePrint();
    binaryTree& operator=(const binaryTree &rhs);
    float avgAllNums();
    int *modeAllNums();
    float medianAllNums();
    void printModes(int *modeList);

  private: 
    tree makeNewTree(int levels);
    int treeToList(tree head, ptrList &listHead);
    int *mergeSort(int *oldList, int oldLength);
    float roundFloat(float f, int digits);
    float sumAllNums(tree head);
    int countAllNums(tree head);
    void countNums(tree head, modeList &numList);
    void updateList(int num, modeList &numList);
    tree deepCopy(tree original);
    void primitivePrint(tree head);
    int findPath(tree head, boolList &pathTail);
    void printPath(boolList pathHead);
    void insertNum(tree head, boolList nextDirection, int num);
    void deleteTree(tree head);
    void deleteList(ptrList head);
    void deleteList(modeList head);
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

void binaryTree::deleteList(modeList head){
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

float binaryTree::avgAllNums(){
  float sum = sumAllNums(_head);
  int count = countAllNums(_head);
  float raw = sum / count;
  float rounded = roundFloat(raw, 2);
  return rounded;
}

float binaryTree::roundFloat(float f, int digits){
  int multiplyBy = pow(10, digits);
  float bigger = f * multiplyBy;
  (fmod(bigger, 1.0) >= 0.5) ? bigger = ceil(bigger): bigger = floor(bigger);
  bigger /= multiplyBy;
  return bigger;
}

int binaryTree::countAllNums(tree head){
  if (!head) return 0;
  int sum = 1;
  sum += countAllNums(head->LeftSide);
  sum += countAllNums(head->RightSide);
  return sum;
}

float binaryTree::sumAllNums(tree head){
  if (!head) return 0;
  int sum = head->n;
  sum += sumAllNums(head->LeftSide);
  sum += sumAllNums(head->RightSide);
  return sum;
}

int* binaryTree::modeAllNums(){
  //Add check to see if _head is NULL
  modeList treeNumbers = NULL;
  countNums(_head, treeNumbers);
  modeList loopPtr = treeNumbers;
  modeList mode = new modeNode;
  mode->num = -1;
  mode->reps = -1;
  mode->next = NULL;
  while (loopPtr){
    if (loopPtr->reps > mode->reps){
      deleteList(mode);
      modeList newLargest = new modeNode;
      newLargest->num = loopPtr->num;
      newLargest->reps = loopPtr->reps;
      newLargest->next = NULL;
      mode = newLargest;
    } else if (loopPtr->reps == mode->reps){
      modeList newLargest = new modeNode;
      newLargest->num = loopPtr->num;
      newLargest->reps = loopPtr->reps;
      newLargest->next = mode;
      mode = newLargest;
    }
    loopPtr = loopPtr->next;
  }
  int i = 0;
  modeList loopPtr2 = mode;
  while (loopPtr2){
    i++;
    loopPtr2 = loopPtr2->next;
  }

  int *largestNums = new int[i + 1];
  largestNums[0] = i;
  loopPtr2 = mode;
  for (int j = 0; j < i; j++){
    largestNums[j + 1] = loopPtr2->num; // Start here
    loopPtr2 = loopPtr2->next;
  }
  deleteList(mode);
  deleteList(treeNumbers);
  return largestNums;
}

void binaryTree::countNums(tree head, modeList &numList){
  if (!head) return;
  updateList(head->n, numList);
  countNums(head->LeftSide, numList);
  countNums(head->RightSide, numList);
}

void binaryTree::updateList(int num, modeList &numList){
  modeList loopPtr = numList;
  while (loopPtr){
    if (loopPtr->num == num){
      loopPtr->reps++;
      return;
    }
    loopPtr = loopPtr->next;
  }
  loopPtr = new modeNode;
  loopPtr->num = num;
  loopPtr->next = numList;
  loopPtr->reps = 1;
  numList = loopPtr;
} 

float binaryTree::medianAllNums(){
  ptrList newList = NULL;
  int count = treeToList(_head, newList);
  int *numArray = new int[count];
  ptrList loopPtr = newList;
  int i = 0;
  while (loopPtr){
    *(numArray + i) = loopPtr->current->n;
    loopPtr = loopPtr->next;
    i++;
  }
  int *sortedArray = mergeSort(&numArray[0], count);
  int middleIndex = count / 2;
  float median = *(sortedArray + middleIndex) * 1.0;
  if (!(count % 2)){
    median += *(sortedArray + middleIndex - 1);
    median /= 2;
  }
  delete[] sortedArray;
  delete[] numArray;
  return median;
}



int binaryTree::treeToList(tree head, ptrList &listHead){
  if (!head) return 0;
  ptrList newNode = new ptrNode;
  newNode->current = head;
  newNode->next = listHead;
  listHead = newNode;
  int left = treeToList(head->LeftSide, listHead);
  int right = treeToList(head->RightSide, listHead);
  return left + right + 1;
}

int* binaryTree::mergeSort(int *oldList, int oldLength){
  if (oldLength == 1){ 
    int *single = new int;
    int oldNum = *oldList;
    *single = oldNum;
    return single;
    }
  int leftLength = oldLength / 2;
  int rightLength = oldLength - leftLength;
  int *leftList = mergeSort(oldList, leftLength);
  int *rightList = mergeSort(oldList + leftLength, rightLength);
  int *newList = new int[oldLength];

  int right = 0, left = 0, newCount = 0;

  int curRight = *rightList;
  int curLeft = *leftList; 

  while (newCount < oldLength){
    if ((curLeft < curRight && curLeft != 0) || curRight == 0){
      *(newList + newCount) = curLeft;
      left++;
      (left < leftLength) ? curLeft = *(leftList + left) : curLeft = 0;
    } else {
      *(newList + newCount) = curRight;
      right++;
      (right < rightLength) ? curRight = *(rightList + right) : curRight = 0; 
    }
    newCount++;
  }
  delete[] leftList;
  delete[] rightList;
  return newList;
}

void binaryTree::printModes(int *modeList){
  cout << "Mode(s):";
  for (int i = 0; i < modeList[0]; i++){
    cout << modeList[i + 1] << " ";
  }
  cout << endl;
}

int main (){
  binaryTree firstTree;
  firstTree.insertNum(1);
  firstTree.insertNum(75);
  firstTree.insertNum(6);
  firstTree.insertNum(13);
  firstTree.insertNum(5);
  firstTree.insertNum(9);
  firstTree.insertNum(5);
  firstTree.insertNum(9);
  firstTree.printTree();
  binaryTree secondTree;
  secondTree = firstTree;
  int *modes = secondTree.modeAllNums();
  secondTree.printModes(modes);
  delete[] modes;
  float median = secondTree.medianAllNums();
  cout << "\nMedian:" << median << endl;
  float avg = secondTree.avgAllNums();
  cout << "Average:" << avg << endl;
}

// Class for binary tree
// Includes functions for:
// - Inserting number into next available spot in tree
// - Finding the average of all numbers in the tree
// - Finding the median of all numbers in the tree
// - Finding the mode(s) of all numbers in the tree
// - Print modes
// - Print numbers in tree in sequence
// - Printing the tree visually
// - Overloaded assignment operator
// - Constructor and destructor

// **Highlighted helper function**:
// - mergeSort: Sorts an array of integers using merge sort, returns a pointer to the sorted array