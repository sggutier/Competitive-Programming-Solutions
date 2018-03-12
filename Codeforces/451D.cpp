#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ans[] = {0, 0};
    long long cnt[2][2] = {{0, 0}, {0, 0}};
    string str;
    cin >> str;
    for(int i=0; i<(int) str.size(); i++) {
        int pos = str[i]-'a', pd = i%2;
        ans[0] += cnt[pos][1-pd];
        ans[1] += cnt[pos][pd]+1;
        cnt[pos][pd]++;
    }
    cout << ans[0] << " " << ans[1] << endl;
}
