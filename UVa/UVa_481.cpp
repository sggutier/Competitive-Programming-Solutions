#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>
const int inf = (1<<30);

int main() {
    vector <par> maxS(1, par(-inf, 1));
    vector <int> prev;
    vector <int> arr;
    par srx = par(0, 1);

    while(scanf("%d", &srx.first)!=EOF) {
        srx.second --;
        arr.push_back(srx.first);
        vector <par>::iterator it = lower_bound(maxS.begin(), maxS.end(), srx);
        if(it==maxS.end()) {
            prev.push_back(-maxS[maxS.size()-1].second);
            maxS.push_back(srx);
        }
        else {
            *it = srx;
            prev.push_back(-((it-1)->second));
        }
    }

    int pos = -maxS[maxS.size()-1].second;
    stack <int> ans;

    while(pos!=-1) {
        ans.push(pos);
        pos = prev[pos];
    }
    printf("%d\n-\n", (int)(ans.size()) );
    while(!ans.empty()) {
        printf("%d\n", arr[ans.top()]); ans.pop();
    }
    
    return 0;
}
