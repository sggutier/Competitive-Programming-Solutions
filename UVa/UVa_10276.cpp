#include <bits/stdc++.h>
using namespace std;

bool isSqr(int n) {
    int rt = sqrt(n);
    for(int i=rt-2; i < rt+3; i++)
        if(i * i == n)
            return true;
    return false;
}

int main() {
    // vector <int> pgs(55);
    // int maxP = 0 ;
    // for(int x=1; maxP <= 50 ; x++) {
    //     int pos = 0 ;
    //     for(int j=0; j < 55; j++) {
    //         if(!pgs[j] || isSqr(pgs[j] + x)) {
    //             pos = j ;
    //             break;
    //         }
    //     }
    //     pgs[pos] = x;
    //     if(pos <= maxP)
    //         continue;
    //     maxP = pos;
    //     printf("%d, ", x);
    // }
    int ans[] = {0, 2, 4, 8, 12, 18, 24, 32, 40, 50, 60, 72, 84, 98, 112, 128, 144, 162, 180, 200, 220, 242, 264, 288, 312, 338, 364, 392, 420, 450, 480, 512, 544, 578, 612, 648, 684, 722, 760, 800, 840, 882, 924, 968, 1012, 1058, 1104, 1152, 1200, 1250, 1300, 1352};
    int tc ;
    scanf("%d", &tc);
    for(int i=0, a; i < tc; i++) {
        scanf("%d", &a);
        printf("%d\n", ans[a] - 1);
    }
}
