#include <bits/stdc++.h>
#define ll int64_t
#define ff first
#define ss second
#define all(a) (a.begin(),a.end())
#define name "lazy"
using namespace std;

ifstream fi (name".inp");
ofstream fo (name".out");

int n,q;

struct node {
	ll s, lz;
}st[1<<19];

void app(int i, ll x, int l2, int r2){
	st[i].s+=x*(l2-r2+1);
	st[i].lz+=x;
}

void psh(int i, int l2, int m2, int r2){
	app(i*2,st[i].lz,l2,m2);
	app(i*2+1,st[i].lz,m2+1,r2);
	st[i].lz=0;
}

void upd(int l1, ll x, int i=1, int l2=0, int r2=n-1){
	if(l2==r2){
		st[i].s=x;
		return;
	}
	int m2 = (l2+r2)>>1;
	if(l1<=m2)upd(l1,x,2*i,l2,m2);
	else upd(l1,x,2*i+1,m2+1,r2);
	st[i].s=st[i*2].s+st[i*2+1].s;
}

void upd2(int l1, int r1, ll x, int i=1, int l2=0, int r2=n-1){
	if(l1<=l2 && r2<=r1){
		app(i,x,l2,r2);
		return;
	}
	int m2=(l2+r2)>>1;
	psh(i,l2,m2,r2);
	if(l1<=m2){
		upd2(l1,r1,x,2*i,l2,m2);
	}
	if(m2<r1){
		upd2(l1,r1,x,2*i+1,m2+1,r2);
	}
	st[i].s = st[i*2].s + st[i*2+1].s;
}

ll query(int l1, int r1,int i=1, int l2=0, int r2=n-1){
	if(l1<=l2 && r2<=r1) return st[i].s;
	int m2=(l2+r2)>>1;
	psh(i,l2,m2,r2);
	return (l1<=m2?query(l1,r1,2*i,l2,m2):0LL)+(m2<r1?query(l1,r1,2*i+1,m2+1,r2):0LL);
}

int main()
{
	ios::sync_with_stdio(0);
	fi.tie(0);
	fo.tie(0);
	srand(time(NULL));
	fi >> n >> q;
	for(int i=0;i<n;++i){
		upd(i,0);
	}
	while(q--){
		int a,b,c;
		fi >> a >> b >> c, --a, --b;
		upd2(a,b,c);
	}
	for(int i=0;i<n;++i) fo<<query(i,i)<<' ';
	fo << "\nTime: " << clock()/(double)10000 << " sec.";
	return 0;
}


