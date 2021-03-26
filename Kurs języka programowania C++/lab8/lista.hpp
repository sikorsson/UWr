#ifndef INC_8_LISTA_HPP
#define INC_8_LISTA_HPP

#include <iostream>
using namespace std;

template<class T>
class list {
private:
    class node {
    public:
        node* next;
        T data;
    };

    node *head;
public:
    list();
    list(const list& l);
    list(const list&& l);
    ~list();
    void pushFront(T data);
    void pushBack(T data);
    void insert(int pos, T data);
    void deleteData(T data);
    int size();
    bool search(T data);
    friend ostream &operator <<(ostream &s, const list& l) {
        node *n = l.head;
        while(n) {
            s << n->data << " ";
            n = n->next;
        }
        s << endl;
        return s;
    }
};

#endif //INC_8_LISTA_HPP
