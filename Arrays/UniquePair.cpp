#include<bits/stdc++.h>
using namespace std;

bool arr[1001];

int main(){
    int t; scanf("%d", &t);

    while(t--){
        memset(arr, 0, sizeof(arr));

        int n; scanf("%d", &n);
        int temp;
        for(int i=1; i<=n; i++){
            scanf("%d", &temp);
            if(arr[temp]==1){
                arr[temp] =0;
            }else{
                arr[temp] =1;
            }
        }


        int a=0; int b=0;
        for(int i=1; i<=1000; i++){
            if(arr[i]==1){
                if(a==0){
                    a = i;
                }
                else{
                    b = i;
                    break;
                }
            }
        }
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}
