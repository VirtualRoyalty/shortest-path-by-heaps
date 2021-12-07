#pragma once
#include <chrono>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>


template<typename S, typename K>
void auxPerformanceFunc(S &hashMap, std::vector<K> &testVec,
                        std::vector<std::string> &insertVec,
                        std::vector<std::string> &searchVec,
                        std::vector<std::string> &deleteVec,
                        std::vector<std::string> &attemptVec){

  size_t testSize = testVec.size();
  hashMap.resetCollisions();
  // test inserts
  auto start = high_resolution_clock::now();
  for(auto const& value: testVec){
      hashMap.insert(value, value);
  }
  auto stop = high_resolution_clock::now();
  float duration = duration_cast<microseconds>(stop - start).count();
  insertVec.push_back(to_string(duration / testSize));

  // test search
  K value;
  start = high_resolution_clock::now();
  for(auto const& key: testVec){
    hashMap.search(key, value);
  }
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start).count();
  searchVec.push_back(to_string(duration / testSize));

  // test delete
  start = high_resolution_clock::now();
  for(auto const& key: testVec){
    hashMap.remove(key);
  }
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start).count();
  deleteVec.push_back(to_string(duration / testSize));
  attemptVec.push_back(to_string((float)hashMap.getNcollisions() / (testSize * 3)));
};


template<typename S, typename K>
void auxPerformanceOperations(S &hashMap, std::vector<K> &testVec){

  size_t testSize = testVec.size();
  // test inserts
  auto start = high_resolution_clock::now();
  for (auto const &value : testVec) {
    hashMap.insert(value, value);
  }
  auto stop = high_resolution_clock::now();
  float duration = duration_cast<microseconds>(stop - start).count();
  cout << "Average insert time: " << duration / testSize << " microsec" << endl;
  // test search
  K value;
  start = high_resolution_clock::now();
  for (auto const &key : testVec) {
    hashMap.search(key, value);
  }
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start).count();
  cout << "Average search time: " << duration / testSize << " microsec" << endl;
  // test delete
  start = high_resolution_clock::now();
  for (auto const &key : testVec) {
    hashMap.remove(key);
  }
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start).count();
  cout << "Average delete time: " << duration / testSize << " microsec" << endl;
  // cout << "N attempts per operation: " << hashMap.getNcollisions() / (testSize * 3) << endl;
};
