package tests;

import structures.OrderedList;

public class testInteger {
    public static void test() throws Exception {
        OrderedList<Integer> a = new OrderedList<Integer>();
        a.insert(5);
        a.insert(6);
        a.insert(3);
        a.insert(4);
        a.insert(1);
        a.insert(2);
        System.out.println(a.min() + "\n");
        System.out.println(a.max() + "\n");
        System.out.println(a.toString() + "\n");

        a.remove(3);
        System.out.println(a.toString() + "\n");

        Integer i = a.at(3);
        System.out.println(i);

        System.out.println(a.search(4));
        System.out.println(a.search(7) + "\n");

        System.out.println(a.index(1));
        System.out.println(a.index(4));
        System.out.println(a.index(6) + "\n");

        for(Integer x: a){
            System.out.println(x);
        }
    }
}
