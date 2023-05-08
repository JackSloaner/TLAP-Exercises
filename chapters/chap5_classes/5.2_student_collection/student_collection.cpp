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
  private:
    stuList copyList(stuList original);
    void deleteList(stuList &list);
    stuList readFile(string fname);
    stuList _head;
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
}

stuCo::stuCo(string fName){
  _head = readFile(fName);
}

stuCo::stuCo(stuCo &original){
  _head = copyList(original._head);
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

int main(){
  stuCo firstCollection("students");
  firstCollection.printNames();
  stuCo secondCollection;
  secondCollection = *(firstCollection.recordRange(80, 100));
  secondCollection.printNames();
  
}

//Class for a collection of students, includes methods for adding a student, getting the average grade, getting a student by id, and getting a collection of students within a grade range. Also includes overloaded assignment operator and copy constructor.