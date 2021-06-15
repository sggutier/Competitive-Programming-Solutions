#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int N ;
int ord[limN];
int invos[limN];
int nums[limN], ans[limN];
map <int, vector<int> > zerop;
map <int, vector<int> > aprs;

int valo(int k) {
    return k;
    if(k > N)
        return N;
    if(k > N/2)
        return max(0, N - k);
    return k;
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &invos[i]);
        invos[i] --;
        ord[invos[i]] = i;
        ans[i] = N ;
    }
    for(int i=0; i<N; i++) {
        scanf("%d", &nums[i]);
        nums[i] = ord[nums[i]-1] ;
    }

    // zerop.insert(-10*N);
    // zerop.insert(10*N);
    for(int k=0, w; k<N; k++) {
        int ro, b ;
        w = nums[k];
        // printf("%d => ", invos[w] + 1);
        if(w == k)
            ro = 0;
        else if(k < w)
            ro = N - w + k;
        else
            ro = k-w;
        zerop[ro+w].push_back(ro);
        zerop[ro+w-N].push_back(ro-N);
        zerop[ro+w+N].push_back(ro+N);
        b = N - w -1 ;
        aprs[ro-b].push_back(ro);
        aprs[ro-N-b].push_back(ro-N);
        aprs[ro+N-b].push_back(ro+N);
        // printf("%d >> %d\n", ro, b);
        // printf("\t");
        // for(int i=0; i<N; i++)
        //     printf("%2d ", invos[nums[(i+ro)%N]] + 1);
        // printf("\n");
    }

    // for(const int z : zerop)
    //     printf("%d ", z);
    // printf("\n");

    auto r = zerop.end();
    r --;
    priority_queue <int> Q;
    for(int i=2*N-1; i>=0; i--) {
        // printf("%d >> %d\n", i, r->first);
        while(!Q.empty() && Q.top() > i)
            Q.pop();
        while(r->first > i)
            r --;
        if(r->first == i)
            for(const int w : r->second) {
                // printf("met %d %d\n", i, w);
                Q.push(w);
            }
        if(i >= N)
            continue;
        ans[i] = i - Q.top();
    }

    auto it = aprs.begin();
    set <int> inis;
    for(int i=-N; i<N; i++) {
        while(!inis.empty() && *inis.begin() < i)
            inis.erase(inis.begin());
        while(it->first < i)
            it ++;
        if(it->first == i)
            for(const int w : it->second) {
                // printf("met %d %d\n", i, w);
                inis.insert(w);
            }
        if(i < 0)
            continue;
        ans[i] = min(ans[i], *inis.begin() - i);
    }

    for(int i=0; i<N; i++)
        printf("%d\n", ans[i]);
}
