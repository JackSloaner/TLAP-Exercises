#include <iostream>
using namespace std;

int recursiveTargNum(int target, int numbers[], int size){
  if (size == 0) return 0;
  return (target == numbers[size - 1]) + recursiveTargNum(target, numbers, size - 1);
}

int targetNum(int target, int numbers[], int size){
  int count = 0;
  for (int i = 0; i < size; i++){
    if (numbers[i] == target) count++;
  }
  return count;
}

int main(){
  int numbers[] = {21, 5, 2, 5, 3, 89, 75, 44, 5, 5};
  cout << recursiveTargNum(5, numbers, 10);
}

// Counts the amount of times a target number appears in an array. Done recursively and iteratively.