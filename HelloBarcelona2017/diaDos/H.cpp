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
    return w(x, MAXV + 100);
}

int main() {
    cin >> N;

    S = 0;

    while(S < N) {

        int i = -MAXV, j = MAXV;
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

        x_coords.push_back(NX);
        n_points.push_back(NS - S);

        S = NS;
    }

    for(int k = 0; k < x_coords.size();k++) {
        int x = x_coords[k];
        int p_before = w(x-1, MAXV + 100);

        G = n_points[k];

        for(int l = 1; l <= G; l++) {
            int i = -MAXV, j = MAXV;
            int NS, NY;

            while(i <= j) {
                int m = (i+j)/2;

                NS = w(x,m) - p_before;

                if(NS >= l) {
                    NY = m;
                    j = m - 1;
                } else {
                    i = m + 1;
                }
            }

            ans.push_back(make_pair(x, NY));
        }
    }

    cout << "!";

    for(int i=0;i<ans.size();i++)
        cout << " " << ans[i].first << " " << ans[i].second;

    cout << endl;

    return 0;
}
