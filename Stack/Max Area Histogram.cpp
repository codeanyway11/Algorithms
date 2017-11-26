#include<bits/stdc++.h>
using namespace std;

int max_area(int arr[], int n){
    stack<int> s;
    int tp; int max_area_val =0; int max_top;

    int i=0;
    while(i<n){
        if(s.empty() || arr[s.top()]<=arr[i]){
            s.push(i++);
        }
        else{
            int tp= s.top();
            s.pop();
            max_top = arr[tp]*(s.empty()? i:(i-s.top()-1));
            if(max_area_val <max_top){
                max_area_val = max_top;
            }
        }
    }

    while(!s.empty()){
          int tp= s.top();
            s.pop();
            max_top = arr[tp]*(s.empty()? i:(i-s.top()-1));
            if(max_area_val <max_top){
                max_area_val = max_top;
            }
    }
    return max_area_val;
}

int main(){
	int t; scanf("%d", &t);

	while(t--){
		int n; scanf("%d", &n);
		int arr[n];
		for(int i=0; i<n; i++){
			scanf("%d", &arr[i]);
		}

		cout<<max_area(arr, n)<<endl;


	}
	return 0;
}
