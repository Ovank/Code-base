#include<bits/stdc++.h>
#include<math.h>

using namespace std;

#define lli long long int

int main()
{

	lli n;
	
	cin>>n;

	lli a=n;

	lli num[a][a];

	for(lli u=0;u<a;u++)
	{
	
		for(lli y=0;y<a;y++)
		{
			cin>>num[u][y];
		}
	}
	
		for(lli u=0;u<a;u++)
        	{
              		  for(lli y=0;y<a;y++)
               		 {
                       		 cout<<num[u][y]<<" ";
              		  }
			  cout<<endl;
       		 }
	
	lli found=0;

	for(lli u=0;u<=a/2;u++)
	{
		for(lli y=0;y<=a/2;y++)
		{	
	//		cout<<num[u][y]<<" "<<num[u][a-y-1]<<" "<<num[a-1-u][y]<<" "<< num[a-1-u][a-y-1] <<endl;
			if(num[u][y] == num[u][a-y-1] && num[a-1-u][y] == num[a-1-u][a-y-1] &&  num[u][a-y-1] ==  num[a-1-u][y])
			{
				continue;
			}
			else
			{
				found=1;
				break;
			}
		}

		if(found==1)
		{
			break;
		}
	
	}

	if(found == 1)
	{
		cout<<"NO";
	}
	else
	{
		cout<<"YES"<<endl;

		for(lli u=0;u<a;u++)
        	{
              		  for(lli y=0;y<a;y++)
               		 {
                       		 cout<<num[u][y]<<" ";
              		  }
			  cout<<endl;
       		 }

	}

}
