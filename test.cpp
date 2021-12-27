#include <iostream>

using namespace std;

template<typename T>
class List {
public:
    List();
    ~List();
private:
    class Node {
    public:
        Node* pNext;
        T data;
        Node (T data = T(), Node* pNext= nullptr){
            this->data = data;
            this->pNext = pNext;
        }
    };

    int size;
    Node* getLastNode(Node* current);
    Node* getPreviousAt(int index);


public:
    Node* head;
    int getSize() {return size;};
    T& operator[](int index);
    void push_back(T data);
    void pop_front();
    void clear();
    void push_front(T data);
    void print();
    void insert(int index, T data);
    void removeAt(int index);
    void pop_back();
    
};


template<typename T>
List<T>::List () {
    size = 0;
    head = nullptr;
  
}

template<typename T>
List<T>::~List () {
    clear();
}

template<typename T>
typename List<T>::Node* List<T>::getLastNode(Node* current)
{
    while (current->pNext != nullptr)
    {   
        current = current->pNext;
    }
    return current;
}

template<typename T>
void List<T>::push_back(T data) {
    if (head == nullptr) {
        head = new Node(data);
        size++;
        return;
    }
    Node* last = getLastNode(head);
    
    last->pNext = new Node(data);
    size++;
}

template<typename T>
void List<T>::pop_front() {
    Node* temp = head;
    head = head->pNext;
    delete temp;
    size--;
}

template<typename T>
void List<T>::clear() {
    while(size) {
        pop_front();
    }
}

template<typename T>
T& List<T>::operator[](int index)
{

    Node* current = head;
    for(auto i = 0; i < index; ++i)
    {
        current = current->pNext;
    }
    return current->data;
}

template<typename T>
void List<T>::print() {
    cout << "size: " << getSize() << endl;
    for(auto i = 0; i < getSize(); ++i)
    {
        cout << operator[](i) << endl;
    }
}

template<typename T>
void List<T>::push_front(T data) {
    head = new Node(data, head);
    size++;
}

template<typename T>
typename List<T>::Node* List<T>::getPreviousAt(int index) {
    Node* current = head;
    for(auto i = 0; i < (index - 1); ++i) {   
        current = current->pNext;
    }
    return current;
}

template<typename T>
void List<T>::insert(int index, T data) {
    if (index == 0) {
        push_front(data);
        return;
    }
    Node* previous = getPreviousAt(index);
    Node* newNode = new Node(data, previous->pNext);
    previous->pNext = newNode;
    size++;
}

template<typename T>
void List<T>::removeAt(int index) {
    if (index == 0) {
        pop_front();
        return;
    }
    Node* previous = getPreviousAt(index);
    Node* current = previous->pNext;
    Node* next = current->pNext;
    previous->pNext = next;
    delete current;
    size--;
}

template<typename T>
void List<T>::pop_back() {
    removeAt(size - 1);
}



int main()
{

    auto s1 = List<int>();
    cout << "push_back 5" << endl;
    for(auto i = 0; i < 5; ++i)
    {
        s1.push_back(i);
    }

    s1.print();

    cout << "clear" << endl;
    s1.clear();
    s1.print();

    cout << "push_back 6" << endl;
    for(auto i = 0; i < 6; ++i)
    {
        s1.push_back(i);
    }

    s1.print();

    cout << "push_front" << endl;
    s1.push_front(22);
    s1.print();

    cout << "push_front" << endl;
    s1.push_front(33);
    s1.print();

    cout << "insert" << endl;
    s1.insert(3, 44);
    s1.print();

    cout << "removeAt" << endl;
    s1.removeAt(2);
    s1.print();

    cout << "pop_back" << endl;
    s1.pop_back();
    s1.print();


    

    return 0;
}