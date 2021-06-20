#include <bits/stdc++.h>
using namespace std;

map <string, int> roToI;
string iToRo[4000];

string lets[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
int vals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
int S = 13;

void precarga(int N=4000) {
    for(int i=1; i<N; i++) {
        int w = i;
        string ans = "";
        for(int j=0; j<S; j++) {
            while(w>=vals[j]) {
                w -= vals[j];
                ans += lets[j];
            }
        }
        iToRo[i] = ans;
        roToI[ans] = i;
    }
}

void testCase(char *S) {
    if(isdigit(S[0])) {
        int k;
        sscanf(S, "%d", &k);
        printf("%s\n", iToRo[k].c_str());
    }
    else {
        printf("%d\n", roToI[S]);
    }
}

int main() {
    precarga();
    char S[60];
    while(gets(S))
        testCase(S);
}
