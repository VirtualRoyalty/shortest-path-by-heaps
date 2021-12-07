#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1

#include <chrono>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "Dijkstras.h"
#include "DijkstrasBinomialHeap.h"
#include "DijkstrasDHeap.h"
#include "utils.h"

using namespace std;
using namespace std::chrono;

void getUnitTesting() {
  std::vector<std::vector<std::string>> units = read_csv(UNITTESTS);
  std::vector<std::vector<std::string>> answer;
  std::vector<std::vector<std::pair<int, float>>> graph;

  cout << "\n\nProgress: ";
  for (auto const &unit : units) {

    cout << "### " << unit[0] << "\n";
    graph = construct_graph_from_csv(unit[0]);
    answer = read_csv(unit[1]);

    for (auto const &dist : answer[0]) {
      std::cout << dist << " ";
    }
    cout << "\t- answer \n";
    Dijkstras algorithm(graph);
    DijkstrasDheap algorithm_dheap(graph);
    DijkstrasBinomialHeap algorithm_binomheap(graph);

    algorithm.run(0);

    algorithm.printSolutionRaw();
    cout << "\t- Dijkstras: \n";

    algorithm_dheap.run(0);
    algorithm.printSolutionRaw();
    cout << "\t- Dijkstras+3-heap: \n";

    algorithm_binomheap.run(0);
    algorithm.printSolutionRaw();
    cout << "\t- Dijkstras+binomial-heap: \n";
  }
};
