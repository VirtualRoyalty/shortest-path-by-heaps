#pragma once
#include <iostream>
#include <tuple>
#define MAX_NUM 1000000

template <typename M> class Dheap {
private:
  size_t D;
  std::vector<std::pair<M, int>> heap;
  int *id2pos;
  size_t capacity;
  size_t heap_size;

public:
  // Dheap(M heap[], size_t capacity, size_t D) {
  Dheap(size_t capacity, size_t D) {
    this->heap_size = 0;
    this->id2pos = new M[capacity];
    // this->heap = heap;
    this->capacity = capacity;
    this->D = D;
  }

  int get_left_child(int node) { return (D * node + 1); }

  int get_right_child(int node) { return (D * node + D); }

  int get_parent(int node) {
    if (node == 0)
      return -1;
    return (node - 1) % D;
  }

  int get_min_child(int node) {
    int left_child = get_left_child(node);
    int right_child = get_right_child(node);
    // std::cout << "  ~~ left: " << left_child << " right: " << right_child <<
    int smallest = node;
    // if (left_child >= capacity) {
    if (left_child > heap_size) {
      // std::cout << "    left dont exists, heap size: " << heap_size <<
      return -1;
    }
    for (int i = left_child; i <= right_child; i++) {
      // if (i < capacity && heap[smallest] > heap[i])
      if (i <= heap_size && heap[smallest].first > heap[i].first) {
        smallest = i;
      }
    }
    return smallest;
  }

  void dive(int node) {
    // std::cout << "DIVE NODE: " << node;
    int smallest = get_min_child(node);
    if (smallest == -1)
      return;
    if (smallest != node) {
      // std::cout << std::endl << "SWAP! " << node <<" and " << smallest <<
      std::swap(heap[node], heap[smallest]);
      std::swap(id2pos[heap[node].second], id2pos[heap[smallest].second]);
      dive(smallest);
    }
  }

  void emersion(int node) {
    // std::cout << "EMERSE NODE: " << node;
    int parent = get_parent(node);
    if (parent == -1)
      return;
    if (heap[parent].first > heap[node].first) {
      std::swap(heap[node], heap[parent]);
      std::swap(id2pos[heap[node].second], id2pos[heap[parent].second]);
      emersion(parent);
    }
  }

  void insert_pair(std::pair<M, int> new_pair) {
    if (heap_size == capacity) {
      std::cout << "\nOverflow: Could not insertKey\n";
      return;
    }
    heap_size++;
    int insert_place = heap_size - 1;
    heap.push_back(new_pair);
    id2pos[new_pair.second] = insert_place;
    emersion(insert_place);
  }

  std::pair<M, int> extract_min() {
    if (heap_size <= 0) {
      return std::make_pair((M)-1, -1);
    }
    if (heap_size == 1) {
      heap_size--;
      return heap[0];
    }
    std::pair<M, int> root = heap[0];
    heap[0] = heap[heap_size - 1];
    heap_size--;
    // capacity--;
    dive(0);
    return root;
  }

  void decrease_key(int id, M new_val) {
    heap[id2pos[id]] = std::make_pair(new_val, id);
    emersion(id2pos[id]);
  }

  size_t size() { return heap_size; }

  void print_heap() {
    std::cout << std::endl << "HEAP: ";
    for (int i = 0; i < heap_size; i++) {
      std::cout << " (" << heap[i].first << ",  " << heap[i].second << ") ";
    }
    std::cout << std::endl << "POS: ";
    for (int i = 0; i < heap_size; i++) {
      std::cout << " (" << i << " " << id2pos[i] << ") ";
    }
    std::cout << std::endl;
  }
};
