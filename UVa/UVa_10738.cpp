#include <bits/stdc++.h>
using namespace std;
const int limP = 1e6;

bool comp[limP+1];
int mu[limP+1];
int M[limP+1];

void criba() {
    for(int i=2; i*i<limP; i++) {
        if(!comp[i]) {
            for(int j=i*i; j<=limP; j+=i)
                comp[j] = true;
            int i2 = i*i;
            for(int j=i2; j<=limP; j+=i2)
                mu[j] = 0;
        }
    }
    for(int i=2; i<limP; i++) {
        if(comp[i])
            continue;
        for(int j=i; j<=limP; j+=i)
            mu[j] *= -1;
    }
}

void precarga() {
    for(int i=0; i<=limP; i++)
        mu[i] = 1;
    criba();
    for(int i=1; i<=limP; i++) {
        M[i] = M[i-1] + mu[i];
    }
}

int main() {
    precarga();

    int a ;

    while(scanf("%d", &a)!=EOF && a) {
        printf("%8d%8d%8d\n", a, mu[a], M[a]);
    }
}
