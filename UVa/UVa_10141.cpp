#include <bits/stdc++.h>
using namespace std ;

class prop {
public:
    int rm;
    double cost;
    string name;
};

bool operator<(prop A, prop B) {
    return A.rm != B.rm? A.rm > B.rm : A.cost < B.cost;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t=0;
    int offer_n, req_n;
    prop offers[1000];
    string tmp;
    while(getline(cin, tmp), sscanf(tmp.c_str(), "%d%d", &req_n, &offer_n), offer_n or req_n) {
        for(int i=0; i<req_n; i++)
            getline(cin, tmp);
        for(int i=0; i<offer_n; i++) {
            getline(cin, offers[i].name);
            getline(cin, tmp);
            sscanf(tmp.c_str(), "%lf%d", &offers[i].cost, &offers[i].rm);
            for(int j=0; j<offers[i].rm; j++)
                getline(cin, tmp);
        }
        sort(offers, offers+offer_n);
        if(t)
            cout << endl;
        cout << "RFP #" << ++t << endl;
        cout << offers[0].name << endl;
    }

    return 0;
}
