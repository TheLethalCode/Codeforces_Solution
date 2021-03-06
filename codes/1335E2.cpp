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

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %
int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vi v(n);
        vector< vi > pref(n+1, vi(201, 0)), cnt(201);
        FOR(i, n) 
        {
            pref[i+1] = pref[i];
            cin>>v[i];
            cnt[v[i]].pb(i+1), pref[i+1][v[i]]++;
        }
        int ans = 0;
        for(int i=1;i<=200;i++)
        {
            if(cnt[i].empty())
                continue;
            int r = cnt[i].size();
            int x = 0, y = r-1;
            while(x<y)
            {
                int temp = 0, l=cnt[i][x++], t=cnt[i][y--];
                for(int j=1;j<=200;j++)
                {
                    if(i==j)
                        continue;
                    temp = max(temp, pref[t-1][j]-pref[l][j]);
                }
                ans = max(ans, temp + 2*x);
            }
            ans = max(ans, r);
        }
        cout<<ans<<endl;
    }
}