package Lab7;

import java.util.Scanner;

public class CountingSort {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        int m=in.nextInt();

        int[] a=new int[n];
        int[] b=new int[n];
        int[] c=new int[m+1];
        for (int i = 0; i < m+1; i++) {
            c[i]=0;
        }
        for (int i = 0; i < n; i++) {
            a[i]=in.nextInt();
            c[a[i]]++;
        }
        for (int i = 1; i < m+1; i++) {
            c[i]+=c[i-1];
        }
        for (int i = n-1; i >=0 ; i--) {
            b[c[a[i]]-1]=a[i];
            c[a[i]]--;
        }
        for (int i = 0; i < n; i++) {
            System.out.print(b[i]+" ");
        }
    }
}
