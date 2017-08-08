//Find the Kth smallest element in a unsorted array
//The following solution uses a randomized algorithm and thus the expected runtime is O(n)
#include <bits/stdc++.h>
using namespace std;
//Find the Kth smallest element in a unsorted array
//The following solution uses a randomized algorithm and thus the expected runtime is O(n)

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partitionCustom(int A[], int l, int r){
  int temp = A[l];
  int i=l; int j=r;
  while(i<j){
    while(A[i]<=temp)
      i++;
    while(A[j]>temp)
      j--;
    if(i<j)
      swap(&A[i], &A[j]);
  }
  A[l]=A[j]; A[j]=temp;
  return j;
}


int randomPartition(int arr[], int l, int r){
  int n = r-l+1;
  int pivot = rand()%n;
  swap( &arr[l+pivot], &arr[l] );
  return partitionCustom(arr, l, r);
}

int kthSmallestElement(int arr[], int l, int r, int k){
  if(k >0 && k<= r-l+1){
    int pos= randomPartition(arr, l, r);
    if(pos == k-1)
      return arr[pos];
    if(pos > k-1)
      return kthSmallestElement(arr, l, pos-1, k);
    return kthSmallestElement(arr, pos+1, r, k-pos);
  }
}

int main() {
	int t, n, k;
	cin>>t;
	while(t--){
	    cin>>n;
	    int a[n];
	    for(int i=0; i<n; i++)
	        cin>>a[i];
	   cin>>k;
	  cout<<kthSmallestElement(a, 0, n-1, k)<<endl;

	}
	return 0;
}
