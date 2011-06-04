#include "car.h"

#include <iostream>

using namespace std;

int main()
{
  Cars carsList;
  carsList.enterCarsInformation();
  cout << "There is input cars list" << endl;
  carsList.printCarsInformation();
  carsList.sortCarsList();
  cout << "There is output cars list" << endl;
  carsList.printCarsInformation();

  return 0;
}
