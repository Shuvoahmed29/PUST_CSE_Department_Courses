public class A_20_imp_3_a {
    public static void main(String[] args) {
        example obj = new example();
        obj.diaplay();
    }
}
class example {
    public int i = 10; // instance variable
    static int s = 20; // static variable

    void diaplay() {
        int l = 20; // local variable
        System.out.println("Local Variable: " + l);
        System.out.println("Inastance Variable: " + i);
        System.out.println("Static Variable: " + s);
    }
}


