import java.util.*;
class DuplicateException extends Exception{
 
}
public class Dup {
   
    public static void main(String[] args) {
    Scanner sc= new Scanner(System.in);
    int n=sc.nextInt();
    int[] a=new int[n];
    for(int i=0;i<n;i++){
        int x=sc.nextInt();
        a[i]=x;
        try{
            //check(x,a);
            for(int j=0;j<i;j++){
                if(x==a[j]){
                    throw new DuplicateException();
                }
            }
            }
        catch(Exception e){
            System.out.println("the exception is Duplicate one"+e);
        }
        }
        for(int x:a){
            System.out.println(x);
        }
    }
}

