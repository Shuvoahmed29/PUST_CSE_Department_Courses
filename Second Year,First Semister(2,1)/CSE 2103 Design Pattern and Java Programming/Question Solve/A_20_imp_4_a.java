import java.util.*;
import java.lang.Exception;
public class A_20_imp_4_a {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        variable obj = new variable();
        System.out.print("Enter two integer number: ");
        obj.a = scanner.nextInt();
        obj.b = scanner.nextInt();
        sum obj1 = new sum();
        obj1.display();
        
        multiplication obj2 = new multiplication();
        obj2.display();
        
        division obj3 = new division();
        obj3.display();
    }
}
class variable{
    static int a,b;
}
class sum extends variable{
    void display(){
        System.out.println("Sum: "+(a+b));
    }
}
class multiplication extends sum{
    void display(){
        System.out.println("Multiplication: "+(a*b));
    }
}
class division extends multiplication{
    void display(){
        try{
            int ans = a/b;
            System.out.println("division: "+ ans);
        }catch(Exception e){
            System.out.println("Exception: "+e);
        }
    }
}
