#include <bits/stdc++.h>
using namespace std;
const int limReps = 300;
const int limN = 1e6 + 5;
const int limRul = 1e4 + 5;

char str[limN];

void testCase() {
    char reps[limReps];
    char rules[limRul][2];
    scanf("%s", str);
    int n = strlen(str), rulCnt;

    scanf("%d", &rulCnt);
    for(int i=0; i<limReps; i++)
        reps[i] = i;

    for(int i=0; i<rulCnt; i++) {
        char A[5], B[5];
        scanf("%s%s", A, B);
        rules[i][0] = B[0];
        rules[i][1] = A[0];
    }

    for(char a='A'; a<='Z'; a++) {
        char c = a;
        for(int i=0; i<rulCnt; i++) {
            if(c==rules[i][0])
                c = rules[i][1];
        }
        reps[(int) a] = c;
    }

    for(int i=0; i<n; i++)
        str[i] = reps[(int) str[i]];
    printf("%s\n", str);
}

int main() {
    int tc;

    scanf("%d", &tc);
    while(tc--)
        testCase();
    
    
    return 0;
}
