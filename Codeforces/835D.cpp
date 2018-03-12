#include <bits/stdc++.h>
using namespace std;
const int limN = 5005;

char str[limN];
int gradMemo[limN][limN];
bool usd[limN][limN];
int cnt[limN];

int grad(int l, int r) {
    if(l > r)
        return 1;
    if(usd[l][r])
        return gradMemo[l][r];
    usd[l][r] = true;
    int &ans = gradMemo[l][r];
    if(str[l] != str[r] || grad(l+1, r-1)==0)
        return ans = 0;
    if(l==r)
        return ans = 1;
    return ans = grad(l, (l+r-1)/2) + 1;
}

int main() {
    scanf("%s", str);
    int N = strlen(str);

    for(int i=0; i<N; i++) {
        for(int j=i; j<N; j++) {
            cnt[grad(i,j)]++;
        }
    }
    for(int i=N-1; i>0; i--)
        cnt[i] += cnt[i+1];

    for(int i=1; i<=N; i++)
        printf("%d ", cnt[i]);
    printf("\n");
}
