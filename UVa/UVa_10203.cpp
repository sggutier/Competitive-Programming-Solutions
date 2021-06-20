#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 205;
#define f first
#define s second
#define par pair<double, double>

int N;
double ans = 0.0;

inline double dst(const par&A, const par &B) {
    return sqrt((A.f - B.f)*(A.f - B.f) +  (A.s - B.s)*(A.s - B.s));
}

void testCase() {
    char str[500];
    map <par, int> ids;
    par tmp, sig;
    N = 0;
    double a = 3.0, b= 1000.0, wowo = b;
    ans = 0.0;

    gets(str);
    sscanf(str, "%lf%lf", &tmp.f, &tmp.s);
    ids[tmp] = N++;
    while(gets(str) && str[0]) {
        int a, b;
        sscanf(str, "%lf%lf%lf%lf", &tmp.f, &tmp.s, &sig.f, &sig.s);
        if(ids.count(tmp)==0)
            ids[tmp] = N++;
        a = ids[tmp];
        if(ids.count(sig)==0)
            ids[sig] = N++;
        b = ids[sig];
        tmp.f /= wowo;
        tmp.s /= wowo;
        sig.f /= wowo;
        sig.s /= wowo;
        ans += 6.0*dst(tmp, sig);
    }

    //printf("%.3Lf\n", ans);
    long long mins = round(ans);
    long long W = 60;
    printf("%lld:%02lld\n", mins/W, mins%W);
}

int main() {
    char tmp[500];
    int tc;
    gets(tmp);
    sscanf(tmp, "%d", &tc);
    gets(tmp);
    for(int i=0; i<tc; i++) {
        if(i)
            printf("\n");
        testCase();
    }
}
