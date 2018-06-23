#ifndef SCENARIO_HPP
#define SCENARIO_HPP
#include <mecacell/mecacell.h>

class Scenario {
  using World = MecaCell::World<Cell>;

 private:
	World w;
	double currentTime = 0;
	double nsteps = 10;
  double duration;

 public:
  World &getWorld() { return w; }

	// called at initialisation
  void init(int argc, char** argv) {
		// here we just add a cell at (0,0,0);
    w.addCell(new Cell());
    duration = nsteps * w.getDt();
	}

	void loop(){
		// this code is called before every frame by the viewer
		// here we just call the world update method, which will handle all the physics
    // and call our MyCell::updateBehavior() method
		currentTime += w.getDt();
		w.update();
		// handle events, plug your own methods call, whatever you want goes in this method...
	}

	bool finished() { return currentTime > duration; }
};

#endif
