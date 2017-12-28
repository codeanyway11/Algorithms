#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; scanf("%d", &t);

	while(t--){
	    bool flag =1;
		int n; scanf("%d", &n);
		int arr[n];
		for(int i=0; i<n; i++){
			scanf("%d", &arr[i]);
		}

		for(int i=0; i<n/2; i++){
		    if(arr[i]!= arr[n-i-1]){
		        flag =0;
		        break;
		    }
		}

		if(flag){
		    cout<<"PERFECT"<<endl;
		}
		else{
		    cout<<"NOT PERFECT"<<endl;
		}


	}
	return 0;
}
