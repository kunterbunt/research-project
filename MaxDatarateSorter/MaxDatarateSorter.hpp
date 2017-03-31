#ifndef SCHEDULER_MAXDATARATESORTER_HPP
#define SCHEDULER_MAXDATARATESORTER_HPP

#include <map>
#include <vector>

typedef unsigned short MacNodeId;
typedef unsigned short Band;
enum Direction {
  DL, UL, D2D, D2D_MULTI, UNKNOWN_DIRECTION
};

class IdRatePair {
  public:
    IdRatePair(const MacNodeId& from, const MacNodeId& to, double txPower, const double rate, const Direction& dir)
        : from(from), to(to), rate(rate), txPower(txPower), dir(dir) {}
    MacNodeId from, to;
    double rate, txPower;
    Direction dir;
    
    bool operator>(const IdRatePair& other) {
      return rate > other.rate;
    }
    
    bool operator<(const IdRatePair& other) {
      return !((*this) > other);
    }
};

/**
 * This container can be given <node id, throughput> pairs.
 * It always keeps the internal list sorted according to throughput.
 */
class MaxDatarateSorter {
  public:
    MaxDatarateSorter(size_t numBands);
    
    void put(const Band& band, const IdRatePair& idRatePair);
    
    /**
     * Removes 'id' from all elements in this container where element.from == 'id'.
     * @param id
     */
    void remove(const MacNodeId id);
    
    /**
     *
     * @param band
     * @param position
     * @return The xth best node according to throughput.
     */
    const IdRatePair& get(const Band& band, const size_t& position) const;
    const std::vector<IdRatePair>& get(const Band& band) const;
    
    size_t size() const {
      return mBandToIdRate.size();
    }
    
    std::string toString() const;
    
    
  private:
    /**
     * The outer vector corresponds to the bands.
     * Each inner vector holds an always-sorted list of <id, rate> pairs in descending order rate-wise.
    **/
    std::vector<std::vector<IdRatePair>> mBandToIdRate;
    const size_t mNumBands;
};


#endif //SCHEDULER_MAXDATARATESORTER_HPP
