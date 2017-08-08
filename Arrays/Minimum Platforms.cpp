//Given arrival and departure times of all trains that reach a railway station, find the minimum number of platforms required for the railway station so that no train waits.

//The following solution is O(nlogn)
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n], dep[n];
        for(int i=0; i<n; i++)
        cin>>arr[i];
        for(int i=0; i<n; i++)
        cin>>dep[i];

        sort(arr, arr+n);
        sort(dep, dep+n);
        int plat=1, result=1;
        int i=1; int j=0;

        while(i<n && j<n){
            if(arr[i]<dep[j])
            {
                plat++;
                i++;
                if(result<plat)
                result=plat;
            }
            else{
                plat--;
                j++;
            }
        }
        cout<<result<<endl;
    }
    return 0;
}


//The below approach uses Map and has an additional space complexity of O(n)
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        if(!n){
            cout<<"0"<<endl;
            break;
        }
        int result=0;
        int platforms=0;
        int arr[n], dep[n];
        multimap<int, char> map;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        for(int i=0; i<n; i++){
            cin>>dep[i];
            map.insert(make_pair(dep[i], 'd'));
        }

        for(int i=0; i<n; i++){
            map.insert(make_pair(arr[i], 'r'));

        }
        multimap<int, char>::iterator it= map.begin();

        for(; it!=map.end(); it++){
            //cout<<(*it).first<< "  "<<(*it).second<<endl;
            if((*it).second=='r')
            platforms++;
            else
            platforms--;
            if(platforms>result)
            result=platforms;

        }
        if(!result)
        result=1;
        cout<<result<<endl;
    }
    return 0;
}
