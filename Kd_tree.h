#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using std::cin;
using std::cout;
using std::endl;

#include "merge_sort.h"
#include "math.h"

const int Horizontal = 0;
const int Vertical = 1;

typedef struct kdNode 
{
int direction;
long splitLine;
struct kdNode *l_child;
struct kdNode *r_child;
} kdnode, *pkdnode;

pkdnode createKdTree() {
    pkdnode new_node = (pkdnode)(new kdnode);
    // cout << "?" << endl;
    new_node->direction = -1;
    // cout << "?1" << endl;
    new_node->splitLine = -1;
    // cout << "?2" << endl;
    new_node->l_child = NULL;
    new_node->r_child = NULL;
    // cout << "?3" << endl;
    
    return new_node;
}

bool even (int direction) {
    if (direction % 2 == 0) {
        return true;
    }
    
    else {
        return false;
    }
}

pkdnode buildKdTree(long (*origin)[2], Rank lo, Rank hi, int direction) {
    // cout << "X" << endl;
    // cout << hi - lo << endl;
    // cout << lo << ", " << hi << endl;
    if (hi - lo == 1) {
        pkdnode leaf_head = createKdTree();
        leaf_head->direction = direction;
        leaf_head->splitLine = origin[lo][direction];
        
        pkdnode leaf_tail = createKdTree();
        leaf_tail->direction = (direction + 1) % 2;
        leaf_tail->splitLine = origin[lo][(direction + 1) % 2];
        
        leaf_head->l_child = leaf_tail;
        
        return leaf_head;
    }
    
    // cout << "Y" << endl;
    pkdnode root = createKdTree();
    // cout << "Z" << endl;
    root->direction = even(direction) ? Horizontal:Vertical;
    
    // find median
    mergeSort(origin, lo, hi, direction);
    // if (lo == 0 && hi == 3) {
    //     for (int i = 0; i<3 ;i++) {
    //         cout << origin[i][0] << ", " << origin[i][1] << endl;
    //     }
    // }
    
    // if (direction == 0) {
    //     cout << "X-axis" << endl;
    // }
    // else {
    //     cout << "Y-axis" << endl;
    // }
    // for (int i = lo; lo < hi; i++) {
    //     cout << origin[i][0] << ", " << origin[i][1] << endl; 
    // }
    // }
    long median = lo + ceil(float(hi - lo) / float(2));
    
    // cout << "M" << endl;
    // cout << lo << ", " << hi << endl;
    root->splitLine = origin[median-1][direction];
    // cout << root->splitLine << endl;
    root->l_child = buildKdTree(origin, lo, median, (direction + 1) % 2);
    // cout << lo << ", " << hi << endl;
    // exit(0);
    
    if (hi - median != 0) {
        // cout << "before: " << lo << ", "  << median << ", " << hi << endl;
        // mergeSort(origin, lo, hi, direction);
        // cout << "something happend!" << endl;
        root->r_child = buildKdTree(origin, median, hi, (direction + 1) % 2);
        // cout << "after: " << lo << ", "  << median << ", " << hi << endl;
        // exit(0);
    }
    // cout << "N" << endl;
    
    return root;
}





