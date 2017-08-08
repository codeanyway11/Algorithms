#include<iostream>
using namespace std;
int main() {
    int t, n; cin>>t;
    while(t--){
        int n, temp;
        int arr[3]={0,0, 0};
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>temp;
            arr[temp]++; }

            for(int i=0; i<3; i++){
                while(arr[i]){
                    cout<<i<<" ";
                    arr[i]--;
                }
            }
            cout<<endl;
        }
        return 0;
    }
