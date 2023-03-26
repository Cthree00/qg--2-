#include <stdio.h>
#include <malloc.h>
#include <string>
#include<iostream>
#include"SqStack.h"
using namespace std;

//��ʼ��˳��ջ
void Init(SqStack& S)
{
    S.base = new ElemType[MAXSIZE];
    S.top = S.base;

}

//�ж�ջ�Ƿ�Ϊ��
int Empty(SqStack  S)
{
    if (S.top == S.base)
        return 1;
    else
        return 0;
}

//�ж��Ƿ�ջ��
int SqStack_Full(SqStack S)
{
    if (S.top-S.base==MAXSIZE)	//ջ��
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//��ջ
int Push(SqStack &S, ElemType x)
{
    //���ջ��
    if (S.top-S.base==MAXSIZE)
    {
        printf("OverFlow!\n");
        return 0;
    }
    *S.top++ = x;
    return 1;
}

//��ջ
int Pop(SqStack& S, ElemType& x)
{
    //���ջ��
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

//��ȡջ��Ԫ��
int GetTop(SqStack&S, ElemType& x)
{
    //���ջ��
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

//��׺���ʽת��׺���ʽ
string Trans(string &express)
{
    char operation;	//�洢�����
    char oprand;	//�洢�������������
    SqStack S;
    string postfix;
    int offset = 0;
    Init(S);
    int len = express.length();
    postfix = (char*)malloc(len * sizeof(char));
    //������׺���ʽ����������֣���ֱ�Ӵ����׺���ʽ�������������������ȼ����г���ջ����
    for (int i = 0; express[i] != '\0'; i++)
    {
        oprand = express[i];
        switch (oprand)
        {
            //�����'+'��'-'����ջ��'('ǰ���������ջ�������׺���ʽ
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
            //�����'*'��'/'����ջ��Ϊ'*'��'/'���������ջ�������׺���ʽ
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
            //����ǡ��������򽫡�������ջ
        case '(':
            Push(S, oprand);
            break;
            //����ǡ��������򽫡�����ǰ���������ջ�������׺���ʽ��
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
            //��������֣���ֱ�Ӵ����׺���ʽ
        default:
            postfix[offset++] = oprand;
        }
    }
    //��������׺���ʽ�󣬽�ջ��ʣ���������ջ���������׺���ʽ��
    while (!Empty(S))
    {
        Pop(S, operation);
        postfix[offset++] = operation;
    }
    postfix[offset] = '\0';
    return postfix;
}

//���ַ�ת��Ϊ����
int ChangeCharToData(char c)
{
    return c - '0';
}

//������ת��Ϊ�ַ�
char ChangeDataToChar(int x)
{
    return x + 48;
}

//���ݲ������Ͳ�����������������
int Arithmetical(int operand1, int operand2, char operation)
{
    int result;
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

//���ݲ�����������ֵ����
void Calculate(SqStack &S, char operation)
{
    char operand1, operand2;	//�洢������1�Ͳ�����2
    int result;
    Pop(S, operand2);
    Pop(S, operand1);
    //���������operation������Arithmetical������������
    result = Arithmetical(ChangeCharToData(operand1), ChangeCharToData(operand2), operation);
    Push(S, ChangeDataToChar(result));
}

//���ݺ�׺���ʽ��ֵ
int EvaluatePostfix(string &express)
{
    char oprand;	//�洢��׺���ʽ�е�Ԫ��
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

