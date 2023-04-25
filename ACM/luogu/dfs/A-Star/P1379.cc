#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
#define ll long long//在这里看到一种很骚的操作：直接把int定义成long long；main函数用signed类型--麻麻再也不怕我忘开long long了！
using namespace std;
const ll dx[]={-1,0,0,1},dy[]={0,-1,1,0};//转移数组；
ll n;
int  main()
{
    map<int , int > aaa;
    aaa[1] = 2;
    aaa[1] = 3;
    cout<<aaa.count(1)<<endl;
}
