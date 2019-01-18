#include <bits/stdc++.h>
using namespace std;

set <int> nms;

int main() {
    int n, k ;
    scanf("%d%d", &n, &k);
    for(int i=0, a; i<n; i++) {
        scanf("%d", &a);
        nms.insert(a);
    }

    int lst = 0;
    for(auto it=nms.begin(); k; k--) {
        if(it==nms.end())
            printf("0\n");
        else {
            printf("%d\n", *it - lst);
            lst = *it;
            it++;
        }
    }
}
