#include<bits/stdc++.h>


using namespace std;


void print(int a)
{
	if(a>0)
	{
		static int x=0;
		int y=0;

		cout<<"x="<<x++ <<" y="<<y<<endl;

		print(--a);

	}

	return ;
}

int main()
{
	print(3);
}
