#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

//Chostastico

int main() {
    int dr[4] = { -1,  1, -1,  1 } ;
    int dc[4] = { -1, -1,  1,  1 } ;
    string dS[4] = { "LD", "LU", "RD" , "RU" } ;
    int dr2[4] = {  0,  0,  1, -1 } ;
    int dc2[4] = { -1,  1,  0,  0 } ;
    string dS2[4] = { "L", "R", "U" , "D" } ;
    int d ;
    char S[5], S2[5] ;
    
    cin >> S ;
    cin >> S2 ;
    
    d = 0 ;
    if( S[0] < S2[0]  )  
        d +=2 ;
    if( S[1] < S2[1]  ) 
        d ++ ;
    
    cout <<  max(   abs(S[0]-S2[0]),  abs(S[1]-S2[1])   ) << endl ;;
    while(  S[0] != S2[0]  &&  S[1] != S2[1]  ) {
        S[0] += dc[d] ;
        S[1] += dr[d] ;
        cout << dS[d] << endl ;
    }
    
    if( S[0] > S2[0]  )  
        d = 0 ;
    else if( S[0] < S2[0]  ) 
        d = 1 ;
    else if( S[1] < S2[1]  ) 
        d = 2 ;
    else
        d = 3 ;
    while(  S[0] != S2[0]  ||  S[1] != S2[1]  ) {
        S[0] += dc2[d] ;
        S[1] += dr2[d] ;
        cout << dS2[d] << endl ;
    }
    
    return 0 ;
}
