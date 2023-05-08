#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct studentRecord{
  string name;
  int grade;
  string id;
};

class stuCo {
  private:
    struct stuNode{
      studentRecord record;
      stuNode *next;
    };

  typedef stuNode *stuList;

  typedef bool (stuCo::*fsPolicy)(studentRecord r1, studentRecord r2);
  public:
    stuCo();
    stuCo(string fName);
    stuCo(stuCo &original);
    ~stuCo();
    void addRecord(studentRecord stuRec);
    stuCo& operator=(stuCo &rhs);
    stuCo *recordRange(int min, int max);
    double averageRecord();
    studentRecord getStudentWithId(string id);
    void printNames();
    void setCurrentPolicy(int policy);
    studentRecord firstStudent();
  private:
    bool fsHighGrade(studentRecord r1, studentRecord r2);
    bool fsLowStuNum(studentRecord r1, studentRecord r2);
    bool fsAlphabetical(studentRecord r1, studentRecord r2);
    stuList copyList(stuList original);
    void deleteList(stuList &list);
    stuList readFile(string fname);
    stuList _head;
    bool (stuCo::*_currentPolicy)(studentRecord r1, studentRecord r2);
};

stuCo::~stuCo(){
  deleteList(_head);
}

void stuCo::deleteList(stuList &list){
  while (list){
    stuList placeHold = list;
    list = list->next;
    delete placeHold;
  }
  list = NULL;
}

stuCo::stuList stuCo::readFile(string fName){
  fName = "./csv/" + fName + ".csv";
  fstream file;
  file.open(fName); 
  if ( !file.is_open()){
    cerr << "Unable to open file";
    exit(0);
  }
  int position = 0;
  stuList newRecord = NULL;
  stuList listHead = NULL;
  for (string i; getline(file, i, ','); ){
    if (position == 0){
        newRecord = new stuNode;
        newRecord->record.name = i; 
    } else if (position == 1){
        newRecord->record.grade = stoi(i);
    } else if (position == 2){
        newRecord->record.id = i;
        newRecord->next = listHead;
        listHead = newRecord; 
    }
    (position < 2) ? position++ : position = 0;
  }
  return listHead;
}

stuCo::stuCo(){
  _head = NULL;
  _currentPolicy = &stuCo::fsAlphabetical;
}

stuCo::stuCo(string fName){
  _head = readFile(fName);
  _currentPolicy = &stuCo::fsAlphabetical;
}

stuCo::stuCo(stuCo &original){
  _head = copyList(original._head);
  _currentPolicy = original._currentPolicy;
}

void stuCo::addRecord(studentRecord stuRec){
  stuList newStudentRec = new stuNode;
  newStudentRec->record = stuRec;
  newStudentRec->next = _head;
  _head = newStudentRec;
}

double stuCo::averageRecord(){
  stuList loopPtr = _head;
  int sum = 0;
  int count = 0;
  while (loopPtr){
    sum += loopPtr->record.grade;
    loopPtr = loopPtr->next;
    count++;
  }
  double avg = (double)sum/count;
  return avg;
}

stuCo::stuList stuCo::copyList(stuList original){
  stuList oldLoopPtr = original;
  stuList newLoopPtr = NULL;
  while (oldLoopPtr){
    stuList newNode = new stuNode;
    newNode->record = oldLoopPtr->record;
    newNode->next = newLoopPtr;
    newLoopPtr = newNode;
    oldLoopPtr = oldLoopPtr->next;
  }
  return newLoopPtr;
}

stuCo& stuCo::operator=(stuCo &rhs){
  if (&rhs != this){
    deleteList(_head);
    _head = copyList(rhs._head);
  }
  return *this;
}

stuCo* stuCo::recordRange(int min, int max){
  stuList loopPtr = _head;
  stuCo *newCollection = new stuCo;
  while (loopPtr){
    if (loopPtr->record.grade >= min && loopPtr->record.grade <= max){
      newCollection->addRecord(loopPtr->record);
    }
    loopPtr = loopPtr->next;
  }
  return newCollection;
}

studentRecord stuCo::getStudentWithId(string id){
  stuList listPtr = _head;
  while (listPtr){
    if (listPtr->record.id == id) return listPtr->record;
    listPtr = listPtr->next;
  }
  studentRecord negative;
  negative.grade = -1;
  negative.id = "";
  negative.name = "";
  return negative;
}

void stuCo::printNames(){
  stuList loopPtr = _head;
  while (loopPtr){
    cout << loopPtr->record.name << "*";
    loopPtr = loopPtr->next;
  }
  cout << "\n";
}

studentRecord stuCo::firstStudent(){
  if (!_head || !_currentPolicy){
    studentRecord newRecord;
    newRecord.grade = -1;
    newRecord.id = -1;
    newRecord.name = "";
    return newRecord;
  }
  stuList loopPtr = _head;
  studentRecord first = loopPtr->record;
  loopPtr = loopPtr->next;
  while (loopPtr){
    if ((this->*_currentPolicy)(loopPtr->record, first)) {
      first = loopPtr->record;
    }
    loopPtr = loopPtr->next;
  }
  return first;
}

bool stuCo::fsHighGrade(studentRecord r1, studentRecord r2){
  return r1.grade > r2.grade;
}

bool stuCo::fsLowStuNum(studentRecord r1, studentRecord r2){
  return r1.id < r2.id;
}

bool stuCo::fsAlphabetical(studentRecord r1, studentRecord r2){
  return strcmp(r1.name.c_str(), r2.name.c_str()) < 0;
}

void stuCo::setCurrentPolicy(int policy){
    switch (policy)
  {
  case 0:
    _currentPolicy = &stuCo::fsHighGrade;
    break;
  
  case 1:
    _currentPolicy = &stuCo::fsLowStuNum;
    break;
  default: 
    _currentPolicy = &stuCo::fsAlphabetical;
  }
}

int main(){
  stuCo firstCollection("students");
  firstCollection.printNames();
  firstCollection.setCurrentPolicy(0);
  cout << firstCollection.firstStudent().name;
}

// Use policy/strategy design pattern to allow the user to specify the sorting policy for the firstStudent() method.