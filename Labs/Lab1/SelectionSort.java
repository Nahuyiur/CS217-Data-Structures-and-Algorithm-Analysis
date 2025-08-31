package Lab1;

import java.util.Scanner;

public class SelectionSort {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int N=in.nextInt();
        int arr[]=new int[N];
        for(int i=0;i<N;i++){
            arr[i]=in.nextInt();
        }

        for (int i = 0; i < N-1; i++) {
            int min=i;
            for(int j=i+1;j<N;j++){
                if(arr[j]<arr[min])min=j;
            }
            int t=arr[i];
            arr[i]=arr[min];
            arr[min]=t;
        }

        for (int i = 0; i < N; i++) {
            System.out.print(arr[i]+" ");
        }
    }
}
