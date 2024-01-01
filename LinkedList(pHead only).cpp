#include<iostream>
struct Node{
    int data;
    Node *pNext;
};

struct SingleList{
    Node *pHead;
};

void initialize(SingleList &List)
{
    List.pHead = NULL;
}

Node *createNode(int d)
{
    //Dynamic Memory

    Node *pNode = new Node;
    if(pNode!= NULL) //Memory Allocated Successful
    {
        pNode->data = d;
        pNode->pNext = NULL;
    }

    else {
        std::cout<<"Can't Allocate new Space for memory";
    }
}

void printList(SingleList &List)
{
    Node *pTmp = List.pHead;
    if(pTmp == NULL)
    {
        std::cout<<"\n This List is empty";
        return;
    }
    while(pTmp != NULL)
    {
        std::cout<<pTmp->data<<" ";
        pTmp= pTmp->pNext;
    }
}

int CountNode(SingleList List)
{
    Node *pTmp = List.pHead;
    int counter = 0;
    while(pTmp != NULL)
    {
        pTmp= pTmp->pNext;
        counter++;
    }
    return counter;
}
void insertFirst(SingleList &List, int d)
{
    Node *pNode = createNode(d);
    if(List.pHead == NULL)
    {
        List.pHead = pNode;
    }
    else{
        pNode->pNext = List.pHead;
        List.pHead = pNode;
    }
}
void insertLast(SingleList &List, int d)
{
    Node *pNode = createNode(d);
    if(List.pHead == NULL)
    {
        List.pHead = pNode;
    }
    else{
        Node *pTmp = List.pHead;
        while(pTmp->pNext != NULL)
        {
           pTmp = pTmp->pNext;
        }
    pTmp->pNext = pNode;
    }
}
void insertMid(SingleList &List, int pos, int d)
{

    if(pos < 0 || pos >= CountNode(List))
    {
        std::cout<<"Not Valid position to insert";
        return;
    }
    if(pos == 0)
        insertFirst(List,d);
    else if(pos == CountNode(List)- 1)
        insertLast(List,d);

    else
    {
        Node *pNode = createNode(d);
        Node *pIns = List.pHead;
        Node *pPre =NULL;
        int i = 0;
        while(pIns != NULL)
        {
            if(i==pos)
                break;
            pPre=pIns;
            pIns= pIns->pNext;
            i++;
        }
        pPre->pNext =pNode;
        pNode->pNext = pIns;
    }
}

Node * searchNode(SingleList List, int data)
{
    Node *pTmp = List.pHead;
    while(pTmp != NULL)
    {
        if(pTmp->data == data)
            break;
        pTmp = pTmp->pNext;
    }
    return pTmp;
}
void removeNode(SingleList &list, int d)
{
    Node *pDel=list.pHead;
    if(pDel==NULL)
    {
        std::cout<<"\n The List is empty!";
    }
    else
    {
        Node *pPre = NULL;
        while(pDel!=NULL)
        {
            if(pDel->data==d)
                break;
            pPre=pDel;
            pDel=pDel->pNext;
        }
        if(pDel == NULL)
        {
            std::cout << "\nError: Variable '" << d << "' not found.";
        }
        else
        {
            if(pDel==list.pHead)
            {
                list.pHead=list.pHead->pNext;
                pDel->pNext=NULL;
                delete pDel;
                pDel = NULL;
            }
            else
            {
                pPre->pNext=pDel->pNext;
                pDel->pNext = NULL;
                delete pDel;
                pDel=NULL;
            }
        }
    }
}
int main()
{
    SingleList List;
    initialize(List);
    insertFirst(List,10);
    insertFirst(List,3);
    insertFirst(List,7);
    insertFirst(List,8);
    printList(List);

    //insertMid(List, 2, 4);
    std::cout<<"\n Node is found ";
    Node *psearch = searchNode(List,3);
    if(psearch != NULL)
    {
        std::cout<<psearch->data;
    }
    else{
        std::cout<<"NULL";
    }

    removeNode(List, 9);


    removeNode(List, 10);
    std::cout<<"\n New List :";
    printList(List);

}
