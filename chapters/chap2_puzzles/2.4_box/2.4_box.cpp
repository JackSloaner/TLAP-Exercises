#include <iostream>
#include <unistd.h>
using namespace std;

bool checkForHash(int outer, int inner, int limit){
  if (inner == 0){
    return true;
  } else if (inner == limit - 1){
    return true;
  } else if (inner == outer){
    return true;
  } else if (inner == limit - (outer + 1)){
    return true;
  }
  return false;
}

int isEven(int length){
  if (length % 2 == 0){
    return true;
  } else{
    return false;
  }
}

void box(int len){
  int even = isEven(len);
  for (int i = 0, n = len; i < n; i++){
    if(isEven(len) && i == len / 2){
      i++;
    }

    if (i == 0 || i == n - 1){
      for(int j = 0; j < n; j++){
        cout << "#";
      }
    } else {
      for(int j = 0; j < n; j++){
        if (checkForHash(i, j, n)){
          cout << "#";
        } else {
          cout << " ";
        }
      }
    }
    cout << "\n";
  }
}

void timer(float seconds){
  usleep(1000000 * seconds);
}

int main() {
  int largest = 40;
  for(int i = 1; i <= largest; i++){
    for(int j = 0; j < largest; j++){
      cout << "\n";
    }
    box(i);
    timer(0.1);
  }
  
}

// Print len * len box of hashes as the contour and spaces filling the middle, with an X of hashes crossing through the middle of the box
// Use timer library to make the box appear to grow in the shell, printing a slightly larger box each time 0.1 seconds passes.
// Adapt algorithm to deal with even and odd values of len slightly differently