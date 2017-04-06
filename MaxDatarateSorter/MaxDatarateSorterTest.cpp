#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include "MaxDatarateSorter.hpp"

using namespace std;

class MaxDatarateSorterTest : public CppUnit::TestFixture {
  private:
    MaxDatarateSorter *mSorter;
    int numBands = 5;
  
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
        const std::vector<IdRatePair>& currentBandVec = mSorter->at(i);
        for (size_t j = 0; j < currentBandVec.size(); j++)
          CPPUNIT_ASSERT(currentBandVec.at(j).from != MacNodeId(1025));
      }
      mSorter->remove(1026);
      // Make sure there's no node 1025 left.
      for (size_t i = 0; i < mSorter->size(); i++) {
        const std::vector<IdRatePair>& currentBandVec = mSorter->at(i);
        for (size_t j = 0; j < currentBandVec.size(); j++)
          CPPUNIT_ASSERT(currentBandVec.at(j).from != MacNodeId(1026));
      }
      mSorter->remove(1027);
      for (size_t i = 0; i < mSorter->size(); i++) {
        const std::vector<IdRatePair>& currentBandVec = mSorter->at(i);
        CPPUNIT_ASSERT_EQUAL(size_t(0), currentBandVec.size());
      }
    }
    
    void testFindBestBand() {
      cout << "[MaxDatarateSorterTest/testFindBestBand]" << endl;
      mSorter->put(0, IdRatePair(1025, 1, 26, 1000, Direction::UL));
      mSorter->put(1, IdRatePair(1025, 1, 26, 1001, Direction::UL));
      mSorter->put(2, IdRatePair(1025, 1, 26, 1002, Direction::UL));
      mSorter->put(3, IdRatePair(1025, 1, 26, 1003, Direction::UL)); // <-- Largest rate!
      mSorter->put(4, IdRatePair(1025, 1, 26, 999, Direction::UL));
      CPPUNIT_ASSERT_EQUAL(Band(3), mSorter->getBestBand(MacNodeId(1025)));
    }
    
    CPPUNIT_TEST_SUITE(MaxDatarateSorterTest);
    CPPUNIT_TEST(testPut);
    CPPUNIT_TEST(testRemove);
    CPPUNIT_TEST(testFindBestBand);
    CPPUNIT_TEST_SUITE_END();
};
