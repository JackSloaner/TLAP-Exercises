#include <iostream>
using namespace std;

bool recursiveEvenOdd(bool bString[], int size){
  if (!size) return false;
  bool tf = bString[size - 1];
  bool prev = recursiveEvenOdd(bString, size - 1);
  if (!tf) return tf + prev;
  if (prev) return false;
  return true;
}

bool evenOdd(bool bString[], int size){
  bool tf = false;
  for (int i = 0; i < size; i++){
    if (bString[i]){
      tf ? tf = false : tf = true;
    }
  }
  return tf;
}

int main() {
  bool bString[] = {1, 0, 1, 0, 1, 1, 1, 1, 1};
  cout << recursiveEvenOdd(bString, 9);
}

// Store string of boolean values in an array, return true if there are an even number of true values, false otherwise, one version using recursion, one without