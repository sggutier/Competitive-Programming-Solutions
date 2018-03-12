#include <bits/stdc++.h>
using namespace std;
vector<string> abos = {"AA", "AB", "AO", "BB", "BO", "OO"};
vector<string> abosN = {"A", "AB", "A", "B", "B", "O"};
vector<string> rhs = {"++", "+-", "--"};
vector<string> rhsN = {"+", "+", "-"};

string normu(const string &a, const string &r) {
    string ans = "";
    for(int i=abos.size()-1; i>=0; i--)
        if(abos[i]==a)
            ans += abosN[i];
    for(int i=rhs.size()-1; i>=0; i--)
        if(rhs[i]==r)
            ans += rhsN[i];
    return ans;
}

void pset(set <string> &s) {
    if(s.empty()) {
        printf("IMPOSSIBLE");
        return;
    }
    if(s.size() > 1)
        printf("{");
    bool fst = true;
    for(auto &a:s) {
        if(!fst)
            printf(", ");
        fst = false;
        printf("%s", a.c_str());
    }
    if(s.size() > 1)
        printf("}");
}

bool vafs(string &a1, string &r1, string &a2, string &r2, string &ac, string &rc) {
    string a="XX", r="XX";
    string cbo = normu(ac, rc);
    for(int i=0; i<2; i++) {
        a[0] = a1[i];
        for(int j=0; j<2; j++) {
            a[1] = a2[j];
            for(int x=0; x<2; x++) {
                r[0] = r1[x];
                for(int y=0; y<2; y++) {
                    r[1] = r2[x];
                    string p=a, q=r;
                    sort(p.begin(), p.end());
                    sort(q.begin(), q.end());
                    if(normu(p, q) == cbo)
                        return true;
                }
            }
        }
    }
    return false;
}

void testCase(string p1, string p2, string ch) {
    set <string> ap1, ap2, ach;
    if(p1!="?")
        ap1.insert(p1);
    if(p2!="?")
        ap2.insert(p2);
    if(ch!="?")
        ach.insert(ch);
    for(auto &a1:abos) {
        for(auto &r1:rhs) {
            if(p1 != "?" && normu(a1, r1)!=p1)
                continue;
            for(auto &a2:abos) {
                for(auto &r2:rhs) {
                    if(p2 != "?" && normu(a2, r2)!=p2)
                        continue;
                    for(auto &a3:abos) {
                        for(auto &r3:rhs) {
                            if(ch != "?" && normu(a3, r3)!=ch)
                                continue;                            
                            // cout << a1<<r1 << " ";
                            // cout << a2<<r2 << " ";
                            // cout << a3<<r3 << endl;
                            if(!vafs(a1, r1, a2,r2, a3, r3))
                                continue;
                            ap1.insert(normu(a1, r1));
                            ap2.insert(normu(a2, r2));
                            ach.insert(normu(a3, r3));
                        }
                    }
                }
            }
        }
    }

    pset(ap1);
    printf(" " );
    pset(ap2);
    printf(" " );
    pset(ach);
    printf("\n" );
}

int main() {
    char a[15], b[15], c[15];
    int tc = 1;
    while(scanf("%s%s%s", a, b, c)!=EOF && a[0]!='E') {
        printf("Case %d: ", tc++);
        testCase(a, b, c);
    }
}
