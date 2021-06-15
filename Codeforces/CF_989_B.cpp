#include <bits/stdc++.h>
using namespace std;
const int limN = 5005;

int main() {
    int N, p;
    char str[limN];
    bool ans = false;

    scanf("%d%d%s", &N, &p, str);
    for(int i=0; i<p; i++) {
        set <int> tips ;
        for(int j=i; j<N; j+=p)
            if(str[j] != '.')
                tips.insert(str[j]);
        for(int j=i; j<N; j+=p) {
            if(str[j] == '.') {
                if(tips.count('0'))
                    str[j] = '1';
                else
                    str[j] = '0';
                tips.insert(str[j]);
            }
        }
        if(tips.size() == 2)
            ans = true;
    }

    printf("%s\n", ans? str : "No");
}
