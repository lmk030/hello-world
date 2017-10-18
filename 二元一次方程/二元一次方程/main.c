//
//  main.c
//  二元一次方程
//
//  Created by 李民凯 on 2017/9/26.
//  Copyright © 2017年 llmklmk. All rights reserved.
//

#include <stdio.h>


int main(int argc, const char * argv[]) {
    double a,b,c,d,e,f;
    printf("请按顺序输入二元一次方程组中的常数\n");
    printf("ax+by+c=0\n");
    printf("dx+ey+f=0\n");
    scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
    if ((a == 0 && b == 0 && c != 0)||(d == 0 && e == 0 && f != 0)) {
        printf("无解\n");
    }
    else
    {
        if (a * e == b * d)
        {
            if (c != f)
            {
                printf("无解\n");
            }
            else
                printf("有无数组解\n");
        }
        else{
            printf("x = %f y = %f\n",(b * f - c * e)/(a * e - b * d),(a * f - c * d)/(b * d - a * e));
        }
    }
    return 0;


}
