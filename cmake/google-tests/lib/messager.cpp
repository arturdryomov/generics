#include "messager.h"


void Messager::putMessage(string message)
{
  this->message = message;
}


string Messager::getMessage()
{
  return message;
}
