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
      bool reassigned = false;
      memory->put(id1, Band(0), reassigned);
      memory->put(id1, Band(1), reassigned);
      memory->put(id1, Band(2), reassigned);
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
      bool reassigned = false;
      memory->put(id1, Band(0), reassigned);
      memory->put(id1, Band(1), reassigned);
      memory->put(id1, Band(2), reassigned);
      SchedulingMemory copy(*memory);
      CPPUNIT_ASSERT_EQUAL(size_t(3), copy.getNumberAssignedBands(id1));
      const vector<Band>& bandsVec = copy.getBands(id1);
      for (size_t i = 0; i < bandsVec.size(); i++)
        CPPUNIT_ASSERT_EQUAL(Band(i), bandsVec.at(i));
    }
    
    void testReassignment() {
      cout << "[SchedulingMemoryTest/testReassignment]" << endl;
      MacNodeId id1 = MacNodeId(1025);
      memory->put(id1, Band(0), false);
      memory->put(id1, Band(1), true);
      const vector<bool>& assignments = memory->getReassignments(id1);
      CPPUNIT_ASSERT_EQUAL(false, assignments.at(0));
      CPPUNIT_ASSERT_EQUAL(true, assignments.at(1));
    }
  
  CPPUNIT_TEST_SUITE(SchedulingMemoryTest);
      CPPUNIT_TEST(testPut);
      CPPUNIT_TEST(testCopyConstructor);
      CPPUNIT_TEST(testReassignment);
    CPPUNIT_TEST_SUITE_END();
};
