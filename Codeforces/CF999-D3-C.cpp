#include <bits/stdc++.h>
using namespace std;
const int limC = 26;
const int limN = 1e6 + 5;

int N ;
char str[limN];
list <int> poss[limC];
bool usd[limN];

int main() {
    int k;
    scanf("%d%d", &N, &k);
    scanf("%s", str);
    for(int i=0; i<N; i++)
        poss[str[i]-'a'].push_back(i);
    
    for(int let=0; let<limC; let++) {
        for(const int &p : poss[let]) {
            if(!k) break;
            k--;
            usd[p] = true;
        }
    }

    for(int i=0; i<N; i++)
        if(!usd[i])
            printf("%c", str[i]);
    printf("\n");
}
