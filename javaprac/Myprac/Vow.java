import java.util.*;
class NoVowelException extends Exception{

}
public class Vow {
    public static void checkvow(String s)throws NoVowelException{
        int c=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='a'||s.charAt(i)=='e'||s.charAt(i)=='i'||s.charAt(i)=='o'||s.charAt(i)=='u'){
                c++;
            }
        }
        if(c==0){
            throw new NoVowelException();
        }
        else{
            System.out.println("NO PROB");
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        try{
            checkvow(s);
        }
        catch(NoVowelException e){
            System.out.println("the error is "+e);
        }
    }   
}
