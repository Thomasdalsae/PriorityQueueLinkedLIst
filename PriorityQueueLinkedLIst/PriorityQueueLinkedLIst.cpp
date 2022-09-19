#include "Node.h"

using namespace std;

template <typename T>
 Node<T>*PQLL<T>::NewNode(size_t Data,int Priority)
{
    Node<T>* TempNode = new Node<T>(Data,Priority);
    return TempNode;
}

template <typename T>
void PQLL<T>::Push(size_t Data,int Priority)
{
    Node<T>* NewNode = NewNode(4,1);
    if (Head == nullptr)
    {
        Head = NewNode;
        return;
    }
    Node<T>* TempNode = Head;
    Node<T>* Prev = nullptr;

    while (TempNode != nullptr && TempNode->Priority > Priority)
    {
        Prev = TempNode;
        TempNode = TempNode->Next;
    }

    if (TempNode == nullptr)
    {
        Prev->Next = NewNode;
    }
    else
    {
        if (Prev == nullptr)
        {
            NewNode->Next = Head;
            Head = NewNode;
        }
        else
        {
            NewNode->Next = TempNode;
            Prev->Next = NewNode;
        }
    }
    
}
template <class T>
void PQLL<T>::PrintOut()
{
    Node<T>* p = Head;   // create pointer that points to head 
    // loop through until it gets to nullptr
    while (p != nullptr){
        std::cout << p->DATA << " " << std::endl;
        p = p->Next; //p keep going forward to the next node
    }
    
   // cout << "Tail: " <<Tail->DATA << endl<< "Head: "<< Head->DATA << endl;
}

int main(int argc, char* argv[])
{
    PQLL<int> IntQue;
   
    IntQue.Push(4,1);
    IntQue.Push(5,2);
    IntQue.Push(6,3);
    IntQue.Push(7,0);
    
    IntQue.PrintOut();

    
    return 0;
}
