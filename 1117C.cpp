#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define vi vector< int >
#define vli vector< lli >
#define endl "\n"
#define pa pair<lli,lli>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int main()
{
    crap;
    lli x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    string s;
    cin>>s;
    int n=s.length();
    lli dirx = x2-x1,diry=y2-y1;
    vector<pa> v(n+1,{0,0});
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='U')
            v[i].fi=v[i-1].fi,v[i].se=v[i-1].se+1;
        if(s[i-1]=='D')
            v[i].fi=v[i-1].fi,v[i].se=v[i-1].se-1;
        if(s[i-1]=='L')
            v[i].fi=v[i-1].fi-1,v[i].se=v[i-1].se;
        if(s[i-1]=='R')
            v[i].fi=v[i-1].fi+1,v[i].se=v[i-1].se;
    }
    if(abs(v[n].fi) + abs(v[n].se) == n && v[n].fi*dirx < 0 && v[n].se*diry<0)
        cout<<-1;
    else
    {
        int up=0,right=0;
        if(diry>0)
            up=1;
        else
            up=-1;
        if(dirx>0)
            right=1;
        else
            right=-1;
        
        lli times=(abs(dirx) + abs(diry))/(v[n].fi*right + v[n].se*up + n);
        times*=(v[n].fi*right + v[n].se*up + n);
        for(int i=1;i<=n;i++) 
        {
            if(times + i + v[i].fi*right + v[i].se*up >= abs(dirx) + abs(diry))
            {
                times+=i;
                break;
            }
        }
    }
}