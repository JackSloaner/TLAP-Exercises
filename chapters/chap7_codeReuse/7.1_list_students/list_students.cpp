#include <list>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct studentRecord{
  string name;
  int grade;
  int id;
};

class stuCo {
  public:
    stuCo();
    stuCo(string fName);
    stuCo(stuCo &original);
    void addRecord(studentRecord stuRec);
    double averageRecord();
    studentRecord getStudentWithId(int id);
    void printNames();
  private:
		studentRecord *listToArray();
		void insertionSort(studentRecord *stuArray, int length);
    list<studentRecord> readFile(string fname);
    list<studentRecord> _stuList;
};

list<studentRecord> stuCo::readFile(string fName){
  fName = "./csv/" + fName + ".csv";
  fstream file;
  file.open(fName); 
  if ( !file.is_open()){
    cerr << "Unable to open file";
    exit(0);
  }
  int position = 0;
  studentRecord newRecord;
  list<studentRecord> newList;
  for (string i; getline(file, i, ','); ){
    if (position == 0){
        newRecord.name = i; 
    } else if (position == 1){
        newRecord.grade = stoi(i);
    } else if (position == 2){
        newRecord.id = stoi(i);
        newList.push_back(newRecord); 
    }
    (position < 2) ? position++ : position = 0;
  }
  return newList;
}

stuCo::stuCo(string fName){
  _stuList = readFile(fName);
}

stuCo::stuCo(){

}

void stuCo::addRecord(studentRecord stuRec){
	_stuList.push_back(stuRec);
}

double stuCo::averageRecord(){
	auto front = _stuList.begin();
	int total = 0;
  for (int i = 0; i < _stuList.size(); i++){
		total += (*front).grade;
		advance(front, 1);
	}
	return (double) total / _stuList.size();
}

studentRecord stuCo::getStudentWithId(int id){
	int n = _stuList.size();
	studentRecord *stuArray = listToArray();
	insertionSort(stuArray, n);
	int begin = 0;
	int end = n - 1;
	while (begin <= end && id >= stuArray[begin].id && id <=stuArray[end].id){
		int position = begin + (double) (end - begin) / (stuArray[end].id - stuArray[begin].id) * (id - stuArray[begin].id);
		if (stuArray[position].id == id){
			studentRecord temp = stuArray[position];
			delete[] stuArray;
			return temp;
		} 
		if (stuArray[position].id < id){
			begin = position + 1;
		} else {
			begin = position - 1;
		}
	}
	studentRecord dummyRecord;
	dummyRecord.grade = -1;
	dummyRecord.id = -1;
	dummyRecord.name = "";
	return dummyRecord;
}

studentRecord* stuCo::listToArray(){
	auto front = _stuList.begin();
	studentRecord *stuArr = new studentRecord[_stuList.size()];
  for (int i = 0; i < _stuList.size(); i++){
		stuArr[i] = *front;
		advance(front, 1);
	}
	return stuArr;
}

void stuCo::insertionSort(studentRecord *stuArray, int length){
	for (int i = 1; i < length; i++){
		for (int j = i; j > 0 && stuArray[j - 1].id > stuArray[j].id; j--){
			studentRecord temp = stuArray[j - 1];
			stuArray[j - 1] = stuArray[j];
			stuArray[j] = temp;
		}
	}
}

void stuCo::printNames(){
	auto front = _stuList.begin();
  for (int i = 0; i < _stuList.size(); i++){

		cout << (*front).name;
		advance(front, 1);
	}
}



int main(){
  stuCo firstCollection("students");
  cout << firstCollection.getStudentWithId(5).name;
}

//Variant of the studentColletion class that uses a list class instead of a linked list to store the studentRecord objects