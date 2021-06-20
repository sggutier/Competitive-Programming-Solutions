#include <bits/stdc++.h>
using namespace std;

int req[300];

// string toBin(int n) {
//     string ans = "";
//     while(n) {
//         ans = (n%2? "1" : "0") + ans;
//         n /= 2;        
//     }
//     return ans;
// }

void testCase(int f, int w) {
    int msk = (1<<12)-1;
    int maxLen = 0;
    set <string> ans;
    for(int i=0; i<f; i++) {
        int  t;
        scanf("%d", &t);
        msk ^= (1<<t);
    }
    for(int i=0; i<w; i++) {
        char str[55];
        int m = 0, n=0;
        scanf("%s", str);
        for(char *c=str; *c; c++, n++) {
            m |= (1<<req[(int) *c]);
        }
        //cout << str << " " << toBin(m) << " " << toBin(m & msk) << endl;
        if((m & msk)!=m)
            continue;
        if(n>maxLen) {
            maxLen = n;
            ans.clear();
        }
        if(n==maxLen)
            ans.insert(str);
    }
    printf("%d\n", (int) ans.size());
    for(const string &s:ans)
        printf("%s\n", s.c_str());
}

int main() {
    req['q'] = 1;
    req['a'] = 1;
    req['z'] = 1;
    req['w'] = 2;
    req['s'] = 2;
    req['x'] = 2;

    req['e'] = 3;
    req['d'] = 3;
    req['c'] = 3;

    req['r'] = 4;
    req['f'] = 4;
    req['v'] = 4;
    req['t'] = 4;
    req['g'] = 4;
    req['b'] = 4;

    req['y'] = 7;
    req['h'] = 7;
    req['n'] = 7;
    req['u'] = 7;
    req['j'] = 7;
    req['m'] = 7;

    req['i'] = 8;
    req['k'] = 8;
    req[','] = 8;

    req['o'] = 9;
    req['l'] = 9;
    req['.'] = 9;

    req['p'] = 10;
    req[';'] = 10;
    req['/'] = 10;

    int f, w;
    while(scanf("%d%d", &f, &w)!=EOF) {
        testCase(f, w);
    }
}
