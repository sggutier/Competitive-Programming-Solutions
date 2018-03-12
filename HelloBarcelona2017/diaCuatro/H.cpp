#include <bits/stdc++.h>
#define MAXV 1000000
using namespace std;

typedef pair<int, int> pii;

int N, S, G;
vector <int> x_coords, n_points;
vector <pii> ans;

int w(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int r;
    cin >> r;
    return r;
}

int q(int x) {
    return w(x, MAXV);
}

int w2(int x, int y) {
    int orig = w(x, y);

    for(int i=0;i<ans.size();i++) {
        if(ans[i].first <= x && ans[i].second <= y)
            orig--;
    }

    return orig;
}

int main() {
    cin >> N;

    S = 0;

    int li = -MAXV;

    while(S < N) {

        int i = -MAXV , j = MAXV ;
        int NS, NX;

        while(i <= j) {
            int m = (i + j) / 2;

            int qs = q(m);

            if(qs > S) {
                NX = m;
                NS = qs;
                j = m - 1;
            } else {
                i = m + 1;
            }
        }

        li = NX;

        x_coords.push_back(NX);
        n_points.push_back(NS - S);

        S = NS;
    }

    for(int k = 0; k < x_coords.size();k++) {
        int x = x_coords[k];

        G = n_points[k];

        int li = -MAXV ;

        for(int l = 1; l <= G; l++) {
            int i = -MAXV , j = MAXV ;
            int NSS, NY;

            while(i <= j) {
                int m = (i+j)/2;

                NSS = w2(x,m);

                if(NSS >= l) {
                    NY = m;
                    j = m - 1;
                } else {
                    i = m + 1;
                }
            }

            ans.push_back(make_pair(x, NY));
            li = NY;
        }
    }

    cout << "!";

    for(int i=0;i<ans.size();i++)
        cout << " " << ans[i].first << " " << ans[i].second;

    cout << endl;

    return 0;
}
