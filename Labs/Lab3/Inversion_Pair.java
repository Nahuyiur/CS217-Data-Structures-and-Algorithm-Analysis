package Lab3;

import java.util.Scanner;

public class Inversion_Pair {
    public static int count=0;
    public static int[] merge(int[] a,int[] b){
        int length=a.length+b.length;
        int ans[]=new int[length];

        int acount=0,bcount=0;
        int i=0;
        while(acount<a.length&&bcount<b.length){
            if(a[acount]<b[bcount]){
                ans[i]=a[acount];
                acount++;
            }else{
                ans[i]=b[bcount];
                bcount++;
                count+=(a.length-acount);
            }
            i++;
        }
        while(acount<a.length){
            ans[i]=a[acount];
            acount++;i++;
        }
        while(bcount<b.length){
            ans[i]=b[bcount];
            bcount++;i++;
        }
        return ans;
    }
    public static int[] doMergeSort(int[] a){
        if(a.length==1||a.length==0){
            return a;
        }
        int m=a.length/2;
        int[] l=new int[m];
        int[] r=new int[a.length-m];
        for (int i = 0; i < m; i++) {
            l[i]=a[i];
        }
        for (int i = 0; i < a.length-m; i++) {
            r[i]=a[i+m];
        }
        int[] ln;
        int[] rn;
        ln=doMergeSort(l);
        rn=doMergeSort(r);
        int[] ans;
        ans=merge(ln,rn);
        return ans;
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        int[] arr=new int[n];
        for (int i = 0; i < n; i++) {
            arr[i]=in.nextInt();
        }
        int[] ans=doMergeSort(arr);

        System.out.println(count);
    }
}
