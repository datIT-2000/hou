#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n, ans=0;
	cin >> n;
	vector<int> a(n), b(n);
	for(int &i:a) cin >> i;
	for(int &i:b) cin >> i;
	for(int i=0;i<n;++i){
		for(int j=i+1; j<n;++j){
			int cur = (a[i]-a[j])*(a[i]-a[j])+
					  (b[i]-b[j])*(b[i]-b[j]);
			ans=max(ans,cur);
		}
	}
	cout << ans << '\n';
	return 0;
}
