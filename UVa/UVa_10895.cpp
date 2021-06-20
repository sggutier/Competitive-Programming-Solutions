#include <bits/stdc++.h>
using namespace std;
const int limN = 1e4 + 5;

void testCase(int rowCnt, int colCnt) {
    list <int> cols;
    list <int> ansRows[colCnt], ansVals[colCnt];
    for(int i=0; i<rowCnt; i++) {
        cols.clear();
        int K, a;        
        scanf("%d", &K);
        for(int j=0; j<K; j++) {
            scanf("%d", &a);
            cols.push_back(a-1);
        }
        auto it = cols.begin();
        for(int j=0; j<K; j++, it++) {
            scanf("%d", &a);
            ansRows[*it].push_back(i);
            ansVals[*it].push_back(a);
        }
    }
    printf("%d %d\n", colCnt, rowCnt);
    for(int i=0; i<colCnt; i++) {
        printf("%d", (int) ansRows[i].size());
        bool fst ;
        fst = true;
        for(const int &a:ansRows[i]) {
            printf(" ");
            fst = false;
            printf("%d", a+1);
        }
        printf("\n");
        fst = true;
        for(const int &a:ansVals[i]) {
            if(!fst)
                printf(" ");
            fst = false;
            printf("%d", a);
        }
        printf("\n");
    }
}

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b)!=EOF)
        testCase(a, b);
}
