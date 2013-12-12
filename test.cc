#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Kd_tree.h"
using std::cin;
using std::cout;
using std::endl;

int print_tree(pkdnode & kd_root) {
    if (kd_root->splitLine != -1) {
        if (kd_root->direction == 0) {
            cout << "X-axis" << endl;
        }
        else {
            cout << "Y-axis" << endl;
        }
        // cout << kd_root->direction << endl;
        cout << kd_root->splitLine << endl;
        pkdnode left = kd_root->l_child;
        pkdnode right = kd_root->r_child;
        
        if (left != NULL) {
            cout << "L_CHILD--------" << endl;
            print_tree(left);
        }
        if (right != NULL) {
            cout << "R_CHILD++++++++" << endl;
            print_tree(right);
        }
    }
    
    return 0;
}

int main (int argc, char const *argv[])
{
    long (*A)[2] = new long[5][2];
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 8; 
    A[2][0] = -10; A[2][1] = 7; 
    A[3][0] = 9; A[3][1] = -2; 
    A[4][0] = 0; A[4][1] = 20; 
    
    pkdnode kd_root = buildKdTree(A, 0, 5, Horizontal);
    print_tree(kd_root);
    
    
    return 0;
}
