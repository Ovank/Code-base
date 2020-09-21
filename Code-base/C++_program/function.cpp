#include<bits/stdc++.h>


using namespace std;
/*
void f(long);
void f(char);
void f(char *);
void f(int *);

void g(int a)
{

	f(a);
}

int main()
{
	int i=10;

	g(i);	
}

void f(int* a)
{
	cout<<a<<endl;
}
void f(char a)
{
	cout<<a<<endl;
}
void f(char* a)
{
	cout<<a<<endl;
}
void f(long a)
{
	cout<<a<<endl;
}


 * This program when compiled throws an error stating ambigous call of unction f(a),it is becaause of in over loading compiler identify the function using function parameter while following set of rules.if the parameter with which function is called and the parameter of the defined function doesn't matches the parameters are promoted by the compile to mathch the signature of defined function if after that if compile can't resolve furthure is throws an error.
 *
 * in above case their is no function declared with function parameter int,but in main we call function giving parameter of type int,so in this case compiler try to promote the parameter but it confuse as function with parameter char and long both are present so it can't decide which one to select so,it throws an error.
 */

void print(char a)
{
	cout<<a<<endl;
}
/*
void print(int y)
{
	cout<<y<<endl;
}
*/
int  main()
{
	long h=100001;


	print(h);
}
