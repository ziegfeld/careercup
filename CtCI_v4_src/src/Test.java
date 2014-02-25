import java.util.Scanner;

class Test {
  public static void main (String arg[]) {
    Scanner scan = new Scanner(System.in);
    int withdraw = scan.nextInt();
    Double balance = scan.nextDouble();
    if ((withdraw % 5 == 0) && ((balance - 0.5 - withdraw) >= 0)) {
      System.out.format("%.2f\n", balance -=  0.5 + withdraw);
    } else {
      System.out.format("%.2f\n", balance);
    }
  }
}