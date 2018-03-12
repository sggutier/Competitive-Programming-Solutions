#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <map>
using namespace std ;
#define mod 1000003

map <char,string> arr ;

int main() {
	string S, W ;
	int res=0, pot=1 ;
	
	arr['>']="1000";
	arr['<']="1001";
	arr['+']="1010";
	arr['-']="1011";
	arr['.']="1100";
	arr[',']="1101";
	arr['[']="1110";
	arr[']']="1111";
	
	cin >> S ;
	for( int i=0; i<S.size(); i++ ) 
		W += arr[S[i]] ;
	
	reverse( W.begin(), W.end() ) ;
	for( int i=0; i<W.size(); i++ ) {
		res += (W[i]-'0')*pot ;
		res %= mod ;
		pot *= 2 ;
		pot %= mod ;
	}
	
	cout << res << endl ;
	
	return 0 ;
}
