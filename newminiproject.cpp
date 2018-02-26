#include<iostream.h>
#define MAX 50
class set
{
	private:
		int n,k,s,a[MAX],al[MAX];
		long int count;
	public :
		void setdata(int nn,int kk,int ss);
		void init();
		void init1(int i);
		int calculate();
		int add(int a[],int k);
		void setcall();
};
int set::add(int a[],int k)
{
	int ans=0,i;
	for(i=0;i<k;i++)
	{
		ans=ans+a[i];
		
	}
	return ans;
}
void set::init1(int i)
{
	int j;
	a[i]=a[i]+1;
	for(j=i+1;j<k;j++)
	{
		a[j]=a[j-1]+1;
	}
	for(j=1;j<k;j++)
	{
		if(a[j]==n)
		{
			i=j-1;
			init1(i);
		}
	}
}
void set::setcall()
{
	int i,v;
	al[0]=n;a[0]=n;
	a[1]=0;
	for(i=2;i<k;i++)
	{
		a[i]=a[i-1]+1;
	}
	al[k-1]=n-1;
	for(v=k-2;v>=1;v--)
	{
		al[v]=al[v+1]-1;
	}

}
void set::init()				//initialize the set & counter
{
	int i;
	a[0]=n;
	for(i=1;i<k;i++)
	{
		a[i]=0;
	}
	count=0;
}
void set::setdata(int nn,int kk,int ss)		//get data  form user
{
	n=nn;
	k=kk;
	s=ss;		
}
int set::calculate()					//check the all element of sets
{
	int v,i,j;
	switch(k)
	{
		case 1:
				if(a[0]==n && a[0]==s)
				{
					count++;
				}
				break;
		case 2:
				init();
				for(a[1]=0;a[1]<n;a[1]++)
				{
					v=0;
					v=add(a,k);
					if(v==s)
					{
						count++;
					}
				}
				break;
		case 3:
				init();				
				for(a[1]=0;a[1]<n;a[1]++)
				{
					for(a[2]=a[1]+1;a[2]<n;a[2]++)
					{
						
							v=0;
							v=add(a,k);
							if(v==s)
							{
								count++;
							}						
					}
				}
				break;
		default:
				setcall();
				while(1)
				{
					v=0;
					v=add(a,k);
					if(v==s)
					{
						count++;
					}
					a[k-1]++;
					if(a[k-1]>=n)
					{
						for(j=1;j<k;j++)
						{
							if(a[j]==n)
							{
								i=j-1;
								init1(i);
							}
						}
					}
					int count1=0;
					for(i=0;i<k;i++)
					{
						if(a[i]==al[i])
						{
							count1++;
						}
					}
					if(count1==k)
					{
						break;
					}
					
				}
				break;
	}
return count;
}

int main()
{
	set obj1;
	int nn,kk,ss;
	int z,aaa[MAX],c=-1;
 	bool flag;
	 cout<<"enter the dataset n , k , s in one line with space \n";
	while(1)
	{
	
		
		do
		{
	
		 cin>>nn;
		 cin>>kk;
		 cin>>ss;
		 flag=true;
		 if(cin)
		 {
			cin.clear();
			cin.ignore(100,'\n');
			flag=false;
			if(flag==false)
			{
				cout<<"\nentered dataset is invalid \n";
			}
		 }
		}while(!flag);
		if(nn>-1 && kk>-1 && ss>-1 && nn>=kk)
		{	
			if(nn==0 && kk== 0 && ss==0)
				{			
					break;
				}
				else
				{
					obj1.setdata(nn,kk,ss);
 					obj1.init();
					c++;
					aaa[c]=obj1.calculate();	
				}
		}
		else
		{
			if(nn<=-1 || kk<=-1 || ss<=-1)
			{
				cout<<"\n entered values are negative \n enter the correct inputs \n";
			}
			else
			{
				c++;
				aaa[c]=0;
			}
			
		}
		
	}
		
	cout<<"\n\nthe sets are formed to each dataset \n";
	for(z=0;z<=c;z++)

 	{	
		cout<<"\n"<<aaa[z];
	}
	cout<<endl;
return 0;
}
