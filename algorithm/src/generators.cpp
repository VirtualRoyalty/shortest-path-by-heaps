#include <algorithm>
#include <array>
#include <cstring>
#include <functional>
#include <random>
#include <sstream>   //
#include <stdexcept> // std::runtime_error
#include <string>
#include <utility> // std::pair
#include <vector>

int genRandomUid(unsigned int a, unsigned int b) {
  std::random_device rd;
  std::mt19937 mersenne(
      rd()); // инициализируем Вихрь Мерсенна случайным стартовым числом
  std::uniform_int_distribution<int> uid(a, b);
  return uid(mersenne);
};

std::vector<int> genRandVec(size_t N, unsigned int a, unsigned int b) {

  std::vector<int> randVec(N);
  // std::generate(randVec.begin(), randVec.end(), genRandomUid(a,b));
  for (auto i = 0; i < randVec.size(); ++i) {
    randVec[i] = genRandomUid(a, b);
  }

  return randVec;
};

std::string genRandString(size_t stringLen) {
  std::string resultStr;
  static std::random_device rd;
  static std::mt19937 mt(rd());
  static std::uniform_int_distribution<int> dist(-25, 25);
  for (int i = 0; i < stringLen; ++i) {
    resultStr += ('a' + dist(mt));
  }
  return resultStr;
};

std::vector<std::string> genRandStrings(size_t N) {
  std::vector<std::string> randVec(N);
  static std::random_device rd;
  static std::mt19937 mt(rd());
  static std::uniform_int_distribution<int> dist(4, 20);
  for (auto i = 0; i < randVec.size(); ++i)
    randVec[i] = genRandString(dist(mt));
  return randVec;
};
