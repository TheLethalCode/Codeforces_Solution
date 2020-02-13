#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define pa pair<int,int>
#define pal pair<lli,lli>
#define vi vector< int >
#define vli vector< lli >
#define vpa vector< pa >
#define vpal vector< pal >
#define fi first
#define se second
#define pb push_back
#define pp pop_back

#define nl cout<<"\n"
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(int i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %

pair<int, string> func(string cur, int n, int m)
{
    if(n==0)
    {
        int k = cur.size();
        vi temp(k+1,0);
        FOR(i,k)
            temp[i+1]= temp[i] + (cur[i]=='1');
        int ans = 0;
        for(int i=0;i<k;i++)
            for(int j=i;j<k;j++)
                if(temp[j+1]-temp[i])
                    ans++;
        return {ans,cur};
    }
    pair<int, string> ma = func(cur+'0',n-1,m);
    pair<int, string> a = m?func(cur+'1',n-1,m-1):ma;
    if(a.fi > ma.fi)
        ma = a;
    return ma;
}

int main(int argc, char **argv)
{
    crap;
    pair<int, string> r;
    FOR(i,20)
        FOR(j,i+2)
            r = func("",i+1,j), cout<<i+1<<" "<<j<<" "<<r.fi<<endl;
}