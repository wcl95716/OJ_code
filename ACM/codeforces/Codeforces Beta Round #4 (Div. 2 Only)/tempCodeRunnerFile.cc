#include <bits/stdc++.h>
using namespace std;

struct Node{
    int x,y,index;
    Node(int x,int y,int index) : x(x),y(y),index(index){};

};

bool cmp(Node &a , Node &b){
    if(a.x!=b.x){
        return a.x < b.x;
    }
    return a.y < b.y;
}

void run() {
    int n, w, h;
    cin >> n >> w >> h;
    vector<Node> arr(n + 1 , Node(0,0,0));
    vector<pair<int ,int > > dp(n + 1, make_pair(1,0));
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = Node(x,y,i);
        //dp[i].second = i;
    }

    sort(arr.begin()+1, arr.end() , cmp);
    int maxs = 0 , tag = 0;
    for (int i = 1; i <= n; i++) {
        //cout<< arr[i].x<<' '<<arr[i].y<<' '<<arr[i].index<<endl;
        for (int j = i - 1; j >= 1; j--) {
            if(arr[i].x >= arr[j].x && arr[i].y >= arr[j].y){
                int ans = dp[j].first + 1;
                if(dp[i].first < ans){
                    dp[i].first = ans;
                    dp[i].second = j;
                    if(ans > maxs){
                        maxs = ans;
                        tag = i;
                    }
                }
            }
        }
    }

    stack<int > tem_stack;
    cout<<maxs<<endl;
    do{
        //cout<<arr[tag].index<<' ';
        tem_stack.push(arr[tag].index);
        tag = dp[tag].second;
    }while(tag != dp[tag].second);

    while(tem_stack.size()){
        cout<<tem_stack.top()<< ' ';
        tem_stack.pop();
    }

}

int main() {
#if defined(__APPLE__)
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}