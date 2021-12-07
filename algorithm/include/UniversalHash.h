#pragma once
#include <math.h>
#include <random>
#include <string>

template <typename K> class KeyHash {
private:
  size_t tableSize;

public:
  KeyHash(size_t tableSize) : tableSize(tableSize) {}

  unsigned int operator[](const K &key) const {
    return (key) % this->tableSize;
  }
};

template <> class KeyHash<int> {
private:
  size_t tableSize;
  int k = -1;
  unsigned int a, b;
  unsigned int prime = 150001;
  std::vector<int> a_array;
public:
  KeyHash(size_t tableSize) {
    this->tableSize = tableSize;
    std::random_device randDev;
    std::mt19937 mers(randDev());
    std::uniform_int_distribution<int> a_uid(1, prime - 1);
    std::uniform_int_distribution<int> b_uid(0, prime - 1);
    this->a = a_uid(mers);
    this->b = b_uid(mers);
  }
  KeyHash(size_t tableSize, int k) {
    this->k = k;
    this->tableSize = tableSize;
    std::random_device randDev;
    std::mt19937 mers(randDev());
    std::uniform_int_distribution<int> a_uid(1, prime - 1);
    std::uniform_int_distribution<int> b_uid(0, prime - 1);
    for (int i = 0; i < k; i++) {
        this->a_array.push_back(a_uid(mers));
    }
    this->b = b_uid(mers);
  }
  unsigned int operator[](const int &key) const {
    unsigned int l = 0;
    if (k == -1) {
        l = a * key + b;
    } else {
        for (int i = 0; i < k; i++) {
            l = l + this->a_array[i] * pow(key, i);
        }
        l = l + this->b;
    }
    if (l >= tableSize) {
        l = (l >= prime) ? l % prime : l;
        return (l >= tableSize) ? (l % tableSize) : l;
    } else {
        return l;
    }
}
};

template <> class KeyHash<std::string> {
private:
  size_t tableSize;
public:
  KeyHash(size_t tableSize) {
    this->tableSize = tableSize;
    std::random_device randDev;
  }
  unsigned int operator[](const std::string key) const {
    unsigned int hkey = 5381;
    for (auto i = 0; i < key.size(); ++i) {
      hkey = ((hkey << 5)+hkey) + key[i];
    }
    return (hkey >= tableSize) ? hkey % tableSize : hkey;
  }
};
