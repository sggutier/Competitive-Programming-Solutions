#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void calcProb(int n) {
    int p = 0, t = 0 ;
    int nums[n];
    for(int i=0; i < n; i++) nums[i] = i;
    do {
        t ++ ;
        p ++ ;
        for(int i=0; i < n; i++) if(nums[i] == i) {
                p -- ;
                break;
            }
    }while(next_permutation(nums, nums+n));
    printf("\"%d/%d\", ", p, t);
}

int main() {
    // for(int i=2; i <= 12; i++)
    //     calcProb(i);
    // printf("\n");
    string ans[] = {"1/2", "2/6", "9/24", "44/120", "265/720", "1854/5040", "14833/40320", "133496/362880", "1334961/3628800", "14684570/39916800", "176214841/479001600"};
    int tc, n ;
    for(scanf("%d", &tc); tc; tc--) {
        scanf("%d", &n);
        puts(ans[n-2].c_str());
    }
}
