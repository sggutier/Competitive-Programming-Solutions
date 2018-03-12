#include <bits/stdc++.h>
using namespace std;

int T, N, A, B, K;
double R;
pair <char, int> L[3105];
vector <int> C;
char buf[3];

double area(pair<char,int> p) {
    if(p.first == 'T')
        return sqrt(3)/ 4.0 * p.second * p.second;
    return p.second * p.second;
}

int main() {
    scanf("%d", &T);

    while(T--) {
        scanf("%d", &N);

        C.clear();

        for(int i=0;i<N;i++) {
            scanf("%s %d", buf, &K);
            L[i] = make_pair(buf[0], K);
            if(L[i].first == 'C')
                C.push_back(i);
        }

        A = 0;

        for(int i=C[0];i<=C[1];i++)
            A += L[i].second;

        B = 0;

        for(int i=C[1];i<=C[2];i++)
            B += L[i].second;

        R = (double)A * (double)B;

        for(int i=0;i<N;i++)
            R -= area(L[i]);

        printf("%.4f\n", R);
    }
    return 0;
}
