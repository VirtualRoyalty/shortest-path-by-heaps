#pragma once

#define ATTEMPTS 2
#define BENCHMARKS "../benchmarks/benchmarks.txt"
#define OUTFILE "../results/performance.csv"

// files utils
void write_csv(
    std::string filename,
    std::vector<std::pair<std::string, std::vector<std::string>>> dataset);
std::vector<std::vector<std::string>> read_csv(std::string filename);

std::vector<std::vector<std::pair<int, float>>>
construct_graph_from_csv(std::string filename);

// random generators
int genRandomUid(unsigned int a, unsigned int b);
std::vector<int> genRandVec(size_t N, unsigned int a, unsigned int b);
std::string genRandString(size_t);
std::vector<std::string> genRandStrings(size_t);

// performance evaluation int
void getPerformanceToFile();
