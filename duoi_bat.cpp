#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;

int main()
{
    constexpr int inf=1e9;
    int dr[]={-1, 1, 0, 0}, dc[]={0, 0, -1, 1};
    char dl[]="UDLR";
    int R, C, r0=0, c0=0;
    cin >> R >> C;
    vector<string> s(R);
    queue<pii> q;
    vector<vi> mt(R,vi(C,inf)),ht(R,vi(C,inf)), p(R,vi(C));
    for(int r=0;r<R;++r){
        cin >> s[r];
        for(int c=0;c<C;++c){
            if(s[r][c] == 'A'){
                ht[r][c] = 0;
                r0=r; c0=c;
                s[r][c] = '.';
            }
            if(s[r][c]=='M'){
                q.push({r,c});
                s[r][c]='.';
                mt[r][c]=0;
            }
        }
    }
    for( ; !q.empty(); q.pop()){
        int r,c;
        tie(r,c) = q.front();
        for(int i=0;i<4;++i){
            int rr=  r+dr[i], cc= c+dc[i];
            if(rr<0 || rr>=R || cc<0 || cc>=C) continue;
            if(s[rr][cc]=='.' && mt[rr][cc]==inf){
                mt[rr][cc]=mt[r][c]+1;
                q.push(make_pair(rr,cc));
            }
        }
    }

    for( q.push({r0,c0}); !q.empty(); q.pop()){
        int r,c;
        tie(r,c) = q.front();
        for(int i=0;i<4;++i){
            int rr=  r+dr[i], cc= c+dc[i];
            if(rr<0 || rr>=R || cc<0 || cc>=C) continue;
           if (s[rr][cc]=='.' && ht[rr][cc]==inf
                && ht[r][c]+1<mt[rr][cc]) {
                ht[rr][cc]=ht[r][c]+1;
                q.push({rr, cc});
                p[rr][cc]=i;
            }
        }
    }

    for(int r=0;r<R;++r)
    {
        for(int c=0;c<C;++c){
            if(r>0 && r<R-1 && c>0 && c<C-1)continue;
            if(ht[r][c]<inf){
                string ans="";
                while(r!=r0 || c!=c0){
                    int d = p[r][c];
                    ans+=dl[d];
                    r-=dr[d]; c-=dc[d];
                }
                reverse(ans.begin(),ans.end());
                cout << "YES\n" << ans.size() << '\n' << ans;
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
