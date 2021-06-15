#include <bits/stdc++.h>
using namespace std;

string toStr(int t) {
    char sa[20];
    sprintf(sa, "%02d:%02d\n", t/60, t%60);
    return sa;
}

bool isPal(string s) {
    for(int i=0; i<3; i++)
        if(s[i] != s[4-i])
            return false;
    return true;
}

int main() {
    int a, b ;
    int x = 0 ;
    scanf("%d:%d", &a, &b);
    for(int t=a*60 + b; !isPal(toStr(t)); x++, t=(t+1)%(60*24));
    printf("%d\n", x);
}
