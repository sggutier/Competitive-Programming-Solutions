#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int LIM_N = 1e5 + 5;

int cnt[255];

int main() {
    vector<string> strs = {
        ";-)", ";-(", ":)", ":(", ":-\\", ":-P", ":D", ":C", ":-0", ":-|", "8-0", ":-E", "%0", ":-X", ":~(", "[:|||:]"
    };
    int N = strs.size();
    vector <bool> usd(N);
    char S[LIM_N];

    scanf("%s", S);
    for(char *c = S; *c; c++)
        cnt[(int) *c] ++;

    for(int w=0; w < 2; w++)
    for(int i=0; i < N; i++) {
        if(usd[i]) continue;
        bool fnd = 0 ;
        for(char c : strs[i]) {
            bool wks = true;
            for(int j=0; j < N; j++) {
                if(i == j || usd[j]) continue;
                for(char x : strs[j])
                    if(x == c)
                        wks = false;
            }
            if(wks) {
                // printf("%c => %s\n", c, strs[i].c_str());
                int x = c ;
                for(int a = cnt[x]; a; a--) {
                    printf("%s\n", strs[i].c_str());
                    for(char z : strs[i]) {
                        cnt[(int) z] --;
                    }
                }
                fnd = true;
                break;
            }
        }
        usd[i] = fnd;
    }

    for(int i=0; i < N; i++) {
        if(usd[i]) continue;
        int minV = cnt[(int) strs[i][0]];
        for(char c : strs[i])
            minV = min(minV, cnt[(int) c]);
        for(int a = minV; a; a--) {
            printf("%s\n", strs[i].c_str());
            for(char z : strs[i]) {
                cnt[(int) z] --;
            }
        }
    }

    printf("LOL\n");
}
