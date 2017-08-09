// Mr. Yash asks all the great programmers of the world to solve a trivial problem. 
// He gives them an integer m and asks for the number of positive integers n, such
// that the factorial of n ends with exactly m zeroes. Are you among those great
// programmers who can solve this problem? Input First line of input contains an
// integer T number of test cases. Each test case contains an integer M
// (1 ≤ M ≤ 100,000) — the required number of trailing zeroes in factorial. Output
// First print k — the number of values of n such that the factorial of n ends
// with m zeroes. Then print these k integers in increasing order.

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
    if(myMap[n].second - myMap[n].first!=0)
    cout<<myMap[n].second - myMap[n].first + 1<<endl;
    for(int i= myMap[n].first; i<=myMap[n].second; i++)
    cout<<i<<" ";
    cout<<endl;
  }
  return 0;
}
