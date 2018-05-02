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
