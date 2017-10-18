//
//  main.cpp
//  LoopList
//
//  Created by 李民凯 on 2017/10/10.
//  Copyright © 2017年 llmklmk. All rights reserved.
//

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class looplist
{
protected:
    Node p;
    Node *head;
    Node *rear;
    int length;
public:
    looplist(int a);
    virtual ~looplist();
    void del(int a);
    Node* getelem(int a);
};
void looplist::del(int a)
{
    if (a == 1) {
        Node* p = head -> next;
        delete head;
        head = p;
        rear -> next = head;
        length--;
    }
    if (a == length) {
        Node* q = getelem(length - 1);
        delete rear;
        rear = q;
        rear -> next = head;
        length--;
    }
    
    Node * q = getelem(a) -> next;
    delete getelem(a);
    getelem(a-1) -> next = q;
    length--;
}
looplist::looplist(int a)
{
    head = new Node;
    Node * name[a];
    name [0] = head;
    for (int i = 1; i < a; i ++) {
        name[i] = new Node;
        name[i-1] -> next = name [i];
    }
    rear = name[a-1];
    rear -> next = head;
}
looplist ::~looplist()
{
    while (head != NULL) {
        del(1);
    }
}
Node* looplist::getelem(int a)
{
    Node* p = head;
    for (int i = 0; i < a-1; i++) {
        p = p -> next;
    }
    return p;
}



int main(int argc, const char * argv[]) {
    return 0;
}
