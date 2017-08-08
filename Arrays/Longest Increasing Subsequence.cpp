//The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order.

#include<iostream>
using namespace std;

int lis( int arr[], int n )
{
    int *lis, i, j, max = 0;
    lis = (int*) malloc ( sizeof( int ) * n );

    for (i = 0; i < n; i++ )
        lis[i] = 1;

    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];

    free(lis);

    return max;
}
