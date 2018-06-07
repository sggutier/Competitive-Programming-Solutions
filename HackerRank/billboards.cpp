// - The problem can be viewed as picking the billboards to be deleted in such a way that
//   the space between the deleted ones and the border is no more than k.  The sum of all
//   can be added at the end to get the answer to the problem.
// - This can be done with a dp, the answer for each billboard being the least expensive dp
//   to come from.  A priority queue can be used for getting the smallest one fastly, just
//   getting out of it the ones that are outside the range.
// - For the above to work, the positions 0 and N+1 have to be considered as billboards with
//   cost 0 and the dp of 0 being 0.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
#define f first
#define s second

int main() {
    int N, K;
    ll sumo = 0;
    priority_queue <pli> Q;

    Q.push({0, 0});

    scanf("%d%d", &N, &K);
    K ++;
    for(int i=1, a; i<=N; i++) {
        scanf("%d", &a);
        sumo += a;
        while(Q.top().s < i-K)
            Q.pop();
        Q.push({Q.top().f - a, i});
    }
    while(Q.top().s < N+1-K)
        Q.pop();

    printf("%lld\n", sumo + Q.top().f);
}
