
//Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array such that the integers in the subsequence are sorted in increasing order.
#include <iostream>
using namespace std;

int main() {
	int t, n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int a[n]; int max=0;
	    for(int i=0; i<n; i++)
	        cin>>a[i];

	    int *mlis = (int*) malloc(sizeof(int)*n);
	    for(int i=0; i<n; i++)
	        mlis[i] = a[i];

	   for(int i=1; i<n; i++){
	       for(int j=0; j<i; j++){
	           if(a[j]<a[i] && mlis[i]<mlis[j]+a[i])
	            mlis[i] = mlis[j]+ a[i];
	       }
	   }
	   for(int i=0; i<n; i++){
	       if(mlis[i]>max)
	        max=mlis[i];
	   }
	   cout<<max<<endl;

	}
	return 0;
}
