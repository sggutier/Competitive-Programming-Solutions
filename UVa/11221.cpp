#include <bits/stdc++.h>
using namespace std ;

int test_case(string S) {
    int n=0;
    char tmp[100005];
    for(unsigned int i=0; i<S.size(); i++) {
        if(S[i]>='a' and S[i]<='z')
            tmp[n++] = S[i];
    }
    if(int(pow(int(sqrt(n)), 2))!=n) {
        return -1;
    }
    n = int(sqrt(n));
    for(int i=0; 2*i<n; i++) {
        for(int j=i; j<n-i; j++) {
            if(tmp[i*n + j] != tmp[j*n +i] || tmp[i*n + j] != tmp[(n-1-j)*n +(n-1-i)] || tmp[i*n + j] != tmp[(n-1-i)*n +(n-1-j)])
                return -1;
        }
    }
    return n;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    string tmp;
    getline(cin, tmp);
    sscanf(tmp.c_str(), "%d", &t);
    for(int i=1; i<=t; i++) {
        getline(cin, tmp);
        test_case(tmp);
        int ans = test_case(tmp);
        cout << "Case #" << i << ":\n" << (ans==-1? "No magic :(" : to_string(ans)) << endl;
    }
    
    return 0;
}
