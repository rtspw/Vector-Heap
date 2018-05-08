#include <iostream>
#include "node.h"
#include "avlbst.h"
#include "heap.h"
using namespace std;

int main() {

    heap bb;

    bb.insert("apple",1,1,1);
    bb.insert("abba",1,1,1);
    bb.insert("appl",1,1,1);
    bb.insert("appla",1,1,1);
    bb.insert("apricot",1,1,1);
    bb.insert("alice",1,1,1);
    bb.insert("a",1,1,1);
    bb.insert("an",1,1,1);
    bb.insert("answer",1,1,1);

    while(!bb.empty()) {
        cout << bb.pop().word << endl;
    }
    return 0;

}
