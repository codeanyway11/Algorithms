#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int count =0;
        int  n, a, b, temp, t;
        cin>>n;
        int arr[n]; int arr2[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
            arr2[i]= arr[i];
        }
        cin>>temp>>a>>b>>t;
        int x[t];
        x[0]=temp;
        for(int i=1; i<t; i++){
          //One thing we should pay attention to, is integer overflow when getting the new basket index.
          // The easiest solution in order to avoid this issue, is to use 64-bit integers.
            x[i] = (1LL*a*x[i-1] + b)%n;
        }
        for(int i=0; i<t; i++){
            temp= x[i];
            arr2[temp]-=1;
            if(arr2[temp]==0){
                count++;
                arr2[temp]=arr[temp];
            }
        }
        cout<<count<<endl;
    }
}
