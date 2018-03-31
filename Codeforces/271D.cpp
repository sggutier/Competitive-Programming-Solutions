#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod1 = 1e9 + 7;
ll mod2 = 1e8 + 7;
const int limN = 2000;

int sumo[limN];
char bumal[limN];
string str;
int buCnt[limN];

set <pair <int, int> > anso;

int main() {
    int N, K ;
    int ans = 0;
    
    scanf("%s", bumal);
    str = string(bumal);
    N = str.size();
    scanf("%s", bumal);
    scanf("%d", &K);
    
    for(int i='a'; i<='z'; i++)
        buCnt[i] = bumal[i-'a']=='0'? 1 : 0;
    for(int i=1; i<=N; i++)
        sumo[i] = sumo[i-1] + buCnt[(int) str[i-1]];
    
    for(int i=0; i<N; i++) {
        ll p = 0, q = 0;
        for(int j=i+1; j<=N; j++) {
            // printf("%d %d => %d %d | %s %d\n", i, j, sumo[i], sumo[j], str.substr(i, j-i).c_str(), sumo[j] - sumo[i]);
            p = (p*27 + str[j-1] - 'a' + 1) % mod1;
            q = (q*27 + str[j-1] - 'a' + 1) % mod2;
            if(sumo[j] - sumo[i] <= K) {
                anso.insert({p, q});
                // printf("%s es buena\n", str.substr(i, j-i).c_str());
            }
        }
    }

    ans = anso.size();
    printf("%d\n", ans);
}
