#include <bits/stdc++.h>
using namespace std;
const int inf = (1<<29);

void testCase(int w) {
    vector <vector<int>> minP( 20, vector<int> (20, inf));
    for(int i=0; i<20; i++)
        minP[i][i] = 0;
    for(int i=0; i<w; i++) {
        int a;
        scanf("%d", &a);
        a--;
        minP[0][a] = minP[a][0] = 1;
    }
    for(int b=1; b<19; b++) {
        scanf("%d", &w);
        for(int i=0; i<w; i++) {
            int a;
            scanf("%d", &a);
            a--;
            minP[b][a] = minP[a][b] = 1;
        }
    }
    for(int k=0; k<20; k++)
        for(int i=0; i<20; i++)
            for(int j=0; j<20; j++)
                minP[i][j] = min(minP[i][j], minP[i][k] + minP[k][j]);

    int querCnt;
    scanf("%d", &querCnt);
    while(querCnt--) {
        int a, b;        
        scanf("%d%d", &a, &b);
        // cout << a << " " << b << endl;
        printf("%2d to %2d: %d\n", a, b, minP[a-1][b-1]);
    }
}

int main() {
    int w;
    int tc=0;

    while(scanf("%d", &w)!=EOF && w) {
        // if(tc++)
        //     printf("\n");
        printf("Test Set #%d\n", ++tc);
        testCase(w);
        printf("\n");
    }
    // printf("\n");
    
    return 0;
}


