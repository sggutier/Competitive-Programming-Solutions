#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

int divCnt[limN];
bool esComp[limN];

void precarga(int N = limN-1) {
    for(int i=2; i*i<limN; i++)
        if(!esComp[i])
            for(int j=i*i; j<limN; j+=i)
                esComp[j] = true;
    for(int i=2; i<limN; i++) {
        if(esComp[i]) continue;
        for(int j=i; j<limN; j+=i) {
            int k = 0, c = j;
            while(c % i == 0) {
                c /= i;
                k ++;
            }
            divCnt[j] = max(divCnt[j], k);
        }
    }
}

int main() {
    precarga();
    int tc;
    for(scanf("%d", &tc); tc; tc--) {
        int a ;
        scanf("%d", &a);
        printf("%d\n", divCnt[a]);
    }
}
