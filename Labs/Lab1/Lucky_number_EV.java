package Lab1;

import java.util.Scanner;

public class Lucky_number_EV {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        int k=in.nextInt();
        int arr[]=new int[n];

        for (int i = 0; i < n; i++) {
            arr[i]=in.nextInt();
        }
        for(int i=0;i<n-1;i++){
            for (int j = i+1; j < n; j++) {
                if(arr[i]>arr[j]){
                    int t=arr[i];
                    arr[i]=arr[j];
                    arr[j]=t;
                }
            }
        }

        System.out.println(arr[k-1]);
    }
}
