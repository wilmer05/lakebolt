import java.util.*;


public class fibo{


    public static int f(int x){
        if(x<=2) return 1;
        return f(x-1) + f(x-2);
    }

    public static void main(String[] argv){
        if(argv.length!=1) {
            System.out.println("Usage: java fibo <number>");
            return;
        }

        System.out.println(f(Integer.parseInt(argv[0])));
    }
}
