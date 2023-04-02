#include <stdio.h>
#include <malloc.h>
#include <string>
#include<iostream>
#include"SqStack.h"
using namespace std;

//初始化顺序栈
void Init(SqStack& S)
{
    S.base = new ElemType[MAXSIZE];
    S.top = S.base;

}

//判断栈是否为空
int Empty(SqStack  S)
{
    if (S.top == S.base)
        return 1;
    else
        return 0;
}

//判断是否栈满
int SqStack_Full(SqStack S)
{
    if (S.top-S.base==MAXSIZE)	//栈满
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//入栈
int Push(SqStack &S, ElemType x)
{
    //如果栈满
    if (S.top-S.base==MAXSIZE)
    {
        printf("OverFlow!\n");
        return 0;
    }
    *S.top++ = x;
    return 1;
}

//出栈
int Pop(SqStack& S, ElemType& x)
{
    //如果栈空
    if (S.top==S.base)
    {
        printf("Error!\n");
        return 0;
    }
    else
    {
        x = *--S.top;
        return 1;
    }
}

//获取栈顶元素
int GetTop(SqStack&S, ElemType& x)
{
    //如果栈空
    if (S.top==S.base)
    {
        printf("Error!\n");
        return 0;
    }
    else
    {
        x = *--S.top;
        S.top++;
        return 1;
    }
}

//中缀表达式转后缀表达式
string Trans(string &express)
{
    char operation;	//存储运算符
    char oprand;	//存储操作数或运算符
    SqStack S;
    string postfix;
    int offset = 0;
    Init(S);
    int len = express.length();
    postfix = (char*)malloc(len * sizeof(char));
    //遍历中缀表达式，如果是数字，就直接存入后缀表达式，否则根据运算符的优先级进行出入栈操作
    for (int i = 0; express[i] != '\0'; i++)
    {
        oprand = express[i];
        switch (oprand)
        {
            //如果是'+'、'-'，则将栈中'('前的运算符出栈并存入后缀表达式
        case '+':
        case '-':
            while (!Empty(S))
            {
                GetTop(S, operation);
                if (operation != '(')
                {
                    Pop(S, operation);
                    postfix[offset++] = operation;
                }
                else
                {
                    break;
                }
            }
            Push(S, oprand);
            break;
            //如果是'*'、'/'，则将栈顶为'*'、'/'的运算符出栈并存入后缀表达式
        case '*':
        case '/':
            while (!Empty(S))
            {
                GetTop(S, operation);
                if (operation == '*' || operation == '/')
                {
                    Pop(S, operation);
                    postfix[offset++] = operation;
                }
                else
                {
                    break;
                }
            }
            Push(S, oprand);
            break;
            //如果是‘（’，则将‘（’入栈
        case '(':
            Push(S, oprand);
            break;
            //如果是‘）’，则将‘）’前的运算符出栈并存入后缀表达式中
        case ')':
            while (!Empty(S))
            {
                GetTop(S, operation);
                if (operation != '(')
                {
                    Pop(S, operation);
                    postfix[offset++] = operation;
                }
                else
                {
                    Pop(S, operation);
                    break;
                }
            }
            break;
            //如果是数字，则直接存入后缀表达式
        default:
            postfix[offset++] = oprand;
        }
    }
    //遍历完中缀表达式后，将栈中剩余运算符出栈，并存入后缀表达式中
    while (!Empty(S))
    {
        Pop(S, operation);
        postfix[offset++] = operation;
    }
    postfix[offset] = '\0';
    return postfix;
}

//将字符转换为数字
int ChangeCharToData(char c)
{
    return c - '0';
}

//将数字转换为字符
char ChangeDataToChar(int x)
{
    return x + 48;
}

//根据操作符和操作数进行四则运算
int Arithmetical(int operand1, int operand2, char operation)
{
    int result=0;
    switch (operation)
    {
    case '+':
        result = operand1 + operand2;
        break;
    case '-':
        result = operand1 - operand2;
        break;
    case '*':
        result = operand1 * operand2;
        break;
    case '/':
        result = operand1 / operand2;
        break;
    }
    return result;
}

//根据操作符进行求值运算
void Calculate(SqStack &S, char operation)
{
    char operand1, operand2;	//存储操作数1和操作数2
    int result;
    Pop(S, operand2);
    Pop(S, operand1);
    //根据运算符operation，调用Arithmetical函数进行运算
    result = Arithmetical(ChangeCharToData(operand1), ChangeCharToData(operand2), operation);
    Push(S, ChangeDataToChar(result));
}

//根据后缀表达式求值
int EvaluatePostfix(string &express)
{
    char oprand;	//存储后缀表达式中的元素
    SqStack S;
    char result;
    Init(S);
    for (int i = 0; express[i] != '\0'; i++)
    {
        oprand = express[i];
        if (oprand >= '0' && oprand <= '9')
        {
            Push(S, oprand);
        }
        else
        {
            Calculate(S, oprand);
        }
    }
    Pop(S, result);
    return ChangeCharToData(result);
}

