#include <stdio.h>
#include <string.h>
#define limN 1005

int combCnt = 0;
int readMsk[limN][256];

int readLinaro(int *ans) {
    int i;
    for(i='a'; i<='z'; i++)
        ans[i] = 0;
    int tmp ;
    tmp=getchar();
    if(tmp=='#') {
        getchar();
        return -1;
    }
    if(tmp==EOF)
        return 0;
    ans[tmp] ++;
    while((tmp=getchar())!=EOF && tmp!='\n') {
        ans[tmp] ++;
    }
    return 1;
}

void testCase() {
    int tmpo[256];
    int i, j;
    while(readLinaro(readMsk[++combCnt]) > 0);
    while(readLinaro(tmpo) > 0) {
        int ans = 0;
        for(i=0; i<combCnt; i++) {
            int works = 1;
            for(j='a'; j<='z'; j++) {
                if(tmpo[j]<readMsk[i][j]) {
                    works = 0;
                    break;
                }
            }
            ans += works;
        }
        printf("%d\n", ans);
    }
}

int main() {
    while(readLinaro(readMsk[combCnt=0])>0)
        testCase();
}
