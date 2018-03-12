#include <bits/stdc++.h>
using namespace std;

void printa(vector <int> &neg) {
    printf("%d", (int) neg.size());
    for(const int n:neg)
        printf(" %d", n);
    printf("\n");
}

int main() {
    int N;
    vector <int> neg, pos, cer;
    cin >> N ;
    while(N--) {
        int a ; cin >> a ;
        if(a<0)
            neg.push_back(a);
        else if(a==0)
            cer.push_back(a);
        else
            pos.push_back(a);
    }
    if(pos.size()==0) {
        pos.push_back(neg.back()); neg.pop_back();
        pos.push_back(neg.back()); neg.pop_back();
    }
    if(neg.size()%2 == 0) {
        cer.push_back(neg.back()); neg.pop_back();
    }
    printa(neg);
    printa(pos);
    printa(cer);
}
