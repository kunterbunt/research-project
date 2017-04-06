#include <iostream>
#include <SchedulingMemoryTest.cc>
#include <cppunit/ui/text/TestRunner.h>

using namespace std;

int main() {
  cout << "Running Tests" << endl;
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(SchedulingMemoryTest::suite());
  runner.run();
  return 0;
}
