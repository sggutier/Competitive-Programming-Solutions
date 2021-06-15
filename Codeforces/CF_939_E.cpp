#include <bits/stdc++.h>
using namespace std;
const int limN = 5e5 + 5;

double isec(double a, double b, double c, double d) {
    return (a-c) / (d-b);
}

double s[limN];

int main() {
    deque <int> q;
    int qCnt;    
    double ans = 0.0;
    int n = 1, w = 1;
    double acum = 0.0;

    q.push_back(1);
    
    scanf("%d", &qCnt);
    while(qCnt--) {
        double x ;
        scanf("%lf", &x);
        if(x==2.0) {
            printf("%.9lf\n", ans);
            continue;
        }
        scanf("%lf", &x);
        while(w >= 2 &&
              s[q[0]] + x/q[0] >= s[q[1]] + x/q[1])
            q.pop_front(), w--;
        ans = x - (s[q[0]] + x/q[0]);
        n++;
        acum += x;
        s[n] = acum / n;
        while(w >= 2 &&
              isec(s[n], 1.0/n, s[q[w-1]], 1.0/q[w-1])
              <= isec(s[q[w-1]], 1.0/q[w-1], s[q[w-2]], 1.0/q[w-2]) )
            q.pop_back(), w--;
        q.push_back(n);
        w++;
    }
}
