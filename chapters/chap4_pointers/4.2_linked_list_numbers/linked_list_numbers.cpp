#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct numNode {
  int n;
  numNode *next;
  numNode *prev;
};

typedef numNode *numb;

struct dubList {
  numb start;
  numb finish;
};

dubList readFile(string fName){
  fName = "./csv/" + fName + ".csv";
  fstream file;
  file.open(fName); 
  if ( !file.is_open()){
    cerr << "Unable to open file";
    exit(0);
  }
    
  int count = 0;
  numb bottom = NULL;
  numb top = NULL;
  for (string i; getline(file, i, ','); ){
    numb curDig = new numNode;
    int placeHold = stoi(i);
    curDig->n = placeHold;
    curDig->prev = bottom;
    curDig->next = NULL;
    if (bottom){
    bottom->next = curDig;
    } else {
    top = curDig;
    }
    bottom = curDig;
    count++;
  }
  dubList initial;
  initial.start = top;
  initial.finish = bottom;
  return initial;
}

void printList (numb list){
  while (list != NULL){
    cout << list->n; 
    list = list->next;
  }
  cout << "\n";
  return;
}

void deleteList(numb& list){
  while (list != NULL){
    numb placeHold = list;
    list = placeHold->next;
    delete placeHold;
  }
  list = 0;
}

dubList userPrompt(){
  int inputNum = 0;
  string fullNum = "";
  cout << "enter your number, one digit at a time, -1 to end your number: \n";
  numb bottom = NULL;
  numb top = NULL;
  label:
  while (inputNum >= 0){
    bool keepGoing = true;
    do {
      cout << ":";
      cin >> inputNum;
      if (inputNum < 10) keepGoing = false;
      if (inputNum < 0) goto label;
    } while(keepGoing);
    fullNum += to_string(inputNum);
    cout << fullNum << "\n";

    numb newDig = new numNode;
    newDig->n = inputNum;
    newDig->prev = bottom;
    newDig->next = NULL;
    if (bottom){
      bottom->next = newDig;
    } else {
      top = newDig;
    }
    bottom = newDig;
  }
  dubList finalNum;
  finalNum.start = top;
  finalNum.finish = bottom;
  return finalNum;
}

dubList intToList(int numbr){
  dubList num;
  num.start = NULL;
  num.finish = NULL;
  if (numbr == 0) {
    numb zer = new numNode;
    zer->n = 0;
    zer->next = NULL;
    zer->prev = NULL;
    num.start = zer;
    num.finish = zer;
    return num;
  } 
  int i = 1;
  while (numbr >= i){
    int j = i * 10;
    int chopped = numbr % j;
    int count = 0;
    while (chopped >= i){
      chopped -= i;
      count++;
    }
    
    numb currentPos = new numNode;
    currentPos->n = count;
    currentPos->next = num.start;
    currentPos->prev = NULL;
    if (num.start){
      num.start->prev = currentPos;
    } else {
      num.finish = currentPos;
    }
    num.start = currentPos;
    i *= 10;
  }
  return num;
}

dubList sumLists(dubList numbers[]){
  numb digArray[2];
  digArray[0] = numbers[0].finish;
  digArray[1] = numbers[1].finish;
  dubList finalSum;
  finalSum.start = NULL;
  finalSum.finish = NULL;
  bool plusOne = false;
  bool keepGoing = false;
  do {
    int sum = 0;
    for (int i = 0; i < 2; i++){
      if (digArray[i]){
        sum += digArray[i]->n;
      }
    }
    sum += plusOne;
    if (sum >= 10){
      sum %= 10;
      plusOne = true;
    } else{
      plusOne = false;
    }
    numb newSum = new numNode;
    newSum->n = sum;
    newSum->prev = NULL;
    newSum->next = finalSum.start;
    if (finalSum.start){
      finalSum.start->prev = newSum;
    } else{
      finalSum.finish = newSum;
    }
    finalSum.start = newSum;
    for (int i = 0; i < 2; i++){
      if (digArray[i]){
        digArray[i] = digArray[i]->prev;
      }
    }

    keepGoing = false;
    for (int i = 0; i < 2; i++){
      keepGoing = keepGoing || digArray[i];
    }
    keepGoing = keepGoing || plusOne;
  } while (keepGoing); 
  return finalSum;
}

int main(){
  // dubList firstNum = readFile("nums");
  dubList numbs[2];
  numbs[0] = intToList(500);
  numbs[1] = intToList(13543);
  dubList sum = sumLists(numbs);
  printList(sum.start);
  deleteList(sum.start);
  deleteList(numbs[0].start);
  deleteList(numbs[1].start);
}

// Stores numbers in a linked list, Adds two numbers together, and returns the sum in a linked list
// Includes userPrompt function to get user input for numbers