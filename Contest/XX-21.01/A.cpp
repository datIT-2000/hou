#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,d , ans=0;
	cin >> a >> b >> c >> d;
	ans=(b-a)+(d-c);
	if(a>c && b<d){
		ans-=b-a;
	}
	else if(c>a && b>d){
		ans-=d-c;
	}
	else if(a<c){
		if(b>c) ans-=(b-c);
	}
	else{
		if(d>a)ans-=(d-a);
	}
	cout << ans;
	return 0;
}
