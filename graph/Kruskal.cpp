#include <bits/stdc++.h>

using namespace std;

const int INF=99999999;
int dist[506],len,father[506],n,w,cnt,ans;

struct edge{
    int x,y,v;
}edges[10006];

int getfather(int x){
    if(father[x]==x) return x;
    else return father[x]=getfather(father[x]);
}
void merge(int x,int y){
    int fx=getfather(x);
    int fy=getfather(y);
    if(father[x]!=father[y]){
        father[fx]=fy;
    }
}
bool cmp(edge x,edge y){
    return x.v<y.v;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    //freopen("agrinet.in","r",stdin);
    //freopen("agrinet.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>w;
            if(i==j) continue;
            len++;
            edges[len].x=i;
            edges[len].y=j;
            edges[len].v=w;
        }
    }
    sort(edges+1,edges+len+1,cmp);
    for(int i=1;i<=n;i++) father[i]=i;

    for(int i=1;i<=len;i++){
        int u=getfather(edges[i].x);
        int v=getfather(edges[i].y);
        if(u!=v){
            merge(u,v);
            ans+=edges[i].v;
            cnt++;
            if(cnt==n-1) break;
        }
    }
    cout<<ans<<'\n';
}
