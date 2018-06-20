// - The solution is like in the tutorial: https://apps.topcoder.com/wiki/display/tc/SRM+452
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 2505;
const int mod = 1e9 + 7;

int N, unoCnt = 0 ;
int dp[limN][limN];

class IOIString {
public:
	int countIOIs(vector <string> mask) {
    	string str = "" ;
        int pot2 = 1;
        for(const string &s : mask) {
            str += s;
        }
        N = str.size();
        vector <int> sums(N, 0);
        int first1 = N;
        for(int i=0; i<N; i++) {
            if(str[i]=='?')
                pot2 = (pot2*2) % mod;
            else if(str[i]=='I') {
                first1 = min(first1, i);
                sums[i] = 1;
            }
            if(i)
                sums[i] += sums[i-1];
        }
        
        int ans = first1==N? 1 : 0;
        for(int i=N-1; i>=0; i--) {
            if(str[i] == 'O')
                continue;
            for(int d=1; d+i < N; d+=2) {
                if(sums[i+d] - sums[i] > 0) {
                    if(str[i+d] == 'I' && sums[i+d] - sums[i] == 1)
                        dp[i][d] = (dp[i][d] + dp[i + d][d]) % mod;
                    break;
                }
                dp[i][d] = (dp[i][d] + dp[i + d][d]) % mod;
            }
            if(i <= first1) {
                if(unoCnt == 0)
                    ans = (ans + 1) % mod;
                for(int d=1; i + d < N; d += 2)
                    ans = (ans + dp[i][d]) % mod;
            }
            if(unoCnt == 0)
                for(int d=1; d < N; d+=2)
                    dp[i][d] = (dp[i][d] + 1) % mod;
            if(str[i]=='I')
                unoCnt++;
        }
        // printf("pot2 is %d\n", pot2);
        // printf("ans is %d\n", ans);
        return (pot2 + (mod - ans)%mod) % mod;
	}
};

int main() {
    string str;
    cin >> str;
    cout << IOIString().countIOIs({str}) << endl;
}
