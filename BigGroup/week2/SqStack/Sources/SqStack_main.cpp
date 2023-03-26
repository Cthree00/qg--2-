#include <stdio.h>
#include <malloc.h>
#include <string>
#include<iostream>
#include"SqStack.h"
using namespace std;




int main()
{
    string infix;		//中缀表达式
    string postfix;	//后缀表达式
    int result = 0;

    printf("请输入中缀表达式：");
    getline(cin, infix);
    postfix = Trans(infix);
    cout << "转换后的后缀表达式为" << postfix << endl;
    result = EvaluatePostfix(postfix);
    printf("计算结果是：%d\n", result);
    return 0;
}