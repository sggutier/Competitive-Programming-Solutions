#include <cstdio>
#include <stack>
#include <utility>
using namespace std ;
const int lim = 1005 ;
#define par pair<int,int>
#define x first
#define y second

int R, C ;
char mapa[lim][lim] ;
stack <par> pend ;
// Las variables de abajo describen las 4 direcciones en sentido horario comenzando por arriba
int dx[] = { -1, 0, 1, 0 } ;
int dy[] = { 0, 1, 0, -1 } ;

// Funcion para revisar si cierta casilla es un espacio vacio
bool casillaValida( par pos ) {
	if( pos.x<0 || pos.x>=R || pos.y<0 || pos.y>=C ) 
		return 0 ;
	return mapa[pos.x][pos.y] == '.' ;
}

// Funcion para expandir la tierra
void floodFill( par pos ) {
	pend.push( pos ) ;
	while( !pend.empty()  )  {

		pos = pend.top() ;
		pend.pop() ;

		// Si ya tenia algo o esta en la orilla la ignoramos
		if( pos.x==0 || pos.x==R-1 || pos.y==0 || pos.y==C-1 || mapa[pos.x][pos.y]!='.' )
			continue ;

		int ady = 0 ;
		// Contamos cuantas casillas con tierra tiene alrededor
		for( int d=0; d<4; d++ )
			if( mapa[ pos.x+dx[d] ][ pos.y+dy[d] ] == 'A' )
				ady ++ ;

		// Si solo tiene 1 pedazo alrededor, pude que tengamos que poner algo en el centro
		// pero de momento no corresponde decidir
		if( ady<2 )
			continue ;
		else if( ady==2 ) {
			bool posb = 1 ;
			// Si tiene 2 y queremos poner algo, estas cosas no tienen que estar en frente
			// unas de otras. 
			// Puede que tengamos que poner algo despues. No es momento de decidir eso.
			for( int d=0; d<2; d++ )
				if( mapa[ pos.x+dx[d] ][ pos.y+dy[d] ] == mapa[ pos.x+dx[(d+2)%4] ][ pos.y+dy[(d+2)%4] ]  )
					posb = 0 ;

			if( !posb )
				continue ;
			posb = 0 ;
			
			// Si no podemos encontrar los 4 cuadros vacios opuestos a los 2, entonces no ponemos nada ahi
			for( int d=0; d<4; d++ ) {
				if( mapa[pos.x+dx[d]][pos.y+dy[d]] == '.' && 
				    mapa[pos.x+dx[(d+1)%4]][pos.y+dy[(d+1)%4]] == '.' && 
				    mapa[ pos.x + dx[d] + dx[(d+1)%4] ][ pos.y + dy[d] + dy[(d+1)%4] ] == '.' )
					posb = 1 ;
			}

			if( !posb )
				continue ;

		}
		
		// Expandimos la tierra y probamos con las 4 adyacentes
		mapa[pos.x][pos.y] = 'A' ;
		for( int d=0; d<4; d++ ) 
			pend.push(  par(pos.x+dx[d], pos.y+dy[d])  )  ;
	}
}

int main() {
	int tamCiclo = 0, dir=1 ;
	par posIni, pos ;

	// Lectura
	scanf("%d%d", &R, &C ) ;
	for( int i=0; i<R; i++ ) 
		scanf("%s", mapa[i] ) ;

	// Para cada casilla hacemos un Flood Fill para expandir la isla
	for( int i=0; i<R; i++ ) 
		for( int j=0; j<C; j++ ) 
			floodFill( par(i,j) ) ;

	// Buscamos la posicion de la isla mas arriba y mas a la izquierda posible para comenzar el recorrido
	// en la posicion que esta arriba de esta
	for( int i=0; i<R; i++ ) {
		for( int j=0; j<C; j++ ) {
			if( mapa[i][j]=='A' ) {
				pos = par(i-1,j) ;
				i = R ;
				break ;
			}
		}
	}

	// Hacemos la mano derecha para determinar la longitud del ciclo
	posIni = pos ;
	do {
		// Como es una mano derecha se debe intentar una posicion libre a la derecha de nuestra
		// direccion actual, luego la de en frente, la de la izquierda y la de atras.
		dir = (dir+1)%4 ;
		while( !casillaValida(  par( pos.x + dx[dir],  pos.y + dy[dir] )  )    )
			// Hacer (+3)%4 es como hacer -1
			dir = (dir+3)%4 ;
		tamCiclo ++ ;
		pos.x += dx[dir] ;
		pos.y += dy[dir] ;
	} while( pos!=posIni ) ;

	printf("%d\n", tamCiclo ) ;

	return 0 ;
}


