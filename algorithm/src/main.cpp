#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <utility>
#include <vector>

#include "BinomialHeap.h"
#include "Dheap.h"
#include "Dijkstras.h"
#include "DijkstrasBinomialHeap.h"
#include "DijkstrasDHeap.h"
#include "utils.h"

using namespace std;
using namespace std::chrono;

int main() {
  getPerformanceToFile();
  return 0;
}

// std::string benchmarks_file = "../benchmarks/benchmarks.txt";
// std::vector<std::vector<std::string>> benchmarks = read_csv(benchmarks_file);
// for (auto const &value : benchmarks) {
//   std::cout << value[0] << " ";
// }
// std::cout << "START..." << '\n';
// std::string filepath = "../benchmarks/test.txt";
// std::vector<std::vector<std::string>> file;
// std::vector<std::vector<std::pair<int, float>>> graph;
//
// graph = construct_graph_from_csv(filepath);
//
// auto start = high_resolution_clock::now();
// Dijkstras algorithm(graph);
// algorithm.run(5);
// // algorithm.printSolution();
// auto stop = high_resolution_clock::now();
// float duration = duration_cast<microseconds>(stop - start).count();
// cout << "Djikstra time: " << duration << " microsec" << endl;
//
// start = high_resolution_clock::now();
// DijkstrasBinomialHeap algorithm_binomheap(graph);
// algorithm_binomheap.run(5);
// // algorithm_binomheap.printSolution();
// stop = high_resolution_clock::now();
// duration = duration_cast<microseconds>(stop - start).count();
// cout << "Djikstra binomial-heap time: " << duration << " microsec" << endl;
//
// start = high_resolution_clock::now();
// DijkstrasDheap algorithm_dheap(graph);
// algorithm_dheap.run(5);
// // algorithm_dheap.printSolution();
// stop = high_resolution_clock::now();
// duration = duration_cast<microseconds>(stop - start).count();
// cout << "Djikstra 3-heap time: " << duration << " microsec" << endl;
//
// std::cout << "SIZE:" << graph.size() << '\n';
// std::cout << "END..." << '\n';
//
// int some_arr[] = {6, 100, 5, 9, 8, 1, 0};
// // Dheap<int> three_heap(some_arr, 6, 3);
// Dheap<int> tre_heap(20, 3);
// // tre_heap.heapify();
// // tre_heap.print_heap();
// for (int i = 0; i < 7; i++) {
//   tre_heap.insert_pair(std::make_pair(some_arr[i], i));
// }
// tre_heap.print_heap();
// std::cout << std::endl << "Min extr: ";
// int elem = 0;
// while (elem >= 0) {
//   elem = tre_heap.extract_min().first;
//   std::cout << elem << " ";
// }
//
// std::cout << "\n\nBINOMIAL HEAP:\n\n";
// BinomialHeap binomial_heap(20);
// int new_some_arr[] = {6, 100, 5, 9, 8, 1, 0};
// for (int i = 0; i < 7; i++) {
//   binomial_heap.insert_pair(std::make_pair((float)new_some_arr[i], i));
// }
// // int found_elem = 0;
// for (int i = 0; i < 7; i++) {
//   // found_elem = binomial_heap.findNode(i);
//   if (binomial_heap.findNode(i) != NULL)
//     std::cout << "~~FIND: " << binomial_heap.findNode(i)->x.second << "~~\n
//     ";
// }
//
// binomial_heap.print_heap();
// std::cout << std::endl << "Min extr:\n";
// int some_elem = 0;
// while (some_elem >= 0) {
//   some_elem = binomial_heap.extract_min().first;
//   std::cout << "~~EXTRACT: " << some_elem << "~~\n ";
//   if (binomial_heap.findNode(4) != NULL)
//     std::cout << "~~FIND: " << binomial_heap.findNode(4)->x.second << "~~\n
//     ";
