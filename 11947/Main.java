import java.util.*;
import java.text.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    sc.nextLine();
    for(int i = 1; i <= n; ++i) {
      String date = sc.nextLine();
      int m = Integer.valueOf(date.substring(0,2));
      int d = Integer.valueOf(date.substring(2,4));
      int y = Integer.valueOf(date.substring(4));
      GregorianCalendar cal = new GregorianCalendar(y,m-1,d);
      cal.add(Calendar.DAY_OF_MONTH, 280);
      SimpleDateFormat sdf = new SimpleDateFormat("MM/dd/yyyy");
      for(Map.Entry<Date,String> e : zodiacs.entrySet())  e.getKey().setYear(cal.get(Calendar.YEAR)-1900);
      System.out.println(i + " " + sdf.format(cal.getTime()) + " " + zodiacs.floorEntry(cal.getTime()).getValue());
    }   
  }
  static TreeMap<Date,String> zodiacs = new TreeMap<>();
  static {
    zodiacs.put(new Date(0, 0, 1), "capricorn");
    zodiacs.put(new Date(0, 0, 21), "aquarius");
    zodiacs.put(new Date(0, 1, 20), "pisces");
    zodiacs.put(new Date(0, 2, 21), "aries");
    zodiacs.put(new Date(0, 3, 21), "taurus");
    zodiacs.put(new Date(0, 4, 22), "gemini");
    zodiacs.put(new Date(0, 5, 22), "cancer");
    zodiacs.put(new Date(0, 6, 23), "leo");
    zodiacs.put(new Date(0, 7, 22), "virgo");
    zodiacs.put(new Date(0, 8, 24), "libra");
    zodiacs.put(new Date(0, 9, 24), "scorpio");
    zodiacs.put(new Date(0, 10, 23), "sagittarius");
    zodiacs.put(new Date(0, 11, 23), "capricorn");
  }
}
