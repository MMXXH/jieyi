#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define maxn 1000
char buf[maxn], str[maxn], signStack[maxn], ch[2];
int len, id, idSign, idAns, i, n,k=0;
double ans[maxn];
void checkSign(char sign){
    if(sign == '(') signStack[idSign++] = sign;
    else if(sign == '*' || sign == '/'){
        while(idSign && (signStack[idSign-1] == '*' || signStack[idSign-1] == '/'))
            str[id++] = signStack[--idSign];
        signStack[idSign++] = sign;
    }else if(sign == ')'){
        while(signStack[idSign-1] != '(') str[id++] = signStack[--idSign];
        --idSign;
    }else{
        while(idSign && signStack[idSign-1] != '(') str[id++] = signStack[--idSign];
        signStack[idSign++] = sign;
    }
    str[id++] = ' ';
}

int check(double a, char sign){
    if(a == 0 && sign == '/'){
        printf("0\n");
        system("pause");
        exit(EXIT_FAILURE);
    }
    return 1;
}

double cal(double a, double b, char sign){
    switch(sign){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

int main(){
    while(1)
        {k++;
        gets(buf); id = idSign = idAns = 0;
        if((len = strlen(buf)) == 0) continue;

        int flag = 0; //这个是用来判断'-'字符是负号还是减号的。1表示数字，0表示 +*/(
        /*判断原理：如果第一次读取就碰到-，那么一定是负号，若最近一次读取是+*-/(那么
            也一定是负号，如果是右括号或数字那么是减号*/

        for(i = 0; i < len; ++i){
            if(buf[i] == ' ') continue;
            if(buf[i] >= '0' && buf[i] <= '9' || buf[i] == '.' || buf[i] == '-' && !flag){
                 str[id++] = buf[i]; flag = 1;
            }
            else {
                str[id++] = ' '; checkSign(buf[i]);
                if(buf[i] != ')') flag = 0;
                else flag = 1;
            }
        }
        while(idSign) str[id++] = signStack[--idSign];

        for(i = 0, n = 0; i < id; ++i){
            if(str[i] == ' ') continue;
            /*用增加空格的方式判断‘-’字符是负号还是减号，若‘-’后面挨着数字或小数点，那么一定是负号*/
            if(str[i] >= '0' && str[i] <= '9' || str[i] == '.' || str[i] == '-'
                && (str[i+1] >= '0' && str[i+1] <= '9' || str[i+1] == '.')){
                sscanf(str + i, "%lf%n", &ans[idAns++], &n);
                i += n - 1;  continue;
            }else if(check(ans[idAns-1], str[i])){
                ans[idAns-2] = cal(ans[idAns-2], ans[idAns-1], str[i]);
                --idAns;
            }
        }
        printf("%d..........       %.2lf\n \n",k,ans[0]);
    }
    system("pause");
    return 0;
}
