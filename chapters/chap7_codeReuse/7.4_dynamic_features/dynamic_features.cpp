#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class studentRecord{
  private:
      struct kvString{
      string key;
      string val;
      kvString *next;
    };

    struct kvInt{
      string key;
      int val;
      kvInt *next;
    };

    struct kvBool{
      string key;
      int val;
      kvBool *next;
    };

    kvString *stringVals;
    kvInt *intVals;
    kvBool *boolVals;

  public:
    string _info;
    ~studentRecord(){
      deleteStrings(stringVals);
      deleteInts(intVals);
      deleteBools(boolVals);
    }
    studentRecord(){
      stringVals = NULL;
      intVals = NULL;
      boolVals = NULL;
      _info = "Value keys: ";
    }
    int getIntVal(string key){
      kvInt *loopPtr = intVals;
      while (loopPtr){
        if (loopPtr->key == key) return loopPtr->val;
        loopPtr = loopPtr->next;
      }
      return -1;
    }
    string getStringVal(string key){
      kvString *loopPtr = stringVals;
      while (loopPtr){
        if (loopPtr->key == key) return loopPtr->val;
        loopPtr = loopPtr->next;
      }
      return "No such Key";
    }
    string getBoolVal(string key){
      kvBool *loopPtr = boolVals;
      while (loopPtr){
        if (loopPtr->key == key){
          string returnMessage;
          (loopPtr->val) ? returnMessage = "y" : returnMessage = "n";
          return returnMessage;
        }
        loopPtr = loopPtr->next;
      }
      return "No such Key";
    }
    friend class builder;
  private:
    void deleteStrings(kvString *head){
      while(head){
        kvString *placeHold = head;
        head = head->next;
        delete placeHold;
      }
    }
    void deleteInts(kvInt *head){
      while(head){
        kvInt *placeHold = head;
        head = head->next;
        delete placeHold;
      }
    }
    void deleteBools(kvBool *head){
      while(head){
        kvBool *placeHold = head;
        head = head->next;
        delete placeHold;
      }
    }
};




class builder{
  private:
    studentRecord *_stuRec;
  public:
    builder();
    builder(string name, int grade, int stuID);
    void reset();
    void addDefaults(string name, int grade, int stuID);
    void addName(string name);
    void addGrade(int grade);
    void addID(int ID);
    void addDOB(string date);
    void addIsAudit(bool isAudit);
    void addPaperTitle(string Title);
    void deleteRec(){delete _stuRec;}
    studentRecord *getRecord(){
      return _stuRec;
    }

  private:
    void addNode(string key, string val);
    void addNode(string key, int val);
    void addNode(string key, bool val);
};

builder::builder(){
  _stuRec = new studentRecord;
}

builder::builder(string name, int grade, int stuID){
  _stuRec = new studentRecord;
  addDefaults(name, grade, stuID);
}

void builder::reset(){
  _stuRec = new studentRecord;
}

void builder::addDefaults(string name, int grade, int stuID){
  addNode("name", name);
  addNode("grade", grade);
  addNode("id", stuID);

}

void builder::addName(string name){
  addNode("name", name);
}

void builder::addID(int ID){
  addNode("id", ID);
}

void builder::addGrade(int grade){
  addNode("grade", grade);
}

void builder::addPaperTitle(string Title){
  addNode("title", Title);
}

void builder::addDOB(string date){
  addNode("dob", date);
}

void builder::addIsAudit(bool isAudit){
  addNode("isaudit", isAudit);
}

void builder::addNode(string key, string val){
  studentRecord::kvString *newNode = new studentRecord::kvString;  
  newNode->key = key;
  newNode->val = val;
  newNode->next = _stuRec->stringVals;
  _stuRec->stringVals = newNode;
  _stuRec->_info += "'" + key + "', ";

  // add a part that updates the studentrecord with a list of its components so the client code can see which components it has
}

void builder::addNode(string key, int val){
  studentRecord::kvInt *newNode = new studentRecord::kvInt;  
  newNode->key = key;
  newNode->val = val;
  newNode->next = _stuRec->intVals;
  _stuRec->intVals = newNode;
  _stuRec->_info += "'" + key + "', ";
}

void builder::addNode(string key, bool val){
  studentRecord::kvBool *newNode = new studentRecord::kvBool;  
  newNode->key = key;
  newNode->val = val;
  newNode->next = _stuRec->boolVals;
  _stuRec->boolVals = newNode;
  _stuRec->_info += "'" + key + "', ";
}

class stuCo : public studentRecord{
  private:
    struct stuNode{
      studentRecord *record;
      stuNode *next;
    };
    typedef stuNode *stuList;

    stuList _head;

  public:
    stuCo();
    stuCo(string fName);
    stuCo(stuCo &original);
    ~stuCo();
    void addRecord(studentRecord *stuRec);
    stuCo& operator=(stuCo &rhs);
    stuCo *recordRange(int min, int max);
    double averageRecord();
    studentRecord *getStudentWithId(int id); 
    void printNames();
  private:
    builder *deepCopy(studentRecord *original);
    stuList copyList(stuList original);
    void deleteList(stuList &list);
    stuList readFile(string fname);
    
};

stuCo::~stuCo(){
  deleteList(_head);
}

void stuCo::deleteList(stuList &list){
  while (list){
    stuList placeHold = list;
    list = list->next;
    delete placeHold->record;
    delete placeHold;
  }
  list = NULL;
}

void stuCo::printNames(){
  stuList loopPtr = _head;
  while (loopPtr){
    cout << loopPtr->record->getStringVal("name") << "*";
    loopPtr = loopPtr->next;
  }
  cout << "\n";
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
  builder newStudent;
  stuList listHead = NULL;
  for (string i; getline(file, i, ','); ){
    if (position == 0){
        newStudent.reset();
        newStudent.addName(i);
    } else if (position == 1){
        newStudent.addGrade(stoi(i));
    } else if (position == 2){
        newStudent.addID(stoi(i));
        stuList newRecord = new stuNode;
        newRecord->record = newStudent.getRecord();
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

stuCo::stuCo(stuCo &original){
  _head = copyList(original._head);
}

stuCo::stuList stuCo::copyList(stuList original){
  if (!original) return NULL;
  stuList newList = new stuNode;
  builder *copy = deepCopy(original->record);
  newList->record = copy->getRecord();
  newList->next = copyList(original->next);
  delete copy;
  return newList;
}

stuCo::stuCo(string fName){
  _head = readFile(fName);
}

stuCo& stuCo::operator=(stuCo &rhs){
  if (this == &rhs) return *this;
  deleteList(_head);
  _head = copyList(rhs._head);
  return *this;
}

studentRecord* stuCo::getStudentWithId(int id){
  stuList listPtr = _head;
  while (listPtr){
    if (listPtr->record->getIntVal("id") == id) return listPtr->record;
    listPtr = listPtr->next;
  }
  builder dummy("", -1, -1);
  return dummy.getRecord();
}

double stuCo::averageRecord(){
  stuList loopPtr = _head;
  double sum = 0;
  int count = 0;
  while (loopPtr){
    sum += loopPtr->record->getIntVal("grade");
    count++;
    loopPtr = loopPtr->next;
  }
  return sum / count;
}

void stuCo::addRecord(studentRecord *stuRec){
  stuList newStudentRec = new stuNode;
  newStudentRec->record = stuRec;
  newStudentRec->next = _head;
  _head = newStudentRec;
}

stuCo* stuCo::recordRange(int min, int max){
  stuList loopPtr = _head;
  stuCo *newCollection = new stuCo;
  while (loopPtr){
    int grade = loopPtr->record->getIntVal("grade");
    if (grade >= min && grade <= max){
      builder *dCopy = deepCopy(loopPtr->record);
      newCollection->addRecord(dCopy->getRecord());
      delete dCopy;
    }
    loopPtr = loopPtr->next;
  }
  return newCollection;
}

builder* stuCo::deepCopy(studentRecord *original){
  builder *newBuilder = new builder;
  newBuilder->addDefaults(original->getStringVal("name"), original->getIntVal("grade"), original->getIntVal("id"));
  string dob = original->getStringVal("dob");
  if (dob != "No such Key"){
    newBuilder->addDOB(dob);
  }
  string paperTitle = original->getStringVal("title");
  if (paperTitle != "No such Key"){
    newBuilder->addPaperTitle(paperTitle);
  }
  string isAuditRaw = original->getBoolVal("isaudit");
  if (isAuditRaw != "No such Key"){
    bool isAudit = (isAuditRaw == "y") ? true : false;
    newBuilder->addIsAudit(isAudit);
  }
  return newBuilder;

}

int main(){
  stuCo collection("students");
  builder newBuilder("Nads", 34, 99);
  newBuilder.addDOB("1976/09/28");
  collection.addRecord(newBuilder.getRecord());
  stuCo range = *collection.recordRange(95, 100);
  range.printNames();
  cout << collection.getStudentWithId(99)->getIntVal("grade");
}

// Add on to the studentCollection class from chapter 5. 
// Student records are now stored in objects with linked lists containing their attributes (grade, name date of birth, etc.), seperated into types. 
// Includes a builder class that can be used to create student records with custom attributes.
// The studentCollection (stuCo) class can read in a csv file and create student records from it. Also includes deep copy constructor and overloaded assignment operator.
// Contains modified methods from the original stuCo class that work with the new builder and studentrecord classes, such as: averageRecord, recordRange, as well as the overloaded assignment operator and deep copy constructor.