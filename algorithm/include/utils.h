#pragma once

#define ITERATIONS 100
#define COEFFICIENT 2
#define OPERATIONS 30
#define STEP 1000
#define STRESS_SIZE 700
#define INT_FILE "../data/output/integerPerformanceM2N_1.csv"
#define STRING_FILE "../data/output/stringPerformanceM2N_1.csv"


// files utils
void write_csv(
    std::string filename,
    std::vector<std::pair<std::string, std::vector<std::string>>> dataset);
std::vector<std::vector<std::string>>read_csv(std::string filename);

std::vector<std::vector<std::pair<int, float>>>construct_graph_from_csv(std::string filename); 

// random generators
int genRandomUid(unsigned int a, unsigned int b);
std::vector<int> genRandVec(size_t N, unsigned int a, unsigned int b);
std::string genRandString(size_t);
std::vector<std::string> genRandStrings(size_t);

// // unit tests
// void unitTestOpenHashMap();
// void unitTestChainedHashMap();
// void unitTestCuckooHashMap();
//
// // stress tests
// void stressTestChainedHashMap();
// void stressTestOpenHashMap();
// void stressTestCuckooHashMap();
//
// // performance evaluation int
// void getPerformanceInteger();
// void getPerformanceIntegerToFile();
//
// // performance evaluation string
// void getPerformanceString();
// void getPerformanceStringToFile();
//
// //real life data tests
// void realLifeDataTets();
