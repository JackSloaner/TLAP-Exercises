#include <iostream>
#include <string>
using namespace std;

typedef char *strn;

class stringC{
private:
  struct charNode{
    char c;
    charNode *next;
  };
  struct ptrNode{
    strn s;
    ptrNode *next;
  };

  typedef charNode *str;
  typedef ptrNode *ptrPtr;
public:
  stringC();
  stringC(string s);
  stringC(const stringC &original);
  ~stringC();
  void appendChar(char newChar);
  void concatenate(const stringC &newString);
  strn getString();
  char characterAt(int pos);
  void deleteChar(char delChar);  
  void deleteLastChar();
  stringC subStr(int startPos, int numSpots);
  stringC& operator=(const stringC &rhs);
  char operator[](int pos);
private:
  str deepCopy(str original, int count);
  str deepCopy(str original);
  int strLength(str s);
  void initPtrs();
  void deleteList(str head);
  void deleteList(ptrPtr head);
  str _head;
  str _tail;
  ptrPtr _ptrList;
};

void stringC::initPtrs(){
  _head = NULL;
  _tail = NULL;
  _ptrList = NULL;
}

void stringC::deleteList(str head){
  if (head == NULL) return;
  str placeHold = head->next;
  delete head;
  deleteList(placeHold);
}

void stringC::deleteList(ptrPtr head){
  if (head == NULL) return;
  ptrPtr placeHold = head->next;
  delete head->s;
  delete head;
  deleteList(placeHold);
}

stringC::stringC(){
  initPtrs();
}

stringC::stringC(string s){
  initPtrs();
  for (int i = 0; i < s.length(); i++){
    appendChar(s[i]);
  }
}

stringC::stringC(const stringC &original){
  initPtrs();
  concatenate(original);
}

stringC::~stringC(){
  deleteList(_head);
  _head = NULL;
  deleteList(_ptrList);
  _ptrList = NULL;
}

void stringC::appendChar(char newChar){
  str newNode = new charNode;
  newNode->c = newChar;
  if (_tail){
    _tail->next = newNode;
  } else {
    _head = newNode;
  }
  _tail = newNode;
  _tail->next = NULL;
}

void stringC::concatenate(const stringC &newString){
  str newLoopPtr = newString._head;
  while (newLoopPtr != NULL){
    appendChar(newLoopPtr->c);
    newLoopPtr = newLoopPtr->next;
  }
}

int stringC::strLength(str s){
  if (!s) return 0;
  int count = strLength(s->next) + 1;
  return count;
}

strn stringC::getString(){
  int count = strLength(_head);
  strn copied = new char[count + 1];
  str loopPtr = _head;
  for (int i = 0; i < count; i ++){
    copied[i] = loopPtr->c;
    loopPtr = loopPtr->next;
  }
  copied[count] = NULL;
  ptrPtr newPtr = new ptrNode;
  newPtr->s = copied;
  newPtr->next = _ptrList;
  _ptrList = newPtr;
  return copied;
}

char stringC::characterAt(int pos){
  if (!_head) return NULL;
  str loopPtr = _head;
  int i = 0;
  while (true){
    if (i == pos) return loopPtr->c;
    if (!loopPtr->next) return NULL;
    loopPtr = loopPtr->next;
    i++;
  }
}

void stringC::deleteChar(char delChar){
  if (!_head) return;
  if (_head->c == delChar){
    str delPtr = _head;
    _head = _head->next;
    delete delPtr;
    deleteChar(delChar);
    return;
  }
  str current = _head->next;
  str trail = _head;
  while (current != NULL){
    if (current->c == delChar) {
      trail->next = current->next;
      if (!current->next) _tail = trail;
      delete current;
      current = trail->next;
    } else {
      trail = trail->next;
      current = current->next;
    }
  }
}

void stringC::deleteLastChar(){
  if (!_head){
    return;
  } else if (!_head->next){
    delete _head;
    _head = NULL;
    _tail = NULL;
    return;
  }
  str trail = _head;
  str current = _head->next;
  while (true){
    if (!current->next){
      delete current;
      trail->next = NULL;
      _tail = trail;
      return;
    }
    current = current->next;
    trail = trail->next;
  }
}

stringC stringC::subStr(int startPos, int numSpots){
  str startChar = _head;
  stringC newStr;
  while (startPos && startChar){
    startChar = startChar->next;
    startPos--;
  }
  newStr._head = deepCopy(startChar, numSpots);
  return newStr;
}

stringC::str stringC::deepCopy(str original, int count){
  if (!original || !count){
      return NULL;
  } else {
    str newNode = new charNode;
    newNode->c = original->c;
    count--;
    newNode->next = deepCopy(original->next, count);
    return newNode;
  }
}

stringC::str stringC::deepCopy(str original){
  if (!original){
      return NULL;
  } else {
    str newNode = new charNode;
    newNode->c = original->c;
    newNode->next = deepCopy(original->next);
    return newNode;
  }
}

stringC& stringC::operator=(const stringC &rhs){
  if (this != &rhs){
    deleteList(_head);
    _head = deepCopy(rhs._head);
  }
  return *this;
}

char stringC::operator[](int pos){
  return this->characterAt(pos);
}

int main(){
  stringC firstStr("Hello World!");
  cout << firstStr[1];
}

// Class for strings as linked list of of characters. 
// Includes methods for appending an extra character, concatenating another string of the same class, deleting a certain character out of a string,
// deleting the last character in the string, finding character at a given index, and getting substrings. 
// Also includes overloaded assignment operator and [] operator.