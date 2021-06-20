#include <bits/stdc++.h>
using namespace std;

char ledsStr[10][10] = {"YYYYYYN",
                     "NYYNNNN",
                     "YYNYYNY",
                     "YYYYNNY",
                     "NYYNNYY",
                     "YNYYNYY",
                     "YNYYYYY",
                     "YYYNNNN",
                     "YYYYYYY",
                     "YYYYNYY"};
int leds[10];

void precarga() {
    for(int i=0; i<10; i++) {
        for(int j=0; j<7; j++)
            if(ledsStr[i][j]=='Y')
                leds[i] |= (1<<j);
    }
}

bool works(const int &N, const int *msks, int pos) {
    for(int i=0, m=(1<<7)-1; i<N; i++, pos--) {
        int b = m & leds[pos];        
        if(b!=(b | msks[i]))
            return false;
        m -= (b - msks[i]);
    }
    return true;
}

void testCase(int N) {
    char tmp[15];
    int msks[10];
    for(int i=0; i<N; i++) {
        scanf("%s", tmp);
        msks[i] = 0;
        for(int j=0; j<7; j++)
            if(tmp[j]=='Y')
                msks[i] |= (1<<j);
    }

    for(int i=9; i>=N-1; i--) {
        if(works(N, msks, i)) {
            printf("MATCH\n");
            return;
        }
    }
    printf("MISMATCH\n");
}

int main() {
    precarga();
    int n;
    while(scanf("%d", &n)!=EOF && n)
        testCase(n);
}
