#include <bits/stdc++.h>
using namespace std;
#define par pair<long long,int>
const int limN = 1e6 + 5;

int primCnt = 0;
//vector <int> primos;
int primos[79000];
bool comp[limN];

void criba() {
    for(int i=2; i*i<limN; i++)
        if(!comp[i])
            for(int j=i*i; j<limN; j+=i)
                comp[j] = true;
    for(int i=2; i<limN; i++)
        if(!comp[i])
            primos[primCnt++] = i;
    //cout << primCnt << endl;
}

vector <par> descPrim(long long n) {
    vector <par> ans;
    for(int i=0; i<primCnt; i++) {
        if(n%primos[i])
            continue;
        ans.push_back(par(primos[i], 0LL));
        int k = ans.size()-1;
        while(n%primos[i]==0) {
            n /= primos[i];
            ans[k].second++;
        }
        if(n==1)
            break;
    }
    if(n>1)
        ans.push_back(par(n,1));
    return ans;
}

long long divRecur(const vector<par> &facts, int pos, long long crg) {
    if(pos==-1) {
        return crg;
    }
    long long ans = divRecur(facts, pos-1, crg);
    for(int i=facts[pos].second; i; i--) {
        crg *= facts[pos].first;
        ans += divRecur(facts, pos-1, crg);
    }
    return ans;
}

long long divPropSum(long long n) {
    if(n==1LL)
        return 0LL;
    vector <par> d = descPrim(n);
    /*for(int i=0; i<d.size(); i++) {
        cout << d[i].first << " " << d[i].second << endl;
    }*/
    return divRecur(d, d.size()-1, 1LL) - n;
}

int main() {
    criba();

    int tc;
    for(scanf("%d", &tc); tc; tc--) {
        long long w, d ;
        scanf("%lld", &w);
        d = divPropSum(w);
        //cout << d << endl;
        if(d<w)
            printf("deficient\n");
        else if(d==w)
            printf("perfect\n");
        else
            printf("abundant\n");
    }

    return 0;
}
