#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n-1);
    for(auto &i:a) cin >> i;
    for(int i=1;i<=a[0];++i){
        set<int> s;
        vector<int> res;
        s.insert(i);
        res.push_back(i);
        for(int j=0;j<a.size();++j){
            if(a[j]>res.back()){
                s.insert(a[j]-res.back());
                res.push_back(a[j]-res.back());
            }
            else{
                break;
            }
        }
        if(s.size()==n){
            for(int i=0;i<res.size();++i) 
                cout << res[i] << (i<res.size()-1?' ':'\n');
            return 0;   
        }
    }
}
 
