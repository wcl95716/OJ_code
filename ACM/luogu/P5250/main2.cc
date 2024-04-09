#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int MAX_LEN = 1000*1000;

int getMinMax(set<int> &myset , int y){
    int l = 0 , r = y - 1;
    int res = -1;
    while(l <= r){
        int mid = (l + r) / 2;
        auto lower = myset.lower_bound(mid);
        if(lower != myset.end() && *lower < y){
            res = *lower;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return res;
}

void run() {
    int n;
    cin >> n;
    set<int> myset;
    for (int i = 0,x,y; i < n; i++){
        cin>> x >> y;
        if(x == 1){
            if(myset.find(y) == myset.end()){
                myset.insert(y);
            }
            else{
                cout << "Already Exist" << endl;
            }
        }
        else{
            auto lower = myset.lower_bound(y);
            
            int lower_op = getMinMax(myset , y);
            // cout<< "lower: " << *lower << " lower_op: " << lower_op <<endl;
            if(lower_op != -1 &&  abs((lower_op) -y) <=  abs(y - (*lower))  ){
                cout << lower_op <<endl;
                // 删除lower
                myset.erase(lower_op);
            }
            else if(lower != myset.end()){
                cout << *lower <<endl;
                // 删除lower
                int s = *lower;
                myset.erase(s);
            }
            else{
                cout << "Empty"<<endl;
            }
            // cout<<"myset: "<< myset.size()<<" myset_op: "<< myset_op.size()<<endl;

        }
       
    }

    cout << endl;
}

int main() {
#if defined(__APPLE__) || defined(__WIN32__)
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}
