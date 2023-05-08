#include <iostream>
#include <unistd.h>
using namespace std;

void x(int qPart){
  int branches = qPart - 1;
  int length = qPart + branches;
  for (int i = 0, n = qPart; i < n; i++){
    for (int j = 0; j < i; j++){
      cout << " ";
    }
    
    for (int j = 0; j < i + 1; j++){
      cout << "#";
    }

    for (int j = 0, l = (2 * length) - 2 - (4 * i); j < l; j++){
      cout << " ";
    }

    for (int j = 0; j < i + 1; j++){
      cout << "#";
    }
    cout << "\n";
  }


  for (int i = 0, n = qPart; i < n; i++){
    for (int j = 0; j < n - (i + 1); j++){
      cout << " ";
    }
    
    for (int j = 0; j < qPart - i; j++){
      cout << "#";
    }

    for (int j = 0, l = i * 4; j < l; j++){
      cout << " ";
    }

    for (int j = 0; j < qPart - i; j++){
      cout << "#";
    }
    cout << "\n";
  }
}

void timer(float seconds){
  usleep(1000000 * seconds);
}

int main() {
  int largest = 40;
  for(int i = 1; i <= largest/2; i++){
    for(int j = 0; j < largest; j++){
      cout << "\n";
    }
    x(i);
    timer(0.1);
  }
}

// Print a weird X in the shell using hashes and spaces, mimicing the shape from the book
// Use timer library to make the X appear to grow in the shell, printing a slightly larger X each time 0.1 seconds passes.