#include <iostream>
#include <math.h>
using namespace std;

int main(){
  int num;
  cout << "Enter a number to be represented in binary:";
  cin >> num;
  bool binary[30];
  for (int i = 29; i >= 0; i--){
    int modulo = pow(2, i);
    int previous = num;
    num = num % modulo;
    if (num != previous){
      binary[29 - i] = true;
    } else{
      binary[29 - i] = false;
    }
  }

  for (int i = 0; i < 30; i++){
    if (binary[i]){
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << "\n";
}


// Convert any integer number to binary (base 2). The rightmost unit is 2^0, then going left it's 2^1, 2^2, 2^3, etc.
