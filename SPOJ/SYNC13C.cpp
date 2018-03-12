#include <bits/stdc++.h>
using namespace std;
const int limN = 1003;

// bool gana[limN][limN];

int main() {
    int tc; 
    int R, C;

    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        scanf("%d%d", &R, &C);
        printf("%s\n", R%2==1 && C%2==1? "Ramesh" : "Suresh");
    }
    // return 0;
    
    // cin >> R >> C;
    // for(int r=1; r<=R; r++) {
    //     for(int c=1; c<=C; c++) {
    //         int nms[] = {r, c};
    //         for(int w=0; w<2; w++) {
    //             int k = nms[w];
    //             for(int i=1; i<k; i++) {
    //                 gana[r][c] |= (gana[min(i, k-i)][max(i, k-i)]==false);
    //                 // if(gana[i][k-i]==false)
    //                 //     printf("%d %d gana gracias a %d %d\n", r, c, i, k-i);
    //             }
    //         }
    //         printf("%c", gana[r][c]? 'Y' : 'N');
    //     }
    //     printf("\n");
    // }
}
