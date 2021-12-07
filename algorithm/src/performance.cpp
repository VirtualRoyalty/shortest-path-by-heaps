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

void getPerformanceToFile() {
  size_t tableSize;
  size_t testSize, vecSize;
  vector<int> baseVec, testVec;
  std::vector<std::vector<std::string>> benchmarks = read_csv(BENCHMARKS);

  vector<string> number_of_nodes, number_of_edges, density, _benchmarks;
  vector<string> time_dijkstra, time_dijkstra_dheap, time_dijkstra_binomheap;
  std::vector<std::vector<std::pair<int, float>>> graph;

  cout << "\n\nProgress: ";
  for (auto const &benchmark : benchmarks) {
    for (int i = 0; i < ATTEMPTS; ++i) {
      cout << "### " << benchmark[0] << "\n";
      graph = construct_graph_from_csv(benchmark[0]);
      _benchmarks.push_back(benchmark[0]);
      number_of_nodes.push_back(benchmark[1]);
      number_of_edges.push_back(benchmark[2]);
      density.push_back(benchmark[3]);
      Dijkstras algorithm(graph);
      DijkstrasDheap algorithm_dheap(graph);
      DijkstrasBinomialHeap algorithm_binomheap(graph);

      auto start = high_resolution_clock::now();
      algorithm.run(0);
      auto stop = high_resolution_clock::now();
      float duration = duration_cast<microseconds>(stop - start).count();
      time_dijkstra.push_back(to_string(duration));

      start = high_resolution_clock::now();
      algorithm_dheap.run(0);
      stop = high_resolution_clock::now();
      duration = duration_cast<microseconds>(stop - start).count();
      time_dijkstra_dheap.push_back(to_string(duration));

      start = high_resolution_clock::now();
      algorithm_binomheap.run(0);
      stop = high_resolution_clock::now();
      duration = duration_cast<microseconds>(stop - start).count();
      time_dijkstra_binomheap.push_back(to_string(duration));
    }
  }
  cout << "FINISH\n ";
  vector<pair<string, vector<string>>> vals = {
      {"benchmark", _benchmarks},
      {"number_of_nodes", number_of_nodes},
      {"number_of_edges", number_of_edges},
      {"density", density},
      {"Dijkstras", time_dijkstra},
      {"Dijkstras_DHeap", time_dijkstra_dheap},
      {"Dijkstras_BinomialHeap", time_dijkstra_binomheap},
  };

  write_csv(OUTFILE, vals);
};
