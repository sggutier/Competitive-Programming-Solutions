#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

char strA[limN];
char strB[limN];

int main() {
    scanf("%s", strA);
    scanf("%s", strB);
    int N = strlen(strA);
    int B = strlen(strB);
    printf("%d\n", ((strA[N-1]-'0')*(strB[B-1]-'0')) % 10);
}
