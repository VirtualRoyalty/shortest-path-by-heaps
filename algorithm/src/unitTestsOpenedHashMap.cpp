// #include <iostream>
// #include <iterator>
// #include <map>
// #include <random>
// #include <string>
// #include <vector>
//
// #include "utils.h"
// #include "auxStress.h"
// #include "OpenedHashMap.h"
//
//
// std::map<bool, std::string> oresult = {{false, "FAILED"}, {true, "PASSED"}};
//
//
// void unitTestOpenHashMap() {
//   std::cout << "\n***Unit tets: Opened Hash map __LINEAR__****";
//   // test 1
//   std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   const size_t tableSize = 9;
//   OpenHashMap<int, int> openedHmap(tableSize, "LINEAR");
//   for (auto const &value : v) {
//     openedHmap.insert(value, value);
//   }
//   bool result = openedHmap.insert(11, 11);
//   std::cout << "\nTest 1 is " << oresult[!result];
//
//   // test 2
//   v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   OpenHashMap<int, int> openedHmap2(tableSize, "LINEAR");
//   for (auto const &value : v) {
//     openedHmap2.insert(value, value);
//   }
//   int value;
//   result = openedHmap2.search(3, value);
//   result = result && (value == 3);
//   std::cout << "\nTest 2 is " << oresult[result];
//
//   // test 3
//   v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   OpenHashMap<int, int> openedHmap3(tableSize, "LINEAR");
//   for (auto const &value : v) {
//     openedHmap3.insert(value, value);
//   }
//   result = openedHmap3.search(7, value);
//   result = result && (value == 7);
//   std::cout << "\nTest 3 is " << oresult[result];
//
//   // test 4
//   v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   OpenHashMap<int, int> openedHmap4(tableSize, "LINEAR");
//   for (auto const &value : v) {
//     openedHmap4.insert(value, value);
//   }
//   bool result1 = openedHmap4.search(5, value);
//   openedHmap4.remove(5);
//   result = result1 && !(openedHmap4.search(5, value));
//   std::cout << "\nTest 4 is " << oresult[result];
//
//   std::cout << "\n\n***Unit tets: Opened Hash map __QUADRATIC__***"
//             << std::endl;
//   // test 1
//   OpenHashMap<int, int> openedHmap5(tableSize, "QUADRATIC");
//   for (auto const &value : v) {
//     openedHmap5.insert(value, value);
//   }
//   result = openedHmap.insert(11, 11);
//   std::cout << "\nTest 1 is " << oresult[!result];
//
//   // test 2
//   v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   OpenHashMap<int, int> openedHmap6(tableSize, "QUADRATIC");
//   for (auto const &value : v) {
//     openedHmap6.insert(value, value);
//   }
//   result = openedHmap6.search(3, value);
//   result = result && (value == 3);
//   std::cout << "\nTest 2 is " << oresult[result];
//
//   // test 3
//   v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   OpenHashMap<int, int> openedHmap7(tableSize, "QUADRATIC");
//   for (auto const &value : v) {
//     openedHmap7.insert(value, value);
//   }
//   result = openedHmap7.search(7, value);
//   result = result && (value == 7);
//   std::cout << "\nTest 3 is " << oresult[result];
//
//   // test 4
//   v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   OpenHashMap<int, int> openedHmap8(tableSize, "QUADRATIC");
//   // openedHmap8.displayHash();
//   for (auto const &value : v) {
//     openedHmap8.insert(value, value);
//   }
//   // openedHmap8.displayHash();
//   result1 = openedHmap8.search(5, value);
//   openedHmap8.remove(5);
//   // openedHmap8.displayHash();
//   result = result1 && !(openedHmap8.search(5, value));
//   std::cout << "\nTest 4 is " << oresult[result];
//   // << " searchYES " << result1 << " searchNO " << openedHmap8.search(5,
//   // value);
//
//   std::cout << "\n\n***Unit tets: Opened Hash map __DOUBLE__***"
//             << std::endl;
//   // test 1
//   OpenHashMap<int, int> openedHmap9(tableSize, "DOUBLE");
//   for (auto const &value : v) {
//     openedHmap9.insert(value, value);
//   }
//   result = openedHmap9.insert(11, 11);
//   std::cout << "\nTest 1 is " << oresult[!result];
//
//   // test 2
//   v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   OpenHashMap<int, int> openedHmap10(tableSize, "QUADRATIC");
//   for (auto const &value : v) {
//     openedHmap10.insert(value, value);
//   }
//   result = openedHmap10.search(3, value);
//   result = result && (value == 3);
//   std::cout << "\nTest 2 is " << oresult[result];
//
//   // test 3
//   v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   OpenHashMap<int, int> openedHmap11(tableSize, "QUADRATIC");
//   for (auto const &value : v) {
//     openedHmap11.insert(value, value);
//   }
//   result = openedHmap11.search(7, value);
//   result = result && (value == 7);
//   std::cout << "\nTest 3 is " << oresult[result];
//
//   // test 4
//   v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   OpenHashMap<int, int> openedHmap12(tableSize, "QUADRATIC");
//   // openedHmap12.displayHash();
//   for (auto const &value : v) {
//     openedHmap12.insert(value, value);
//   }
//   // openedHmap12.displayHash();
//   result1 = openedHmap12.search(5, value);
//   openedHmap12.remove(5);
//   // openedHmap8.displayHash();
//   result = result1 && !(openedHmap12.search(5, value));
//   std::cout << "\nTest 4 is " << oresult[result];
//   //<< " searchYES " << result1 << " searchNO " << openedHmap12.search(5,
//   // value);
//
//   std::cout << "\n\n***Unit tets: Opened Hash map __LINEAR__ (string)***"
//             << std::endl;
//   // test 1
//   std::vector<std::string> vs = {"100", "2111", "333", "asf4", "555", "654", "777", "888", "987", "10000"};
//   OpenHashMap<std::string, std::string> openedHmapStr(tableSize, "LINEAR");
//   for (auto const &value : vs) {
//     openedHmapStr.insert(value, value);
//   }
//   bool resultStr = openedHmapStr.insert("extra", "extra");
//   std::cout << "\nTest 1 is " << oresult[!resultStr];
//   // test 2
//   OpenHashMap<std::string, std::string> openedHmapStr1(tableSize, "LINEAR");
//   for (auto const &value : vs) {
//     openedHmapStr1.insert(value, value);
//   }
//   std::string svalue;
//   resultStr = openedHmapStr1.search("333", svalue);
//   resultStr = resultStr && (svalue == "333");
//   std::cout << "\nTest 2 is " << oresult[resultStr];
//
//   // test 3
//   OpenHashMap<std::string, std::string> openedHmapStr2(tableSize, "LINEAR");
//   for (auto const &value : vs) {
//     openedHmapStr2.insert(value, value);
//   }
//   resultStr = openedHmapStr2.search("777", svalue);
//   resultStr = resultStr && (svalue == "777");
//   std::cout << "\nTest 3 is " << oresult[resultStr];
//
//   // test 4
//   OpenHashMap<std::string, std::string> openedHmapStr3(tableSize, "LINEAR");
//   for (auto const &value : vs) {
//     openedHmapStr3.insert(value, value);
//   }
//   result1 = openedHmapStr3.search("777", svalue);
//   openedHmapStr3.remove("777");
//   resultStr = result1 && !(openedHmapStr3.search("777", svalue));
//   std::cout << "\nTest 4 is " << oresult[resultStr];
//
//   std::cout << "\n\n***Unit tets: Opened Hash map __QUADRATIC__ (string)***"
//             << std::endl;
//   // test 1
//   OpenHashMap<std::string, std::string> openedHmapStr4(tableSize, "QUADRATIC");
//   for (auto const &value : vs) {
//     openedHmapStr4.insert(value, value);
//   }
//   resultStr = openedHmapStr4.insert("extra", "extra");
//   std::cout << "\nTest 1 is " << oresult[!resultStr];
//   // test 2
//   OpenHashMap<std::string, std::string> openedHmapStr5(tableSize, "QUADRATIC");
//   for (auto const &value : vs) {
//     openedHmapStr5.insert(value, value);
//   }
//   svalue;
//   resultStr = openedHmapStr5.search("333", svalue);
//   resultStr = resultStr && (svalue == "333");
//   std::cout << "\nTest 2 is " << oresult[resultStr];
//
//   // test 3
//   OpenHashMap<std::string, std::string> openedHmapStr6(tableSize, "QUADRATIC");
//   for (auto const &value : vs) {
//     openedHmapStr6.insert(value, value);
//   }
//   resultStr = openedHmapStr6.search("777", svalue);
//   resultStr = resultStr && (svalue == "777");
//   std::cout << "\nTest 3 is " << oresult[resultStr];
//
//   // test 4
//   OpenHashMap<std::string, std::string> openedHmapStr7(tableSize, "QUADRATIC");
//   for (auto const &value : vs) {
//     openedHmapStr7.insert(value, value);
//   }
//   result1 = openedHmapStr7.search("777", svalue);
//   openedHmapStr7.remove("777");
//   resultStr = result1 && !(openedHmapStr7.search("777", svalue));
//   std::cout << "\nTest 4 is " << oresult[resultStr];
//
//   std::cout << "\n\n***Unit tets: Opened Hash map __DOUBLE__ (string)***"
//             << std::endl;
//   // test 1
//   OpenHashMap<std::string, std::string> openedHmapStr8(tableSize, "DOUBLE");
//   for (auto const &value : vs) {
//     openedHmapStr8.insert(value, value);
//   }
//   resultStr = openedHmapStr8.insert("extra", "extra");
//   std::cout << "\nTest 1 is " << oresult[!resultStr];
//   // test 2
//   OpenHashMap<std::string, std::string> openedHmapStr9(tableSize, "DOUBLE");
//   for (auto const &value : vs) {
//     openedHmapStr9.insert(value, value);
//   }
//   resultStr = openedHmapStr9.search("333", svalue);
//   resultStr = resultStr && (svalue == "333");
//   std::cout << "\nTest 2 is " << oresult[resultStr];
//
//   // test 3
//   OpenHashMap<std::string, std::string> openedHmapStr10(tableSize, "DOUBLE");
//   for (auto const &value : vs) {
//     openedHmapStr10.insert(value, value);
//   }
//   resultStr = openedHmapStr10.search("777", svalue);
//   resultStr = resultStr && (svalue == "777");
//   std::cout << "\nTest 3 is " << oresult[resultStr];
//
//   // test 4
//   OpenHashMap<std::string, std::string> openedHmapStr11(tableSize, "DOUBLE");
//   for (auto const &value : vs) {
//     openedHmapStr11.insert(value, value);
//   }
//   std::string newSvalue;
//   result1 = openedHmapStr11.search("777", newSvalue);
//   openedHmapStr11.remove("777");
//   resultStr = result1 && !(openedHmapStr11.search("777", newSvalue));
//   std::cout << "\nTest 4 is " << oresult[resultStr];
// };
//
//
// void stressTestOpenHashMap() {
//   size_t stressSize = STRESS_SIZE;
//   std::cout << "\n\n**Stress tets: Opened Hash map __LINEAR__**"<< std::endl;
//   typedef OpenHashMap<int, int> intOpenHashMap;
//   stressTesterOpened<intOpenHashMap>(stressSize, "LINEAR");
//
//   std::cout << "\n\n**Stress tets: Opened Hash map __QUADRATIC__**"<< std::endl;
//   stressTesterOpened<intOpenHashMap>(stressSize, "QUADRATIC");
//
//   std::cout << "\n\n**Stress tets: Opened Hash map __DOUBLE__**"<< std::endl;
//   stressTesterOpened<intOpenHashMap>(stressSize, "DOUBLE");
//
// };
