#include <bits/stdc++.h>
using namespace std;

void testCase() {
    int n ;
    vector <int> letVals(300, 0);
    int ans = 0;

    scanf("%d\n", &n);
    for(; n; n--) {
        unsigned char a;
        int v;
        scanf("%c %d\n", &a, &v);
        letVals[a] = v;
    }
    scanf("%d\n", &n);
    while(n) {
        unsigned char a;
        if(scanf("%c", &a)==EOF)
            a = '\n';
        // printf("%hhu", a);        
        if(a=='\n') {
            n --;
            continue;
        }
        ans += letVals[a];
    }

    printf("%d.%02d$\n", ans/100, ans%100);
}

int main() {
    int tc ;

    for(scanf("%d", &tc); tc; tc--) {
        testCase();
    }
    
    return 0;
}
