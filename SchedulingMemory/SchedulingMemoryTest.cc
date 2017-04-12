#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include "SchedulingMemory.hpp"

using namespace std;

class SchedulingMemoryTest : public CppUnit::TestFixture {
  private:
    SchedulingMemory* memory;
  
  public:
    void setUp() override {
      memory = new SchedulingMemory();
    }
    
    void tearDown() override {
      delete memory;
    }
    
    void testPut() {
      cout << "[SchedulingMemoryTest/testPut]" << endl;
      MacNodeId id1 = MacNodeId(1025);
      memory->put(id1, Band(0));
      memory->put(id1, Band(1));
      memory->put(id1, Band(2));
      CPPUNIT_ASSERT_EQUAL(size_t(3), memory->getNumberAssignedBands(id1));
      MacNodeId  id2 = MacNodeId(1026);
      bool exceptionOccurred = false;
      try {
        memory->getBands(id2);
      } catch (const exception& e) {
        exceptionOccurred = true;
      }
      CPPUNIT_ASSERT_EQUAL(true, exceptionOccurred);
      
      const vector<Band>& bandsVec = memory->getBands(id1);
      for (size_t i = 0; i < bandsVec.size(); i++)
        CPPUNIT_ASSERT_EQUAL(Band(i), bandsVec.at(i));
    }
    
    void testCopyConstructor() {
      cout << "[SchedulingMemoryTest/testCopyConstructor]" << endl;
      MacNodeId id1 = MacNodeId(1025);
      memory->put(id1, Band(0));
      memory->put(id1, Band(1));
      memory->put(id1, Band(2));
      SchedulingMemory copy(*memory);
      CPPUNIT_ASSERT_EQUAL(size_t(3), copy.getNumberAssignedBands(id1));
      const vector<Band>& bandsVec = copy.getBands(id1);
      for (size_t i = 0; i < bandsVec.size(); i++)
        CPPUNIT_ASSERT_EQUAL(Band(i), bandsVec.at(i));
    }
  
  CPPUNIT_TEST_SUITE(SchedulingMemoryTest);
      CPPUNIT_TEST(testPut);
      CPPUNIT_TEST(testCopyConstructor);
    CPPUNIT_TEST_SUITE_END();
};
