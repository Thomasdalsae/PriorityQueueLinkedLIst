#include "Node.h"


using namespace std;

template <typename T>
 Node<T>*PQLL<T>::NewNode(size_t Data,int Priority)
{
    Node<T>* TempNode = new Node<T>(Data,Priority);
    TempNode->Next = nullptr;
    TempNode->Previous = nullptr;
    TempNode->DATA = Data;
    TempNode->Priority = Priority;
    if (Head == nullptr)
    {
        Head = Tail = TempNode;
    }
    else
    {
        TempNode->Previous = Tail;
        Tail = Tail->Next= TempNode;
    }
    size++;
    return TempNode;
}

template <typename T>
void PQLL<T>::Push(size_t Data,int Priority)
{   Node<T>*NewNodeTemp = NewNode(Data,Priority);

    if (Head->Priority > Priority)
    {
        NewNodeTemp->Next = Head;
        Head = NewNodeTemp;
    }
    else
    {
        while (Head->Next != nullptr && Head->Next->Priority < Priority)
        {
            Head = Head->Next;
        }
        NewNodeTemp->Next = Head->Next;
        Head->Next = NewNodeTemp;
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
