#ifndef CAR_H
#define CAR_H

#include <string>
#include <vector>

using namespace std;

struct Car {
  string brand;
  string model;
  int serial;
  int year;
  int color;
};

class Cars {
public:
  void enterCarsInformation();
  void sortCarsList();
  void printCarsInformation();
private:
  vector<Car> m_carsList;

  void enterFromFile(string filename);
  void enterFromStdio();
  void addCar(vector<string> inputParts);
  // Comparsion methods should be static
  static bool compareYear(const Car first, const Car second);
  static bool compareBrand(const Car first, const Car second);
};

#endif // CAR_H
