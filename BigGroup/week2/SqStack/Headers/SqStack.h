#ifndef SQSTACK_H
#define SQSTACK_H

#define MAXSIZE 1024
#include<string>
using namespace std;
typedef char ElemType;
typedef struct
{
    ElemType* base;
    ElemType* top;//’ª∂•÷∏’Î
}SqStack;

void Init(SqStack& S);
int Empty(SqStack  S);
int SqStack_Full(SqStack S);
int Push(SqStack& S, ElemType x);
int Pop(SqStack& S, ElemType& x);
int GetTop(SqStack& S, ElemType& x);
string Trans(string& express);
int ChangeCharToData(char c);
char ChangeDataToChar(int x);
int Arithmetical(int operand1, int operand2, char operation);
void Calculate(SqStack& S, char operation);
int EvaluatePostfix(string& express);



#endif
