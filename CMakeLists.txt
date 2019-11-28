cmake_minimum_required(VERSION 3.10)

option(test "Build all tests." OFF) # Makes boolean 'test' available.

project(hello-ppa-world CXX)

# Building
add_library(helloppaworld SHARED src/helloppaworld.cpp)
target_include_directories(helloppaworld PUBLIC include)

# Testing
if(test)
  enable_testing()

  find_package(GTest REQUIRED)

  include_directories(${GTEST_INCLUDE_DIRS})

  add_executable(tests test/main.cpp)

  target_link_libraries(tests helloppaworld ${GTEST_BOTH_LIBRARIES} pthread)

  target_include_directories(tests PRIVATE include)

  add_test(test tests)
endif()

# Install

install(TARGETS helloppaworld
  LIBRARY
    DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  PUBLIC_HEADER
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include)

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Tom Lankhorst")
INCLUDE(CPack)
