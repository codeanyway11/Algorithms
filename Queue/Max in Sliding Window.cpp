#include<bits/stdc++.h>
using namespace std;

void printKMax(int arr[], int n, int k){
    deque<int> q(k);
    int i;
    for(i=0; i<k; i++){
        while((!q.empty()) && arr[i]>=arr[q.back()])
            q.pop_back();

        q.push_back(i);
    }

    for(; i<n; i++){
        cout<<arr[q.front()]<<" ";
        while((!q.empty()) && q.front()<=i-k){
            q.pop_front();
        }

        while((!q.empty()) && arr[i]>=arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    cout<<arr[q.front()];

}

int main(){
	int t; scanf("%d", &t);

	while(t--){
		int n; scanf("%d", &n);
		int k; scanf("%d", &k);

		int arr[n];
		for(int i=0; i<n; i++){
			scanf("%d", &arr[i]);
		}
        printKMax(arr, n, k);
        cout<<endl;
	}
	return 0;
}
