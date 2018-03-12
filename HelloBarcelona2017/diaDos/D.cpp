#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair <int,int> pt;
typedef pair <pt,pt> ln;

char ins[2500];
pt a, b;
ln l;

set <pt> pt_s;
set <ln> ln_s;

int ct = 1;

int main() {
    scanf("%s", ins);

    b = make_pair(0,0);
    pt_s.insert(make_pair(0,0));

    for(int i=0;i<strlen(ins);i++) {
        a = b;

        switch(ins[i]) {
            case 'L':
                b = make_pair(a.x-1, a.y);
                break;
            case 'R':
                b = make_pair(a.x+1, a.y);
                break;
            case 'U':
                b = make_pair(a.x, a.y+1);
                break;
            case 'D':
                b = make_pair(a.x, a.y-1);
                break;
        }

        l = make_pair(a, b);

        if(l.second < l.first)
            swap(l.first, l.second);

        if(ln_s.find(l) == ln_s.end()) {
            ln_s.insert(l);

            if(pt_s.find(b) != pt_s.end()) {
                ct++;
            }

            pt_s.insert(b);
        }

    }

    printf("%d\n", ct);

    return 0;
}
