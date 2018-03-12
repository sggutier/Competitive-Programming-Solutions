#include <bits/stdc++.h>
using namespace std;
const int A = 1e5 + 5;
#define I cin
#define rep(i, b) for(i=0; i<b; ++i)

string B[A];
char C[A], D[A], F[A];

void W() {
int i, N;
I>>C;
for(i=0; C[i]; i++)
D[(int) C[i]] = i+'a';
I>>N;
rep(i,N){
I >>F;
B[i] = F;
for(char &c:B[i])
c = D[(int) c];
}
sort(B, B+N);
rep(i,N){
for(char &c:B[i])
cout<<C[c-'a'];
cout<<endl;
}
}

int main() {
int t, i;
I>>t;
rep(i,t) {
if(i) cout<<endl;
W();
}
}
