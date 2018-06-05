#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 1;

vector <int> divs[limN];
long long anso[limN];
int cnts[limN];

void precarga() {
    for(int i=1; i<limN; i++)
        for(int j=2*i; j<limN; j+=i)
            divs[j].push_back(i);
    for(int i=1, n; i<limN; i++) {
        n = divs[i].size();
        for(int j=n-1; j>=0; j--) {
            cnts[j] = i / divs[i][j] - 1;
            for(int k=j+1; k<n; k++)
                if(divs[i][k] % divs[i][j] == 0)
                    cnts[j] -= cnts[k];
            anso[i] += cnts[j]*divs[i][j];
        }
        anso[i] += anso[i-1];
    }
}

int main() {
    precarga();
    int n ;
    while(scanf("%d", &n)!=EOF && n)
        printf("%lld\n", anso[n]);
}
