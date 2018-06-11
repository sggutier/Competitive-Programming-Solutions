// - A cloud that goes leftwards can only intersect with a cloud that goes rightwards
// - A cloud that goes rightwards can only intersect with clouds right to it
// - Two clouds that can intersect (one goes right, another left) at positions x_i and x_j
//   will intersect between times (x_j - x_i)/2 and (x_j + L - x_i)/2, independently from any
//   w
// - The only purpose of w is putting the clouds into place
// - If t is fixed, the values for w must be between -x_i / t -1 and (-x_j - L) / t +1 
//   (not inclusively)
// - In the above formulas, clearly a bigger value for t gives smaller absolute values for
//   the ranges of w.
// - Therefore, the biggest possible value for t ( just below (x_j + L - x_i)/2 ) must be taken.
// - Because of all of the above, two clouds can intersect if and only if the cloud at
//   x_i goes rightwards, the one at x_j goes leftwards, x_i < x_j, and
//   min( | -x_i / t -1 |, |  (-x_j - L) / t +1  | ) < maxW
// - The above last condition is equivalent to
//   min( | -2 * x_i  - t *2 |, |  2*(-x_j - L) + t*2  | ) < 2*t*maxW
// - It can be proven that if a cloud going right is able to cover the moon alongside another one,
//   it can cover the moon with another one located to the right of the one going left
// - Because of that one last thing, two vectors containing the clouds going left and right
//   can be made, then gaving two pointers moving them accordingly and then adding everything
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1e5 + 5;

ll maxW, L ;
int N ;
vector <int> ders, izqs;

bool funca(ll xi, ll xj) {
    ll t2 = xj+L-xi;
    return min(abs(-xi*2 - t2),
               abs((-xj-L)*2 + t2)) < t2*maxW;
}

int main() {
    ll ans = 0;
    
    scanf("%d%lld%lld", &N, &L, &maxW);
    for(int i=0, a,b; i<N; i++) {
        scanf("%d%d", &a, &b);
        if(b==-1)
            izqs.push_back(a);
        else
            ders.push_back(a);
    }
    sort(izqs.begin(), izqs.end());
    sort(ders.begin(), ders.end());

    N = izqs.size();
    int lp = 0;

    for(const int p : ders) {
        while(lp < N  &&  (izqs[lp] < p  || !funca(p, izqs[lp])) )
            lp ++;
        ans += N-lp;
    }

    printf("%lld\n", ans);
}
