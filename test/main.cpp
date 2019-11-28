#include <gtest/gtest.h>

#include <iostream>
#include <sstream>

#include <helloppaworld/helloppaworld.hpp>

namespace helloppaworld {
namespace {

TEST(helloppaworld, SaysHi) { 
  std::ostringstream ss;
  helloppaworld::sayHello(ss);
  std::string out = ss.str();
  EXPECT_EQ(out, "Hello PPA World!\n");
}

}
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
