//Given an array A your task is to tell at which position the equilibrium first occurs in the array. Equilibrium position in an array is a position such that the sum of elements below it is equal to the sum of elements after it.

#include <iostream>
using namespace std;

int main() {
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        int sum=0; int flag=0;
        if(n==1){
        		cin>>a[0];
                cout<<"1"<<endl;
                flag=1;
                continue;
            }
        for(int i=0; i<n; i++){
            cin>>a[i];
            sum+=a[i];
        }
        int leftsum=0; int rightsum=sum;
        for(int i=0; i<n; i++){
            rightsum-=a[i];
            if(leftsum==rightsum){
                cout<<i+1<<endl;
                flag=1;
                break;
            }
            leftsum+=a[i];
        }
       if(!flag)
       cout<<"-1"<<endl;
    }
	return 0;
}
