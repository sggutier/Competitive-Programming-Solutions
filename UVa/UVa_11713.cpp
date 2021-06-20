#include <bits/stdc++.h>
using namespace std;

inline bool isvowel(const char &a) {
    return a=='a' || a=='e' || a=='i' || a=='o' || a=='u';
}

bool testCase() {
    char A[100], B[100];
    int n;

    scanf("%s%s", A, B);
    n = strlen(A);
    if((int) strlen(B)!=n)
        return false;

    int dif = 0;
    for(int i=0; i<n; i++) {
        if(A[i]==B[i])
            continue;
        bool x=isvowel(A[i]), y=isvowel(B[i]);
        if(!x || !y)
            return false;
        dif ++;
    }
    return true;
}

int main() {
    int n;

    scanf("%d", &n);
    while(n--)
        printf("%s\n", testCase()? "Yes" : "No") ;
    
    return 0;
}
