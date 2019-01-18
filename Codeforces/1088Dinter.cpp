#include <bits/stdc++.h>
using namespace std;

int main() {
    FILE *f = fopen("D.in", "r");
    int a, b ;
    fscanf(f, "%d%d", &a, &b);

    string s;
    int c, d;
    int tot = 0;
    do {
        tot ++;
        cin >> s >> c >> d;
        int x = a^c, y = b^d;
        int res = 0;
        if(x != y)
            res = x < y? -1 : 1;
        printf("query %s %d %d\n", s.c_str(), c, d);
        printf("res = %d\n", res);
    } while(s != "!") ;

    if(a == c && b == d)
        printf("bien\n");
    printf("tot = %d\n", tot);
}
