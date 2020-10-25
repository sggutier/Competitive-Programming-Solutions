#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 5e6 + 5;

int N;
ll BIT[limN];

void mete(int pos, const ll nov) {
  for(; pos < N; pos+=pos & -pos) {
    BIT[pos] += nov;
  }
}

ll saca(int pos) {
  ll ans = 0;
  for(; pos; pos -= pos & -pos) {
    ans += BIT[pos];
  }
  return ans;
}

int main() {
  int Q;
  char S[5];
  scanf("%d%d", &N, &Q);
  N+=2;
  for(int i=0, a, b; i<Q; i++) {
    scanf("%s%d", S, &a);
    a++;
    if(S[0] == '+') {
      scanf("%d", &b);
      mete(a, b);
    }
    else {
      printf("%lld\n", saca(a-1));
    }
  }
}
