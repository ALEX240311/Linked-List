#include <iostream>
// Cau truc du lieu cua danh sach lien ket don
//bat dau voi khoi tao cau truc Node
struct Node{
    int data;
    Node *pNext;

};
//Khoi tao Node moi
Node *createNode(int d)
{
    Node *pNode = new Node;
    if(pNode != NULL)
    {
        pNode->data = d;
        pNode->pNext = NULL;
    }
    else
    {
        std::cout<<"Error Allocated Memory";
    }
    return pNode;
}

//Khoi tao cau truc cua danh sach lien ket voi 1 node quan ly la pHead
struct SingleList{
    Node *pHead;
};

//Khoi tao danh sach lien ket, do chua co Node moi nen Node dau tien cua danh sach luon la Null
void initialize(SingleList &List)
{
    List.pHead = NULL;
}
void printList(SingleList List)
{
    Node *nodeTmp = List.pHead;
    if(nodeTmp == NULL)
    {
        std::cout<<"This List is empty";
        return;
    }
    while(nodeTmp != NULL)
    {
        std::cout<<nodeTmp->data<<" ";
        nodeTmp = nodeTmp->pNext;
    }
}

int sizeOfList(SingleList List)
{
    Node *nodeTmp = List.pHead;
    int nSize = 0;
    while(nodeTmp != NULL)
    {
        nodeTmp = nodeTmp->pNext;
        nSize++;
    }
    return nSize;

}

void insertFirst(SingleList List, int d)
{
    Node *pNode = createNode(d);
    if(List.pHead == NULL)
    {
        List.pHead = pNode;
    }
    else
    {
        pNode->pNext = List.pHead;
        List.pHead= pNode;
    }
}
int main(int argc, char** argv)
{
    SingleList List;
    initialize(List);
    insertFirst(List,10);
    insertFirst(List,5);
    insertFirst(List,9);
    printList(List);
}