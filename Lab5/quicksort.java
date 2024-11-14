package Lab5;
import java.util.Scanner;
public class quicksort {
    public static void quickSort(int[] a,int p,int r){
        if(p<r){
            int q[]=partition(a,p,r);
            quickSort(a,p,q[0]-1);
            quickSort(a,q[1]+1,r);
        }
    }
    public static int[] partition(int[] a ,int p,int j){
        int x = a[j];
        int i = p - 1;
        int k = j;
        int pt = p;

        while (pt < k) {
            if (a[pt] < x) {
                i++;
                int t = a[pt];
                a[pt] = a[i];
                a[i] = t;
                pt++;
            } else if (a[pt] > x) {
                k--;
                int t = a[pt];
                a[pt] = a[k];
                a[k] = t;
            } else {
                pt++;
            }
        }

        int tempt = a[k];
        a[k] = a[j];
        a[j] = tempt;
        int q=i+1;
        int t=k;
        return new int[] { q, t };
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        int[] arr=new int[n];
        for (int i = 0; i <n; i++) {
            arr[i]=in.nextInt();
        }

        quickSort(arr,0,n-1);
        for (int i = 0; i <n; i++) {
            System.out.print(arr[i]+" ");
        }
    }
}
