#include<bits/stdc++.h>

using namespace std;

template<class T>
class A {
   int i;

	public:
   		A(int s)
		{
			i=s;
		}
};

template<class T>
class B :public A<T> {
	int y;

	public:
	
	B(int s):A(int n)
	{
		y=s
	}
  	
      	int foo() {
        	return this->i;
   	 }

	void dis()
	{
		cout<<"y "<<y<<endl;
	}

};

int main() {
    B<int> b(1,2);
    int a=b.foo();

    cout<<"a "<<a<<endl;

    b.dis();


}
