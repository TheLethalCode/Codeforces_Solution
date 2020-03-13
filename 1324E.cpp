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

int main(int argc, char **argv)
{
    crap;
    int n,h,l,r;
    cin>>n>>h>>l>>r;
    vi v(n);
    FOR(i, n) cin>>v[i];

    vi te(n,0);
    vpa si(n);

    int prev = 0;
    for(int i=0;i<n;i++)
    {
        prev += v[i], prev %= h;
        te[i] = prev;
        if(prev < l)
            si[i].fi = l - prev, si[i].se = r - prev;
        else if(prev <= r)
            si[i].fi = 0, si[i].se = r - prev;
        else
            si[i].fi = (l - prev + h ) % h, si[i].se = s[i].fi + r - l;
    }
}