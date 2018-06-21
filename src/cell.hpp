#ifndef CELL_HPP
#define CELL_HPP
#include <mecacell/mecacell.h>
#include <mecacell/springbody.hpp>

class Cell : public MecaCell::ConnectableCell<Cell, MecaCell::SpringBody> {

public:
	using Parent = MecaCell::ConnectableCell<Cell, MecaCell::SpringBody>;
	Cell(const MecaCell::Vector3D& v) : Parent(v) {}

	// returns the adhesion coef (between 0 & 1) with the cell *c
	double getAdhesionWith(Cell*, MecaCell::Vec) { return 0.9; }

	// update routine, called at every loop iteration
	// returns a pointer to a new cell if division
	// returns nullptr if not
	template <typename W> void updateBehavior(W& w) {
		// access inputs here
	}
};

#endif
