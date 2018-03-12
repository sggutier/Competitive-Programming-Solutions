#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
typedef pair<par, int> tri;
#define f first
#define s second
const int limN = 2e5 + 5;

int main() {
    int N, T;
    priority_queue <par> Q;
    par ans(0, 0);
    tri nums[limN];

    scanf("%d%d", &N, &T);
    for(int i=0; i<N; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        nums[i] = tri(par(a, b), i);
    }
    sort(nums, nums+N);
    
    for(int i=N-1, s=0; i>=0; i--) {
        int a = nums[i].f.f, b = nums[i].f.s, c = nums[i].s;
        Q.push(par(b, c));
        // printf("Con %d %d (%d)\n", a, b, c);
        s += b;
        // printf("meto %d [%d %d]\n", b, s, T);
        while((int) Q.size() > a || s > T) {
            s -= Q.top().f;            
            // printf("saco %d [%d %d]\n", Q.top().f, s, T);
            Q.pop();
        }
        ans = max(ans, par(Q.size(), i));
    }
    while(!Q.empty())
        Q.pop();
    if(ans.f == 0) {
        printf("0\n");
        printf("0\n");
        printf("\n");
        return 0;
    }
    printf("%d\n", ans.f);
    printf("%d\n", ans.f);
    for(int i=N-1, s=0; i>=0; i--) {
        int a = nums[i].f.f, b = nums[i].f.s, c = nums[i].s;
        Q.push(par(b, c));
        s += b;
        while((int) Q.size() > a || s > T) {
            s -= Q.top().f;
            Q.pop();
        }
        if((int) Q.size() == ans.f) {
            while(!Q.empty()) {
                printf("%d ", Q.top().s+1);
                Q.pop();
            }
            printf("\n");
            break;
        }
    }
}
