// #define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1
//
// #include <chrono>
// #include <iostream>
// #include <iterator>
// #include <random>
// #include <vector>
//
// // standart maps
// #include <hash_map>
// #include <map>
//
// #include "utils.h"
// #include "auxPerformance.h"
//
// // our implementation
// #include "ChainedHashMap.h"
// #include "OpenedHashMap.h"
// #include "CuckooHashMap.h"
//
// using namespace std;
// using namespace std::chrono;
//
// void getPerformanceString() {
//
//   const size_t tableSize = 10000;
//   size_t testSize, vecSize = 5000;
//   cout << "\nEnter testSize: ";
//   cin >> testSize;
//
//   vector<string> baseVec, testVec;
//   baseVec = genRandStrings(vecSize);
//   testVec = genRandStrings(testSize);
//
//   /*      map part            */
//   cout << "\n*******STD::MAP*************" << endl;
//   map<string, string> stdMap;
//   for (auto const &value : baseVec) {
//     stdMap.insert(make_pair(value, value));
//   }
//   // test inserts
//   auto start = high_resolution_clock::now();
//   for (auto const &value : testVec) {
//     stdMap.insert(make_pair(value, value));
//   }
//   auto stop = high_resolution_clock::now();
//   float duration = duration_cast<microseconds>(stop - start).count();
//   cout << "Average insert time: " << duration / testSize << " microsec" << endl;
//
//   // test search
//   map<string, string>::iterator it;
//   start = high_resolution_clock::now();
//   for (auto const &key : testVec) {
//     it = stdMap.find(key);
//   }
//   stop = high_resolution_clock::now();
//   duration = duration_cast<microseconds>(stop - start).count();
//   cout << "Average search time: " << duration / testSize << " microsec" << endl;
//   // test delete
//   start = high_resolution_clock::now();
//   for (auto const &key : testVec) {
//     stdMap.erase(key);
//   }
//   stop = high_resolution_clock::now();
//   duration = duration_cast<microseconds>(stop - start).count();
//   cout << "Average delete time: " << duration / testSize << " microsec" << endl;
//
//   /*      map part            */
//   cout << "\n*******STD::HASH_MAP*************" << endl;
//   hash_map<string, string> stdHashMap;
//   for (auto const &value : baseVec) {
//     stdHashMap.insert(make_pair(value, value));
//   }
//   // test inserts
//   start = high_resolution_clock::now();
//   for (auto const &value : testVec) {
//     stdHashMap.insert(make_pair(value, value));
//   }
//   stop = high_resolution_clock::now();
//   duration = duration_cast<microseconds>(stop - start).count();
//   cout << "Average insert time: " << duration / testSize << " microsec" << endl;
//
//   // test search
//   hash_map<string, string>::iterator hit;
//   start = high_resolution_clock::now();
//   for (auto const &key : testVec) {
//     hit = stdHashMap.find(key);
//   }
//   stop = high_resolution_clock::now();
//   duration = duration_cast<microseconds>(stop - start).count();
//   cout << "Average search time: " << duration / testSize << " microsec" << endl;
//   // test delete
//   start = high_resolution_clock::now();
//   for (auto const &key : testVec) {
//     stdHashMap.erase(key);
//   }
//   stop = high_resolution_clock::now();
//   duration = duration_cast<microseconds>(stop - start).count();
//   cout << "Average delete time: " << duration / testSize << " microsec" << endl;
//
//   /*      Chained Hash Map part            */
//   cout << "\n*****Chained Hash map*******" << endl;
//   HashMap<string, string> chainedHmap(tableSize);
//   for (auto const &value : baseVec) {
//     // cout << "[" << value << "]" << endl;
//     chainedHmap.insert(value, value);
//   }
//   auxPerformanceOperations(chainedHmap, testVec);
//
//   /*      Opened Hash Map part          */
//   cout << "\n*****Opened Hash map __LINEAR__*******" << endl;
//   OpenHashMap<string, string> openHmap(tableSize, "LINEAR");
//   for (auto const &value : baseVec) {
//     openHmap.insert(value, value);
//   }
//   // openHmap.resetCollisions();
//   auxPerformanceOperations(openHmap, testVec);
//
//   cout << "\n*****Opened Hash map __QUADRATIC__*******" << endl;
//   OpenHashMap<string, string> openHmapQdr(tableSize, "QUADRATIC");
//   for (auto const &value : baseVec) {
//     openHmapQdr.insert(value, value);
//   }
//   // openHmapQdr.resetCollisions();
//   auxPerformanceOperations(openHmapQdr, testVec);
//
//   cout << "\n*****Opened Hash map __DOUBLE__*******" << endl;
//   OpenHashMap<string, string> openHmapDbl(tableSize, "DOUBLE");
//   for (auto const &value : baseVec) {
//     openHmapDbl.insert(value, value);
//   }
//   openHmapDbl.resetCollisions();
//   auxPerformanceOperations(openHmapDbl, testVec);
//
//   /*      CoCoo Hash Map part          */
//   cout << "\n*****Cuckoo Hash map*******" << endl;
//   int counter = 0;
//   CuckooHashMap<string, string> cuckooHmap(2*tableSize, tableSize);
//   for (auto const &value : baseVec) {
//     if (counter++ % 100 == 0)
//       cout << "#";
//     cuckooHmap.insert(value, value);
//   }
//   cout<<endl;
//   auxPerformanceOperations(cuckooHmap, testVec);
//
// };
//
//
// void getPerformanceStringToFile()
// {
//   size_t tableSize;
//   size_t testSize, vecSize;
//   vector<string> baseVec, testVec;
//   string filepath = STRING_FILE;
//   vector<string> HashTableSize, DataSize;
//
//   vector<string> insertMap, insertHashMap;
//   vector<string> searchMap, searchHashMap;
//   vector<string> deleteMap, deleteHashMap;
//
//   vector<string> attemptsChained, attemptsOpened_linear, attemptsOpened_quadratic, attemptsOpened_double, attemptsCuckoo;
//
//   vector<string> insertChained, insertOpened_linear, insertOpened_quadratic, insertOpened_double, insertCuckoo;
//   vector<string> searchChained, searchOpened_linear, searchOpened_quadratic, searchOpened_double, searchCuckoo;
//   vector<string> deleteChained, deleteOpened_linear, deleteOpened_quadratic, deleteOpened_double, deleteCuckoo;
//
//   typedef HashMap <string, string> strChainedHashMap;
//   typedef OpenHashMap <string, string> strOpenedHashMap;
//   typedef CuckooHashMap <string, string> strCuckooHashMap;
//
//   cout << "\n\nProgress: ";
//   for (auto i=1; i<=ITERATIONS; ++i){
//     if (i % 10 == 0){
//       cout<<"#";
//     }
//     tableSize = STEP * i;
//     vecSize = tableSize / COEFFICIENT;
//     testSize = OPERATIONS;
//     baseVec = genRandStrings(vecSize);
//     testVec = genRandStrings(testSize);
//
//     HashTableSize.push_back(to_string(tableSize));
//     DataSize.push_back(to_string(vecSize));
//
//       /*      map part            */
//     map<string, string> stdMap;
//     for (auto const &value : baseVec) {
//       stdMap.insert(make_pair(value, value));
//     }
//     // test inserts
//     auto start = high_resolution_clock::now();
//     for (auto const &value : testVec) {
//       stdMap.insert(make_pair(value, value));
//     }
//     auto stop = high_resolution_clock::now();
//     float duration = duration_cast<microseconds>(stop - start).count();
//     insertMap.push_back(to_string(duration / testSize));
//     // test search
//     map<string, string>::iterator it;
//     start = high_resolution_clock::now();
//     for (auto const &key : testVec) {
//       it = stdMap.find(key);
//     }
//     stop = high_resolution_clock::now();
//     duration = duration_cast<microseconds>(stop - start).count();
//     searchMap.push_back(to_string(duration / testSize));
//     // test delete
//     start = high_resolution_clock::now();
//     for (auto const &key : testVec) {
//       stdMap.erase(key);
//     }
//     stop = high_resolution_clock::now();
//     duration = duration_cast<microseconds>(stop - start).count();
//     deleteMap.push_back(to_string(duration / testSize));
//
//     /*      hash_map part            */
//     hash_map<string, string> stdHashMap;
//     for (auto const &value : baseVec) {
//       // cout << "[" << value << "]" << endl;
//       stdHashMap.insert(make_pair(value, value));
//     }
//     // test inserts
//     start = high_resolution_clock::now();
//     for (auto const &value : testVec) {
//       stdHashMap.insert(make_pair(value, value));
//     }
//     stop = high_resolution_clock::now();
//     duration = duration_cast<microseconds>(stop - start).count();
//     insertHashMap.push_back(to_string(duration / testSize));
//     // test search
//     hash_map<string, string>::iterator hit;
//     start = high_resolution_clock::now();
//     for (auto const &key : testVec) {
//       hit = stdHashMap.find(key);
//     }
//     stop = high_resolution_clock::now();
//     duration = duration_cast<microseconds>(stop - start).count();
//     searchHashMap.push_back(to_string(duration / testSize));
//     // test delete
//     start = high_resolution_clock::now();
//     for (auto const &key : testVec) {
//       stdHashMap.erase(key);
//     }
//     stop = high_resolution_clock::now();
//     duration = duration_cast<microseconds>(stop - start).count();
//     deleteHashMap.push_back(to_string(duration / testSize));
//
//     strChainedHashMap hmap(tableSize);
//     for(auto const& value: baseVec){
//         hmap.insert(value, value);
//     }
//     auxPerformanceFunc<strChainedHashMap, string>(hmap, testVec, insertChained, searchChained, deleteChained, attemptsChained);
//
//     strOpenedHashMap openedHmapL(tableSize, "LINEAR");
//     for(auto const& value: baseVec){
//         openedHmapL.insert(value, value);
//     }
//     auxPerformanceFunc<strOpenedHashMap, string>(openedHmapL, testVec, insertOpened_linear, searchOpened_linear, deleteOpened_linear, attemptsOpened_linear);
//
//     strOpenedHashMap openedHmapQ(tableSize, "QUADRATIC");
//     for(auto const& value: baseVec){
//         openedHmapQ.insert(value, value);
//     }
//     auxPerformanceFunc<strOpenedHashMap, string>(openedHmapQ, testVec, insertOpened_quadratic, searchOpened_quadratic, deleteOpened_quadratic, attemptsOpened_quadratic);
//
//     strOpenedHashMap openedHmapD(tableSize, "DOUBLE");
//     for(auto const& value: baseVec){
//         openedHmapD.insert(value, value);
//     }
//     auxPerformanceFunc<strOpenedHashMap, string>(openedHmapD, testVec, insertOpened_double, searchOpened_double, deleteOpened_double, attemptsOpened_double);
//
//     strCuckooHashMap cuckooHmap(4*tableSize, tableSize);
//     for(auto const& value: baseVec){
//         cuckooHmap.insert(value, value);
//     }
//     auxPerformanceFunc<strCuckooHashMap, string>(cuckooHmap, testVec, insertCuckoo, searchCuckoo, deleteCuckoo, attemptsCuckoo);
//   }
//     vector<pair<string, vector<string>>> vals = {   {"TableSize", HashTableSize},
//                                                     {"DataSize", DataSize},
//
//                                                     {"insertStdMap",
//                                                     insertMap},
//                                                     {"searchStdMap",
//                                                     searchMap},
//                                                     {"deleteStdMap",
//                                                     deleteMap},
//
//                                                     {"insertStdHashMap",
//                                                     insertHashMap},
//                                                     {"searchStdHashMap",
//                                                     searchHashMap},
//                                                     {"deleteStdHashMap",
//                                                     deleteHashMap},
//
//                                                     {"insertChained",
//                                                     insertChained},
//                                                     {"searchChained",
//                                                     searchChained},
//                                                     {"deleteChained",
//                                                     deleteChained},
//                                                     {"attemptsChained",
//                                                     attemptsChained},
//                                                     {"insertOpened_linear",
//                                                     insertOpened_linear},
//                                                     {"searchOpened_linear",
//                                                     searchOpened_linear},
//                                                     {"deleteOpened_linear",
//                                                     deleteOpened_linear},
//
//                                                     {"insertOpened_quadratic",
//                                                     insertOpened_quadratic},
//                                                     {"searchOpened_quadratic",
//                                                     searchOpened_quadratic},
//                                                     {"deleteOpened_quadratic",
//                                                     deleteOpened_quadratic},
//                                                     {"attemptsOpened_quadratic",
//                                                     attemptsOpened_quadratic},
//
//                                                     {"insertOpened_double",
//                                                     insertOpened_double},
//                                                     {"searchOpened_double",
//                                                     searchOpened_double},
//                                                     {"deleteOpened_double",
//                                                     deleteOpened_double},
//                                                     {"attemptsOpened_double",
//                                                     attemptsOpened_double},
//
//                                                     {"insertCuckoo",
//                                                     insertCuckoo},
//                                                     {"searchCuckoo",
//                                                     searchCuckoo},
//                                                     {"deleteCuckoo",
//                                                     deleteCuckoo},
//                                                     {"attemptsCuckoo",
//                                                     attemptsCuckoo},
//                                       };
//
//     write_csv(filepath, vals);
//   };
