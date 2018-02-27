import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int d, m, y, N;
    while(true) {
      N = sc.nextInt();
      d = sc.nextInt();
      m = sc.nextInt();
      y = sc.nextInt();
      if(d == 0 && m == 0 && y == 0 && N == 0) break;
      GregorianCalendar cal = new GregorianCalendar(y, m-1, d);
      cal.add(Calendar.DATE, N);
      System.out.println(cal.get(Calendar.DAY_OF_MONTH) + " " + (cal.get(Calendar.MONTH)+1) + " " + cal.get(Calendar.YEAR));
    }
  }
}
