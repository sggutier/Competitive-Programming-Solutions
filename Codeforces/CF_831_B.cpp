#include <bits/stdc++.h>
using namespace std;

char convo[300];

int main() {
    string A, B, C ;

    cin >> A >> B >> C ;
    for(int i=0; i<26; i++) {
        convo[(int) A[i]] = B[i];
        convo[toupper(A[i])] = toupper(B[i]);
    }
    for(int i='0'; i<='9'; i++)
		convo[i] = i;

    for(char c : C)
        printf("%c", convo[(int) c]);
    printf("\n");
}
