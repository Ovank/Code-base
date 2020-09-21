#include<bits/stdc++.h>


using namespace std;

void print(string);

void (*pointer) (string);

int main()
{
	
//	pointer=&print; //ok

	pointer=print; //is also correct

//	pointer("error");

	(*pointer)("error"); //(*pointer) must be kept inside the bracket.
	
}

void print(string a)
{
	cout<<a<<endl;
}
