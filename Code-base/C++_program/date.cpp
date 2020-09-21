#include<bits/stdc++.h>


using namespace std;

class Date{

	private:

		int day;
		int month;
		int year;

	public:
		Date(int m,int n,int y)
		{
			day=m;
			month=n;
			year=y;
		}

		void display() const
		{
			cout<<day<<" "<<month<<" "<<year<<endl;
		}

		Date& dinc()
		{
			day++;

			return *this;
		}

		Date& minc()
		{
			month++;

			return *this;
		}

		Date& yinc()
		{
			year++;

			return *this;
		}

		int drt()
		{
			return day;
		}

		Date* returnm()
		{
			return this;
		}

};


int main()
{

	Date a(10,2,2018);


	a.display();

	a.dinc().minc().yinc();

//	b.inc();

	a.display();

	int x=a.drt();

	cout<<x<<endl;

	Date *b;

	b=a.returnm();

	b->display();
}
			
