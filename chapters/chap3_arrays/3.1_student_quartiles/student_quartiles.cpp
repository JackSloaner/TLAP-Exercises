#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

struct student {
  string name;
  int  grade;
};

struct dataa { // Struct for readFile()
  string name;
  string grade;
};

vector<student> sortStudents(vector<student> a){
  for(int stu = 0; stu < a.size() - 1; stu++){
    for (int remainder = 0; remainder < a.size() - 1; remainder++){
        if (a.at(remainder).grade > a.at(remainder + 1).grade){
          student placeHold = a.at(remainder);
          a.at(remainder) = a.at(remainder + 1);
          a.at(remainder + 1) = placeHold;
        }
    }
  }
  return a;
}

vector<student> readFile(){
const string FILENAME = "students.csv";
  fstream file;
  file.open(FILENAME); 

  if ( !file.is_open()){
    cerr << "Unable to open file";
    exit(0);
  }

  vector<student> students;
  for (dataa i; getline(file, i.name, ',') && getline(file, i.grade, ','); ){
    student current;
    current.grade = stoi(i.grade);
    current.name = i.name;
    students.push_back(current);
  }

  file.close();
  return students;
}

double round(double num){
  if (fmod(num, 1.0) >= 0.5){
    num = ceil(num);
  } else {
    num = floor(num);
  }
  return num;
}

int main(){
  vector<student> students = readFile();
  students = sortStudents(students);
  double size = students.size();
  double quarts[4];
  for (int quart = 0; quart < 4; quart++){
    quarts[quart] = students.at(round(floor(size * 0.25) * (quart + 1)) - 1.0).grade;
  }

  for (auto i: quarts){
    cout << i << " ";
  }
  
  
}

// Find the quartiles of a set of student grades.