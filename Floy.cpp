/**
	create: TrinhDat
	19-07-2000
	code: Floy
*/

#include <bits/stdc++.h>
#define ll int64_t
#define ff first
#define ss second
#define all(a) (a.begin(),a.end())
using namespace std;

constexpr int mod = 1e9+7;
constexpr int MAX = 2e5;
const ll inf = 1e18;

int n, m, q;
vector<vector<ll>> g;

void Floy(){
	for(int k=0;k<n;++k){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin.exceptions(cin.failbit);
	srand(time(NULL));
	cin >> n >> m >> q;
	g.resize(n,vector<ll>(n,inf));
	for(int i=0;i<m;++i){
		ll a,b,c;
		cin >> a >> b >> c, --a, --b;
		g[a][b] = min(g[a][b],c);
		g[b][a] = min(g[b][a],c);
	}
	Floy();
	while(q--){
		ll a,b;
		cin >> a >> b, --a, --b;
		cout << (g[a][b]==inf?-1:g[a][b]) << '\n';
	}
	return 0;
}


/**
	4 3 5
	1 2 5
	1 3 9
	2 3 3
	1 2
	2 1
	1 3
	1 4
	3 2
---------
	5
	5
	8
	-1
	3
*/

