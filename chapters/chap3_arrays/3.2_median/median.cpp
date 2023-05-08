#include <iostream>
using namespace std;



int sort(const void * voidA, const void * voidB){
  int * intA = (int *)(voidA);
  int * intB = (int *)(voidB);
  return *intA - *intB;
}

int findMedian(int arr[], int length){
  int halfWay = length / 2;
  int median = (arr[halfWay] + arr[halfWay + 1]) / 2;
  cout << median << "\n";
  return median;
}

struct medianType {
  int med;
  int agent;
};

int main(){
  const int MONTHS = 12;
  const int NUM_AGENTS = 3;
  medianType highestMedian;
  highestMedian.med = 0;
  int agents[NUM_AGENTS][MONTHS];
  int currentVal = 0;
  for (int agent = 0; agent < NUM_AGENTS; agent++){
  cout << "Agent" << agent << "\n";
  for (int curMonth = 0; curMonth < MONTHS; curMonth++){
    cin >> currentVal;
    agents[agent][curMonth] = currentVal;
  }

  qsort(agents[agent], MONTHS, sizeof(int), sort);
  medianType median;
  median.med = findMedian(agents[agent], MONTHS);
  median.agent = agent;
  if (median.med > highestMedian.med){
    highestMedian = median;
  }
  cout << "\n";
  }
  
  cout << "Highest median was Agent" << highestMedian.agent << " With a median of " << highestMedian.med;
}

// Find the highest median out of 3 agents' sales data over 12 months; User inputs data
