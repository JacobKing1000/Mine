
import java.util.Scanner;

public class cgpa{
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Put sum of all 5 subjects:");
        int a=sc.nextInt();
        float cgpa = (((a/500f)*100f)/9.5f);
        System.out.println("The Cgpa is:"+cgpa);
    }
}