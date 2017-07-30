//Given an array containing both negative and positive integers. Find the contiguous sub-array with maximum sum.

//1st Method
//Brute Force we compare all continuous subarrays.

#include <iostream>
using namespace std;

int sumArr(int arr[], int i, int j){
    int sum=0;
    for(int k=i; k<=j; k++)
    sum+=arr[k];
    return sum;
}

int main() {
    int t, n, max_sum, sum;
    int start=0; int end=0;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        cin>>arr[i];
        int sum = max_sum = arr[0];
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                sum = sumArr(arr, i, j);
                if(sum >max_sum){
                    max_sum = sum;
                    start =i;
                    end =j;
                }
            }
        }
        cout<<max_sum<<endl;
    }
    return 0;
}

//The above is O(n^3) which can be improved to O(n^2) for Brute Force.


#include <iostream>
using namespace std;

int main() {
    int n, sum, maxsum;
    int start=0; int end =0;
    cin>>n;
    int  arr[n];
    for(int i=0; i<n; i++)
    cin>>arr[i];

    //we form a cummulative sum subarray
    int b[n+1];
    b[0]=0;
    //we initialize maxsum with arr[0] when we have all negative numbers.
    maxsum=arr[0];
    for(int i=1; i<=n; i++)
    b[i]= arr[i-1] + b[i-1];

    for(int i=n; i>0; i--){
        for(int j=i-1; j>=0; j--){
            sum = b[i] - b[j];

            if(maxsum<sum){
                maxsum=sum;
                start= j;
                end = i-1;
            }
        }
    }
    cout<< maxsum<<endl;
}

//Now to further improve the runtime to O(n), we use Kadane's algorithm
#include <iostream>
#include<algorithm>

using namespace std;

int maxSubArraySum(int a[], int n){
    //Kadane's Algorithm
    if( n<1 ) return 0;
    //The below two statements are there to handle the case where all elements are negative
    int max_so_far = a[0];
    int curr_max = a[0];
    int start =0; int end =0; int s=start;
    for(int i =1; i<n ; i++){
         curr_max = max(a[i], curr_max + a[i])

        if(max_so_far < curr_max){
            max_so_far =curr_max;
            end =i;
            if(curr_max == a[i])
                start=s;
        }
    }
    return max_so_far;
}
