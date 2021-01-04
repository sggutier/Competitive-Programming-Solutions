#include <bits/stdc++.h>
using namespace std;

struct SuffixArray {
     string S ;
     vector <int> SA, RA ;
     int N ;

     void bucketSort(int k) {                     // O(n)
          int maxi = max(300, N);                      // up to 255 ASCII chars
          vector<int> c(maxi, 0);                               // clear frequency table
          for (int i = 0; i < N; ++i)                  // count the frequency
               ++c[i+k < N ? RA[i+k] : 0];                // of each integer rank
          for (int i = 0, sum = 0; i < maxi; ++i) {
               int t = c[i]; c[i] = sum; sum += t;
          }
          vector<int> tempSA(N);
          for (int i = 0; i < N; ++i)                  // sort SA
               tempSA[c[SA[i]+k < N ? RA[SA[i]+k] : 0]++] = SA[i];
          swap(SA, tempSA);                            // update SA
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

     pair<int,int> stringMatching(const char *P) {             // in O(m log n)
    int m = (int)strlen(P);                      // usually, m < n
    int lo = 0, hi = N-1;                        // range = [0..n-1]
    while (lo < hi) {                            // find lower bound
      int mid = (lo+hi) / 2;                     // this is round down
      int res = strncmp(S.c_str()+SA[mid], P, m);        // P in suffix SA[mid]?
      (res >= 0) ? hi = mid : lo = mid+1;        // notice the >= sign
    }
    if (strncmp(S.c_str()+SA[lo], P, m) != 0) return {-1, -1}; // if not found
    pair<int,int> ans; ans.first = lo;
    hi = N-1;                                    // range = [lo..n-1]
    while (lo < hi) {                            // now find upper bound
      int mid = (lo+hi) / 2;
      int res = strncmp(S.c_str()+SA[mid], P, m);
      (res > 0) ? hi = mid : lo = mid+1;         // notice the > sign
    }
    if (strncmp(S.c_str()+SA[hi], P, m) != 0) --hi;      // special case
    ans.second = hi;
    return ans;                                  // returns (lb, ub)
  }                                              //
};

vector <int> testCase(const string &W, const string &S) {
     SuffixArray SA(S);
     vector<int> ans ;
     int ansL, ansR;
     auto pp = SA.stringMatching(W.c_str());

     for(int i=0; i < SA.N; i++) {
          if(pp.first <= i && i <= pp.second) {
               ans.push_back(SA.SA[i]);
          }
     }
     sort(ans.begin(), ans.end());

     return ans;
}

int main() {
     ios::sync_with_stdio();
     string S, W ;
     while(getline(cin, W)) {
          getline(cin, S);
          auto ans = testCase(W, S);
          bool fst = true;
          for(const int p : ans) {
               if(!fst) {
                    printf(" ");
               }
               printf("%d", p);
               fst = false;
          }
          printf("\n");
     }
}
