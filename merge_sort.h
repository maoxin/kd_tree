// #include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
// using std::cin;
// using std::cout;
// using std::endl;
// 
#pragma once

typedef long Rank;

int merge(long (*origin)[2], Rank lo, Rank mi, Rank hi, const int & axis) { 
    long (*A)[2] = origin + lo; 
    int lb = mi - lo; long (*B)[2] = new long[lb][2]; 
    for (Rank i = 0; i < lb; i++) {
        B[i][0] = A[i][0];
        B[i][1] = A[i][1];
    } 
    int lc = hi - mi; long (*C)[2] = origin + mi; 
    for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc); ) { 
       if ( (j < lb) && ( !(k < lc) || (B[j][axis] <= C[k][axis]) ) ) {
           A[i][0] = B[j][0];
           A[i][1] = B[j][1];
           i++;
           j++;
       }
       if ( (k < lc) && ( !(j < lb) || (C[k][axis] <  B[j][axis]) ) ) {
           A[i][0] = C[k][0];
           A[i][1] = C[k][1];
           i++;
           k++;
       }
    }
    
    delete [] B; 
    
    return 0;
}

int mergeSort(long (*origin)[2], Rank lo, Rank hi, const int & axis) { 
    if (hi - lo < 2) return 0; 
    int mi = (lo + hi) / 2; 
    mergeSort(origin, lo, mi, axis); mergeSort(origin, mi, hi, axis); merge(origin, lo, mi, hi, axis); 
    
    return 0;
}


// int main (int argc, char const *argv[])
// {
//     long (*A)[2] = new long[5][2];
//     A[0][0] = 1; A[0][1] = 2;
//     A[1][0] = 3; A[1][1] = 8; 
//     A[2][0] = -10; A[2][1] = 7; 
//     A[3][0] = 9; A[3][1] = -2; 
//     A[4][0] = 0; A[4][1] = 20; 
// 
//     for (long i = 0; i<5; i++) {
//         cout << A[i][0] << ", " << A[i][1] << endl;
//     }
//     mergeSort(A, 0, 5, 0);
//     cout << "new----" << endl;
//     for (long i = 0; i<5; i++) {
//         cout << A[i][0] << ", " << A[i][1] << endl;
//     }
//     cout << "new++++" << endl;
//     mergeSort(A, 0, 5, 1);
//     for (long i = 0; i<5; i++) {
//         cout << A[i][0] << ", " << A[i][1] << endl;
//     }
    // 
    // mergeSort(A, 0, 5);
    // A[0] = 1; A[1] = 5; A[2] = 2; A[3] = 9; A[4] = -10;
    
    
    // for (long i=0; i<5; i++) {
    //     cout << A[i] << endl;
    // }
    
    // mergeSort(A, 0, 5);
    // for (long i=0; i<5; i++) {
        // cout << A[i] << endl;
    // }
    // return 0;
// }