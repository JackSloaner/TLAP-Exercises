#include <iostream>
#include <math.h>
using namespace std;

int findMax(int base){
  bool keepGoing = true;
  int i = 0;
  int modulo;
  while(keepGoing) {
    modulo = pow(base, i);
    if (__INT_MAX__ - modulo < modulo){
      keepGoing = false;
    } else {
      i++;
    }
  }
  return i;
}

void convert(bool arr[], int max, int b, int num){
  for (int i = max - 1; i >= 0; i--){
    int modulo = pow(b, i);
    int previous = num;
    num = num % modulo;
    if (num != previous){
      arr[(max - 1) - i] = true;
    } else{
      arr[(max - 1) - i] = false;
    }
  }

  for (int i = 0; i < max; i++){
    if (arr[i]){
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << "\n";
}

void initializeArray(bool arr[], int max){
  for (int i = 0; i < max; i++){
    arr[i] = false;
  }
}

int main(){
  int base;
  cout << "Enter a base:";
  cin >> base;
  int max = findMax(base);
  int num;
  cout << "Enter a number to be represented:";
  cin >> num;
  bool converted[max];
  initializeArray(converted, max);
  convert(converted, max, base, num);
}

// Convert any integer number to its closest representation of the number in base b, where the smallest denomination (rightmost unit) is b^0 and the largest is b^(max - 1) (leftmost unit)
// max is calculated in relation to the base and the maximum integer value.