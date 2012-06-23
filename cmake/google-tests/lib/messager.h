#ifndef MESSAGER_H
#define MESSAGER_H


#include <string>


using namespace std;


class Messager
{
public:
  void putMessage(string message);
  string getMessage();

private:
  string message;
};


#endif // MESSAGER_H 
