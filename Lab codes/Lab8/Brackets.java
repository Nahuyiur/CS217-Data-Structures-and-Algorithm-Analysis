package Lab8;

import java.util.Scanner;

class Stack{
    int top=0;
    char[] c;
    void push(char ch){
        c[top]=ch;
        top++;
    }
    void pop(){
        top--;
        c[top]='0';
    }

}
public class Brackets {
public static boolean judge(char c1,char c2){
    if(c1=='('&& c2==')'||
            c1=='['&& c2==']'||
            c1=='{'&& c2=='}')return true;
    return false;
}

    public static void main(String[] args) {
        String str;
        Scanner in=new Scanner(System.in);

        str=in.nextLine();

        Stack s=new Stack();
        s.c=new char[100001];

        for (int i = 0; i < str.length(); i++) {
            if(str.charAt(i)=='('||str.charAt(i)=='['||str.charAt(i)=='{'){
                s.push(str.charAt(i));
            }else{

                if(s.top==0||!judge(s.c[s.top-1],str.charAt(i))){
                    System.out.println("No");
                    return;
                }else{
                    s.pop();
                }
            }
        }
        if(s.top==0){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}
