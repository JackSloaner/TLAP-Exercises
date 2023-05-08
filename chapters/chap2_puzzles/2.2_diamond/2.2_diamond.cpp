#include <iostream>
using namespace std;

void diamond(int level){
  for (int i = 0; i < level; i++){
    for (int j = 0; j < level - (i + 1); j++){
      cout << " ";
    }
    for (int j = 0; j < (i + 1) * 2; j++){
      cout << "#";
    }
    for (int j = 0; j < level - (i + 1); j++){
      cout << " ";
    }
    cout << "\n";
  }

  for (int i = 0; i < level; i++){
    for (int j = 0; j < i; j++){
      cout << " ";
    }
    for (int j = 0; j < level * 2 - i * 2; j++){
      cout << "#";
    }
    for (int j = 0; j < i; j++){
      cout << " ";
    }
    cout << "\n";
  }
}

int main() {
  diamond(5);
}

// Print a diamond in the shell using hashes and spaces