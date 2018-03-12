#include <bits/stdc++.h>
using namespace std;
const int limP = 1e6;

int primCnt = 0;
int primos[limP];
bool comp[limP];
int maxDif = 0;

void criba() {
    for(int i=2; i*i<limP; i++)
        if(!comp[i])
            for(int j=i*i; j<limP; j+=i)
                comp[j] = true;
    for(int i=2; i<limP; i++)
        if(!comp[i])
            primos[primCnt++] = i;
    for(int i=1; i<limP; i++)
        maxDif = max(maxDif, primos[i] - primos[i-1]);
    // printf("%d\n", maxDif);
}

void testCase() {
    int a, b;
    int ini, fin;
    int ans = -1, aNum = -1;
    bool otr = true;
    vector<int> reps(maxDif+1);

    scanf("%d%d", &a, &b);
    ini = lower_bound(primos, primos+primCnt, a) - primos;
    fin = upper_bound(primos, primos+primCnt, b) - primos;
    // printf("%d %d\n", primos[ini], primos[fin]);

    for(int i=ini+1; i<fin; i++) {
        int d = ++reps[primos[i] - primos[i-1]] ;
        // printf(" => %d %d\n", primos[i], primos[i] - primos[i-1]);
        if(d > ans) {
            ans = d;
            aNum = primos[i] - primos[i-1];
            otr = false;
        }
        else if(d==ans)
            otr = true;
    }

    if(otr)
        printf("No jumping champion\n");
    else
        printf("The jumping champion is %d\n", aNum);
}

int main() {
    criba();

    int tc;

    scanf("%d", &tc);
    while(tc--) {
        testCase();
    }
}
