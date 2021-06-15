#include <bits/stdc++.h>
using namespace std;

int main() {
    char str[5];
    scanf("%s", str);
    int ans = -1;

    for(int x=-1; x<=1; x++)
        for(int y=-1; y<=1; y++)
            if('a' <= str[0]+x && str[0]+x <='h'
               && '1' <= str[1]+y && str[1]+y <='8')
                ans ++;

    printf("%d\n", ans);
}
