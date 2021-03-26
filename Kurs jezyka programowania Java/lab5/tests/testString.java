package tests;

import structures.OrderedList;

public class testString {
    public static void test() throws Exception {
        OrderedList<String> a = new OrderedList<String>();
        a.insert("Ala");
        a.insert("ma");
        a.insert("kota");
        a.insert("kot");
        a.insert("Ale");
        System.out.println(a.min() + "\n");
        System.out.println(a.max() + "\n");
        System.out.println(a.toString() + "\n");

        a.remove("kot");
        a.remove("Ale");
        System.out.println(a.toString() + "\n");

        String i = a.at(2);
        System.out.println(i + "\n");

        System.out.println(a.search("Ala") + "\n");

        System.out.println(a.index("kota") + "\n");

        for(String x: a){
            System.out.println(x);
        }
    }
}
