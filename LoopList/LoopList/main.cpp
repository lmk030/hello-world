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
public:
    looplist(int a);
    virtual ~looplist();
    void del();
};
void looplist::del()
{
    Node * q = head -> next -> next;
    delete head -> next;
    head ->next = q;
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
}


int main(int argc, const char * argv[]) {
    return 0;
}
