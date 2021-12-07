// #include <iostream>
// #include <iterator>
// #include <map>
// #include <random>
// #include <string>
// #include <vector>
//
// #include "utils.h"
// #include "auxStress.h"
// #include "CuckooHashMap.h"
//
//
// std::map<bool, std::string> uresult = {{false, "FAILED"}, {true, "PASSED"}};
//
//
// void unitTestCuckooHashMap() {
//
//   std::cout << "\n****Unit tets: Cuckoo Hash map****" << std::endl;
//
//   // test 1
//   std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   const size_t tableSize = 9;
//   CuckooHashMap<int, int> hmap(4*tableSize, tableSize, 2);
//   for (auto const &value : v) {
//     hmap.insert(value, value);
//   }
//   bool result = hmap.insert(11, 11);
//   std::cout << "\nTest 1 (k = 1) is " << uresult[result];
//
//   // test 2
//   v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   CuckooHashMap<int, int> hmap2(4*tableSize, tableSize, 2);
//   for (auto const &value : v) {
//     hmap2.insert(value, value);
//   }
//   int value;
//   result = hmap2.search(3, value);
//   result = result && (value == 3);
//   std::cout << "\nTest 2 (k = 2) is " << uresult[result];
//
//   // test 3
//   v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   CuckooHashMap<int, int> hmap3(4*tableSize, tableSize, 3);
//   for (auto const &value : v) {
//     hmap3.insert(value, value);
//   }
//   result = hmap3.search(7, value);
//   result = result && (value == 7);
//   std::cout << "\nTest 3 (k = 3) is " << uresult[result];
//
//   // test 4
//   v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   CuckooHashMap<int, int> hmap4(4*tableSize, tableSize, 4);
//   for (auto const &value : v) {
//     hmap4.insert(value, value);
//   }
//   bool result1 = hmap4.search(5, value);
//   hmap4.remove(5);
//   result = result1 && !(hmap4.search(5, value));
//   std::cout << "\nTest 4 (k = 4) is " << uresult[result];
//
//   std::cout << "\n\n****Unit tets: Cuckoo Hash map (string)***" << std::endl;
//   // test 1
//   std::vector<std::string> vs = {"100", "2111", "333", "asf4", "555", "654", "777", "888", "987", "10000"};
//   CuckooHashMap<std::string, std::string> hmapStr(4*tableSize, tableSize);
//   for (auto const &value : vs) {
//     hmapStr.insert(value, value);
//   }
//   bool resultStr = hmapStr.insert("extra", "extra");
//   std::cout << "\nTest 1 is " << uresult[resultStr];
//   // test 2
//   CuckooHashMap<std::string, std::string> hmapStr1(4*tableSize, tableSize);
//   for (auto const &value : vs) {
//     hmapStr1.insert(value, value);
//   }
//   std::string svalue;
//   resultStr = hmapStr1.search("333", svalue);
//   resultStr = resultStr && (svalue == "333");
//   std::cout << "\nTest 2 is " << uresult[resultStr];
//   //
//   // test 3
//   CuckooHashMap<std::string, std::string> hmapStr2(4*tableSize, tableSize);
//   for (auto const &value : vs) {
//     hmapStr2.insert(value, value);
//   }
//   resultStr = hmapStr2.search("777", svalue);
//   resultStr = resultStr && (svalue == "777");
//   std::cout << "\nTest 3 is " << uresult[resultStr];
//
//   // test 4
//   CuckooHashMap<std::string, std::string> hmapStr3(4*tableSize, tableSize);
//   for (auto const &value : vs) {
//     hmapStr3.insert(value, value);
//   }
//   result1 = hmapStr3.search("777", svalue);
//   hmapStr3.remove("777");
//   resultStr = result1 && !(hmapStr3.search("777", svalue));
//   std::cout << "\nTest 4 is " << uresult[resultStr];
//   std::cout << std::endl;
// };
//
//
// void stressTestCuckooHashMap() {
//     size_t stressSize = STRESS_SIZE;
//     std::cout << "\n\n**Stress tets: Cuckoo Hash Map**"<< std::endl;
//     typedef CuckooHashMap<int, int> inCuckooHashMap;
//     stressTesterCuckoo<inCuckooHashMap>(stressSize, 4);
//   };
