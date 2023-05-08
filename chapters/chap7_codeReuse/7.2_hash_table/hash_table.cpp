#include <iostream>
#include <string>
using namespace std;

class hashNode{
  public:
    hashNode *next;
    string key;
    int value;

    hashNode(){
      this->key = "";
      this->value = -1;
      this->next = NULL;
    }

    hashNode(string key, int val){
      this->key = key;
      this->value = val;
      this->next = NULL;
    }
};

class hashTable{
  public:
    hashTable(int capacity);
    hashTable();
    ~hashTable();
    void addPair(string key, int val);
    int get(string key);

  private:
    int hashFunc(string s);
    void deleteList(hashNode *head);
    int _capacity;
    hashNode **_hashArray;
};



hashTable::hashTable(int capacity){
  _capacity = capacity;
  hashNode **newArray = new hashNode*[capacity];
  _hashArray = newArray;
  for (int i = 0; i < capacity; i++){
    _hashArray[i] = NULL;
  }
}

hashTable::hashTable(){
  _capacity = 20;
  hashNode **newArray = new hashNode*[_capacity];
  _hashArray = newArray;
  for (int i = 0; i < _capacity; i++){
    _hashArray[i] = NULL;
  }
}

hashTable::~hashTable(){
  for (int i = 0; i < _capacity; i++){
    deleteList(_hashArray[i]);
  }
}

void hashTable::deleteList(hashNode *head){
  if (!head) return;
  deleteList(head->next);
  delete head;
}

int hashTable::hashFunc(string s){
  int prime = 31;
  int hash = 0;
  const char *s2 = s.c_str();
  for (int i = 0; i < s.length(); i++){
    hash = prime * hash + int(s2[i]);
  }
  return hash % _capacity;
}

void hashTable::addPair(string key, int val){
  int index = hashFunc(key);
  hashNode *newNode = new hashNode(key, val);
  if (!_hashArray[index]) {
    _hashArray[index] = newNode;
    return;
  }
  hashNode *loopPtr = _hashArray[index];
  while (loopPtr->next){
    loopPtr = loopPtr->next;
  }
  loopPtr->next = newNode;
}


int hashTable::get(string key){
  int index = hashFunc(key);
  hashNode *loopPtr = _hashArray[index];
  while (loopPtr){
    if (loopPtr->key == key) return loopPtr->value;
    loopPtr = loopPtr->next;
  }
  return -1;
}

int main(){
  hashTable h(20);
  h.addPair("Mike", 99);
  cout << h.get("Mike");
}

// My Hash table template class
// includes methods to add key-value pairs, get values by key, hash function, constructor and destructor
// includes hashNode class as linked list node to deal with collisions