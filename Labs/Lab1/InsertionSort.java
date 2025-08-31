package Lab1;

import java.util.Scanner;

public class InsertionSort {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int N=in.nextInt();
        int arr[]=new int[N];
        for(int i=0;i<N;i++){
            arr[i]=in.nextInt();
        }

        for (int i = 1; i < N; i++) {
            int key=arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>key){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }

        for (int i = 0; i < N; i++) {
            System.out.print(arr[i]+" ");
        }
    }
}
