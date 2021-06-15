import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        /*
         * Este es un documento muy importante
         * @return Una cadena xdxd
         */
        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
    //--------------------------------------------------------

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        BigInteger n = new BigInteger(sc.nextLine());
        BigInteger m = n.divide(BigInteger.valueOf(6)).negate();
        BigInteger t0 = n.pow(3);
        BigInteger t1 = BigInteger.valueOf(18).multiply(n.pow(2)).multiply(m);
        BigInteger t2 = BigInteger.valueOf(108).multiply(n).multiply(m.pow(2));
        BigInteger t3 = n ;
        BigInteger t4 = BigInteger.valueOf(216).multiply(m.pow(3));
        BigInteger k = (t0.add(t1).add(t2).subtract(t3).add(t4)).divide(BigInteger.valueOf(6)).abs();

        System.out.println(5);
        System.out.print(BigInteger.valueOf(6).multiply(m).add(n));
        System.out.print(" ");
        System.out.print(k);
        System.out.print(" ");
        System.out.print(k);
        System.out.print(" ");
        System.out.print(k.add(BigInteger.ONE).negate());
        System.out.print(" ");
        System.out.println(k.subtract(BigInteger.ONE).negate());
    }
}
