#include <iostream>
#include "MaxDatarateSorter.hpp"

using namespace std;

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

MaxDatarateSorter::MaxDatarateSorter(size_t numBands) : mNumBands(numBands) {
  for (size_t i = 0; i < numBands; i++)
    mBandToIdRate.push_back(vector<IdRatePair>());
}

void MaxDatarateSorter::put(const Band &band, const IdRatePair& idRatePair) {
  // Grab the band's vector.
  vector<IdRatePair>& list = mBandToIdRate.at(band);
  // Go through list.
  for (size_t i = 0; i < list.size(); i++) {
    IdRatePair current = list.at(i);
    // Is the given rate better than the one at this position?
    if (current < idRatePair) {
      // Then insert this one before it.
      list.insert(list.begin() + i, idRatePair);
      return;
    }
  }
  // The new value must have a worse rate than every list member, so put it at the back.
  list.push_back(idRatePair);
}

const std::vector<IdRatePair> &MaxDatarateSorter::get(const Band &band) const {
  return mBandToIdRate.at(band);
}

const IdRatePair& MaxDatarateSorter::get(const Band& band, const size_t& position) const {
  return get(band).at(position);
}

string MaxDatarateSorter::toString() const {
  string descr = "";
  for (size_t i = 0; i < mBandToIdRate.size(); i++) {
    descr += "Band " + to_string(i) + ":\n";
    for (size_t j = 0; j < mBandToIdRate.at(i).size(); j++) {
      const IdRatePair& pair = mBandToIdRate.at(i).at(j);
      descr += "\t" + to_string(pair.from) + "-" + dirToA(pair.dir) + "->" + to_string(pair.to) + " @" + to_string(pair.txPower) + " with throughput " + to_string(pair.rate) + "\n";
    }
  }
  return descr;
}

void MaxDatarateSorter::remove(const MacNodeId id) {
  for (size_t i = 0; i < mBandToIdRate.size(); i++) {
    vector<IdRatePair>& currentBandVec = mBandToIdRate.at(i);
    for (size_t j = 0; j < currentBandVec.size(); j++) {
      if (currentBandVec.at(j).from == id)
        currentBandVec.erase(currentBandVec.begin() + j);
    }
  }
}
