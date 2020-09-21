#include<bits/stdc++.h>


using namespace std;

class xyz{

	char *x;

	public:

	xyz(char* a)
	{	
		cout<<"object is created"<<endl;
		x=new char[strlen(a)+1];
		strcpy(x,a);
	}

	void as(char* a)
	{	
	//	cout<<"object is created"<<endl;
		x=new char[strlen(a)+1];
		strcpy(x,a);
	}
	void dis()
	{
		cout<<x<<endl;
	}

	~xyz()
	{
		delete[] x;
		cout<<"object deleted"<<endl;
	}

	void Delete()
	{
	
	//	~xyz();
	}
};	

int main()
{

	 xyz a("om is great");

	xyz b=a;

//	a.inc();

//	cout<<"a ";
	a.dis();
	
	a.~xyz();

	a.dis();
	b.dis();	

	a.as("omn mmm");

	a.dis();
}

