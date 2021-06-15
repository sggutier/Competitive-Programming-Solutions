#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll ;
const int LIM_N = 1e5 + 5 ;

// c <= a - b
// b <= a - c
// if ints, b < a - c + 1

template <class T>
using Tree = tree<T, null_type, less_equal<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;

int N ;
ll nms[LIM_N];

ll numKs(const ll c) {
    Tree <ll> tree ;
    tree.insert(0);
    ll ans = 0, sm = 0 ;

    for(int i=0; i < N; i++) {
        sm += nms[i];
        ans += tree.order_of_key(sm -c + 1);
        tree.insert(sm);
    }

    return ans ;
}

int main() {
    ll K ;
    scanf("%d%lld", &N, &K);
    for(int i=0; i < N; i++)
        scanf("%lld", &nms[i]);

    ll ini = -1e14, fin = -ini;
    while(ini < fin) {
        ll piv = (ini + fin) / 2 ;
        if(piv == ini) piv ++ ;
        if(numKs(piv) >= K)
            ini = piv ;
        else
            fin = piv - 1;
    }

    printf("%lld\n", ini);
}
