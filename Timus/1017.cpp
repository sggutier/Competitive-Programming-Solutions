#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1005;

bool usd[limN][limN];
ll dp[limN][limN];

ll memo(int rem, int prev) {
  if(rem==0)
    return 1;
  if(usd[rem][prev])
    return dp[rem][prev];
  usd[rem][prev] = true;
  for(int i=prev+1; i<=rem; i++)
    dp[rem][prev] += memo(rem-i, i);
  return dp[rem][prev];
}

int main() {
  int N ;
  scanf("%d", &N);
  printf("%lld\n", memo(N, 0) - 1);  
}

