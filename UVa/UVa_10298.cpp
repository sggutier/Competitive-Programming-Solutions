#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

class HashedString {
private:
    string S;
    vector <unsigned long long> subhash;
    vector <unsigned long long> pows;
    int n;
public:
    HashedString() {
    }
    HashedString(string S) {
        subhash = vector<unsigned long long>(S.size() + 1, 0LL);
        pows = vector<unsigned long long>(S.size() + 1, 1LL);
        n = S.size();
        for(int i=0; i<n; i++) {
            subhash[i+1] = subhash[i]*27 + (S[i]-'a');
            pows[i+1] = pows[i]*27;
            // cout << ">>>> " << subhash[i+1] << " " << pows[i+1] << endl;
        }
    }
    unsigned long long getHash(int ini, int fin) {
        // cout << ini << " " << fin << " " << subhash[fin+1] - subhash[ini]*pows[fin-(ini-1)] << endl;
        return subhash[fin+1] - subhash[ini]*pows[fin-(ini-1)];        
    }
    unsigned long long getHash() {
        return subhash[subhash.size()-1];
    }
    int size() {
        return n;
    }
};

void testCase(HashedString S) {
    int n = S.size();
    for(int i=1; i*i<n; i++) {
        if(n%i)
            continue;
        unsigned long long h = S.getHash(0, i-1);
        bool itWorks = true;
        for(int j=i; j<n; j+=i) {
            if(S.getHash(j, j+i-1)!=h) {
                itWorks = false;
                break;
            }
        }
        if(itWorks) {
            printf("%d\n", n/i);
            return;
        }
    }
    for(int k=sqrt(n); k>0; k--) {
        if(n%k)
            continue;
        int i = n/k;
        unsigned long long h = S.getHash(0, i-1);
        bool itWorks = true;
        for(int j=i; j<n; j+=i) {
            if(S.getHash(j, j+i-1)!=h) {
                itWorks = false;
                break;
            }
        }
        if(itWorks) {
            printf("%d\n", n/i);
            return;
        }
    }
}

int main() {
    char* arr = new char[limN];

    while(scanf("%s", arr)!=EOF && arr[0]!='.') {
        testCase(HashedString(arr));
    }

    delete[] arr;
    return 0;
}
