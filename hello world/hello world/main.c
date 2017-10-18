//
//  main.c
//  hello world
//
//  Created by 李民凯 on 2017/9/26.
//  Copyright © 2017年 llmklmk. All rights reserved.
//

#include<stdio.h>
#include<bios.h>
int main(void)
{
    int key;
    clrscr();
    while(!bioskey(1)) ;
    key=bioskey(0);
    printf("%x",key);
    getch();
}
