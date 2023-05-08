#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

struct listNode { // For readFile()
  string c;
  listNode *next;
};

typedef listNode *tempStr;

typedef string *str;

struct strPlus {
  str strn;
  int length;
};

struct strNode { //for replaceText()
  int position;
  strNode *next;
};

typedef strNode *firstPos;

void readFile(strPlus& s, string fName){
  fName = "./csv/" + fName + ".csv";
  fstream file;
  file.open(fName); 
  if ( !file.is_open()){
    cerr << "Unable to open file";
    exit(0);
  }

  int count = 0;
  tempStr temp = NULL;
  for (string i; getline(file, i, ','); ){
    tempStr curChar = new listNode;
    curChar->c = i;
    curChar->next = temp;
    temp = curChar;
    count++;
  }

  str s1 = new string[count];
  for (int i = count - 1; i >= 0; i--){
    s1[i] = temp->c;  
    tempStr prev = temp;
    temp = temp->next;
    delete prev;
    prev = 0;
  }
  s.strn = s1;
  s.length = count;
  return;
}

void deleteStr(strPlus s){
  delete[] s.strn;
  s.strn = NULL;
}

void deleteList(firstPos& list){
  while (list != NULL){
    firstPos placeHold = list;
    list = placeHold->next;
    delete placeHold;
    placeHold = 0;
  }
  list = 0;
}

void printList (firstPos list){
  while (list != NULL){
    cout << list->position << " "; 
    list = list->next;
  }
  cout << "\n";
}

strPlus subString(strPlus s, int start, int len){
  strPlus sub;
  if (start >= s.length) {
    sub.length = 0;
    sub.strn = new string[0];
    return sub;
  }
  if (s.length < start + len){
    len = s.length - start;
  }
  sub.length = len;
  sub.strn = new string[sub.length];
  for (int i = 0; i < sub.length; i++){
    sub.strn[i] = s.strn[start + i];
  }
  return sub;
}

void addChars(firstPos& posList, strPlus& source, strPlus replacement, strPlus replaceText, strPlus target){
  int i = 0;
  int j = 0;
  while (i < source.length){
    if (posList == NULL){
      while(i < source.length){
        replacement.strn[j] = source.strn[i];
        j++;
        i++;
      }
    } else {
      while(i < posList->position){
        replacement.strn[j] = source.strn[i];
        j++;
        i++;
      }
      for (int k = 0; k < replaceText.length; k++){
        replacement.strn[j] = replaceText.strn[k];
        j++;
      }
      posList = posList->next;
      i += target.length;
    }

  }
  replacement.length = j;
  deleteList(posList);
}

bool checkMatch(int& i, strPlus source, strPlus target){
  int iNew = i;
  int j = 0;
  while (j < target.length){
    if (source.strn[iNew + j] != target.strn[j]){
      return false;
    }
    j++;
  }
  
  i = iNew - 1;
  return true;
}

strPlus replaceText(strPlus source, strPlus target, strPlus replaceText){
  int numDiff = replaceText.length - target.length;
  firstPos posList = NULL;
  int numPositions = 0;
  for (int i = source.length - 1; i >= 0; i--){
    if (source.strn[i] == *target.strn) {
      int postn = i;
      if (checkMatch(i, source, target)){
        firstPos newPos = new strNode;
        newPos->next = posList;
        newPos->position = postn;
        posList = newPos;
        numPositions++;
      }
    }
  }
  strPlus replaced;
  replaced.length = source.length + numPositions * (replaceText.length - target.length); 
  replaced.strn = new string[replaced.length];
  addChars(posList, source, replaced, replaceText, target);
  return replaced;
}

void printString(strPlus s){
  for (int i = 0; i < s.length; i++){
    cout << s.strn[i];
  }
  return;
}

int main(){
  strPlus s, repText;
  repText.length = 0;
  s.strn = 0;
  readFile(s, "chars");
  readFile(repText, "replace");
  strPlus substr = subString(s, 3, 2);
  strPlus rep = replaceText(s, substr, repText);
  printString(rep);
  
  deleteStr(rep);
  deleteStr(repText);
  deleteStr(substr);
  deleteStr(s);
}

//stores strings as a struct containing a pointer to the string (array of characters), and its length. Includes functions to read in a string from a file, delete a string, print a string, get a substring, and replace a substring with another string.