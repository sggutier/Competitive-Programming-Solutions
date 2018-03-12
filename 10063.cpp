#include <bits/stdc++.h>
using namespace std;

void knuthRec(char *s, int n=0, string ans="") {
    if(*s==0) {
        printf("%s\n", ans.c_str());
        return;
    }
    for(int i=0; i<=n; i++)
        knuthRec(s+1, n+1, ans.substr(0, i) + s[0] + ans.substr(i, n-i));
}

int main() {
    char tmp[50];
    int tc=0 ;

    while(scanf("%s", tmp)!=EOF) {
        if(tc++)
            printf("\n");
        knuthRec(tmp);
    }
    
    return 0;
}
