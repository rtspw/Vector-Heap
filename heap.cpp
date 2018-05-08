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
    return !tree.size() - 1;
}

size_t heap::size() const {
    return tree.size() - 1;
}
const std::string heap::peek() const {
    if(empty()) throw EMPTY_HEAP;
    return tree[1].word;
}

void heap::insert(const std::string &w, const size_t &pIdx, const size_t &lIdx, const size_t &count) {
    std::cout << "INSERTING " << w << std::endl;
    node temp(w, pIdx, lIdx, count);
    tree.push_back(temp);
    if(tree.size() != 2) {
        lastEntered = tree.size();
        size_t idx = lastEntered;
        size_t parent;
        do {
            parent = idx / 2;
            std::cout << "PARENT VALUE: " << parent << std::endl;
            if(tree[idx] < tree[parent]) {
                std::cout << "asdf" << std::endl;
                swap(idx, parent);
            }
            idx = parent;
        } while(parent != 1);
    }
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

void heap::swap(const size_t &x, const size_t &y) {
    node temp = tree[x];
    tree[x] = tree[y];
    tree[y] = temp;
}
