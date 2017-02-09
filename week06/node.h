/***********************************************************************
* Header:
*    Node.h header file
* Author:
*    Adam Shumway, Jenaca Willans
* Summary: 
*    Node Template Class Header File
************************************************************************/

#ifndef NODE_H
#define NODE_H

#include <cassert> //for asserts
#include <iostream>

using namespace std;

/*************************************************
* Node
* A Node struct template that holds stuff
*************************************************/
template <class T>
class Node
{
    public:
        Node() : data(0), pNext(NULL) {}
        Node(const T &t) : data(t), pNext(NULL) {} 
    
        T data;
        Node<T> * pNext;

};

template <class T>
Node<T> * copy(Node<T> * &pHead)
{
//    Node<T> * pNew = new Node<T>;
    Node<T> * pNew = new Node<T>;
    //Node<T> * pCopy;
    pNew->data = pHead->data;
    pHead = pHead->pNext;
        //     cout << "debug: pHead->data is " << pHead->data << endl;
    //     pHead = pHead->pNext;
    //     cout << "debug: iterations of copy are " << i++ << endl;

    //     cout << "debug: pNew->data is " << pNew->data << endl;

    while (pHead != NULL)
    {
        pNew->pNext = new Node<T>(pHead->data);
        pHead = pHead->pNext;
    }

    // for (Node<T> * p = pHead; p; p=p->pNext)
    // {
    //    insert(p->data, pNew);
    //    pHead = pHead->pNext;
    //     // pNew->data = p->data;
    //     // pNew->pNext = new Node<T>;
    // }
       
    // }
    // int i = 0;
    // while (pHead != NULL)
    // {
    //     insert(pHead->data, pNew);
    //     //pNew->pNext = new Node<T>;
    //     cout << "debug: pHead->data is " << pHead->data << endl;
    //     pHead = pHead->pNext;
    //     cout << "debug: iterations of copy are " << i++ << endl;

    //     cout << "debug: pNew->data is " << pNew->data << endl;
    // }
    
        // Node<T> * pNew = new Node<T>;
        // pNew->data = data;

        // //2. fix the next pointer
        // pNew->pNext = pNode->pNext;

        // //3. get pNode->pNext to point to new
        // pNode->pNext = pNew;

    return pNew;
}

template <class T>
Node<T> * insert(T data, Node<T> * &pNode, bool head = false)
{
    if(head || pNode == NULL)
        addToHead(data, pNode);
    else
    {
        // cout << "debug: in else of insert\n";
        // cout << "debug: pNode data is " 
        //     << pNode->data << endl;
        // cout << "debug: pNode next is "
        //     << (pNode->pNext ? "address" : "NULL")
        //     << endl;
        // cout << "debug: insert data is - " << data << endl;
        //1. create a new Node
        Node<T> * pNew = new Node<T>;
        pNew->data = data;

        //2. fix the next pointer
        pNew->pNext = pNode->pNext;

        //3. get pNode->pNext to point to new
        pNode->pNext = pNew;
    }
    
    return pNode;
}

template <class T>
void addToHead(T data, Node<T> * & pHead)
{
    // cout << "debug: adding to head\n";
  //1. create a new Node
    Node<T> * pNew = new Node<T>;
    pNew->data = data;

    //2. fix the next pointer
    pNew->pNext = pHead;

    //3. get pNode->pNext to point to new
    pHead = pNew;
}

template <class T>
Node<T> * find(Node<T> * pHead, T index)
{

}

template <class T>
void freeData(Node<T> * & pHead)
{
    //cout << "debug: we're in freeData\n";
    while (pHead != NULL)
    {
        Node<T> * p = pHead;
        p = p->pNext;
        delete pHead;
        pHead = p;
    }
    // for (Node<T> * p = pHead; p; p = p->pNext)
    // {
    //     cout << "debug: trying to delete " << p->data
    //         << endl;
    //     delete p;
    // }

    pHead = NULL;
}

template <class T>
ostream & operator<<(ostream & out, const Node<T> * pHead)
{
    for (const Node<T> * p = pHead; p; p = p->pNext)
    {
       if(p->pNext != NULL)
       {
          out << p->data << ", ";
       }
       else
       {
          out << p->data;
       }
    }
       return out;
}

#endif //NODE_H
