#pragma once
#include <iostream>
#include <list>
#include <tuple>

struct Node {
  std::pair<float, int> x;
  Node *next, *child, *parent;
  int rank;
};

class BinomialHeap {
private:
  Node *root = NULL;
  Node *root_end = NULL;
  size_t capacity;
  size_t heap_size;
  std::vector<std::vector<Node *>> heap;
  size_t k;

public:
  BinomialHeap(size_t capacity) {
    this->heap_size = 0;
    // this->id2pos = new M[capacity];
    this->heap.resize(capacity);
    this->capacity = capacity;
    this->k = std::log2(capacity) + 1;
  }

  void Append(Node *&a, Node *b) {
    b->next = a;
    a = b;
  }

  Node *Join(Node *a, Node *b) {
    if (a->x.first > b->x.first)
      std::swap(a, b);
    // std::cout << "\n-.-.-.-.-JOIN " << a->x << " & " << b->x << "-.-.-.-\n";
    b->parent = a;
    Append(a->child, b);
    (a->rank)++;
    return a;
  }

  std::pair<float, int> extract_min() {
    if (root == NULL)
      return std::make_pair((float)-1, -1);
    Node **m = &root;
    for (Node **p = &root; *p; p = &((*p)->next)) {
      if ((*p)->x.first < (*m)->x.first)
        m = p;
    }
    Node *res = *m;
    *m = (*m)->next;
    UnionHeaps(root, res->child);
    // std::cout << "MIN BIN_HEAP: ";
    // print_heap();
    // std::cout << "\n";
    return res->x;
  }

  void UnionHeaps(Node *a, Node *b) {
    // if (a == NULL || b == NULL)
    //   return getHeap();
    if (a != NULL)
      Have(a);
    if (b != NULL)
      Have(b);
    getHeap();
    return;
  }

  void Have(Node *a) {
    for (; a; a = a->next)
      heap[a->rank].push_back(a);
  }

  void insert_pair(std::pair<float, int> x) {

    Node *temp = new Node;
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
  }

  void getHeap() {
    Node *new_root = NULL;
    Node *new_root_end = NULL;
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
          // new_root->next = heap[i][0];
        } else {
          new_root_end->next = heap[i][0];
          new_root_end = heap[i][0];
        }
        heap[i].pop_back();
      }
    }

    this->root = new_root;
    this->root_end = new_root_end;
    // std::cout << "\ngetHeap end\n";
    // std::cout << "NEW ROOT " << this->root->x << " NEW END "
    //           << this->root_end->x << " \n";
    return;
  }

  void print_heap() {
    std::cout << "ROOTS: ";
    for (Node **p = &root; *p; p = &((*p)->next)) {
      std::cout << (*p)->x.first << " " << (*p)->x.second << " "
                << "rnk(" << (*p)->rank + 1 << ") ";
    }
    std::cout << " ROOT END: " << root_end->x.first << " rnk("
              << root_end->rank + 1 << ") ";

    // std::cout << std::endl << "POS: ";
    // for (int i = 0; i < heap_size; i++) {
    //   std::cout << " (" << i << " " << id2pos[i] << ") ";
    // }
    // std::cout << std::endl;
  }

  void decrease_key(int id, float new_val) {
    Node *found_node = findNode(id);

    if (found_node == NULL)
      return;

    found_node->x.first = new_val;
    emersion(found_node);
  }

  void emersion(Node *node) {
    Node *parent = node->parent;
    if (parent == NULL)
      return;
    if (parent->x.first > node->x.first) {
      swap(parent->x, node->x);
      // std::pair<float, int> tmp;
      // tmp = node->x;
      // node->x = parent->x;
      // parent->x = tmp;
      emersion(parent);
    }
  }

  Node *findNode(int id) { return recursivefindNode(root, id); }

  Node *recursivefindNode(Node *h, int id) {
    if (h == NULL)
      return NULL;

    if (h->x.second == id)
      return h;

    Node *res = recursivefindNode(h->child, id);
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
