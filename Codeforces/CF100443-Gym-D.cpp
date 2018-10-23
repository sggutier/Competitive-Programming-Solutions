#include <bits/stdc++.h>
using namespace std;
const int limN = 105;

string genNext(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    for(char &c : rev)
        if(c != '(' && c != ')')
           c = c=='L'? 'R' : 'L';
        else
            c = c=='('? ')' : '(';
    // return "(" + s +")" + "L" + "(" + rev + ")";
    return s + "L" + rev;
}


char str[limN];

int brec(int n) {
    int ans = 1;
    int k = 1;
    while(k < n) {
        k = k*2 + 1;
        ans ++;
    }
    return ans;
}

bool igl(int l, int r, int p, int lev);
bool fca(int l, int r, int dir, int lev);

bool igl(int l, int r, int p, int lev) {
    if(r <= l)
        return true;
    printf("igl %d %d %d, lev %d\n", l, r, p, lev);
    for(int k=1;  l <= p-k && p+k <= r;  k++)
        if(str[p-k] == str[p+k])
            return false;
    return fca(l, p-1, -1, lev-1) && fca(p+1, r, 1, lev-1);
}


bool fca(int l, int r, int dir, int lev) {
    printf("fca %d %d %d\n", l, r, dir);
    int dd=1, n = r-l+1;
    for(; dd <= n; dd <<= 1);
    dd >>= 1;
    dd --;
    int p = (l==1? l + dd : r - dd);
    int nl = brec(dd) + 1;
    if(nl == lev-1) {
        if(  (dir==1) != (str[p] == 'R') )
            return false;
    }
    else {
        if(  (dir==1) != (str[p] == 'L') )
            return false;
    }
    return igl(l, r, l==1? l + dd : r - dd, nl);
}


bool testCase() {
    int D ;
    scanf("%d%s", &D, str);
    int N = strlen(str);
    for(int i=0, w; i<N; i++) {
        w = max(brec(i), brec(N-1-i));
        if(w >= D && str[i] == 'R')
            continue;
        for(w++; w <= D; w++)
            if(igl(0, N-1, i, w))
                return true;
    }
    return false;
}


int main() {
    string s = "L";
    for(int i=0; i<10; i++) {
        printf("%d\n", i);
        printf("%s\n", s.c_str());
        s = genNext(s);
    }
    return 0;
    int tc;
    scanf("%d", &tc);
    for(int i=1; i<=tc; i++)
        printf("Case %d: %s\n", i, testCase()? "Yes" : "No");
}
