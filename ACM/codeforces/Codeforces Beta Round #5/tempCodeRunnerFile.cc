
#include <bits/stdc++.h>
using namespace std;

void clean_statck(stack<int> &arr){
    while(!arr.empty()){
        arr.pop();
    }

}


void run(){
    int n;
    cin>>n;
    vector<int > arr(n);
    for(int i= 0 ; i < n; i ++){
        cin>>arr[i];
    }
    stack<int > tag;
    int ans = 0 ;
    for(int i = 0 ; i < arr.size(); i ++){
        if(!tag.empty()){
            if(arr[i] >= tag.top()){
                ans += tag.size();
            }
            else {
                while(tag.size() && arr[i] < tag.top() ) {
                    tag.pop();
                } 
                ans += tag.size();
                clean_statck(tag); 
            }
        }
        tag.push(arr[i]);
    }
    clean_statck(tag);
    for(int i = 0 ; i < arr.size(); i ++){
        if(!tag.empty()){
            if(arr[i] < tag.top()){
                ans += tag.size();
            }
            else {
                while(tag.size() && arr[i] > tag.top() ) {
                    tag.pop();
                }  
                ans += tag.size();
                clean_statck(tag);
            }
        }
        tag.push(arr[i]);
    }

    cout<<ans<<endl;
    


}


int main() {
#if defined(__APPLE__)
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}