#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int n;
    scanf("%d", &n);
    vector <int> dirs(n);
    char S[500];
    int pos = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s", S);
        if(S[0]=='L')
            dirs[i] = -1;
        else if(S[0]=='R')
            dirs[i] = 1;
        else {
            int k;
            scanf("%s%d", S, &k);
            dirs[i] = dirs[k-1];
        }
        pos += dirs[i];
    }
    printf("%d\n", pos);
}

int main() {
    int tc;

    for(scanf("%d", &tc); tc; tc--)
        testCase();
    
    return 0;
}
