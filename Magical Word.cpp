#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int nearestPrime(int n){
  int a[]={67,71,73,79,83,89,97,101, 103, 107, 109, 113};
  int diff=255;
  int p;
  for(int i=0; i<12; i++){
    if(abs(n-a[i])<diff)
    {
      diff = abs(n-a[i]);
      p=a[i];

    }

  }
  return p;
}

int main()
{
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0; i<n; i++){
      s[i]= nearestPrime(s[i]);
    }
    cout<<s<<endl;
  }

}
