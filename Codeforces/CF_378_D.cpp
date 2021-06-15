/*
- The priority in this problem is to minimize the amount of days for fixing the bugs, given
  that it fits in the budget.  Fixing it in more days surely would be cheaper, since a
  student can be made work more days.  This kind of thing makes one think a binary search
  would be feasible.
- For checking every instance of the binary search (one that has to be done in K days),
  the most difficult bug makes neccessary to hire a student with at least enough ability
  to fix it.  Hiring the cheapest one would be the best, since this student can be forced
  to fix the next K-1 bugs easier than the harder one since the objective is to get the
  job done in K days.
- This leaves the remaining bugs in the same conditions, having to hire the cheapest
  student and so on.
- For doing all this, the students and the bugs would have to be sorted, with complexity
  of O(n log n)
- For looking the cheapest one, a priority queue can be used.  Each instance of the binary
  search can be done in O(n log n), and since it takes at most n days to solve it,
  the binary search has O(log n) instances and  altogether takes O(n log^2 n).
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii, int> tri;
#define f first
#define s second
const int limN = 1e5 + 5;

int N, M, _S;
pii bugs[limN];
tri stus[limN];

bool funca(int K) {
    int S = _S;
    priority_queue <tri> Q ;
    for(int i=N-1, j=M-1; i>=0; i-=K) {
        while(j >= 0 && stus[j].f.s >= bugs[i].f) {
            Q.push(stus[j--]);
        }
        if(Q.empty())
            return false;
        tri w = Q.top(); Q.pop();
        if(S + w.f.f < 0)
            return false;
        S += w.f.f;
    }
    // printf("Funca con %d\n", K);
    return true;
}

void calcAns(int K, int * ans) {
    priority_queue <tri> Q ;
    for(int i=N-1, j=M-1; i>=0; i-=K) {
        while(j >= 0 && stus[j].f.s >= bugs[i].f) {
            Q.push(stus[j--]);
        }
        tri w = Q.top(); Q.pop();
        for(int k=0; k<K && i-k>=0; k++)
            ans[bugs[i-k].s] = w.s;
        // printf("Usando %d %d %d [%d %d]\n", w.f.f, w.f.s, w.s, bugs[i].f, bugs[i].s);
    }
}

int main() {
    int ans[limN];
    scanf("%d%d%d", &M, &N, &_S);
    for(int i=0; i<N; i++) {
        scanf("%d", &bugs[i].f);
        bugs[i].s = i;
    }
    for(int i=0; i<M; i++) {
        scanf("%d", &stus[i].f.s);
        stus[i].s = i;
    }
    for(int i=0; i<M; i++) {
        scanf("%d", &stus[i].f.f);
        stus[i].f.f *= -1;
    }

    sort(bugs, bugs+N);
    sort(stus, stus+M,
         [](const tri A, const tri B) {
             return A.f.s < B.f.s ;
         });

    // for(int i=0; i<N; i++)
    //     printf("%d %d\n", bugs[i].f, bugs[i].s);
    // for(int i=0; i<M; i++)
    //     printf("%d %d %d\n", stus[i].f.f, stus[i].f.s, stus[i].s);

    int ini=1, fin=N+1;
    while(ini < fin) {
        int piv = (ini+fin)/2;
        if(funca(piv))
            fin = piv;
        else
            ini = piv+1;
    }

    if(fin==N+1) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    calcAns(ini, ans);
    for(int i=0; i<N; i++)
        printf("%d ", ans[i]+1);
    printf("\n");
}
