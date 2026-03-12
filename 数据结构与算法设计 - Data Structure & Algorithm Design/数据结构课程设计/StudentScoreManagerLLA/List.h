#ifndef myList_h
#define myList_h

template<class T> 
class List {
    
private: 
    class Node {
    public:
        Node *next;
        Node *prev;

        T data;
        Node(T data) : data(data), next(nullptr), prev(nullptr) {}
    };

    Node *head,*tail;
    int total_size;

public:

    class iterator {
        Node *current;

    public: 
        iterator(Node *current) : current(current) {}
        operator Node * () { return current; }
        iterator& operator ++ () { current=current->next; return *this; }
        iterator operator ++ (int) { iterator it = *this; ++(*this); return it; }
        iterator& operator -- () { current=current->prev; return *this; }
        iterator operator -- (int) { iterator it = *this; --(*this); return it; }
        T& operator * () { return current->data; }
        bool operator != (const iterator &other) { return current!= other.current; }
        bool operator == (const iterator &other) { return current == other.current; }
        friend iterator next (iterator it) { return ++it; }
        friend iterator prev (iterator it) { return --it; }
        Node * operator -> () { return current; }
        Node * point () { return current; }
    };

    iterator begin() { return iterator(head->next); }
    iterator end() { return iterator(tail); }
    T& front() { return *begin(); }
    T& back() { return *prev(end()); }
    bool empty() { return begin()!=end(); }
    int size() { return total_size; }

    // 按索引访问元素
    T& operator [] (int index) {
        if(index<0||index>=total_size) throw "Index out of range";
        iterator it = begin();
        for(int i=0;i<index;i++) ++it;
        return *it;
    }

    // 按值查找 返回迭代器
    iterator find(const T& val) {
        for(auto it=begin();it!=end();++it) { 
            if(*it==val) return it;
        }
        return end();
    }

    // 在 it 和 prev(it) 之间插入 data
    iterator insert(iterator it,const T& data) {
        Node *new_node = new Node(data);
        new_node->next = it;
        new_node->prev = it->prev;
        it->prev->next = new_node;
        it->prev = new_node;
        total_size++;

        return iterator(new_node);
    }

    // 按迭代器删除
    bool earse(iterator it) {
        if(it==end()) return false;
        it->prev->next = it->next;
        it->next->prev = it->prev;
        delete it;
        total_size--;
        return true;
    }

    // 按值删除
    bool earse(const T& val) { return earse(find(val)); }

    void push_back(const T& val) { insert(end(),val); }
    void push_front(const T& val) { insert(begin(),val); }
    void pop_back() { erase(prev(end())); }
    void pop_front() { earse(begin()); }

    // 构造
    List() : head(new Node(T())), tail(new Node(T())), total_size(0) {
        head->next = tail;
        tail->prev = head;
    }

    ~List() {
        while(!empty()) {
            earse(begin());
        }
        delete head;
        delete tail;
    }
};


#endif