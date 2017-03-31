#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include "MaxDatarateSorter.hpp"

using namespace std;

class MaxDatarateSorterTest : public CppUnit::TestFixture {
  private:
    MaxDatarateSorter *mSorter;
    int numBands = 2;
  
  public:
    void setUp() override {
      mSorter = new MaxDatarateSorter(numBands);
    }
    
    void tearDown() override {
      delete mSorter;
    }
    
    void testPut() {
      cout << "[MaxDatarateSorterTest/testPut]" << endl;
      mSorter->put(0, IdRatePair(1025, 1, 26, 1000, Direction::UL));
      mSorter->put(0, IdRatePair(1026, 1026, 24, 600, Direction::D2D));
      mSorter->put(0, IdRatePair(1027, 1025, 24, 700, Direction::D2D));
      mSorter->put(1, IdRatePair(1025, 1026, 24, 700, Direction::D2D));
      mSorter->put(1, IdRatePair(1026, 1025, 24, 800, Direction::D2D));
      mSorter->put(1, IdRatePair(1027, 1, 26, 1000, Direction::UL));
      CPPUNIT_ASSERT_EQUAL(MacNodeId(1025), mSorter->get(0, 0).from);
      CPPUNIT_ASSERT_EQUAL(MacNodeId(1027), mSorter->get(0, 1).from);
      CPPUNIT_ASSERT_EQUAL(MacNodeId(1026), mSorter->get(0, 2).from);
      CPPUNIT_ASSERT_EQUAL(MacNodeId(1027), mSorter->get(1, 0).from);
      CPPUNIT_ASSERT_EQUAL(MacNodeId(1026), mSorter->get(1, 1).from);
      CPPUNIT_ASSERT_EQUAL(MacNodeId(1025), mSorter->get(1, 2).from);
    }
    
    void testRemove() {
      cout << "[MaxDatarateSorterTest/testRemove]" << endl;
      // Add some nodes.
      mSorter->put(0, IdRatePair(1025, 1, 26, 1000, Direction::UL));
      mSorter->put(0, IdRatePair(1026, 1026, 24, 600, Direction::D2D));
      mSorter->put(0, IdRatePair(1027, 1025, 24, 700, Direction::D2D));
      mSorter->put(1, IdRatePair(1025, 1026, 24, 700, Direction::D2D));
      mSorter->put(1, IdRatePair(1026, 1025, 24, 800, Direction::D2D));
      mSorter->put(1, IdRatePair(1027, 1, 26, 1000, Direction::UL));
      mSorter->remove(1025);
      // Make sure there's no node 1025 left.
      for (size_t i = 0; i < mSorter->size(); i++) {
        const std::vector<IdRatePair>& currentBandVec = mSorter->get(i);
        for (size_t j = 0; j < currentBandVec.size(); j++)
          CPPUNIT_ASSERT(currentBandVec.at(j).from != MacNodeId(1025));
      }
      mSorter->remove(1026);
      // Make sure there's no node 1025 left.
      for (size_t i = 0; i < mSorter->size(); i++) {
        const std::vector<IdRatePair>& currentBandVec = mSorter->get(i);
        for (size_t j = 0; j < currentBandVec.size(); j++)
          CPPUNIT_ASSERT(currentBandVec.at(j).from != MacNodeId(1026));
      }
      mSorter->remove(1027);
      for (size_t i = 0; i < mSorter->size(); i++) {
        const std::vector<IdRatePair>& currentBandVec = mSorter->get(i);
        CPPUNIT_ASSERT_EQUAL(size_t(0), currentBandVec.size());
      }
    }
    
    CPPUNIT_TEST_SUITE(MaxDatarateSorterTest);
    CPPUNIT_TEST(testPut);
    CPPUNIT_TEST(testRemove);
    CPPUNIT_TEST_SUITE_END();
};
