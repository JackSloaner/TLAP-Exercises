#include <iostream>
using namespace std;

void triangle(int rows){
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < i; j++){
      cout << " ";
    }
    for (int j = 0; j < rows * 2 - 2 * i; j++){
      cout << "#";
    }
    for (int j = 0; j < i; j++){
      cout << " ";
    }
    cout << "\n";
  }
}

int addFive(int original){
  original = original + 5;
  return original;
}

int main() {
  triangle(10);
}

// Print an upside down triangle in the shell using hashes and spaces