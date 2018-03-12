#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

char str[limN];
int pref[limN];

void makePref(const int &N, char *str, int *prev) {
    int i=-1, j=0;
    prev[0] = -1;
    while(j<N) {
        while(i!=-1 && str[i]!=str[j])
            i = prev[i];
        i++, j++;
        prev[j] = i;
    }
}

bool itWorks(const int &M, char *pat, int *prev, const int &N, char *str) {
    int i=0, j=0;
    while(j<N) {
        if(pat[i]!=str[j])
            return false;
        i++, j++;
        if(i==M)
            i = 0;
    }
    return true;
}

int main() {
    int N ;

    //gets(str);
    while(scanf("%s", str)!=EOF) {
        N = strlen(str);
        makePref(N, str, pref);

        int ans = N-pref[N];
        str[ans] = 0;
        printf("%s\n", str);
    }
}
