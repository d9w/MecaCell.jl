#include <mecacell/mecacell.h>
#include "cell.hpp"
#include "scenario.hpp"

int main(int argc, char **argv) {
  Scenario scenario;
	auto start = chrono::high_resolution_clock::now();

  scenario.init(argc, argv);
	while (!scenario.finished()) scenario.loop();

	auto end = chrono::high_resolution_clock::now();
	std::cout << chrono::duration<double, milli>(end - start).count() << " ms" << endl;

  return 0;
}
