#include <bits/stdc++.h>
using namespace std;
const int D = 128;

struct Matr {
    int N ;
    vector < vector <double> > vals;
    Matr(int N) : N(N) {
        vals.assign(N, vector<double>(N));
    }
    Matr operator*(const Matr &otr) {
        Matr ans(N);
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                for(int k=0; k<N; k++)
                    ans.vals[i][j] += vals[i][k] * otr.vals[k][j];
        return ans;
    }
    void printa() {
        printf("Matriz es:\n");
        for(int i=0; i<D; i++) {
            for(int j=0; j<D; j++)
                printf("%.3lf ", vals[i][j]);
            printf("\n");
        }
        printf("----\n");
    }
};

Matr bas(D), uno(D);

Matr expBin(int X) {
    if(X==0)
        return uno;
    if(X==1)
        return bas;
    // printf("Calculando %d\n", X);
    Matr mt = expBin(X/2);
    return X%2? mt*mt*bas : mt*mt;
}

int main() {
    int N, X;
    double vals[D];
    scanf("%d%d", &X, &N);
    for(int i=0; i<=N; i++)
        scanf("%lf", &vals[i]);
    for(int i=0; i<D; i++) {
        for(int j=0; j<=N; j++) {
            bas.vals[i][i^j] = vals[j];
        }
        uno.vals[i][i] = 1.0;
    }
    Matr ans = expBin(X);
    // ans.printa();
    // bas.printa();
    double w = 0.0;
    for(int i=1; i<D; i++)
        w += ans.vals[0][i];
    printf("%.9lf\n", w);
}
