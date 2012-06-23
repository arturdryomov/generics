#include "test_messager.h"


TEST_F(MessagerTest, Common)
{
  string message = "message";

  messager->putMessage(message);
  ASSERT_EQ(message, messager->getMessage());
}
