#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();
typedef pair<int,int> pii;

struct STree {
    vector <pii> vals;
    int n ;
    STree() {
        n = 0;
    }
    STree(const vector <int> &nums) {
        n = nums.size();
        vals = vector<pii>(2*n);
        vals.resize(2*n);
        for(int i=0; i<n; i++)
            vals[i+n] = {nums[i], i};
        for(int i=n-1; i>0; i--)
            vals[i] = min(vals[i<<1], vals[(i<<1)|1]);
    }
    pii __get(int l, int r) {
        pii ans = {INF, INF};
        for(l += n, r += n; l<r; l>>=1, r>>=1) {
            if(l & 1)
                ans = min(ans, vals[l++]);
            if(r & 1)
                ans = min(ans, vals[--r]);
        }
        return ans;
    }
    pii get(int l, int r) {
        return __get(min(l, r), max(l, r)+1);
    }
};

const int LIM_S = 1e5 + 5 ;

char tmp[LIM_S];
STree *st;
vector <pair<string, int>> nods;

void printTree(const int L, const int R) {
    if(R < L) return;
    int minPos = st->get(L, R).second;
    printf("(");
    printTree(L, minPos-1);
    printf("%s/%d", nods[minPos].first.c_str(), nods[minPos].second);
    printTree(minPos+1, R);
    printf(")");
}

void testCase(const int N) {
    vector <int> ns(N);
    nods.clear();
    nods.resize(N);
    for(int i=0, x; i < N; i++) {
        scanf("%s", tmp);
        for(int j=0; tmp[j]; j++) {
            if(tmp[j] != '/') continue;
            tmp[j] = 0;
            x = atoi(tmp + j + 1);
            nods[i] = {tmp, x};
            break;
        }
    }
    sort(nods.begin(), nods.end());
    for(int i=0; i < N; i++)
        ns[i] = -nods[i].second;
    st = new STree(ns);
    printTree(0, N-1);
    printf("\n");
    delete st ;
}

int main() {
    int N ;
    while(scanf("%d", &N) != EOF && N) {
        testCase(N);
    }
}
