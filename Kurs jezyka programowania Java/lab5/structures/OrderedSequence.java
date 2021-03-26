package structures;

public interface OrderedSequence <T extends Comparable<T>> {
    void insert(T el) throws Exception;
    void remove(T el) throws Exception;
    T min();
    T max();
    T at(int pos);
    boolean search(T el);
    int index(T el) throws Exception;

    int listSize();
    boolean isEmpty();
}
