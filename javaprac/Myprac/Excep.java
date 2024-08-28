class OddNumberException extends Exception{

}
public class Excep{
    public static void Odd(int n) throws OddNumberException{
        if(n%2==0){
            System.out.println("Not odd");
        }
        else{
            throw new OddNumberException();
        }
    }
    public static void main(String[] args) {
        try{
            Odd(13);
        }
        catch(OddNumberException e){
            System.out.println("the error is" +e);
        }
    }
}