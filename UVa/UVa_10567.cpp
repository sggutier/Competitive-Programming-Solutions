#include <bits/stdc++.h>
using namespace std;
const int limN = 52;
const int limS = 1e6 + 5;

int toNum(const char &a) {
    if(isupper(a))
        return a - 'A';
    else
        return a -'a' + 26;
}

vector <int> idexi[limN];
char str[limS];

void proca() {
    char *s = str;
    int pos = 0;
    while(*s) {
        idexi[toNum(*(s++))].push_back(pos++);
    }
}

void testCase() {
    char *s = str;
    int pos = -1;
    int ini=-1, fin=0;
    vector <int> *k;
    while(*s) {
        k = &idexi[toNum(*s++)];
        auto it = upper_bound(k->begin(), k->end(), pos);
        if(it == k->end()) {
            printf("Not matched\n");
            return;
        }
        pos = *it;
        if(ini==-1)
            ini = pos;
        fin = pos;
    }
    printf("Matched %d %d\n", ini, fin);
}

int main() {
    gets(str);
    proca();
    gets(str);
    int tc;
    sscanf(str, "%d", &tc);
    while(tc--) {
        gets(str);
        testCase();
    }
}
