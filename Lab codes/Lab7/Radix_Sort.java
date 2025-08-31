package Lab7;

import java.util.Scanner;
public class Radix_Sort {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        int m=in.nextInt();

        String[] lines=new String[n];
        String[] rank=new String[n];
        for (int i = 0; i < n; i++) {//行数
            lines[i]=in.next();
            rank[i]=new String(lines[i]);
        }


        for (int i = m-1; i >=0 ; i--) {//字母数
            int[] count=new int[26];
            for (int j = 0; j < 26; j++) {
                count[j]=0;
            }
            for (int j = 0; j < n; j++) {
                count[lines[j].charAt(i)-97]++;
            }
            for (int j = 1; j < 26; j++) {
                count[j]+=count[j-1];
            }
            for (int j = n-1; j >=0 ; j--) {
                int pos = --count[lines[j].charAt(i) - 'a']; // 获取排序位置
                rank[pos] = new String(lines[j]);
            }
            System.arraycopy(rank, 0, lines, 0, n);
        }
        for (int i = 0; i < n; i++) {
            System.out.println(lines[i]);
        }
    }
}
