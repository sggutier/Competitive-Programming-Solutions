#include <bits/stdc++.h>
using namespace std;
const int limN = 40;

// int pat[limN][limN][limN][limN];

int proco(int x, int y, int z, int d) {
    int arr[3] = {x, y, z};
    sort(arr, arr+3);
    int ans = arr[0]*2;
    int wo ;
    arr[1] -= arr[0];
    arr[2] -= arr[0];
    arr[0] = 0;
    wo= min(arr[2], d);
    ans += wo;
    arr[2] -= wo;
    d -= wo;
    wo= min(arr[1], d);
    ans += wo;
    d -= wo;
    arr[1] -= wo;
    ans += d/3;
    ans += arr[1];
    return ans;
}

void testCase() {
    int N;
    scanf("%d", &N);
    char S[3][N+5];

    for(int i=0; i<3; i++) {
        scanf("%s", S[i]);
    }

    int a=0, b=0, c=0, d=0;
    int ans = 0;

    for(int i=0; i<N; i++) {
        if(S[0][i]==S[1][i] && S[1][i]==S[2][i]) {
            ans ++;
        }
        else if(S[0][i]!=S[1][i] && S[1][i]!=S[2][i] && S[0][i]!=S[2][i]) {
            d ++;
        }
        else if(S[0][i]==S[1][i])
            c++;
        else if(S[0][i]==S[2][i])
            b++;
        else
            a++;
    }

    printf("%d\n", ans + proco(a, b, c, d));
}

// int main() {
//     for(int i=0; i<limN; i++) {
//         for(int j=0; j<limN; j++) {
//             for(int k=0; k<limN; k++) {
//                 for(int w=0; w<limN; w++) {
//                     if(i && w)
//                         pat[i][j][k][w] = max(pat[i][j][k][w],
//                                               pat[i-1][j][k][w-1] + 1);
//                     if(j && w)
//                         pat[i][j][k][w] = max(pat[i][j][k][w],
//                                               pat[i][j-1][k][w-1] + 1);
//                     if(k && w)
//                         pat[i][j][k][w] = max(pat[i][j][k][w],
//                                               pat[i][j][k-1][w-1] + 1);
//                     if(w>=3)
//                         pat[i][j][k][w] = max(pat[i][j][k][w],
//                                               pat[i][j][k][w-3] + 1);
//                     if(i && j && k)
//                         pat[i][j][k][w] = max(pat[i][j][k][w],
//                                               pat[i-1][j-1][k-1][w] + 2);
//                     if(pat[i][j][k][w] != proco(i,j,k,w)) {
//                         //printf("%d \n");
//                         printf("%d %d %d %d => %d (%d)\n", i, j, k, w, pat[i][j][k][w], proco(i, j, k, w));
//                         getchar();
//                     }
//                 }
//             }
//         }
//         //getchar();
//     }
//     return 0;

//     for(int anso=0; anso<100; anso++) {
//         printf("%d ==== \n", anso);
//         for(int i=0; i<limN; i++) {
//         for(int j=i; j<limN; j++) {
//             for(int k=j; k<limN; k++) {
//                 for(int w=0; w<limN; w++) {
//                     if(pat[i][j][k][w] == anso)
//                         printf("%d %d %d %d => %d (%d)\n", i, j, k, w, pat[i][j][k][w], proco(i, j, k, w));
//                 }
//             }
//         }
//         }
//         getchar();
//     }
// }

int main() {
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++)
        testCase();
}
