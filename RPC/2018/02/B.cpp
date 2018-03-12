#include <bits/stdc++.h>
#define fs first
#define sn second
using namespace std;

int N;
pair <string, pair <double, double>> lst[505];
double mn = 500;
vector <int> ans;

int main() {
    cin >> N;

    for(int i=0;i<N;i++)
        cin >> lst[i].fs >> lst[i].sn.fs >> lst[i].sn.sn;

    for(int i=0;i<N;i++) {
        vector <pair <double, int>> nlst;

        for(int j=0;j<N;j++) {
            if(i == j) continue;
            nlst.push_back({ lst[j].sn.sn, j });
        }

        sort(nlst.begin(), nlst.end());

        double nmn = lst[i].sn.fs;
        nmn += nlst[0].fs;
        nmn += nlst[1].fs;
        nmn += nlst[2].fs;

        if(nmn < mn) {
            mn = nmn;
            ans = {i, nlst[0].sn, nlst[1].sn, nlst[2].sn } ;
        }

    }

    cout << mn << endl;
    for(int i=0;i<4;i++)
        cout << lst[ans[i]].fs << endl;
    return 0;
}
