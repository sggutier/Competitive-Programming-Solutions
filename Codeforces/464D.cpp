#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
typedef pair<par, int> tri;
#define f first
#define s second

set <tri> vst;

void cta(int n, int k, int l=1) {
    if(n==0 || k==0)
        return ;
    if(vst.count(tri(par(n, k), l)) )
        return ;
    vst.insert(tri(par(n, k), l));
    cta(n-1, k, l);
    cta(n-1, k, l+1);
    cta(n, k-1);
}

int main() {
    int n, k;
    cin >> n >> k;
    cta(n, k);
    cout << ((int) vst.size()) << endl;
}
