#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; scanf("%d", &t);

    while(t--){
        int n; scanf("%d", &n);
        int arr[n];

        int sum1 =0; int sum2 =0;
        for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
            if(i<n/2){
                sum1+=arr[i];
            }
            else{
                sum2+=arr[i];
            }
        }

        cout<<abs(sum1-sum2)<<endl;

    }
    return 0;
}
