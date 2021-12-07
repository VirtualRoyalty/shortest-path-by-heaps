#pragma once

#define UNITTESTS "../benchmarks/unit/unittests.txt"
#define ATTEMPTS 3
#define BENCHMARKS "../benchmarks/benchmarks.txt"
#define OUTFILE "../results/performance.csv"

// files utils
void write_csv(
    std::string filename,
    std::vector<std::pair<std::string, std::vector<std::string>>> dataset);
std::vector<std::vector<std::string>> read_csv(std::string filename);

std::vector<std::vector<std::pair<int, float>>>
construct_graph_from_csv(std::string filename);

// performance evaluation int
void getPerformanceToFile();
void getUnitTesting();
