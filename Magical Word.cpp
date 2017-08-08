#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int cal_zeroes(int n){
  int base = 5;
  int sum = 0;
  while( n/base )
  {
    sum += n/base;
    base *= 5;
  }
  return sum;
}

int arr[500000];

int main()
{
  map<int, pair<int, int> > myMap;
  int lastVal=1;
  int first=5;
  int last;
  for(int i=6; i<500000; i++)
  {
    int temp = cal_zeroes(i);
    if(temp!= lastVal)
    {
      myMap.insert(make_pair(lastVal, make_pair(first, i-1)));
      lastVal= temp;
      first =i;
    }
    last =i;

  }
  myMap.insert(make_pair(lastVal, make_pair(first, last-1)));

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    cout<<myMap[n].second - myMap[n].first + 1<<endl;
    for(int i= myMap[n].first; i<=myMap[n].second; i++)
    cout<<i<<" ";
    cout<<endl;
  }
  return 0;
}
