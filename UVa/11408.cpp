#include <bits/stdc++.h>
using namespace std;
const int limN = 5e6 ;

bool comp[limN+1];
int suma[limN+1];

void criba() {
    for(int i=2; i<limN; i++) {
        if(comp[i])
            continue;
        suma[i] = i;
        for(int j=i*2; j<=limN; j+=i)  {
            comp[j] = true;
            suma[j] += i;
        }
    }
    for(int i=2; i<=limN; i++) {
        suma[i] = suma[i-1] + (suma[i]<=limN && !comp[suma[i]]? 1 : 0);
    }
}

int main() {
    criba();
    int a, b;
    while(scanf("%d", &a)!=EOF && a) {
        scanf("%d", &b);
        printf("%d\n", suma[b] - suma[a-1]);
    }
}
