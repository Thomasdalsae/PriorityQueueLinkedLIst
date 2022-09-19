#include <iostream>

template <typename T>
struct Node
{
    size_t DATA;
    int Priority;
    Node<T>* Next;
    Node<T>* Previous;

   Node<T>(size_t data,int priority)
   {
       DATA = data;
       Priority = priority;
   }
    
};
template <typename T>
class PQLL
{
public:

    Node<T>* Head;
    Node<T>* Tail;
    int size{};

    PQLL(){
    Head = nullptr;
        Tail = nullptr;
        size = 0;
    }

    Node<T>* NewNode(size_t Data,int Priority);
    void Push(size_t Data,int Priority);
    void PrintOut();
};


