#include <bits/stdc++.h>
using namespace std ;

pair <int, int> testCase(int b_size, int pos) {
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    int n = (int) sqrt(pos) - ((((int) sqrt(pos)%2)==0 && pos!=0)? 1 : 0);
    int last = n*n;
    int x, y;
    y = (x = (n-1)/2 + (b_size+1)/2) + (pos==0? 0 : 1);
    for(int d=0; d<4; d++) {
        if(last + n >= pos) {
            x += dx[d]*(pos-last);
            y += dy[d]*(pos-last);
            break;
        }
        last += n+1;
        x += dx[d]*n + dx[(d+1)%4];
        y += dy[d]*n + dy[(d+1)%4];
    }
    return make_pair(x, y);
}

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b), a!=0 && b!=0) {        
        pair <int,int> tmp = testCase(a, b-1);;
        printf("Line = %d, column = %d.\n", tmp.second, tmp.first);
    }
    
    return 0;
}
