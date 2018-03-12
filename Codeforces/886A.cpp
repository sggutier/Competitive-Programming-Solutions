#include <bits/stdc++.h>
using namespace std;

int main() {
    int N = 6;
    int arr[7];

    for(int i=0; i<N; i++)
        cin >> arr[i];

    for(int x=0; x<(1<<N); x++) {
        int c = 0, a=0, b = 0;
        for(int i=0; i<N; i++) {
            if((1<<i) & x) {
                c++;
                a += arr[i];
            }
            else
                b += arr[i];
        }
        if(c==3 && a==b) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
