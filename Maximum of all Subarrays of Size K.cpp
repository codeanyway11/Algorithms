//Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void printKMax(int arr[], int n, int k){
    deque<int> Q;
    int i;
    for(i=0; i<k; i++){
        while(!Q.empty() && arr[i]>=arr[Q.back()])
            Q.popback();

        Q.pushback(i);
    }

    for(; i<n; i++){
        cout<<arr[Q.front()]<<" ";
        while(!Q.empty() && Q.front()<=i-k)
            Q.popfront();
        while(!Q.empty() && arr[i]>=arr[Q.back()])
            Q.popback();

        Q.pushback(i);
    }
    cout<<arr[Q.front()];
}
