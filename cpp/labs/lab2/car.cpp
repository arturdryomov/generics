#include "car.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void Cars::enterCarsInformation()
{
  cout << "Do you want enter information from file? (y/n): ";
  char key;
  cin >> key;
  // Ignore that user pressed Return
  cin.ignore(1, '\n');
  if (toupper(key) == 'Y') {
    cout << "Enter input file name: ";
    string filename;
    getline(cin, filename);
    enterFromFile(filename);
  }
  else {
    enterFromStdio();
  }
}

void Cars::enterFromFile(string filename)
{
  fstream inputFile(filename.c_str());

  if (inputFile.fail()) {
    cout << "ERROR: There are no such file" << endl;
    return;
  }

  while (inputFile.good()) {
    vector<string> inputParts;
    inputParts.resize(5);

    for (vector<string>::iterator it = inputParts.begin(); it != inputParts.end(); ++it) {
      // Double check, we want at least five elements, but it could be not so good
      if (!inputFile.good()) {
        return;
      }
      inputFile >> *it;
    }

    addCar(inputParts);
  }

  inputFile.close();
}

void Cars::enterFromStdio()
{
  cout << "Enter number of records: ";
  int size;
  cin >> size;
  cout << "Now enter information in format:" << endl;
  cout << " brand model [serial], year, color" << endl;

  for (int i = 0; i < size; i++) {
    vector<string> inputParts;
    inputParts.resize(5);
    for (vector<string>::iterator it = inputParts.begin(); it != inputParts.end(); ++it) {
      cin >> *it;
    }
    addCar(inputParts);
  }
}

void Cars::addCar(vector<string> inputParts)
{
  Car car;

  // Lexical_cast from Boost will be better
  car.brand = inputParts[0];

  car.model = inputParts[1];

  // Erase some symbols to normal converting
  inputParts[2].erase(inputParts[2].begin(), inputParts[2].begin() + 1);
  inputParts[2].erase(inputParts[2].end() - 2, inputParts[2].end());
  istringstream(inputParts[2]) >> car.serial;

  inputParts[3].erase(inputParts[3].end() - 1, inputParts[3].end());
  istringstream(inputParts[3]) >> car.year;

  istringstream(inputParts[4]) >> car.color;

  m_carsList.push_back(car);
}

void Cars::sortCarsList()
{
  sort(m_carsList.begin(), m_carsList.end(), Cars::compareYear);
  sort(m_carsList.begin(), m_carsList.end(), Cars::compareBrand);
}

bool Cars::compareYear(Car first, Car second)
{
  return (first.year < second.year);
}

bool Cars::compareBrand(Car first, Car second)
{
  if (second.brand.compare(first.brand) < 0) {
    return 0;
  }
  return (second.brand.compare(first.brand));
}

void Cars::printCarsInformation()
{
  for (vector<Car>::const_iterator it = m_carsList.begin(); it != m_carsList.end(); ++it) {
    // Trying to be pleasant
    cout << setw(16) << (*it).brand 
         << setw(9) << (*it).model 
         << setw(8) << (*it).serial 
         << setw(5) << (*it).year
         << setw(4) << (*it).color << endl;
  }
}
