#include<bits/stdc++.h>
using namespace std;
char p[6][6];//棋盘 
int f,s,pf,ps;//f是'X'的个数，s是'0'的个数，pf是判断第一个人有没有赢，ps则是判断第二个人； 
void dfs(int a,int b,int c,int d,int e,char t)//a,b是方向,c,d是当前的坐标,e是个数,t是棋子的类型('X'或'0') 
{
	if(e==3){//如果3个连成了一条线
		if(t=='X')pf=1;//第一个人赢
		else ps=1;//第二个人赢
		return;//返回
	}
	else if(a+c<4&&a+c>0&&b+d<4&&b+d>0&&p[a+c][b+d]==t)//如果没出界，并且是同样的棋子
		dfs(a,b,a+c,b+d,e+1,t);//访问下一个坐标
}
int main()
{
	for(int x=1;x<4;x++)
		for(int y=1;y<4;y++){
			cin>>p[x][y];//输入 
			if(p[x][y]=='X')f++;//第一个人的棋子 
			if(p[x][y]=='0')s++;//第二个人的棋子 
		}
	if(s>f||f-s>1){//s>f是第二个人多下了，f-s>1是第一个人多下了 
		cout<<"illegal";//非法情况 
		return 0;//返回 
	}
	for(int x=1;x<4;x++)
		for(int y=1;y<4;y++)
			if(p[x][y]!='.')//如果这个地方不是空的 
				for(int a=-1;a<2;a++)
					for(int b=-1;b<2;b++)
						if(a!=0||b!=0)//并且方向正确
							dfs(a,b,x,y,1,p[x][y]);//访问这一个坐标，记录类型 
	if((pf&&ps)||(pf&&f==s)||(ps&&f>s))cout<<"illegal";//如果两个人都赢了，或者其中一个人赢了之后又下了一枚棋子（很坑！）都是非法的
	else if(pf)cout<<"the first player won";//第一个人赢
	else if(ps)cout<<"the second player won";//第二个人赢
	else if(f+s==9)cout<<"draw";//没有人赢，并且不非法，就是平局
	else if(f>s)cout<<"second";//没下满，第二个人下棋
	else cout<<"first";//第一个人下棋
	return 0;
}