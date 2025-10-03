#include <bits/stdc++.h>

using namespace std;

const int INF=99999999;
int graph[106][106],n,d[106],ans;
bool vis[106];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    //freopen("agrinet.in","r",stdin);
    //freopen("agrinet.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>graph[i][j];
        }
    }
    for(int i=1;i<=n;i++) d[i]=graph[1][i];
    vis[1]=1;
    for(int i=1;i<=n-1;i++){
        int minn=INF,k=0;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&d[j]<minn){
                minn=d[j];
                k=j;
            }
        }
        vis[k]=1;
        ans+=minn;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&graph[k][j]<d[j]) d[j]=graph[k][j];
        }
    }
    cout<<ans<<'\n';
}
