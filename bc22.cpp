#include <ctime>
#include<iostream>
#include<stdlib.h>
#include <cstdlib>
#include <sstream>
#include<stdio.h>
#include<string.h>
#include <fstream>
using namespace std;
#define random(a,b)(rand()%(b-a+1)+a)
const string filename="test000.txt";
char yunsuanfu(int a)
{
    switch(a)
    {
        case 1:return '+' ; break;
        case 2:return '-' ; break;
        case 3:return '*' ; break;
        case 4:return '/' ; break;
    }
}
int main()
{
const string filename="test000.txt";
ofstream fout("test000.txt");
int max,i,j,weishu,geshu,s1,s2,number=12345;
char g,z,d,str[25]={0},f[25],str1[25],str2[25],str3[50]={0};
    int e,a,b,c,o,p,h,v;
    cout<<"请输入题数： ";
    cin>>geshu;
    cout<<"请输入最大数： ";
    cin>>max;
    cout<<"请选择是否有括号 y或n:  ";
    cin>>z;
    if(z=='n')
        p=0;
    cout<<"请选择运算符\n加法:1\n减法：2\n乘法：3\n除法：4\n混合运算：5\n";
    cin>>h;
     cout<<"请选择是否有小数 y或n；";
     cin>>g;
     if(g=='y')
        v=1;
    srand((int)time(0));
    for(j=0;j<geshu;j++){
    a=random(0,1);
    if(p==0)
        a=0;
    if (a==0){
    b=random(0,max);
    fout<<b;
	if(v==1)
	fout <<"."<< random(0,99);
    }
    else{
    c=random(1,4);
    if(h!=5)
        c=h;
    if(c==1||c==2)
    {
    o=random(0,max);
	fout << "("<<o;
	if(v==1)
	fout <<"."<< random(0,99);
	d=yunsuanfu(c);
	fout<<d;
	fout << random(0,max);
	if(v==1)
    fout << "."<<random(0,99);
    fout<<")";
    }
    else{
    o=random(0,max);
	fout <<o;
		if(v==1)
	fout <<"."<< random(0,99);
	d=yunsuanfu(c);
	fout<<d;
	fout << random(0,max);
	if(v==1)
	fout <<"."<< random(0,99);
    }
    }
    for(i=0;i<3;i++)
{
    e=random(1,4);
        if(h!=5)
        e=h;
    d=yunsuanfu(e);
	fout<<d;
    a=random(0,1);
        if(p==0)
        a=0;
    if (a==0){
    b=random(0,max);
    fout<<b;
	if(v==1)
	fout <<"."<< random(0,99);
    }
    else{
    c=random(1,4);
        if(h!=5)
        c=h;
    if(c==1||c==2)
    {
    o=random(0,max);
	fout << "("<<o;
		if(v==1)
	fout <<"."<< random(0,99);
	d=yunsuanfu(c);
	fout<<d;
		if(v==1)
	fout<< random(0,99) <<".";
	fout << random(0,max)<<")";
    }
    else{
    o=random(0,max);
	fout <<o;
			if(v==1)
	fout <<"."<< random(0,99);
	d=yunsuanfu(c);
	fout<<d;
	fout << random(0,max);
			if(v==1)
	fout <<"."<< random(0,99);
    }
    }
}
    fout<<"="<<endl;
    }
fout.close();
return 0;
}
