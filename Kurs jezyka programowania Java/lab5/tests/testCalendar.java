package tests;

import structures.OrderedList;

import java.util.Calendar;
import java.util.Date;
import java.util.TimeZone;

public class testCalendar {
    public static void test() throws Exception {
        Calendar x = Calendar.getInstance();
        Calendar y = Calendar.getInstance(TimeZone.getTimeZone("China"));
        Calendar z = Calendar.getInstance();

        Date d = new Date(0);
        z.setTime(d);

        OrderedList<Calendar> a = new OrderedList<Calendar>();
        a.insert(x);
        a.insert(y);
        a.insert(z);
        System.out.println(a.min() + "\n");
        System.out.println(a.max() + "\n");
        System.out.println(a.toString() + "\n");

        a.remove(y);
        System.out.println(a.toString() + "\n");

        Calendar i = a.at(1);
        System.out.println(i);

        System.out.println(a.search(z) + "\n");

        System.out.println(a.index(x) + "\n");

        for(Calendar k: a){
            System.out.println(k);
        }
    }
}
