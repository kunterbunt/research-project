#include <iostream>
#include <MaxDatarateSorterTest.cpp>
#include <cppunit/ui/text/TestRunner.h>

using namespace std;

int main() {
  cout << "Running Tests" << endl;
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(MaxDatarateSorterTest::suite());
  runner.run();
  return 0;
}
