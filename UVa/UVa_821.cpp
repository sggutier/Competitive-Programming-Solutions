#include <bits/stdc++.h>
using namespace std ;
#define limN 105
#define inf 200

void test_case(int case_n, int a, int b) {
    int min_path[limN][limN];
    int path_num = 0, path_sum = 0;
    for(int i=0; i<105; i++) {
        for(int j=0; j<105; j++)
            min_path[i][j] = inf;
        min_path[i][i] = 0;
    }
    min_path[a][b] = 1;
    while(scanf("%d%d", &a, &b)!=EOF && (a!=0 || b!=0))
        min_path[a][b] = 1;
    for(int k=1; k<limN; k++) 
        for(int i=1; i<limN; i++) 
            for(int j=1; j<limN; j++)
                min_path[i][j] = min(min_path[i][j], min_path[i][k] + min_path[k][j]);
    for(int i=1; i<limN; i++) {
        for(int j=1; j<limN; j++) {
            if(min_path[i][j]%inf!=0) {
                path_num ++ ;
                path_sum += min_path[i][j];
            }
        }
    }
    printf("Case %d: average length between pages = %.3lf clicks\n", case_n, (path_sum*1.0)/path_num);
}

int main() {
    int a, b;
    int tc = 1;

    while(scanf("%d%d", &a, &b)!=EOF && (a!=0 || b!=0)) {
        test_case(tc++, a, b);
    }
    
    return 0;
}
