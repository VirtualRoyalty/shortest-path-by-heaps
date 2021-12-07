#pragma once
#include <iostream>
#include <tuple>
#define MAX_FLOAT 1000000.1

class Dijkstras {
private:
  size_t number_of_nodes;
  std::vector<std::vector<std::pair<int, float>>> graph;
  float *dist;
  bool *short_path_set;

public:
  Dijkstras(std::vector<std::vector<std::pair<int, float>>> &g) {
    graph = g;
    this->number_of_nodes = graph.size();
    this->dist = new float[number_of_nodes];
    this->short_path_set = new bool[number_of_nodes];
  }

  int minDistance() {
    float min_dist = MAX_FLOAT;
    int min_index = 0;

    for (int v = 0; v < number_of_nodes; v++) {
      if (short_path_set[v] == false && dist[v] <= min_dist) {
        min_dist = dist[v];
        min_index = v;
      }
    }
    // std::cout << "min_dist" << min_dist << "\n";
    // std::cout << "min_index " << min_index << "\n";
    return min_index;
  }

  void run(int source) {
    for (int i = 0; i < number_of_nodes; i++) {
      dist[i] = MAX_FLOAT;
      short_path_set[i] = false;
    }
    dist[source] = 0;

    for (int count = 0; count < number_of_nodes; count++) {
      int u = minDistance();
      short_path_set[u] = true;

      for (int v = 0; v < graph[u].size(); v++) {
        int node_v = graph[u][v].first;
        if (!short_path_set[node_v] && dist[u] != MAX_FLOAT) {
          if ((dist[u] + graph[u][v].second) <= dist[node_v])
            dist[node_v] = dist[u] + graph[u][v].second;
        }
      }
    }
  }

  void printSolution() {
    std::cout << "\n\nVertex \t Distance from Source" << std::endl;
    for (int i = 0; i < number_of_nodes; i++)
      std::cout << i << " \t\t" << dist[i] << std::endl;
  }

  void printSolutionRaw() {
    for (int i = 0; i < number_of_nodes; i++)
      std::cout << dist[i] << " ";
    // std::cout << "\n";
  }
};
