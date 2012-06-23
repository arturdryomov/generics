#ifndef TEST_MESSAGER_H
#define TEST_MESSAGER_H


#include <gtest/gtest.h>

#include "messager.h"


using namespace std;


class MessagerTest : public ::testing::Test
{
protected:
  Messager *messager;

  virtual void SetUp()
  {
    messager = new Messager();
  }

  virtual void TearDown()
  {
    delete messager;
  }
};


#endif // TEST_MESSAGER_H 
