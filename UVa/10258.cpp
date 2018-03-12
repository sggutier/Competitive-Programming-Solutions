#include <bits/stdc++.h>
using namespace std;
const int limN = 105;
const int limP = 12;
const int inf = 1e9;
#define par pair<int,int>
#define f first
#define s second
#define tri pair<int, par>

int penal[limN][limP];

void testCase() {
    memset(penal, 0, sizeof(penal));
    char str[limN];
    map <int, par> sbrd;
    while(gets(str) && str[0]) {
        int tm, pb, t;
        char c;
        sscanf(str, "%d %d %d %c", &tm, &pb, &t, &c);
        sbrd[tm];
        switch(c) {
        case 'I':
            penal[tm][pb] += 20;
            break;
        case 'C':
            if(penal[tm][pb]>=0) {
                auto it = sbrd.find(tm);
                it->second.first ++;
                it->second.second += penal[tm][pb] + t;
                penal[tm][pb] = -inf;
            }
            break;
        }        
    }
    tri arr[(int) sbrd.size()];
    int n = 0;
    for(const auto &T:sbrd) {
        arr[n++] = tri(-T.s.f, par(-T.s.s, T.f));
    }
    sort(arr, arr+n);
    for(int i=0; i<n; i++) {
        printf("%d %d %d\n", arr[i].s.s, -arr[i].f, -arr[i].s.f);
    }
}

int main() {
    int tc;
    char tmp[15];
    gets(tmp);
    sscanf(tmp, "%d", &tc);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        else
            gets(tmp);
        testCase();
    }
}
