package Lab3;
import java.util.Scanner;
public class Letter_K_in_keyboard {
    public static boolean doTwo(int pace,char[] c,int l){

        return false;
    }
    public static boolean canPass(int pace,char[] c){
        int last=-1;//包含在前一个中
        boolean flag=false;//false是没遇到
        int lastK=-1;
        for (int i = 0; i < c.length-1; i++) {
            if(c[i]!='K') {
                if (flag) {
                    if (i - last == pace) {
                        last = i;
                        //System.out.println("i="+i+","+"letter="+c[i]+","+"pace="+pace+   ",(A)Update Last="+last);
                        flag = false;
                    }
                }
            }else if(c[i]=='K'){
                lastK=i;
                if(flag){
                    if(i-last<=pace){
                        //System.out.println("(1)pace!="+pace);
                        return false;
                    }else{
                        //System.out.println("i="+i+","+"letter="+c[i]+","+"pace="+pace+   ",(B)Update Last="+last);
                        last=i-1;
                    }
                }else{
                    flag=true;
                    if(i-last>=pace){
                        last=i;
                        flag=false;
                    }
                }
            }
        }
        int fi=c.length-1;
        if(lastK<=last){
            if(c[fi]=='K'&&fi-last>=pace||c[fi]!='K'){
                return true;
            }else {
                return false;
            }
        }else{
            if(c[fi]!='K'&&fi-last>=pace)return true;
            return false;
        }
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        String str=in.next();
        char[] c= str.toCharArray();

        int low=1,high=str.length();
        while(low<high){
            int mid=(low+high)/2;
            if(mid==low){
                if(canPass(high,c)){
                    System.out.println(high);
                }else{
                    System.out.println(low);
                }
                return;
            }else{
                if(canPass(mid,c)){
                    low=mid;
                }else{
                    high=mid-1;
                }
            }
        }
        System.out.println(low);
    }
}
