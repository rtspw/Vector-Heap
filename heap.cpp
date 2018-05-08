#include "heap.h"

heap::heap() {
    lastEntered = -1;
    tree.push_back(node());
}
heap::~heap() {
    deleteAll();
}
heap::heap(const heap &other) {
    copy(other);
}
heap &heap::operator=(const heap &other) {
    if(this != &other) {
        deleteAll();
        copy(other);
    }
    return *this;
}

bool heap::empty() const {
    return tree.size() <= 1;
}

size_t heap::size() const {
    return tree.size() - 1;
}
const std::string heap::peek() const {
    if(empty()) throw EMPTY_HEAP;
    return tree[1].word;
}

void heap::insert(const std::string &w, const size_t &pIdx, const size_t &lIdx, const size_t &count) {

    // Puts node at end of heap vector
    tree.push_back(node(w, pIdx, lIdx, count));

    // Ignores heapify process it first insert
    if(tree.size() != 2)
        heapify();

    /////// ******** DEBUG OUTPUT  use https://www.cs.usfca.edu/~galles/visualization/Heap.html
    for(int i = 0; i < tree.size(); ++i) {
        std::cout << "(" << tree[i].word << ")";
    }
    std::cout << std::endl;
}

void heap::clear() {
    deleteAll();
}

void heap::copy(const heap &other) {
    tree = other.tree;
    lastEntered = other.lastEntered;
}
void heap::deleteAll() {
    tree.clear();
    lastEntered = -1;
}

/* Simple function to swap two node values on the heap */
void heap::swap(const size_t &x, const size_t &y) {
    node temp = tree[x];
    tree[x] = tree[y];
    tree[y] = temp;
}

/* Starting from the last inserted node, swaps the smaller value up the tree */
void heap::heapify() {
    lastEntered = tree.size();
    size_t idx = lastEntered - 1;
    size_t parent;
    do {
        parent = idx / 2;
        std::cout << "PARENT VALUE: " << parent << std::endl;
        std::cout << "idx value: " << idx << std::endl;
        if(tree[idx] < tree[parent]) {
            std::cout << "smaller" << std::endl;
            swap(idx, parent);
        }
        idx = parent;
    } while(parent != 1);
}
