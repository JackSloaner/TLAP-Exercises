#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

struct appearance {
  int num;
  int appearances;
};

vector<int> readFile(){
  const string FILENAME = "mode.csv";
  fstream file;
  file.open(FILENAME); 
  if ( !file.is_open()){
    cerr << "Unable to open file";
    exit(0);
  }
  vector<int> sequence;
  for (string i; getline(file, i, ','); ){
    sequence.push_back(stoi(i));
  }
  return sequence;
}

int containsNum(vector<appearance> vec, int numb){
  for (int i = 0; i < vec.size(); i++){
    if (vec.at(i).num == numb) {
      return i;
    }
  }
  return -1;
}

int main() {
  vector<int> sequence = readFile();
  vector<appearance> a;
  for (auto i: sequence){
    int position = containsNum(a, i);
    if (position != -1){
      a.at(position).appearances++;
    } else{
      appearance newApp;
      newApp.appearances = 1;
      newApp.num = i;
      a.push_back(newApp);
    }
  }

  appearance currentModeApps;
  currentModeApps.appearances = 0;
  for(auto i: a){
    if (i.appearances > currentModeApps.appearances){
      currentModeApps = i;
    } 
  }
  int mostApps = currentModeApps.appearances;
  vector<int> modes;
  for (auto i: a){
    if (i.appearances == mostApps){
      modes.push_back(i.num);
    }
  }

  cout << "The mode(s) is/are the following: ";
  for (auto i: modes){
    cout << "\n" <<  i ;
  }
  cout << "\n";
}

// Counts the number of times each number appears in a sequence of numbers, and returns the mode(s) (the number(s) that appear the most frequently).