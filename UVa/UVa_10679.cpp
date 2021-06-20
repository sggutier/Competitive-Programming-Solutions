#include <bits/stdc++.h>
using namespace std;
const int limA = 1e6 + 5;
const int limB = 1005;

char A[limA];
char B[limB];

void testCase() {
    gets(A);
    int Q;
    gets(B);
    Q = atoi(B);
    char *c;

    while(Q--) {
        gets(B);
        bool works = true;
        for(int i=0; B[i]; i++) {
            if(A[i]!=B[i]) {
                works = false;
                break;
            }
        }
        if(works)
            putchar('y');
        else
            putchar('n');
        putchar('\n');
    }
}

int main() {
    gets(B);
    int tc = atoi(B);
    while(tc--)
        testCase();
}
