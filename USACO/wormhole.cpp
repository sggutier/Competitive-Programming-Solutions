/*
ID: me60
LANG: C++11
TASK: wormhole
*/
#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
#define x first
#define y second

bool itLoops(par* agujeros, int* sig, int n) {
    bool* usd = new bool[n]();
    for(int i=0; i<n; i++) {
        if(usd[i])
            continue;
        usd[i] = true;
        int cur = i;
        do {
            if(cur!=n-1 && agujeros[cur].x == agujeros[cur+1].x) {
                cur = sig[cur+1];
            }
            else {
                cur = n;
                break;
            }
        } while( cur!=i );
        if(cur==i) {
            delete[] usd;
            return true;
        }
    }
    delete[] usd;
    return false;
}

int escojeAgujeros(par* agujeros, int numAgujeros, int* sigAgujero, int numUsados) {
    if(numUsados==numAgujeros) {
        return (int) itLoops(agujeros, sigAgujero, numAgujeros);
    }
    for(int i=0; i<numAgujeros; i++) {
        if(sigAgujero[i]!=-1)
            continue;
        int ans = 0;
        for(int j=i+1; j<numAgujeros; j++) {
            if(sigAgujero[j]==-1) {
                sigAgujero[i] = j;
                sigAgujero[j] = i;
                ans += escojeAgujeros(agujeros, numAgujeros, sigAgujero, numUsados+2);
                sigAgujero[j] = -1;
                sigAgujero[i] = -1;
            }
        }
        return ans;
    }
    return 0;
}

int main() {
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
    int n;
    par* agujeros;
    int* sigAgujero;

    scanf("%d", &n);
    agujeros = new par[n];
    sigAgujero = new int[n];
    for(int i=0; i<n; i++) {
        scanf("%d%d", &agujeros[i].y, &agujeros[i].x);
        sigAgujero[i] = -1;
    }
    sort(agujeros, agujeros+n);
    

    printf("%d\n", escojeAgujeros(agujeros, n, sigAgujero, 0));

    delete[] agujeros;
    delete[] sigAgujero;
    
    return 0;
}
