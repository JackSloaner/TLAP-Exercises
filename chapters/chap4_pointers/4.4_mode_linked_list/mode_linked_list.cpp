#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

struct listNode {
  int number;
  int count;
  listNode *next;
};

typedef listNode *numList;

void readFile(numList& start){
  const string FILENAME = "mode.csv";
  fstream file;
  file.open(FILENAME); 
  if ( !file.is_open()){
    cerr << "Unable to open file";
    exit(0);
  }

  for (string i; getline(file, i, ','); ){
    listNode *newNode = new listNode;
    newNode->next = start;
    newNode->count = 1;
    newNode->number = stoi(i);
    start = newNode;
  }
  return;
}

void deleteList(numList& list){
  while (list != NULL){
    numList placeHold = list;
    list = placeHold->next;
    delete placeHold;
    placeHold = 0;
  }
}

void updateHistogram(numList& histogram, int num){
  numList currentHisto = histogram;
  bool keepGoing = true;
  bool containsNum = false;
  if (histogram){
    while (keepGoing) {
      if(currentHisto->number == num){
        currentHisto->count++;
        keepGoing = false;
        containsNum = true;
      } else{
        currentHisto = currentHisto->next;
        keepGoing = currentHisto;
      }
    }
  }
  
  if (!containsNum){
    numList newNode = new listNode;
    newNode->next = histogram;
    newNode->number = num;
    newNode->count = 1;
    histogram = newNode;
  }

  return;
}

void copyNL(numList toCopy, numList& copyTo){
  copyTo->count = toCopy->count;
  copyTo->number = toCopy->number;
  copyTo->next = NULL;
}

void findMode(numList list, numList& modeList){
  numList current = list;
  numList histogram = 0;
  while (current != NULL) {
    updateHistogram(histogram, current->number);
    current = current->next;
  } 
  numList currentMode = new listNode;
  copyNL(histogram, currentMode);
  current = histogram->next;
  while(current != NULL){
    if (currentMode->count < current->count){
      deleteList(currentMode);
      currentMode = new listNode;
      copyNL(current, currentMode);
    } else if (currentMode->count == current->count){
      numList newNode = new listNode;
      newNode->count = current->count;
      newNode->number = current->number;
      newNode->next = currentMode;
      currentMode = newNode;
    }
    current = current->next;
  }
  modeList = currentMode;
  deleteList(histogram);
  return;
}

void printModes(numList modeList){
  cout << "The mode(s) is/are the following:\n";
  while(modeList != NULL){
    cout << modeList->number << "\n";
    modeList = modeList->next;
  }
}

int main(){
  numList list = 0;
  readFile(list);
  numList mode = 0;
  findMode(list, mode);
  printModes(mode);
  deleteList(list);
  deleteList(mode);
}

//Finds the mode(s) in a linked list of numbers