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

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) a.size()
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

#define AG "Ashishgup"
#define FG "FastestFinger"

// %
int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<FG<<endl;
            continue;
        }
        int ev = 0, od  = 0;
        int temp = n;
        for(int i=2;i<=sqrt(temp);i++){
            while(temp%i==0) temp/=i, (i==2?ev:od)++;
        }
        if(temp!=1) (temp==2?ev:od)++;
        if(!ev){
            cout<<AG<<endl;
        }
        else if(ev == 1){
            cout<<(od==1?FG:AG)<<endl;
        }
        else cout<<(od?AG:FG)<<endl;
    }
}