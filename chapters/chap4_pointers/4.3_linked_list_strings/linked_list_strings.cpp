#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

struct charNode {
  char c;
  charNode *next;
  charNode *prev;
};

typedef charNode *str;

struct dubList {
  str start;
  str finish;
};

void deleteList(str& list){
  while (list != NULL){
    str placeHold = list;
    list = placeHold->next;
    delete placeHold;
  }
  list = 0;
}

void printList (str list){
  while (list != NULL){
    cout << list->c; 
    list = list->next;
  }
  cout << "\n";
  return;
}

dubList readFile(string fName){
  fName = "./csv/" + fName + ".csv";
  fstream file;
  file.open(fName); 
  if ( !file.is_open()){
    cerr << "Unable to open file";
    exit(0);
  }
    
  int count = 0;
  str bottom = NULL;
  str top = NULL;
  for (string i; getline(file, i, ','); ){
    str curChar = new charNode;
    const char *placeHold = i.c_str();
    curChar->c = *placeHold;
    curChar->prev = bottom;
    if (bottom){
    bottom->next = curChar;
    } else {
    top = curChar;
    }
    bottom = curChar;
    count++;
  }
  dubList initial;
  initial.start = top;
  initial.finish = bottom;
  return initial;
}

void append(dubList& list, char char1){
  str curChar = new charNode;
  curChar->prev = list.finish;
  curChar->next = NULL;
  curChar->c = char1;
  list.finish->next = curChar;
  list.finish = curChar;
}

void concat(dubList& first, dubList second){
  str current = second.start;
  while (current != NULL){
    str curChar = new charNode;
    curChar->c = current->c;
    curChar->prev = first.finish;
    curChar->next = NULL;
    first.finish->next = curChar;
    first.finish = curChar;
    current = current->next;
  }
}

void removeChars(dubList& first, int pos, int steps){
  str cur = first.start;
  for (int i = 0; i < pos; i++){
    cur = cur->next;
  }
  str placehold = cur->prev;
  int i = 0;
  while (i < steps){
    str previous = cur;
    if (cur->next){
      
      cur = cur->next;
      delete previous;
    } else {
      placehold->next = NULL;
      return;
    }
    i++;
  }
  placehold->next = cur;
  cur->prev = placehold;
}
int main(){
  dubList initialStr = readFile("chars");
  dubList conStr = readFile("concat");
  printList(initialStr.start);
  removeChars(initialStr, 3, 4);
  printList(initialStr.start); 
  deleteList(initialStr.start);
  deleteList(conStr.start);
}

// Stores strings as linked lists of characters. Includes functions to append, concatenate, and remove characters from a string.