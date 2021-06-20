
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author sggutier
 */
public class P10268 {
    public static long evalPoly(Integer[] nums, int x) {
        int n = nums.length;
        long pot = 1;
        long ans = n>=2? nums[n-2] : 0;
        for(int i=2; i<n; i++) {
            pot *= x;
            ans += pot*nums[n-1-i]*i;
        }
        return ans;
    }
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        while(true) {
            String[] lets = null;
            int x = 0;
            try {
                x = Integer.parseInt(s.nextLine());
                lets = s.nextLine().trim().split("\\s+");
            }
            catch(Exception e) {
                break;
            }
            Integer[] nums = Arrays.stream(lets).map(w -> Integer.parseInt(w)).toArray(Integer[]::new);
            System.out.println(evalPoly(nums, x));
        }
    }
}
