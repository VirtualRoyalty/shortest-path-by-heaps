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
  getUnitTesting();
  getPerformanceToFile();
  return 0;
}
