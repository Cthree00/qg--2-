#include <stdio.h>
#include <malloc.h>
#include <string>
#include<iostream>
#include"SqStack.h"
using namespace std;




int main()
{
    string infix;		//��׺���ʽ
    string postfix;	//��׺���ʽ
    int result = 0;

    printf("��������׺���ʽ��");
    getline(cin, infix);
    postfix = Trans(infix);
    cout << "ת����ĺ�׺���ʽΪ" << postfix << endl;
    result = EvaluatePostfix(postfix);
    printf("�������ǣ�%d\n", result);
    return 0;
}