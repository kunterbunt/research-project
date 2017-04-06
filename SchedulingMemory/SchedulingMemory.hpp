//
// Created by Sebastian Lindner on 05.04.17.
//

#ifndef SCHEDULINGMEMORY_SCHEDULINGMEMORY_HPP
#define SCHEDULINGMEMORY_SCHEDULINGMEMORY_HPP

#include <vector>

typedef unsigned short MacNodeId;
typedef unsigned short Band;
enum Direction {
  DL, UL, D2D, D2D_MULTI, UNKNOWN_DIRECTION
};

/**
 * Maps a node id to its assigned bands and transmission direction.
 */
class SchedulingMemory {
  public:
    /**
     * Notify a 'band' being assigned to 'id'.
     * @param id
     * @param band
     */
    void put(const MacNodeId id, const Band band);
    
    /**
     * Notify that 'id' transmits in 'dir' direction.
     * @param id
     * @param dir
     */
    void put(const MacNodeId id, const Direction dir);
    
    /**
     * @param id
     * @return The number of bands currently assigned to 'id'.
     */
    std::size_t getNumberAssignedBands(const MacNodeId& id) const;
    
    const std::vector<Band>& getBands(const MacNodeId& id) const;
    
    const Direction& getDirection(const MacNodeId& id) const;
    
  private:
    /**
     * A memory item holds the assigned bands per node id
     * as well as the transmission direction this node wants to transmit in.
     */
    class MemoryItem {
      public:
        MemoryItem(MacNodeId id) : _id(id), _dir(UNKNOWN_DIRECTION) {}
        
        void putBand(Band band) {
          _assignedBands.push_back(band);
        }
        std::size_t getNumberOfAssignedBands() const {
          return _assignedBands.size();
        }
        const std::vector<Band>& getBands() const {
          return _assignedBands;
        }
        
        void setDir(Direction dir) {
          _dir = dir;
        }
        const Direction& getDir() const {
          return _dir;
        }
        
        const MacNodeId& getId() const {
          return _id;
        }
      
      private:
        MacNodeId _id;
        std::vector<Band> _assignedBands;
        Direction _dir;
    };
    
  protected:
    const MemoryItem& get(const MacNodeId& id) const;
    MemoryItem& get(const MacNodeId& id);
    
    std::vector<MemoryItem> _memory;
};


#endif //SCHEDULINGMEMORY_SCHEDULINGMEMORY_HPP
