#include <iostream>
using namespace std;
int main(){
long long a,b=0LL;	
for(cin>>a;a;a/=10LL)if(a%10LL==4LL||a%10LL==7LL)b++;
if(!b)b++;
for(;b;b/=10LL)if(b%10LL!=4LL&&b%10LL!=7LL)break;
cout<<(b?"NO\n":"YES\n");
}
