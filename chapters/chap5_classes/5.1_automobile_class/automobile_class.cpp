#include <iostream>
#include <string>
#include <ctime>
using namespace std;
using namespace std::chrono;

class automobile {
public:
automobile();
automobile(string manufac, string model, int year);
void getManufacturer();
void getModel();
void getYear();
void getCar();
void getAge();

private:
string _manufac;
string _model;
int _modelYear;
bool isValidYear(int yr);
bool isValidString(string s);
};

bool automobile::isValidString(string s){
  if (s == "") return false;
  return true;
}

bool automobile::isValidYear(int yr){
  if (yr < 0) return false;
  return true;
}

automobile::automobile(){
  _manufac = "";
  _model = "";
  _modelYear = -1;
}

automobile::automobile(string manufac, string model, int year){
  _manufac = manufac;
  _model = model;
  _modelYear = year;
}

void automobile::getManufacturer(){
  if (!isValidString(_manufac)) return;
  cout << _manufac << "\n";
}

void automobile::getModel(){
  if (!isValidString(_model)) return;
  cout << _model << "\n";
}

void automobile::getYear(){
  if (!isValidYear(_modelYear)) return;
  cout << _modelYear << "\n";
}

void automobile::getCar(){
  if (!isValidString(_model) && !isValidString(_manufac)) return;
  cout << _modelYear << " " << _manufac << " " << _model;
}

void automobile::getAge(){
  if (!isValidYear(_modelYear)) return;
  time_t t = time(nullptr);
  tm const *timeObj = localtime(&t);
  int curYear = timeObj->tm_year + 1900;
  cout << "This car is " << curYear - _modelYear << " Years old";
}


int main(){
  automobile firstCar("Tesla", "Model T", 2019);
  firstCar.getAge();
}

// First c++ class, mock automobile information class