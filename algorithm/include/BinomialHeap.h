#pragma once
#include <iostream>
#include <list>
#include <tuple>

template <typename L> struct Node {
  std::pair<L, int> x;
  Node<L> *next, *child, *parent;
  int rank;
};

template <typename M> class BinomialHeap {
private:
  Node<M> *root = NULL;
  Node<M> *root_end = NULL;
  size_t capacity;
  size_t heap_size;
  size_t nodes = 0;
  std::vector<std::vector<Node<M> *>> heap;
  // size_t k;

public:
  BinomialHeap(size_t capacity) {
    this->heap_size = 0;
    // this->id2pos = new M[capacity];
    this->heap.resize(2 * std::log2(capacity));
    this->capacity = capacity;
    // this->k = std::log2(capacity) + 1;
  }

  void insert_pair(std::pair<M, int> x) {
    Node<M> *temp = new Node<M>;
    temp->x = x;
    temp->rank = 0;
    temp->next = NULL;
    temp->child = NULL;
    temp->parent = NULL;
    if (root == NULL) {
      root = temp;
      root_end = temp;
    } else {
      root_end->next = temp;
      root_end = temp;
    }
    nodes++;
  }

  std::pair<M, int> extract_min() {
    if (root == NULL)
      return std::make_pair((M)-1, -1);
    Node<M> **m = &root;
    for (Node<M> **p = &root; *p; p = &((*p)->next)) {
      if ((*p)->x.first < (*m)->x.first)
        m = p;
    }
    Node<M> *res = *m;
    *m = (*m)->next;
    UnionHeaps(root, res->child);
    // std::cout << "MIN BIN_HEAP: ";
    // print_heap();
    // std::cout << "\n";
    nodes--;
    return res->x;
  }

  void Append(Node<M> *&a, Node<M> *b) {
    b->next = a;
    a = b;
  }

  Node<M> *Join(Node<M> *a, Node<M> *b) {
    if (a->x.first > b->x.first)
      std::swap(a, b);
    b->parent = a;
    Append(a->child, b);
    (a->rank)++;
    return a;
  }

  void UnionHeaps(Node<M> *a, Node<M> *b) {

    if (a != NULL)
      Have(a);
    if (b != NULL)
      Have(b);
    getHeap();
    return;
  }

  void Have(Node<M> *a) {
    for (; a; a = a->next)
      heap[a->rank].push_back(a);
  }

  void getHeap() {
    Node<M> *new_root = NULL;
    Node<M> *new_root_end = NULL;
    size_t k = std::log2(nodes) + 2;
    for (int i = 0; i < k; i++) {
      // std::cout << "\nK_ITER:" << i << "\n";
      // std::cout << " VECTOR: ";
      // for (int i = 0; i < k; i++) {
      //   std::cout << i << ":" << heap[i].size() << "; ";
      // }
      // if ((int)heap[i].size() == 0)
      //   break;
      while ((int)heap[i].size() >= 2) {
        // std::cout << "\nBEFORE HEAP [i] SIZE: " << (int)heap[i].size() << "
        // ";
        heap[i + 1].push_back(Join(heap[i][(int)heap[i].size() - 1],
                                   heap[i][(int)heap[i].size() - 2]));
        heap[i].pop_back();
        heap[i].pop_back();
        // std::cout << "AFTER HEAP [i] SIZE: " << (int)heap[i].size() << "\n";
      }
      if ((int)heap[i].size() == 1) {
        heap[i][0]->next = NULL;
        if (new_root == NULL) {
          new_root = heap[i][0];
          new_root_end = heap[i][0];
        } else {
          new_root_end->next = heap[i][0];
          new_root_end = heap[i][0];
        }
        heap[i].pop_back();
      }
    }

    this->root = new_root;
    this->root_end = new_root_end;
    return;
  }

  void print_heap() {
    std::cout << "ROOTS: ";
    for (Node<M> **p = &root; *p; p = &((*p)->next)) {
      std::cout << (*p)->x.first << " " << (*p)->x.second << " "
                << "rnk(" << (*p)->rank + 1 << ") ";
    }
    std::cout << " ROOT END: " << root_end->x.first << " rnk("
              << root_end->rank + 1 << ") ";
  }

  void decrease_key(int id, M new_val) {
    Node<M> *found_node = findNode(id);

    if (found_node == NULL)
      return;

    found_node->x.first = new_val;
    emersion(found_node);
  }

  void emersion(Node<M> *node) {
    Node<M> *parent = node->parent;
    if (parent == NULL)
      return;
    if (parent->x.first > node->x.first) {
      swap(parent->x, node->x);
      // std::pair<M, int> tmp;
      // tmp = node->x;
      // node->x = parent->x;
      // parent->x = tmp;
      emersion(parent);
    }
  }

  Node<M> *findNode(int id) { return recursivefindNode(root, id); }

  Node<M> *recursivefindNode(Node<M> *h, int id) {
    if (h == NULL)
      return NULL;

    if (h->x.second == id)
      return h;

    Node<M> *res = recursivefindNode(h->child, id);
    if (res != NULL)
      return res;

    return recursivefindNode(h->next, id);
  }

  size_t size() {
    if (root != NULL)
      return 1;
    else
      return 0;
  }
};
