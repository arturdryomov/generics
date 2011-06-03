#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<double> array)
{
  for (vector<double>::iterator it = array.begin(); it != array.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

int main()
{
  // Input user data 
  cout << "Enter size of array: ";
  int size;
  cin >> size;
  vector<double> array;
  array.resize(size);
  cout << "Now enter elements of array: "; 
  for (vector<double>::iterator it = array.begin(); it != array.end(); it++) {
    cin >> *it;
  }
  cout << "Enter number of shifts: ";
  int shifts;
  cin >> shifts;

  cout << ":: Input vector is: ";
  printVector(array);

  // Process
  for (int i = 0; i < shifts; i++) {
    double lastElement = array.back();
    for (vector<double>::iterator it = array.end() - 1; it != array.begin(); it--) {
      *it = *(it - 1); 
    }
    array.front() = lastElement;
  }

  cout << ":: Output vector is: ";
  printVector(array);

  return 0;
}
