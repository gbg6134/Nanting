#include <bits/stdc++.h>

using namespace std;

const int INF=99999999;
int f,n,m,w,s,e,t,dist[506],len;

struct edge{
    int s,e,t;
}edges[10006];

bool bellmanford(int st){
    for(int i=1;i<=n;i++) dist[i]=INF;
    dist[st]=0;
    
    for(int i=1;i<=n;i++){
        bool flag=false;
        for(int i=1;i<=len;i++){
            if(dist[edges[i].s]+edges[i].t<dist[edges[i].e]){
                flag=true;
                dist[edges[i].e]=dist[edges[i].s]+edges[i].t;
            }
        }
        if(!flag) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    //freopen("wormhole.in","r",stdin);
    //freopen("wormhole.out","w",stdout);
    cin>>f;
    while(f--){
        len=0;//important to reset len
        cin>>n>>m>>w;
      
        for(int i=1;i<=m;i++){
            cin>>s>>e>>t;
            len++;
            edges[len].s=s;
            edges[len].e=e;
            edges[len].t=t;

            len++;
            edges[len].s=e;
            edges[len].e=s;
            edges[len].t=t;
        }

        for(int i=1;i<=w;i++){
            cin>>s>>e>>t;
            len++;
            edges[len].s=s;
            edges[len].e=e;
            edges[len].t=-t;
        }

        if(bellmanford(1)) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }    
}
