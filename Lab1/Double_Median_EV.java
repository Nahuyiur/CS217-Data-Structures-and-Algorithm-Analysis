package Lab1;

import java.util.Scanner;

public class Double_Median_EV {
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

        int ans;
        if(N%2==0){
            ans=(arr[N/2]+arr[N/2-1]);
        }else{
            ans=arr[(N-1)/2]*2;
        }
        System.out.println(ans);
    }
}
