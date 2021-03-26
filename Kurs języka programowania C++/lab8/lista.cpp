#include "lista.hpp"

template<class T>
list<T>::list() {
    head = NULL;
}

template<class T>
list<T>::list(const list &l) {
    node *copy = l.head;
    if (copy == NULL) {
        head = NULL;
        return;
    }
    node *n;
    node *_new;
    n = new node();
    n->data = copy->data;
    n->next = NULL;
    head = n;
    copy = copy->next;
    while (copy) {
        _new = new node();
        _new->data = copy->data;
        _new->next = NULL;
        n->next = _new;
        n = n->next;
        copy = copy->next;
    }
}

template<class T>
list<T>::list(const list &&l) {
    node *copy = l.head;
    if (copy == NULL) {
        head = NULL;
        delete copy;
        return;
    }
    node *n;
    node *_new;
    node *tmp;
    n = new node();
    n->data = copy->data;
    n->next = NULL;
    head = n;
    tmp = copy;
    copy = copy->next;
    delete tmp;
    while (copy) {
        _new = new node();
        _new->data = copy->data;
        _new->next = NULL;
        n->next = _new;
        n = n->next;
        tmp = copy;
        copy = copy->next;
        delete tmp;
    }
}

template<class T>
list<T>::~list() {
    node *n = head;
    if (n == NULL) {
        delete n;
        return;
    }
    node *tmp = n->next;
    while (tmp) {
        delete n;
        n = tmp;
        tmp = n->next;
    }
    delete n;
}

template<class T>
void list<T>::pushFront(T data) {
    node *n = new node();
    n->data = data;
    n->next = head;
    head = n;
}

template<class T>
void list<T>::pushBack(T data) {
    node *n = head;
    if (n == NULL) {
        pushFront(data);
        return;
    }
    while (n->next) n = n->next;
    node *_new = new node();
    _new->data = data;
    _new->next = NULL;
    n->next = _new;
}

template<class T>
void list<T>::insert(int pos, T data) {
    if (pos < 0) pos = 0;
    if (pos == 0) {
        pushFront(data);
        return;
    }
    int tmp_size = size() - 1;
    if (pos > tmp_size) pos = tmp_size;
    if (pos == tmp_size) {
        pushBack(data);
        return;
    }
    node *n = head;
    int i = 0;
    while (i < pos - 1) n = n->next;
    node *_next = n->next;
    node *_new = new node();
    _new->data = data;
    _new->next = _next;
    n->next = _new;
}

template<class T>
void list<T>::deleteData(T data) {
    if (size() == 0) throw invalid_argument("Empty list");
    node *n = head;
    if (n->data == data) {
        head = head->next;
        delete n;
        return;
    }
    while (n) {
        if (n->next->data == data) break;
        n = n->next;
    }
    if (n->next->data == data) {
        node *tmp = n->next;
        n->next = tmp->next;
        delete tmp;
    }
}

template<class T>
int list<T>::size() {
    node *n = head;
    int i = 0;
    while (n) {
        i ++;
        n = n->next;
    }
    return i;
}

template<class T>
bool list<T>::search(T data) {
    node *n = head;
    while (n) {
        if (n->data == data) return true;
        n = n->next;
    }
    return false;
}