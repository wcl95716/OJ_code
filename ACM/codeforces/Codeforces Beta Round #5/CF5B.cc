#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q[10001],max=0,o=1;
    /*q是计算每行字符的长度，
    max是找出最长的一行字符个数，
    o就是来计算当不能完美对齐时的左偏还是右偏*/
	char a[1001][1001];//存放读入的字符
	int j=1;
	while(gets(a[j]))
	{
		q[j]=strlen(a[j]);
		if(q[j]>max)
		max=q[j];
		j++;
	}
	j--;
	for(int i=1;i<=max+2;i++)
	cout<<"*";
	cout<<endl;//第一行全是*
	for(int i=1;i<=j;i++)
	{
		cout<<"*";
		if(max%2!=q[i]%2)
		{
		o=-o;//判断正负
		for(int k=1;k<=(max-q[i]+o)/2;k++)
	    cout<<" ";
	    cout<<a[i];
		for(int k=1;k<=(max-q[i]-o)/2;k++)
	    cout<<" ";
	    cout<<"*";
	    cout<<endl;
		}
		else
		{
		for(int k=1;k<=(max-q[i])/2;k++)
	    cout<<" ";
	    cout<<a[i];
		for(int k=1;k<=(max-q[i])/2;k++)
	    cout<<" ";
	    cout<<"*";
	    cout<<endl;
		}
	}
	for(int i=1;i<=max+2;i++)
	cout<<"*";//最后一行行全是*
	return 0;
}