#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include "MaxDatarateSorter.hpp"

using namespace std;

class MaxDatarateSorterTest : public CppUnit::TestFixture {
  private:
    MaxDatarateSorter *mSorter;
    int numBands = 5;
    
    const std::string dirToA(Direction dir)
    {
      switch (dir)
      {
        case DL:
          return "DL";
        case UL:
          return "UL";
        case D2D:
          return "D2D";
        case D2D_MULTI:
          return "D2D_MULTI";
        default:
          return "Unrecognized";
      }
    }
  
  public:
    void setUp() override {
      mSorter = new MaxDatarateSorter(numBands);
    }
    
    void tearDown() override {
      delete mSorter;
    }
    
    void testPut() {
      cout << "[MaxDatarateSorterTest/testPut]" << endl;
      MacCid dummyCid = 1;
      mSorter->put(0, IdRatePair(dummyCid, 1025, 1, 26, 1000, Direction::UL));
      mSorter->put(0, IdRatePair(dummyCid, 1026, 1026, 24, 600, Direction::D2D));
      mSorter->put(0, IdRatePair(dummyCid, 1027, 1025, 24, 700, Direction::D2D));
      mSorter->put(1, IdRatePair(dummyCid, 1025, 1026, 24, 700, Direction::D2D));
      mSorter->put(1, IdRatePair(dummyCid, 1026, 1025, 24, 800, Direction::D2D));
      mSorter->put(1, IdRatePair(dummyCid, 1027, 1, 26, 1000, Direction::UL));
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
      MacCid dummyCid = 1;
      mSorter->put(0, IdRatePair(dummyCid, 1025, 1, 26, 1000, Direction::UL));
      mSorter->put(0, IdRatePair(dummyCid, 1026, 1026, 24, 600, Direction::D2D));
      mSorter->put(0, IdRatePair(dummyCid, 1027, 1025, 24, 700, Direction::D2D));
      mSorter->put(1, IdRatePair(dummyCid, 1025, 1026, 24, 700, Direction::D2D));
      mSorter->put(1, IdRatePair(dummyCid, 1026, 1025, 24, 800, Direction::D2D));
      mSorter->put(1, IdRatePair(dummyCid, 1027, 1, 26, 1000, Direction::UL));
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
      bool seenException = false;
      try {
        mSorter->getBestBand(MacNodeId(1025));
      } catch (const exception& e) {
        seenException = true;
      }
      // Finding a best band on an empty container should throw an exception.
      CPPUNIT_ASSERT_EQUAL(true, seenException);
      
      MacCid dummyCid = 1;
      mSorter->put(0, IdRatePair(dummyCid, 1025, 1, 26, 1000, Direction::UL));
      mSorter->put(1, IdRatePair(dummyCid, 1025, 1, 26, 1001, Direction::UL));
      mSorter->put(2, IdRatePair(dummyCid, 1025, 1, 26, 1002, Direction::UL));
      mSorter->put(3, IdRatePair(dummyCid, 1025, 1, 26, 1003, Direction::UL)); // <-- Largest rate!
      mSorter->put(4, IdRatePair(dummyCid, 1025, 1, 26, 999, Direction::UL));
      CPPUNIT_ASSERT_EQUAL(Band(3), mSorter->getBestBand(MacNodeId(1025)));
    }
    
    void testGetForDirection() {
      cout << "[MaxDatarateSorterTest/testGetForDirection]" << endl;
      MacCid dummyCid = 1;
      mSorter->put(0, IdRatePair(dummyCid, 1025, 1, 26, 1000, Direction::UL));
      mSorter->put(0, IdRatePair(dummyCid, 1026, 1026, 24, 600, Direction::D2D));
      mSorter->put(0, IdRatePair(dummyCid, 1027, 1025, 24, 700, Direction::D2D));
      mSorter->put(1, IdRatePair(dummyCid, 1025, 1026, 24, 700, Direction::D2D));
      mSorter->put(1, IdRatePair(dummyCid, 1026, 1025, 24, 800, Direction::D2D));
      mSorter->put(1, IdRatePair(dummyCid, 1027, 1, 26, 1000, Direction::UL));
      Direction dir = Direction::UL;
      std::vector<IdRatePair> pairs = mSorter->at(0, dir);
      for (size_t i = 0; i < pairs.size(); i++)
        CPPUNIT_ASSERT_EQUAL(dir, pairs.at(i).dir);
      
      dir = Direction::D2D;
      pairs = mSorter->at(0, dir);
      for (size_t i = 0; i < pairs.size(); i++)
        CPPUNIT_ASSERT_EQUAL(dir, pairs.at(i).dir);
  
      dir = Direction::UL;
      pairs = mSorter->at(1, dir);
      for (size_t i = 0; i < pairs.size(); i++)
        CPPUNIT_ASSERT_EQUAL(dir, pairs.at(i).dir);
  
      dir = Direction::D2D;
      pairs = mSorter->at(1, dir);
      for (size_t i = 0; i < pairs.size(); i++)
        CPPUNIT_ASSERT_EQUAL(dir, pairs.at(i).dir);
    }
    
    void testGetForNonD2D() {
      cout << "[MaxDatarateSorterTest/testGetForNonD2D]" << endl;
      MacCid dummyCid = 1;
      mSorter->put(0, IdRatePair(dummyCid, 1025, 1, 26, 1000, Direction::UL));
      mSorter->put(0, IdRatePair(dummyCid, 1026, 1026, 24, 600, Direction::D2D));
      mSorter->put(0, IdRatePair(dummyCid, 1027, 1025, 24, 700, Direction::D2D));
      mSorter->put(1, IdRatePair(dummyCid, 1025, 1026, 24, 700, Direction::D2D));
      mSorter->put(1, IdRatePair(dummyCid, 1026, 1025, 24, 800, Direction::D2D));
      mSorter->put(1, IdRatePair(dummyCid, 1027, 1, 26, 1000, Direction::UL));
      Direction dir = Direction::D2D;
      
      std::vector<IdRatePair> pairs = mSorter->at_nonD2D(0);
      for (size_t i = 0; i < pairs.size(); i++)
        CPPUNIT_ASSERT(dir != pairs.at(i).dir);
      
      pairs = mSorter->at_nonD2D(1);
      for (size_t i = 0; i < pairs.size(); i++)
        CPPUNIT_ASSERT(dir != pairs.at(i).dir);
    }
    
    void testRemoveBand() {
      cout << "[MaxDatarateSorterTest/testRemoveBand]" << endl;
      MacCid dummyCid = 1;
      mSorter->put(0, IdRatePair(dummyCid, 1025, 1026, 24, 700, Direction::D2D));
      mSorter->put(1, IdRatePair(dummyCid, 1025, 1026, 24, 800, Direction::D2D));
      mSorter->put(2, IdRatePair(dummyCid, 1025, 1026, 24, 900, Direction::D2D));
      CPPUNIT_ASSERT_EQUAL(Band(2), mSorter->getBestBand(MacNodeId(1025)));
      mSorter->markBand(2, true);
      CPPUNIT_ASSERT_EQUAL(Band(1), mSorter->getBestBand(MacNodeId(1025)));
      mSorter->markBand(1, true);
      CPPUNIT_ASSERT_EQUAL(Band(0), mSorter->getBestBand(MacNodeId(1025)));
      mSorter->markBand(0, true);
      bool seenException = false;
      try {
        mSorter->getBestBand(MacNodeId(1025));
      } catch (const exception& e) {
        seenException = true;
      }
      CPPUNIT_ASSERT_EQUAL(true, seenException);
    }
    
    CPPUNIT_TEST_SUITE(MaxDatarateSorterTest);
      CPPUNIT_TEST(testPut);
      CPPUNIT_TEST(testRemove);
      CPPUNIT_TEST(testFindBestBand);
      CPPUNIT_TEST(testGetForDirection);
      CPPUNIT_TEST(testGetForNonD2D);
      CPPUNIT_TEST(testRemoveBand);
    CPPUNIT_TEST_SUITE_END();
};
