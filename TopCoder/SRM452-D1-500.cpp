#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 5005;
const int lim2 = limN*limN;
const int lim4 = lim2*4;
const int mod = 1e9 + 7;

vector <int> adj[2*lim4];

inline int neg(const int k) {
    return k + lim4;
}

inline int anum(const int i, const int j, const int t) {
    return t*lim2 + i*limN + j ;
}

class IOIString {
public:
	int countIOIs(vector <string> mask) {
    	string str ;
        ll pot2 = 1;
        int N ;
        for(const string &s : mask) {
            str += s;
            for(char c : s) {
                if(c != '?') continue;
                pot2 = (pot2 * 2) % mod;
            }
        }
        N = str.size();
        for(int i=0; i<N; i++) {
            for(int j=i+1, k=i+2; k<N; j++, k++) {
                if(str[i] == 'I' && str[j] == 'O' && str[k] == 'I')
                    return pot2;
            }
        }
        for(int i=0; i<N; i++) {
            adj[anum(i, i, 0)].push_back(neg(anum(i, i, 0)));
            adj[neg(anum(i, i, 0))].push_back(anum(i, i, 0));
            for(int j=i+1; j<N; j++) {
                // I?
                adj[anum(i, i, 0)].push_back(neg(anum(i, j, 0)));
                adj[anum(i, i, 0)].push_back(neg(anum(i, j, 1)));
                // O?
                adj[neg(anum(i, i, 0))].push_back(neg(anum(i, j, 2)));
                adj[neg(anum(i, i, 0))].push_back(neg(anum(i, j, 3)));
                // ?I
                adj[anum(j, j, 0)].push_back(neg(anum(i, j, 0)));
                adj[anum(j, j, 0)].push_back(neg(anum(i, j, 2)));
                // ?O
                adj[neg(anum(j, j, 0))].push_back(neg(anum(i, j, 1)));
                adj[neg(anum(j, j, 0))].push_back(neg(anum(i, j, 3)));
                // OO
                adj[anum(i, j, 0)].push_back(neg(anum(i, i, 0)));
                adj[anum(i, j, 0)].push_back(neg(anum(j, j, 0)));
                // OI
                adj[anum(i, j, 1)].push_back(neg(anum(i, i, 0)));
                adj[anum(i, j, 1)].push_back(anum(j, j, 0));
                // IO
                adj[anum(i, j, 2)].push_back(anum(i, i, 0));
                adj[anum(i, j, 2)].push_back(neg(anum(j, j, 0)));
                // II
                adj[anum(i, j, 3)].push_back(anum(i, i, 0));
                adj[anum(i, j, 3)].push_back(anum(j, j, 0));
            }
        }
	}
};

int main() {
    string str;
    cin >> str;
    cout << IOIString().countIOIs({str}) << endl;
}
