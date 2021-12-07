// #pragma once
// #include <iostream>
// #include <iterator>
// #include <random>
// #include <vector>
//
// #include "ChainedHashMap.h"
// #include "OpenedHashMap.h"
// #include "CuckooHashMap.h"
//
// typedef OpenHashMap<int, int> intOpenHashMap;
//
// template<typename L>
// void stressTester(size_t stressSize){
//
//   size_t tableSize;
//   size_t testSize, vecSize;
//   std::vector<int> baseVec, testVec;
//   int value;
//   bool result, result1, result2;
//
//   for (auto i=0; i < stressSize; ++i){
//     if (i % 100 == 0)
//     {
//       std::cout << "#";
//     }
//     tableSize = genRandomUid(200, 5500);
//     vecSize = tableSize / COEFFICIENT;
//     testSize = OPERATIONS;
//     baseVec = genRandVec(vecSize, 0, 100000);
//     testVec = genRandVec(testSize, 0, 100000);
//
//     L hashMap(tableSize);
//     bool testInsert = false;
//     for (auto const &value : baseVec) {
//       testInsert = hashMap.insert(value, value);
//       if (!testInsert) {
//         std::cout << "INSERT FAILED" << std::endl;
//         return;
//       }
//     }
//     // test 1
//     unsigned int testNumber = genRandomUid(0, 100000);
//     result = hashMap.insert(testNumber, testNumber);
//     if (!result){
//       std::cout<<"TEST 1 is FAILED (itr: "<<i << " )"<<std::endl;
//       return;
//     }
//
//     // test 2
//     int value, svalue = baseVec[genRandomUid(0, vecSize-1)];
//     result = hashMap.search(svalue, value);
//     result = result && (value == svalue);
//     if (!result){
//       std::cout<<"TEST 2 is FAILED (itr: "<<i << " )"<<std::endl;
//       return;
//     }
//
//     // test 4
//     svalue = baseVec[genRandomUid(0, vecSize-1)];
//     result1 = hashMap.search(svalue, value);
//     hashMap.remove(svalue);
//     result = result1 && !(hashMap.search(svalue, value));
//     if (!result){
//       std::cout<<"TEST 4 is FAILED (itr: "<<i << " )"<<std::endl;
//       return;
//     }
//   }
//     std::cout<<" SUCCESS\n";
// };
//
//
// template<typename D>
// void stressTesterOpened(size_t stressSize, std::string hashType)
// {
//
//   size_t tableSize;
//   size_t testSize, vecSize;
//   std::vector<int> baseVec, testVec;
//   int value;
//   bool result, result1, result2;
//
//   for (auto i=0; i < stressSize; ++i){
//     if (i % 100 == 0)
//     {
//       std::cout << "#";
//     }
//     tableSize = genRandomUid(400, 5000);
//     vecSize = tableSize / 2;
//     testSize = OPERATIONS;
//     baseVec = genRandVec(vecSize, 0, 100000);
//     testVec = genRandVec(testSize, 0, 100000);
//
//     D hashMap(tableSize, hashType);
//     bool testInsert = false;
//     for (auto const &value : baseVec) {
//       testInsert = hashMap.insert(value, value);
//       if(!testInsert){
//         std::cout << "INSERT FAILED (itr: "<<i << " )"<< std::endl;
//         return;
//       }
//     }
//     // test 1
//     unsigned int testNumber = genRandomUid(0, 100000);
//     result = hashMap.insert(testNumber, testNumber);
//     if (!result){
//       std::cout<<"TEST 1 is FAILED (itr: "<<i << " )"<<std::endl;
//       return;
//     }
//
//     // test 2
//     int value, svalue = baseVec[genRandomUid(0, vecSize-1)];
//     result = hashMap.search(svalue, value);
//     result = result && (value == svalue);
//     if (!result){
//       std::cout<<"TEST 2 is FAILED (itr: "<<i << " )"<<std::endl;
//       return;
//     }
//
//     // test 3
//     value = 0;
//     // svalue = baseVec[genRandomUid(0, vecSize-1)];
//     result1 = hashMap.search(testNumber, value);
//     hashMap.remove(testNumber);
//     result = result1 && !(hashMap.search(testNumber, value));
//     if (!result){
//       std::cout<<"\nTEST 3 is FAILED (itr: "<<i << " )";
//       return;
//     }
//   }
//     std::cout<<" SUCCESS\n";
// };
//
//
// template<typename G>
// void stressTesterCuckoo(size_t stressSize, unsigned int coef)
// {
//
//   size_t tableSize;
//   size_t testSize, vecSize;
//   std::vector<int> baseVec, testVec;
//   int value;
//   bool result, result1, result2;
//
//   for (auto i=0; i < stressSize; ++i){
//     if (i % 100 == 0)
//     {
//       std::cout << "#";
//     }
//     tableSize = genRandomUid(400, 5000);
//     vecSize = tableSize / 2;
//     testSize = OPERATIONS;
//     baseVec = genRandVec(vecSize, 0, 100000);
//     testVec = genRandVec(testSize, 0, 100000);
//
//     G hashMap(coef*tableSize, tableSize, 2);
//     bool testInsert = false;
//     for (auto const &value : baseVec) {
//       testInsert = hashMap.insert(value, value);
//       if(!testInsert){
//         std::cout << "INSERT FAILED (itr: "<<i << " )"<< std::endl;
//         return;
//       }
//     }
//     // test 1
//     unsigned int testNumber = genRandomUid(0, 100000);
//     result = hashMap.insert(testNumber, testNumber);
//     if (!result){
//       std::cout<<"TEST 1 is FAILED (itr: "<<i << " )"<<std::endl;
//       return;
//     }
//
//     // test 2
//     int value, svalue = baseVec[genRandomUid(0, vecSize-1)];
//     result = hashMap.search(svalue, value);
//     result = result && (value == svalue);
//     if (!result){
//       std::cout<<"TEST 2 is FAILED (itr: "<<i << " )"<<std::endl;
//       return;
//     }
//
//     // test 3
//     value = 0;
//     // svalue = baseVec[genRandomUid(0, vecSize-1)];
//     result1 = hashMap.search(testNumber, value);
//     hashMap.remove(testNumber);
//     result = result1 && !(hashMap.search(testNumber, value));
//     if (!result){
//       std::cout<<"\nTEST 3 is FAILED (itr: "<<i << " )";
//       return;
//     }
//   }
//     std::cout<<" SUCCESS\n";
// };
