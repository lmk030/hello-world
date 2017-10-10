//
//  main.cpp
//  list
//
//  Created by 李民凯 on 2017/10/11.
//  Copyright © 2017年 llmklmk. All rights reserved.
//

#include <iostream>
#include <iostream>
using namespace std;
template<class Type>
struct node
{
    Type data;
    node<Type> * next;
    node();
    node(Type item,node<Type>* link = NULL);
};
template <class Type>
node<Type> ::node()
{
    next = NULL;
}

template <class Type>
node<Type> :: node(Type item,node<Type>* link)
{
    data = item;
    next = link;
}

template<class type>
class linklist
{
protected:
    node<type> * head;
    node<type> *getElemptr(int position) const;
    void Init();
public:
    linklist();
    virtual ~linklist();
    int length();
    bool empty();
    void clear();
    node<type>* getElem(int a);
    void print(int a);
    void setElem(int a,type e);
    void Delete(int p);
    void Insert(int a,int b,type e);
    void add(type e);
    
    
};

template<class type>
node<type> *linklist<type>::getElemptr(int position) const
{
    node<type> *temptr = head;
    int curPosition = 0;
    
    while (temptr != NULL&&curPosition<position) {
        temptr = temptr->next;
        curPosition++;
    }
    if (temptr != NULL&&curPosition==position) {
        return temptr;
    }
}
template<class type>
void linklist<type>::Init()
{
    head = new node<type>;
}
template<class type>
linklist<type>::linklist()
{
    Init();
}
template<class type>
linklist<type>::~linklist<type>()
{
    clear();
    delete head;
}
template<class type>
int linklist<type>::length(){
    int count = 0;
    for (node<type> *p = head -> next; p!=NULL; p = p -> next) {
        count++;
    }
    return count;
}
template<class type>
bool linklist<type>::empty()
{
    return head -> next;
}
template<class type>
void linklist<type>::clear()
{
    for (node<type>* p = head; p!= NULL; p = p->next)
    {
        Delete(1);
    }
}
template<class type>
node<type>* linklist<type>::getElem(int a)
{
    node<type>* p = head;
    for (int i = 0; i< a; i++)
    {
        p = p->next;
    }
    return p;
    
}

template<class type>
void linklist<type>::setElem(int a,type e)
{
    if (a>length()||a<1) {
        printf("error");
    }
    else{
        node<type>* p;
        p = getElem(a);
        p -> data = e;
    }
}

template<class type>
void linklist<type>::Insert(int a, int b, type e)
{
    if (a>length()||a<1) {
        printf("error");
    }
    else{
        node<type>* p;
        p = new node<type>(e,getElem(b));
        getElem(a) -> next = p;
        
    }
}
template<class type>
void linklist<type>::add(type e)
{
    node<type>* p;
    p = new node<type>(e,NULL);
    getElem(length())->next = p;
    
}
template<class type>
void linklist<type>::Delete(int p)
{
    getElem(p-1)->next = getElem(p)->next;
    node<type>* q;
    q = getElem(p);
    q = NULL;
    delete q;
}
template<class type>
void linklist<type> :: print(int a)
{
    if (a>length()||a<1)
    {
        printf("error");
    }
    else
    {
        node<type>* p = head;
        for (int i = 0; i< a; i++)
        {
            p = p->next;
        }
        cout << p -> data << endl;
    }
    
}


int main(int argc, const char * argv[]) {
   
    return 0;
}
