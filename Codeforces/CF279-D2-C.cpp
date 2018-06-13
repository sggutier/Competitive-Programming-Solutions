#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int N ;
int nums[limN];
int li[limN];
int ld[limN];

bool query(int l, int r) {
    l--, r--;
    int ini = l, fin = r, piv;
    while(ini < fin) {
        piv = (ini+fin)/2 + 1;
        if(li[piv] <= l)
            ini = piv;
        else
            fin = piv-1;
    }
    return ld[r] <= ini;
}

int main() {
    int Q ;

    scanf("%d%d", &N, &Q);
    for(int i=0; i<N; i++) {
        scanf("%d", &nums[i]);
        ld[i] = li[i] = i;
        if(!i) continue;
        if(nums[i-1] <= nums[i])
            li[i] = li[i-1];
        if(nums[i-1] >= nums[i])
            ld[i] = ld[i-1];
    }

    while(Q--) {
        int a, b ;
        scanf("%d%d", &a, &b);
        printf("%s\n", query(a, b)? "Yes" : "No");
    }
}
