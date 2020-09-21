#include<bits/stdc++.h>


using namespace std;

void print(int value,int base=10)
{
	cout<<value <<base<<endl;

}

int f(int ,int=0,char* =0); //correct decleartion.
int f(int =0,int =9,char *) //wrong declaration.
int f(int =0,int,char * =0) //wrong declaraton.
int f(int ,int =0,char *=0);//wrong declaration
			   //because it *=  is a assignement operator a*=2(mean a=a*2)

int main()
{
	print(31);
	print(31,10);
	print(31,16);
	print(31,2);

}


