//
//  main.cpp
//  多项式相加
//
//  Created by 李民凯 on 2017/10/11.
//  Copyright © 2017年 llmklmk. All rights reserved.
//

#include <iostream>
using namespace std;
template<class Type>
struct node
{
    Type data1;
    Type data2;
    node<Type> * next;
    node();
    node(Type item1,Type item2,node<Type>* link = NULL);
};
template <class Type>
node<Type> ::node()
{
    next = NULL;
}

template <class Type>
node<Type> :: node(Type item1,Type item2,node<Type>* link)
{
    data1 = item1;
    data2 = item2;
    next = link;
}

template<class type>
class linklist
{
protected:
    node<type> * head;
    void Init();
public:
    linklist();
    virtual ~linklist();
    int length();
    bool empty();
    void clear();
    node<type>* getElem(int a);
    type geta(int a);
    type getb(int a);
    void print(int a);
    void setElem(int a,type e,type f);
    void Delete(int p);
    void add(type e,type f);
    
    
};
template<class type>
type linklist<type>::geta(int a)
{
    node<type> * p = head;
    for (int i = 0; i < a; i++) {
        p = p -> next;
    }
    return p -> data1;
}
template<class type>
type linklist<type>::getb(int a)
{
    node<type> * p = head;
    for (int i = 0; i < a; i++) {
        p = p -> next;
    }
    return p -> data2;
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
    for (node<type> *p = head -> next; p != NULL; p = p -> next) {
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
void linklist<type>::setElem(int a,type e,type f)
{
    if (a>length()||a<1) {
        printf("error");
    }
    else{
        node<type>* p;
        p = getElem(a);
        p -> data1 = e;
        p -> data2 = f;
    }
}

template<class type>
void linklist<type>::add(type e,type f)
{
    node<type>* p;
    p = new node<type>(e,f,NULL);
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
        cout << p -> data1 << p -> data2 << endl;
    }
    
}


int main(int argc, const char * argv[]) {
    linklist<double> polynomialA;
    double a,b;
    cout << "请输入多项式a的系数和次数" << endl;
    for (int i = 0; i < 3 ; i++) {
        cin >> a >> b;
        polynomialA.add(a, b);

    }
    
    linklist<double> polynomialB;
    double c,d;
    cout << "请输入多项式b的系数和次数" << endl;
    for (int i = 0;  i < 3; i++) {
        cin >> c >> d;
        polynomialB.add(c, d);
    }
    double sum;
    linklist<double> polynomialC;
    for (int i = 1; i <= polynomialA.length(); i++)
    {
        int cout = 0;
        for (int j = 1; j <= polynomialB.length(); j++)
        {
            
            if (polynomialA.getb(i) == polynomialB.getb(j))
            {
                
                sum = polynomialA.geta(i) + polynomialB.geta(j);
                polynomialC.add(sum, polynomialB.getb(j));
                cout ++;
            }
            if (cout == 0) {
                polynomialC.add(polynomialB.geta(j), polynomialB.getb(j));
            }
            
        }
        if (cout == 0) {
             polynomialC.add(polynomialA.geta(i), polynomialA.getb(i));
        }
    }
    for (int i = 1; i <= polynomialC.length(); i++) {
        polynomialC.print(i);
    }

    return 0;
}
