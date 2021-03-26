package structures;

import java.util.Iterator;

public class OrderedList <T extends Comparable<T>> implements OrderedSequence<T>, Iterable<T> {
    private class Node <T extends Comparable<T>> {
        private Node<T> next;
        private T data;

        public Node (T data) {
            if(data == null)
                throw new NullPointerException();
            this.data = data;
        }

        public int compareTo(T el) {
            return data.compareTo(el);
        }

        public T getData() {
            return data;
        }

        public Node<T> getNext() {
            return next;
        }

        public void setData(T data) {
            this.data = data;
        }

        public void setNext(Node<T> next) {
            this.next = next;
        }

        @Override
        public String toString() {
            return data.toString();
        }
    }

    private class OLIterable<T extends Comparable<T>>  implements Iterator<T> {
        private Node<T> current;
        private Node<T> prev;

        private final Node<T> start;

        public OLIterable(Node<T> start) {
            current = start;
            this.start = start;
        }

        @Override
        public boolean hasNext() {
            return current != null;
        }

        @Override
        public T next() {
            if (hasNext()) {
                T tmp = current.data;
                prev = current;
                current = current.next;
                return tmp;
            }
            current = start;
            return null;
        }

        @Override
        public void remove() {
            if(hasNext()) {
                prev.setNext(current.getNext());
            }
        }
    }

    private Node<T> start;

    public OrderedList () {
        start = null;
    }

    @Override
    public Iterator<T> iterator() {
        return new OLIterable<>(start);
    }

    @Override
    public void insert(T el) throws Exception {
        if(el == null)
            throw new NullPointerException();
        Node<T> next = new Node(el);
        if(isEmpty()) {
            start = next;
        }
        else {
            Node<T> tmp = start;
            int i = 0;
            while(tmp.next != null && tmp.next.compareTo(el) < 0) { //szukamy .next z wartoscia wieksza od el
                tmp = tmp.next;                                     //lub aż do natrafimy na null
                i++;
            }
            if(tmp.compareTo(el) == 0) //sprawdzamy czy el juz sie nie powtarza na liscie
                throw new Exception("na liscie wystepuje juz taki element");
            if(tmp.compareTo(el) > 0 && i == 0) { //szczegolny przypadek dla pierwszego elementu
                next.next = start;
                start = next;
                return;
            }
            next.next = tmp.next;
            tmp.next = next;
        }
    }

    @Override
    public void remove(T el) throws Exception {
        if (isEmpty() || el == null)
            throw new NullPointerException();
        Node<T> tmp = start;

        if(tmp.compareTo(el) == 0) {//sprawdzamy pierwszy Node na liscie
            tmp = tmp.next;
            start = tmp;
            return;
        }

        while(tmp.next.compareTo(el) != 0) {//szukamy elementu, ktory jest rowny el
            tmp = tmp.next;
            if (tmp.next == null)
                throw new Exception("brak elementu na liscie");
        }
        Node<T> rmv = tmp.next;
        tmp.next = rmv.next;
    }

    @Override
    public T min() {
        if (isEmpty())
            throw new NullPointerException();
        return start.data;
    }

    @Override
    public T max() {
        if (isEmpty())
            throw new NullPointerException();
        Node<T> tmp = start;
        while(tmp.next != null)
            tmp = tmp.next;
        return tmp.data;
    }

    @Override
    public T at(int pos){
        if (isEmpty())
            throw new NullPointerException();
        Node<T> tmp = start;
        int i = pos;
        while(i > 0) {
            if (tmp == null)
                throw new NullPointerException("brak elementu na liscie");
            tmp = tmp.next;
            i--;
        }
        if(tmp == null) //przypadek jesli pos = n + 1
            throw new NullPointerException("brak elementu na liscie");
        return tmp.data;
    }

    @Override
    public boolean search(T el) {
        if (isEmpty() || el == null)
            throw new NullPointerException();
        Node<T> tmp = start;
        if(tmp.compareTo(el) == 0)
            return true;
        while(tmp.next.compareTo(el) != 0) {
            tmp = tmp.next;
            if (tmp.next == null)
                return false;
        }
        return true;
    }

    @Override
    public int index(T el) throws Exception {
        if (isEmpty() || el == null)
            throw new NullPointerException();
        Node<T> tmp = start;
        if(tmp.compareTo(el) == 0)
            return 0;
        int i = 0;
        while(tmp.compareTo(el) != 0) {
            tmp = tmp.next;
            i++;
            if (tmp == null)
                throw new Exception("brak elementu na liscie");
        }
        return i;
    }

    @Override
    public int listSize() {
        int size = 0;
        Node<T> tmp = start;
        while (tmp != null) {
            size++;
            tmp = tmp.next;
        }
        return size;
    }

    @Override
    public boolean isEmpty() {
        return start == null;
    }

    public Node<T> getStart() {
        return start;
    }

    public void setStart(Node<T> start) {
        this.start = start;
    }

    @Override
    public String toString () {
        StringBuilder s = new StringBuilder();
        Node<T> tmp = start;
        while(tmp != null) {
            s.append(tmp.data).append(" ");
            tmp = tmp.next;
        }
        return s.toString();
    }
}