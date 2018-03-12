#include <iostream>
#include <algorithm>
#include <vector>
#define cost first
#define edge second
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n, m;
pair< int, pair< int, int > > E[1000002];
vector< pair< int, int > > edges[2002];
int p[2002], r[2002];

void preprocess1(){
    for( int i = 1; i <= n; i++ ){
        p[i] = i;
        r[i] = 0;
    }
}

int root( int x ){

    if( p[x] == x )
        return x;
    p[x] = root( p[x] );
    return p[x];

}

bool joined( int x, int y ){
    return root(x) == root(y);
}

void join( int i, int j, int c ){

    int X = root(i), Y = root(j);
    if( r[X] > r[Y] ){
        p[Y] = X;
    } else {
        p[X] = Y;
        if( r[X] == r[Y] )
            r[Y]++;
    }
    edges[i].push_back( make_pair( j, c ) );
    edges[j].push_back( make_pair( i, c ) );

}

int L[2002], T[2002], D[2002];
int P[2002][13], M[2002][13];
bool vis[2002];

void dfs( int i, int parent, int l, int p ){

    T[i] = parent;
    D[i] = p;
    L[i] = l;
    for( int j = 0; j < edges[i].size(); j++ )
        if( edges[i][j].first != parent )
            dfs( edges[i][j].first, i, l + 1, edges[i][j].second );

}

void preprocess(){

    dfs( 1, -1, 0, 0 );
    for( int i = 1; i <= n; i++ ){
        P[i][0] = T[i];
        M[i][0] = D[i];
    }
    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= 11; j++ )
            P[i][j] = -1;

    for( int j = 1; j <= 11; j++ ){
        for( int i = 1; i <= n; i++ ){
            if( P[i][j - 1] != -1 ){
                P[i][j] = P[ P[i][j - 1] ][j - 1];
                M[i][j] = max( M[i][j - 1], M[ P[i][j - 1] ][j - 1] );
            }
        }
    }

}

int maxSave( int p, int q ){

    int ret = -1;
    if( L[p] < L[q] )
        swap( p, q );

    for( int i = 11; i >= 0; i-- ){
        if( L[p] - (1 << i) >= L[q] ){
            ret = max( ret, M[p][i] );
            p = P[p][i];
        }
    }

    if( p == q )
        return ret;

    for( int j = 11; j >= 0; j-- ){
        if( P[p][j] != P[q][j] ){
            ret = max( ret, M[p][j] );
            ret = max( ret, M[q][j] );
            p = P[p][j];
            q = P[q][j];
        }
    }

    ret = max( ret, max( D[p], D[q] ) );
    return ret;

}

int main()
{

    optimizar_io
    cin >> n >> m;
    for( int i = 1; i <= m; i++ )
        cin >> E[i].edge.first >> E[i].edge.second >> E[i].cost;
    sort( E + 1, E + m + 1 );

    int A = 0, price = 0;
    preprocess1();
    for( int i = 1; i <= m && A < n ; i++ ){
        if( joined( E[i].edge.first, E[i].edge.second ) )
            continue;
        join( E[i].edge.first, E[i].edge.second, E[i].cost );
        price += E[i].cost;
        A++;
    }
    preprocess();
    int menor = 1000000000;
    for( int i = 1; i <= m; i++ ){
        int aux = price - maxSave( E[i].edge.first, E[i].edge.second ) - E[i].cost;
        if( aux < menor )
            menor = aux;
    }
    cout << menor << "\n";

    return 0;

}
