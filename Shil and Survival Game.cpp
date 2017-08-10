#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> ans;
    int n;
    cin>>n;
    int a[n];
    int ma =0;
    int idx;
    for(int i=0; i<n; i++){
        cin>>a[i];
        ma= max(ma, a[i]);
        if(ma==a[i])
           idx= i;
    }
    ans.push_back(idx);

    ma=0;
    for(int i=0; i<n; i++){
        if(i==idx)
            break;
        ma= max(ma, a[i]);
        if(ma== a[i]){
            ans.push_back(i);
        }
    }

    ma=0;
    for(int i=n-1; i>=0; i--){
        if(i==idx)
            break;
        ma= max(ma, a[i]);
        if(ma==a[i])
            ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    for(auto x:ans)
        cout<<x+1<<" ";

    return 0;
}
