#include <bits/stdc++.h>
using namespace std;
const int limN = 4e5 + 5;

int reps[limN];
int N, K;
int nums[limN], ord[limN];

int main() {
    long long ans ;

    scanf("%d%d", &N, &K);
    ans = N ;
    ans = ans*(ans+1) / 2;
    for(int i=0; i<N; i++) {
        scanf("%d", &nums[i]);
        ord[i] = i;
    }
    sort(ord, ord+N,
         [](const int a, const int b) {
             return nums[a] < nums[b];});
    for(int i=0, u=nums[ord[0]], c=0; i<N; i++) {
        int &k = nums[ord[i]];
        if(u != k)
            c++;
        u = k;
        k = c;
    }

    for(int l=0, r=0; r<N; r++) {
        int w = nums[r];
        reps[w] ++;
        while(reps[w] >= K)
            reps[nums[l++]] --;
        ans -= r+1-l;
    }

    printf("%lld\n", ans);
}
