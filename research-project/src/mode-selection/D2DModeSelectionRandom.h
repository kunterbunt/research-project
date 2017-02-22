//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef SRC_MODE_SELECTION_D2DMODESELECTIONRANDOM_H_
#define SRC_MODE_SELECTION_D2DMODESELECTIONRANDOM_H_

#include "D2DModeSelectionBase.h"

class D2DModeSelectionRandom : public D2DModeSelectionBase {
public:
    D2DModeSelectionRandom();
    virtual ~D2DModeSelectionRandom();

protected:
    virtual void doModeSelection();
};

#endif /* SRC_MODE_SELECTION_D2DMODESELECTIONRANDOM_H_ */
