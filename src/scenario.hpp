#ifndef SCENARIO_HPP
#define SCENARIO_HPP
#include <mecacell/mecacell.h>

class Scenario {
  using World = MecaCell::World<Cell>;

 private:
	World w;

 public:
  World &getWorld() { return w; }

	// called at initialisation
  void init(int argc, char** argv) {
		// here we just add a cell at (0,0,0);
    w.addCell(new Cell(MecaCell::Vec::zero()));
	}

	void loop(){
		// this code is called before every frame by the viewer
		// here we just call the world update method, which will handle all the physics
    // and call our MyCell::updateBehavior() method
		w.update();
		// handle events, plug your own methods call, whatever you want goes in this method...
	}
};

#endif
