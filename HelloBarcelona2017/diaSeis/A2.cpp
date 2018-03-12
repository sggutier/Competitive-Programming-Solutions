#include <bits/stdc++.h>
using namespace std;

set <int> S;
set <int> R;

int main() {
    char tmp[15];
    int n ;
    while(scanf("%s%d", tmp, &n)!=EOF) {
        if(tmp[0]=='i') {
            S.insert(n);
            R.insert(-n);
        }
        else if(tmp[0]=='d') {
            S.erase(n);
            R.erase(-n);
        }
        else if(tmp[0]=='e') {
            printf("%s\n", !S.count(n)? "false" : "true");
        }
        else if(tmp[0]=='n') {
            auto it = S.upper_bound(n);
            if(it!=S.end())
                printf("%d\n", *it);
            else
                printf("none\n");
        }
        else if(tmp[0]=='p') {
            auto it = R.upper_bound(-n);
            if(it!=R.end())
                printf("%d\n", -*it);
            else
                printf("none\n");
        }
        else {
            //tr.printa();
            printf("*shrugs*\n");
            // for(const auto &p:S)
            //     printf("%d ", p);
            // printf("\n");
            // for(const auto &p:R)
            //     printf("%d ", -p);
            // printf("\n");
        }
    }
}
