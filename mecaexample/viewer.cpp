#include <mecacell/mecacell.h>
#include <mecacellviewer/viewer.h>
#include "cell.hpp"
#include "scenario.hpp"

int main(int argc, char **argv) {
  Scenario scenario;
  scenario.init(argc, argv);
  MecacellViewer::Viewer<Scenario> v(scenario);
  return v.exec(argc, argv);
}
