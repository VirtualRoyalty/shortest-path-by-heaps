#pragma once
#include <iostream>
#include <tuple>

#include "BinomialHeap.h"

#define MAX_INT 1000000

class DijkstrasBinomialHeap {
private:
  size_t number_of_nodes;
  std::vector<std::vector<std::pair<int, float>>> graph;
  std::vector<int> dist;
  bool *short_path_set;

public:
  DijkstrasBinomialHeap(std::vector<std::vector<std::pair<int, float>>> &g) {
    graph = g;
    this->number_of_nodes = graph.size();
    // std::vector<int> _dist(number_of_nodes, MAX_INT);
    this->dist.resize(number_of_nodes, MAX_INT);
    this->short_path_set = new bool[number_of_nodes];
  }

  void run(int source) {

    BinomialHeap<int> binom_heap(number_of_nodes);
    binom_heap.insert_pair(std::make_pair(0, source));
    dist[source] = 0;

    while (binom_heap.size() > 0) {
      int u = binom_heap.extract_min().second;
      for (int v = 0; v < graph[u].size(); v++) {
        int node_v = graph[u][v].first;
        int new_weight = dist[u] + graph[u][v].second;
        if (new_weight <= dist[node_v]) {
          if (dist[node_v] == MAX_INT) {
            binom_heap.insert_pair(std::make_pair(new_weight, node_v));
          } else {
            binom_heap.decrease_key(node_v, new_weight);
          }
          dist[node_v] = new_weight;
        }
      }
    }
  }

  void printSolution() {
    std::cout << "\n\nVertex \t Distance from Source" << std::endl;
    for (int i = 0; i < number_of_nodes; i++)
      std::cout << i << " \t\t" << dist[i] << std::endl;
  }
};
