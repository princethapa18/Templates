// Week 51 22 Dec 2021
// Singly Linked List using templates
// LinkedList<int> intList;

#include <iostream>

template <typename T>
class Node
{
    T data;
    Node<T> *next;
public:
    Node(const T& _data) : data(_data) , next(nullptr) {} 
    void setNext(Node<T> *_next) 
    {
        next = _next;
    }
    Node<T>* getNext() const
    {
        return next;
    }
    T getData() const
    {
        return data;
    }
};

template <typename T>
class LinkedList
{
    Node<T> *head, *tail;
public:
    LinkedList() : head(nullptr) , tail(nullptr) {}
    void insert(const T& data);
    void remove();
    Node<T>* getHead() 
    {
        return head;
    }
    Node<T>* getTail()  
    {
        return tail;
    }
};

template <typename T>
void LinkedList<T>::insert(const T& data)
{
    if(head == nullptr)
    {
        head = new Node<T>(data);
        tail = head;
    }
    else
    {
        Node<T> *node = new Node<T>(data);
        tail->setNext(node);
        tail = node;
    }
}

template<typename T>
void printList(T *head)
{
    T *temp = head;
    while(temp)
    {
        std::cout << temp->getData() << "-->" ;
        temp = temp->getNext();
    }
}

int main()
{
    LinkedList<int> intList{};
    intList.insert(6);
    intList.insert(7);
    intList.insert(8);
    intList.insert(11);

    LinkedList<float> floatList{};
    floatList.insert(6.5f);
    floatList.insert(7.3f);
    floatList.insert(9.6f);

    std::cout << "print int list\n";
    printList<Node<int>>(intList.getHead());
    std::cout << "\nprint float list\n";
    printList<Node<float>>(floatList.getHead());

}