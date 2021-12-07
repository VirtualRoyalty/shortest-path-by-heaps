#pragma once
#include <iostream>
#include <string>

template <typename L> class VComparator {
public:
  VComparator(){};
  bool compare(L a, L b) const { return a == b; }
};

template <> class VComparator<const int *> {
public:
  VComparator(){};
  bool compare(const int *a, const int *b) const { return a == b; }
};

template <> class VComparator<std::vector<int>> {
public:
  VComparator(){};
  bool compare(std::vector<int> a, std::vector<int> b) {
    if (a.size() != b.size())
      return false;
    for (auto i = 0; i < a.size(); i++) {
      if (a[i] != b[i])
        return false;
    }
    return true;
  }
};

template <> class VComparator<std::string> {
public:
  VComparator(){};
  bool compare(std::string a, std::string b) { return a == b; }
};
