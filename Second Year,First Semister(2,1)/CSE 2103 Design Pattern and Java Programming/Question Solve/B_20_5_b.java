import java.util.*;
public class B_20_5_b {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter an integer number: ");
        int n = scanner.nextInt();
        int cunt = 1,p=0,q;
        int y=1,a=0;
        for(int k=1;k<=n;k++){
            cunt = k;
            q=0;
            for(int i=1; i<=(n/2)-a; i++) {
                System.out.print(" ");
            }
            a = a+1;
            for(int j=1; j<=k+p; j++) {
                System.out.print(cunt+" ");
                if(cunt!=y && q ==0) cunt++;
                else{
                    cunt--; 
                    q=1;
                }
                if(cunt>=10) cunt=0;
            }
            p++;
            y=y+2;
            System.out.println();
        }
    }
}
