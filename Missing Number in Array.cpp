//You are given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in list. One of the integers is missing in the list.

//Method 1, simply traverse through the array and check.
//Assuming the array is sorted. This takes O(n)
#include <iostream>
using namespace std;

int main() {
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int temp;
        int prev =0;
        for(int i=1; i<n; i++ )
        {
            cin>>temp;
            if(temp!=prev+1){
                cout<<prev+1<<endl;
                break;
            }
            prev++;
        }

    }
	return 0;
}

//Method 2, calculate sum and subtract the array to find the missing number

int main() {
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;

        int sum= n*(n+1)/2;
        int temp;
        for(int i=1; i<n; i++ )
        {
            cin>>temp;
            sum-=temp;
        }
        cout<<sum<<endl;
    }
	return 0;
}

//Method 3, calculate sum and subtract the array to find the missing number
//Find the XOR of all the numbers from 1 to N, calculate the XOR of all the numbers in the array
//Find XOR of both of these to get the answer


int main() {
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int XOR =1;
        for(int i=2; i<=n; i++)
            XOR= XOR ^ i;
        int x1, temp;
        cin>>x1;
        int XOR2= x1;
        for(int i=2; i<n; i++ )
        {
            cin>>temp;
            XOR2 = XOR2^ temp;
        }
        int ans=XOR2 ^ XOR;
        cout<< ans <<endl;
    }
	return 0;
}
