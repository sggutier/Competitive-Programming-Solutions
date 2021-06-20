import java.math.* ;
import java.util.* ;
import java.io.* ;

class Main {
    static String ReadLn (int maxLg)  // utility function to read from stdin
    {
        byte lin[] = new byte [maxLg];
        int lg = 0, car = -1;
        String line = "";

        try
        {
            while (lg < maxLg)
            {
                car = System.in.read();
                if ((car < 0) || (car == '\n')) break;
                lin [lg++] += car;
            }
        }
        catch (IOException e)
        {
            return (null);
        }

        if ((car < 0) && (lg == 0)) return (null);  // eof
        return (new String (lin, 0, lg));
    }
    
    public static void caso() {
	//System.console().readLine() ;
	ReadLn(255) ;
	int N = Integer.parseInt( ReadLn(255) ); ;
	char[] arrA = new char[N], arrB = new char[N] ;
	String tmp, A, B ;

	for( int i=0; i<N; i++ ) {
	    // tmp = System.console().readLine() ;
	    tmp = ReadLn(255) ;
	    arrA[i] = tmp.charAt(0) ;
	    arrB[i] = tmp.charAt(2) ;
	}
	A = new String(arrA) ;
	B = new String(arrB) ;

	BigInteger res  =  new BigInteger(A).add( new BigInteger(B) ) ;

	System.out.println( res ) ;
    }
    
    public static void main( String[] args ) {
	int T = Integer.parseInt( ReadLn(255) ) ;
	//int T = 25 ;

	//System.out.println(T) ;

	for( int i=0; i<T; i++ ) {
	    if( i>0 )
		System.out.println() ;
	    caso() ;
	}
    }
}
