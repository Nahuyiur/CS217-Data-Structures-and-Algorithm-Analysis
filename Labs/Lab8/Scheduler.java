package Lab8;

import java.util.Arrays;
import java.util.Scanner;

class queue{
    int[] q=new int[10];

    int head=0;
    int tail=0;
    public queue(){
        Arrays.fill(q,-1);
    }
    void enqueue(int x){
        if((tail+1)%10==head){
            System.out.println("overflow");
            return;
        }
        q[tail]=x;
        if(tail==9){
            tail=0;
        }else{
            tail++;
        }
        show();
    }
    void dequeue(){
        if(tail==head&&q[head]==-1){
            System.out.println("underflow");
            return;
        }
        q[head]=-1;
        if(head==9){
            head=0;
        }else{
            head++;
        }
        show();
    }
    void show(){
        int l=head;
        int r=tail;
        if(l==r&&q[l]==-1){
            System.out.println("empty");
            return;
        }
        do{
            System.out.print(q[l]+" ");
            if(l==9){
                l=0;
            }else {
                l++;
            }
        }while (l!=r);
        System.out.println();
    }
}
public class Scheduler {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        in.nextLine();
        int temp=0;
        queue q=new queue();
        for (int i = 0; i < n; i++) {
            temp=in.nextInt();
            if(temp==0){
                q.dequeue();
            }else{
                q.enqueue(temp);
            }
        }
    }
}
