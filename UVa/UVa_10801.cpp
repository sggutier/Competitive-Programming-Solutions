#include <bits/stdc++.h>
using namespace std;
const int limN = 105;
const int inf = (1<<29);

bool nextInt(int &n) {
    n = 0;
    char tmp;
    // printf(" => [");
    while(scanf("%c", &tmp)!=EOF && !isdigit(tmp));
    // printf("%c", tmp);
    // printf("%c", tmp);
    n = tmp-'0';
    // printf("%d ", n);
    while(scanf("%c", &tmp)!=EOF && isdigit(tmp)) {
        n = n*10 + tmp-'0';
        // printf("%d", n);
    }
    // printf("]\n");
    // ycout << endl;
    return tmp==' ';
}

void testCase(int liftCnt, int fin) {
    vector<vector<int>> minP(limN, vector<int>(limN, inf));
    vector <int> speds(liftCnt);
    for(int i=0; i<liftCnt; i++)
        minP[i][i] = 0;
    for(int i=0; i<liftCnt; i++) {
        scanf("%d", &speds[i]);
        // cout << speds[i] << " " ;
    }
    // cout << endl;
    for(int i=0; i<liftCnt; i++) {
        list <int> avils;
        int tmp;
        while(true) {
            bool c = nextInt(tmp);
            avils.push_back(tmp);
            // printf("%d ", tmp);
            if(!c)
                break;
        }
        // printf("\n");
        for(const int &a:avils)
            for(const int &b:avils)
                minP[b][a] = minP[a][b] = min(minP[a][b], abs(a-b)*speds[i]);
    }
    for(int k=0; k<limN; k++) {
        for(int i=0; i<limN; i++) {
            for(int j=0; j<limN; j++) {
                minP[i][j] = min(minP[i][j], minP[i][k] + minP[k][j] + 60);
            }
        }
    }
    if(minP[0][fin]==inf)
        printf("IMPOSSIBLE\n");
    else
        printf("%d\n", minP[0][fin]);
}

int main() {
    int a, b;

    while(scanf("%d%d", &a, &b)!=EOF && (a || b))
        testCase(a, b);
    
    return 0;
}
