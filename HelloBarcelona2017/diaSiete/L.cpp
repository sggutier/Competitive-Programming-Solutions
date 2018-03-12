#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

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

void testCase() {
    int dp[limN], sig[limN], ant[limN];
    int N = strlen(str)-1;
    str[N] = 0;
    int conto = 0;

    dp[N] = 0;
    for(int i=N-1; i>=0; i--) {
        dp[i] = dp[i+1]+1;
        sig[i] = 1;
        ant[i] = -1;
        makePref(N-i, str+i, pref);
        int w = N-i;
        for(int j=1; j<=w; j++) {
            int pos = j;
            while(2*pos>j)
                pos = pref[pos];
            
            //printf("%d (%d) ", pref[j], pos);
            if(pos<=1)
                continue;
            int sumo = dp[i+pos]+1;
            if(sumo < dp[i]) {
                dp[i] = sumo;
                sig[i] = pos;
                ant[i] = j;
            }
        }
        //printf(" => %c %d\n", str[i], dp[i]);
        //printf("\n");
    }

    printf("Typing this string will require %d operations\n", dp[0]);
    printf("These operations are the following:\n");
    // for(int i=N-1; i>=0; i--) {
    //     if(ant[i]==-1)
    //         printf("1 %c\n", str[i]);
    //     else
    //         printf("2 %d %d\n", ant[i], sig[i]);
    // }
    stack <int> ans;
    for(int pos=0; pos<N; pos+=sig[pos]) {
        ans.push(pos);
    }
    while(!ans.empty()) {
        int pos = ans.top(); ans.pop();
        if(ant[pos]==-1)
            printf("1 %c\n", str[pos]);
        else
            printf("2 %d %d\n", ant[pos]-2*sig[pos]+1, ant[pos]-sig[pos]);
    }
}

int main() {
    while(fgets(str, limN, stdin))
        testCase();
}
