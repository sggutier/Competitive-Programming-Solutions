#include <bits/stdc++.h>
using namespace std;

struct SuffixArray {
    string S ;
    vector <int> SA, RA ;
    vector <int> LCP;
    int N ;

    void bucketSort(const int k) {
        int maxVal = max(N, 256);
        queue<int> reps[maxVal];
        for(int i=0; i < N; i++) {
            int val = SA[i]+k >= N? 0 : RA[SA[i]+k];
            reps[val].push(SA[i]);
        }
        for(int i=0, pos=0; i < maxVal; i++) {
            while(!reps[i].empty()) {
                SA[pos++] = reps[i].front();
                reps[i].pop();
            }
        }
    }

    SuffixArray(const string &_S) : S(_S), N(_S.size()) {
        SA.resize(N);
        RA.resize(N);
        vector <int> RA_cpy(N);

        for(int i=0; i < N; i++) {
            RA[i] = S[i];
            SA[i] = i;
        }

        for(int k=1; k < N; k*=2) {
            // Ordenar con respecto a los primeros dos pares
            bucketSort(k);
            bucketSort(0);
            // Recalcular valores de RA con pares
            pair <int, int> ant(RA[SA[0]], RA[SA[k]]);
            RA_cpy[SA[0]] = 0;
            for(int i=1; i < N; i++) {
                pair <int, int> cur(RA[SA[i]], SA[i]+k >= N? 0 : RA[SA[i]+k]);
                RA_cpy[SA[i]] = RA_cpy[SA[i-1]];
                if(cur != ant) {
                    RA_cpy[SA[i]] ++;
                    ant = cur ;
                }
            }
            for(int i=0; i < N; i++) {
                RA[i] = RA_cpy[i];
            }
        }
    }

    void calculaLCP() {
        vector <int> Phi(N), PLCP(N);
        LCP.resize(N);
        Phi[SA[0]] = -1;
        for(int i=1; i < N; i++) {
            Phi[SA[i]] = SA[i-1];
        }
        for(int i=0, pref=0; i < N; i++) {
            pref = max(0, pref-1);
            if(Phi[i] == -1) {
                PLCP[i] = 0;
                continue;
            }
            while(S[i + pref] == S[Phi[i] + pref]) {
                pref ++;
            }
            PLCP[i] = pref;
        }
        for(int i=0; i < N; i++) {
            LCP[i] = PLCP[SA[i]];
        }
    }
};

int main() {
    ios::sync_with_stdio();
    string S ;
    while(cin >> S) {
        SuffixArray SA(S+"$");
        SA.calculaLCP();
    }
}
