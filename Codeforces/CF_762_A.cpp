#include <bits/stdc++.h>
using namespace std;

int main() {
    set <long long> divs;

    long long n;
    int k;

    cin >> n >> k;

    for(long long i=1; i*i<=n; i++) {
        if(n%i==0) {
            divs.insert(i);
            divs.insert(n/i);
        }
    }

    if((int) divs.size() < k) {
        printf("-1\n");
        return 0;
    }

    for(auto it=divs.begin(); it!=divs.end(); it++) {
        if(--k)
            continue;
        cout << *it << endl;
        break;
    }
}
