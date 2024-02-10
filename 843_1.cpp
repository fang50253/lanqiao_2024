#include<iostream>
using namespace std;
int n;
bool map[10][10]={0};
int main()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			map[i][j]=0;
		}
	}
	int case_ac();
	void dfs(int,int);
	cin>>n;
	dfs(1,1); 
	return 0;
}
int case_ac()
{
	int count=0;
	int count_x=0,count_y=0;
	for(int i=1;i<=n;i++)
	{
		count_x=0;
		for(int j=1;j<=n;j++)
		{
			if(map[i][j])
			{
				count++;
				count_x++;
			}
		}
		if(count_x>1) return -1;
	}
	if(count>n) return -1;
	for(int j=1;j<=n;j++)
	{
		count_y=0;
		for(int i=1;i<=n;i++)
		{
			if(map[i][j])
			{
				count_y++;
			}
			if(count_y>1) return -1;
		}
	}
	if(count==n) return 1;
	else return 0;
}
void dfs(int x,int y)
{
//	cout<<case_ac();
	switch (case_ac())
	{
		case -1:
			{
				;
			}
		case 0:
			{
                if(x<n&&y<n)
	            {
	            	map[x+1][y]=1; 
		            dfs(x+1,y);
		            map[x+1][y]=0;
	            }
	            else if(x==n&&y<n)
	            {
	            	map[1][y+1]=1;
		            dfs(1,y+1);
		            map[1][y+1]=0;
	            }
	            else if(x==n&&y==n)
	            {
		            ;
	            }
			}
		case 1:
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=n;j++)
					{
						if(map[i][j]) cout<<"Q";
						else cout<<".";
					}
					cout<<endl;
				}
				cout<<endl;
			}
	}
	
}

