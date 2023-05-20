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

int modulo_count(int num, int modulo){
  int count = 0;
  while(num >= modulo){
    num = num - modulo;
    count++;
  }
  return count;
}

void convert(int arr[], int input_num, int in_base, int out_base){
  int max = findMax(out_base);
  //Convert input number to base 10 integer
  int input_converted = 0;
  for (int i = findMax(in_base) - 1; i >= 0 ; i--){
    int modulo = pow(10, i);
    int base_ten_transfer = modulo_count(input_num, modulo);
    input_num = input_num % modulo;
    base_ten_transfer = pow(in_base, i) * base_ten_transfer;
    cout << base_ten_transfer << endl;
    input_converted += base_ten_transfer;
  }
  //Convert base-10 number to output base
  for (int i = max - 1; i >= 0; i--){
    int modulo = pow(out_base, i);
    int count = modulo_count(input_converted, modulo);
    input_converted = input_converted % modulo;
    arr[(max - 1) - i] = count;
  }
  for (int i = 0; i < max; i++){
    cout << arr[i];
  }
  cout << "\n";
}

void initializeArray(int arr[], int max){
  for (int i = 0; i < max; i++){
    arr[i] = 0;
  }
}

int main(){
  int in_base;
  cout << "Enter a base for your input number:";
  cin >> in_base;
  int input_num;
  printf("Enter your number in base %i:", in_base);
  cin >> input_num;
  int out_base;
  cout << "Enter a base for your output number:";
  cin >> out_base;
  int max = findMax(out_base);
  int converted[max];
  initializeArray(converted, max);
  convert(converted, input_num, in_base, out_base);
}

// Convert any integer number to its representation of the number in base b, where the smallest denomination (rightmost unit) is b^0 and the largest is b^(max - 1) (leftmost unit)
// max is calculated in relation to the base and the maximum integer value.