#include <bits/stdc++.h>
using namespace std;
// const int LIM_N = 1e3;

int maxX ;
vector <int> nums;
int *ans = NULL;

void printNum(const int x) {
    for(int i=maxX-1; i >= 0; i--)
        printf("%d", ((1 << i) & x)? 1 : 0);
    printf("\n");
}

void bruta(const int pos, const int cnt = 0, const int msk = 0, const int ns = 0) {
    if(pos == -1) {
        if(msk) {
        ans[ns] = true;
        for(int b = (ns - 1) & ns; b > 0; b = (b-1) & ns)
            if(!ans[b]) {
                ans[ns] = false;
                break;
            }
        }
        if(!ans[ns]) return ;
        if(cnt != maxX) return;
        for(const int x : nums)
            printNum(x);
        // printf(" => %d\n", ans[ns]);
        printf("---------------\n");
        return ;
    }
    bruta(pos-1, cnt, msk, ns);
    nums.push_back(pos);
    bruta(pos-1, cnt + 1, msk ^ pos, ns | (1 << pos));
    nums.pop_back();
}

int main() {
    int x = 5;
    maxX = x;
    cout << (1LL << (1LL << x)) << endl;
    ans = new int[1LL << (1LL << x)];
    bruta((1 << x) - 1);
    int maxo = (1 << x) << x;
    for(int i=0; i < maxo; i++)
        printf("%d -> %d\n", i, ans[i]);
}

// 101
// 101
// 111
// 010
