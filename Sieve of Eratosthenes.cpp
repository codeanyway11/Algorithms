//Sieve is used to find all prime numbers upto n
//Run time is O(nlog(logn))

#include<bits/stdc++.h>
#include <iostream>
using namespace std;
bool prime[10005];

int main() {
  memset(prime, true, sizeof(prime));
  for(int i=2; i*i<=10005; i++){
    if(prime[i]){
      for(int j=2*i; j<=10005; j+=i){
        prime[j]=false;
      }
    }
  }

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    for(int i=2;i<=n; i++){
      if(prime[i])
      cout<<i<<" ";

    }
    cout<<endl;
  }
  return 0;
}

//Segmented Sieve
#include <bits/stdc++.h>
using namespace std;

void simpleSieve(int limit, vector<int> &prime)
{
    bool mark[limit+1];
    memset(mark, true, sizeof(mark));

    for (int p=2; p*p<limit; p++)
    {
        if (mark[p] == true)
        {
            for (int i=p*2; i<limit; i+=p)
                mark[i] = false;
        }
    }

    for (int p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
            cout << p << "  ";
        }
    }
}

void segmentedSieve(int n)
{
    int limit = floor(sqrt(n))+1;
    vector<int> prime;
    simpleSieve(limit, prime);

    int low  = limit;
    int high = 2*limit;

    while (low < n)
    {
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));

        for (int i = 0; i < prime.size(); i++)
        {
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
             for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }

        for (int i = low; i<high; i++)
            if (mark[i - low] == true)
                cout << i << "  ";

        low  = low + limit;
        high = high + limit;
        if (high >= n) high = n;
    }
}
