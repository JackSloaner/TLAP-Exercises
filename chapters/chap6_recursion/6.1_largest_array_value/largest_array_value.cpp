#include <iostream>
using namespace std;

int findLargest(int numbers[], int size){
  if (size == 0) return -1;
  int prev = findLargest(numbers, size - 1);
  if (prev > numbers[size - 1]) return prev;
  return numbers[size - 1];
}

int main(){
  int numbers[] = {1, 83, 53, 104, 23, 51, 33, 6};
  cout << findLargest(numbers, 8);
}

// Find largest number in an array recursively