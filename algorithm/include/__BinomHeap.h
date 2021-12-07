#pragma once
#include <iostream>
#include <list>
#include <tuple>
#define MAX_NUM 1000000

// template <typename L>

struct Node {
  int key;
  int value;
  size_t num_children;
  Node *parent, left_child, right_child, right_sibling;
};

Node *newNode(int key) {
  Node *temp = new Node;
  temp->key = key;
  temp->num_children = 0;
  temp->parent = temp->left_child = temp->right_child = temp->sibling = NULL;
  return temp;
}

Node *mergeBinomialTrees(Node *b_first, Node *b_second) {
  if (b_first->key > b_second->key)
    swap(b_first, b_second);
  b_second->parent = b_first;
  // b_second->sibling = b_first->child;
  b_first->right_child = b_second;
  b_first->num_children++;
  return b1;
}

// This function perform union operation on two binomial heap i.e. l1 & l2
list<Node *> unionBionomialHeap(list<Node *> l1, list<Node *> l2) {
  // _new to another binomial heap which contain new heap after merging l1 & l2
  list<Node *> _new;
  list<Node *>::iterator it = l1.begin();
  list<Node *>::iterator ot = l2.begin();
  while (it != l1.end() && ot != l2.end()) {
    if ((*it)->num_children <= (*ot)->num_children) {
      _new.push_back(*it);
      it++;
    } else {
      _new.push_back(*ot);
      ot++;
    }
  }
  // if there remains some elements in l1
  while (it != l1.end()) {
    _new.push_back(*it);
    it++;
  }
  // if there remains some elements in l2 binomial heap
  while (ot != l2.end()) {
    _new.push_back(*ot);
    ot++;
  }
  return _new;
}

// adjust function rearranges the heap
list<Node *> adjust(list<Node *> _heap) {
  if (_heap.size() <= 1)
    return _heap;
  list<Node *> new_heap;
  list<Node *>::iterator it1, it2, it3;
  it1 = it2 = it3 = _heap.begin();

  if (_heap.size() == 2) {
    it2 = it1;
    it2++;
    it3 = _heap.end();
  } else {
    it2++;
    it3 = it2;
    it3++;
  }
  while (it1 != _heap.end()) {
    // if only one element remains to be processed
    if (it2 == _heap.end())
      it1++;

    // If D(it1) < D(it2) i.e. merging of Binomial
    // Tree pointed by it1 & it2 is not possible
    // then move next in heap
    else if ((*it1)->num_children < (*it2)->num_children) {
      it1++;
      it2++;
      if (it3 != _heap.end())
        it3++;
    }

    // if D(it1),D(it2) & D(it3) are same i.e. degree of three consecutive
    // Binomial Tree are same in heap
    else if (it3 != _heap.end() &&
             (*it1)->num_children == (*it2)->num_children &&
             (*it1)->num_children == (*it3)->num_children) {
      it1++;
      it2++;
      it3++;
    }

    // if degree of two Binomial Tree are same in heap
    else if ((*it1)->num_children == (*it2)->num_children) {
      Node *temp;
      *it1 = mergeBinomialTrees(*it1, *it2);
      it2 = _heap.erase(it2);
      if (it3 != _heap.end())
        it3++;
    }
  }
  return _heap;
}

// inserting a Binomial Tree into binomial heap
list<Node *> insertATreeInHeap(list<Node *> _heap, Node *tree) {
  list<Node *> temp;
  temp.push_back(tree);
  temp = unionBionomialHeap(_heap, temp);
  return adjust(temp);
}

// removing minimum key element from binomial heap
list<Node *> removeMinFromTreeReturnBHeap(Node *tree) {
  list<Node *> heap;
  Node *temp = tree->child;
  Node *lo;

  // making a binomial heap from Binomial Tree
  while (temp) {
    lo = temp;
    temp = temp->sibling;
    lo->sibling = NULL;
    heap.push_front(lo);
  }
  return heap;
}

// inserting a key into the binomial heap
list<Node *> insert(list<Node *> _head, int key) {
  Node *temp = newNode(key);
  return insertATreeInHeap(_head, temp);
}

// return pointer of minimum value Node present in the binomial heap
Node *getMin(list<Node *> _heap) {
  list<Node *>::iterator it = _heap.begin();
  Node *temp = *it;
  while (it != _heap.end()) {
    if ((*it)->key < temp->key)
      temp = *it;
    it++;
  }
  return temp;
}

list<Node *> extractMin(list<Node *> _heap) {
  list<Node *> new_heap, lo;
  Node *temp;
  temp = getMin(_heap);
  list<Node *>::iterator it;
  it = _heap.begin();
  while (it != _heap.end()) {
    if (*it != temp) {
      new_heap.push_back(*it);
    }
    it++;
  }
  lo = removeMinFromTreeReturnBHeap(temp);
  new_heap = unionBionomialHeap(new_heap, lo);
  new_heap = adjust(new_heap);
  return new_heap;
}
