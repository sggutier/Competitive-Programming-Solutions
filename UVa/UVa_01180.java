import java.io.*;
import java.math.BigInteger;
import java.util.*;

import static java.lang.Math.max;

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
        int N ;
        N = sc.nextInt();
        String lin = sc.nextLine();
        int prob = 1000000;
        BigInteger dos = BigInteger.valueOf(2);
        for (String s: lin.split(",")) {
            int k = Integer.parseInt(s);
            boolean evRes = BigInteger.valueOf(k).isProbablePrime(prob)
                    && dos.pow(k).subtract(BigInteger.ONE).isProbablePrime(prob);
            System.out.println(evRes? "Yes" : "No");
        }
    }
}
