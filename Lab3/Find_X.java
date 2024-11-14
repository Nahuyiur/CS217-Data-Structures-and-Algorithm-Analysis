package Lab3;
import java.util.Scanner;
public class Find_X {
    public static double calculate(double x,int a,int b,int c,int d){
        double ans=x*a+Math.log(x)*b-(double) c/x+ d;
        return ans;
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        //int y,a,b,c,d;
        //y=in.nextInt();a=in.nextInt();b=in.nextInt();c=in.nextInt();d=in.nextInt();
        int y = Integer.parseInt(args[0]);
        int a = Integer.parseInt(args[1]);
        int b = Integer.parseInt(args[2]);
        int c = Integer.parseInt(args[3]);
        int d = Integer.parseInt(args[4]);

        long l= 100L;
        long r= 1000*1000*1000*100L;
        long m=(l+r)/2;
        if(calculate(1,a,b,c,d)>y||calculate(1000000000,a,b,c,d)<y||
                (a==0&&b==0&&c==0&&d!=y)){
            System.out.println("NO ANSWER");
        } else if (a==0&&b==0&&c==0&&y==d) {
            System.out.println("NOT UNIQUE");
        }else{
            while(r>l+1){
                m=(l+r)/2;
                if(calculate((double) m/100,a,b,c,d)>y){
                    r=m;
                    //System.out.println("l="+l+","+"r="+r);
                }else{
                    l=m;
                    //System.out.println("l="+l+","+"r="+r);
                }
            }
            System.out.println(l);
        }
    }
}
