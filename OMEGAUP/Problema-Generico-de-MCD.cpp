#include <bits/stdc++.h>
using namespace std;

set <long long> total;
queue <long long> ant;
long long n;

int main(){
  long long act;
  while(scanf("%lld",&act) != EOF) {
    set<long long>used;
    queue<long long> nw;
    while(!ant.empty()){
      long long c = __gcd(act, ant.front());
      ant.pop();
      if(!used.count(c)){
        used.insert(c);
        nw.push(c);
      }
      total.insert(c);
    }
    nw.push(act);
    total.insert(act);
    ant = nw;
  }
  printf("%lld\n",(long long)total.size());
  return 0;
}
