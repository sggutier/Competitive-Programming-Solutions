#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second

int numIg(pii A, pii B) {
    int ans = 0;
    if(A.f == B.f) ans++;
    if(A.f == B.s) ans++;
    if(A.s == B.f) ans++;
    if(A.s == B.s) ans++;
    return ans;
}

int getIg(pii A, pii B) {
    if(A.f == B.f) return A.f;
    if(A.f == B.s) return A.f;
    return A.s;    
}

int miScias(vector <pii> A, vector <pii> B) {
    set <int> igs;
    for(auto &a : A ) {
        for(auto & b : B) {
            if(numIg(a, b) == 1)
                igs.insert(getIg(a, b));
        }
    }
    return igs.size() == 1? *igs.begin() : -1;
}

bool gxiScias(vector <pii> A, vector <pii> B) {
    for(auto &a : A ) {
        set <int> igs;
        for(auto & b : B) {
            if(numIg(a, b) == 1)
                igs.insert(getIg(a, b));
        }
        if(igs.size() > 1)
            return false;
    }
    return true;
}

int main() {
    
    int N, M ;
    vector <pii> a, b ;
    int p ;
    bool q, r;
    
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a.push_back({x, y});
    }
    for(int i=0; i<M; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        b.push_back({x, y});
    }

    p = miScias(a, b);
    q = gxiScias(a, b);
    r = gxiScias(b, a);
    if(p != -1) {
        printf("%d\n", p);
        return 0;
    }

    if(q && r) {
        printf("0\n");
        return 0;
    }

    printf("-1\n");
}
