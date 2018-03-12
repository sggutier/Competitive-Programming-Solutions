#include <bits/stdc++.h>
using namespace std;

string A = "`1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}ASDFGHJKL:\"ZXCVBNM<>?";
string B = "`123qjlmfp/[]456.orsuyb;=789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+&*(AEHTDCK_)ZX<INWVG\"";

int main() {
    int n = A.size();
    int trad[300];
    for(int i=0; i<300; i++)
        trad[i] = i;
    for(int i=0; i<n; i++)
        trad[(int) A[i]] = B[i];
    char c;
    while((c=getchar())!=EOF) {
        printf("%c", trad[(int) c]);
    }
}
