#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii ;
#define f first
#define s second

priority_queue <pii> Q;

int main() {
    int N, K ;
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++) {
        int a ;
        scanf("%d", &a);
        Q.push({-a, i});
        if(i<K) continue;
        while(!Q.empty() && Q.top().s <= i-K)
            Q.pop();
        if(i!=K)
            printf(" ");
        printf("%d", -Q.top().f);
    }
    printf("\n");
}
