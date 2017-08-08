//Given an array, reverse every sub-array formed by consecutive k elements.

#include <iostream>
using namespace std;

int main() {
    int t, n, k;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        cin>>arr[i];
        cin>>k;
        for(int i=0; i<n; i+=k){
            int left=i;
            int right = min(i + k - 1, n - 1);
            while (left < right)
                swap(arr[left++], arr[right--]);
        }
        for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}
