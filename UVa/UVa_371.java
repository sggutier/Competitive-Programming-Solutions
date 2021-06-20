import java.math.* ;
import java.util.* ;
import java.io.* ;

class Main {
    static Map< BigInteger, Integer > dp ;
    static BigInteger b2, b0, b3, b1 ;

    public static int memo( BigInteger pos) {
	
	if( dp.containsKey(pos) )
	    return dp.get(pos) ;
	int res ;
	if( pos.mod( b2 ) == BigInteger.ZERO )
	    res = memo( pos.divide( b2 )  ) + 1 ;
	else
	    res = memo( (pos.multiply( b3 )).add( b1 )  ) + 1 ;
	dp.put( pos, res ) ;
	return res ;
    }
	
    public static void main( String[] args ) {
	Scanner ent = new Scanner(System.in) ;

	b2 = new BigInteger("2") ;
	b0 = new BigInteger("0") ;
	b3 = new BigInteger("3") ;
	b1 = new BigInteger("1") ;
	dp = new HashMap< BigInteger, Integer >();

	dp.put( b1, 1 ) ;

	while( true ) {
	    int a = ent.nextInt(), b=ent.nextInt(), c ;
	    int res=-1, pRes=a ;
	    if( a==0 && b==0 )
		break ;
	    if( a > b ) {
		c = a ;
		a = b ;
		b = c ;
	    }
	    for( int i=a; i<=b; i++ )  {
		BigInteger swag = new BigInteger(String.valueOf(i) ) ;
		int tmp = memo( swag ) ;
		if( tmp>res ) {
		    res = tmp ;
		    pRes = i ;
		}
	    }
	    System.out.println( "Between " + a + " and " + b + ", " + pRes + " generates the longest sequence of " + res + " values." ) ;
	}
    }
}
