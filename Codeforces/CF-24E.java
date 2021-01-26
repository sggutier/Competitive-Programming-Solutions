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

    public static class

    static boolean isPalindrome(String s) {
        for(int i = 0, j = s.length()-1; i < j; i++, j--) {
            if(s.charAt(i) != s.charAt(j))
                return false;
        }
        return true;
    }

    static int stepNo(String s, int bas) {
        BigInteger cur ;
        try {
            cur = new BigInteger(s, bas);
        }
        catch(Exception e) {
            return MAX_S + 1 ;
        }
        int ans = 0 ;
        while(ans <= MAX_S && !isPalindrome(s)) {
            String rev = new StringBuilder(s).reverse().toString();
            cur = cur.add(new BigInteger(rev, bas));
            s = cur.toString(bas);
            ans ++;
        }
        return ans ;
    }

    /*
     * Este es un documento importante
     * @param lin es una linea, duh
     */
    static void testCase(String lin) {
        boolean sep = false;
        for(int bas=15; bas >= 2; bas--) {
            int stp = stepNo(lin, bas);
            if(sep)
                System.out.print(' ');
            sep = true;
            if(stp > MAX_S) {
                System.out.print('?');
            }
            else {
                System.out.print(stp);
            }
        }
        System.out.print('\n');
    }

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        String lin ;
        while(true) {
            try {
                lin = sc.next();
            } catch (Exception e) {
                break;
            }
            testCase(lin);
        }
    }
}
