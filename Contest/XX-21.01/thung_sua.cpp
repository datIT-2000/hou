#include <bits/stdc++.h>
#define ll int64_t
#define ff first
#define ss second
#define pb(x) push_back(x)
using namespace std;

const int mod = 1e9+7;
const int MAX = 2e5;

typedef pair<int,int> pii;
typedef vector<int> vi;



int main(){
	ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
	srand(time(0));
	int a,b,m,x,y,ans=0;
	cin >> a >> b >> m;
	x=m/a;
	y=m/b;
	for(int i=0;i<=x;++i){
		for(int j=0;j<=y;++j){
			int cur = (i*a+j*b);
			if(cur<=m) ans=max(ans,cur);
		}
	}
	cout << ans;
	return 0;
}
