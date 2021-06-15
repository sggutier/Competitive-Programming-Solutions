#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

bool usd[limN];
int ans[limN];

int main() {
    set <int> lib;
    stack <int> s;
    
    int N, K;
    scanf("%d%d", &N, &K);
    for(int i=1; i<=K; i++) {
        scanf("%d", &ans[i]);
        usd[ans[i]] = true;
    }
    for(int i=1; i<=N; i++)
        if(!usd[i])
            lib.insert(-i);

    for(int i=1, j=1; i<=N; i++) {
        for(; s.empty() || s.top()!=i; j++) {
            int &k = ans[j];
            if(k==0) {
                if(s.empty())
                    k = -*lib.begin();
                else
                    k = -*lib.lower_bound(-s.top()+1);
                lib.erase(k);
            }
            if(!s.empty() && s.top() < k) {
                printf("-1\n");
                return 0;
            }
            s.push(k);
        }
        s.pop();
    }

    for(int i=1; i<=N; i++)
        printf("%d ", ans[i]);
    printf("\n");
}
