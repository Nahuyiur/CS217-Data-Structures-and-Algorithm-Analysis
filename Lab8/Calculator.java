package Lab8;

import java.util.Scanner;

class calstack{
    int top=0;
    int[] c=new int[10001];
    void push(int x){
        c[top]=x;
        top++;
    }
    int pop(){
        top--;
        return c[top];
    }

}

public class Calculator {
    public static boolean judge(String s){
        if(s.equals("+")||s.equals("-")||s.equals("*")){
            return true;
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int n;
        n=in.nextInt();
        in.nextLine();

        String str;
        str=in.nextLine();
        String token[]=str.split(" ");

        calstack s=new calstack();

        for (int i = 0; i < n; i++) {
            if(!judge(token[i])){
                s.push((Integer.parseInt(token[i])));
            }else{
                int n2=s.pop();
                int n1=s.pop();
                int ans=0;
                switch (token[i]){
                    case "+":
                        ans=n1+n2;
                        break;
                    case "-":
                        ans=n1-n2;
                        break;
                    case "*":
                        ans=n1*n2;
                        break;
                    default:
                        break;
                }
                s.push(ans);
            }
        }
        int ans=s.pop();
        System.out.println(ans);
    }
}
