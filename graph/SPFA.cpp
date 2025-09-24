#include <bits/stdc++.h>

using namespace std;

const int INF=99999999;
int Link[1456],len;
struct node{
    int now,next,weight;
}edges[10012];

void insert(int a,int b, int w){
    len++;
    edges[len].next=Link[a];
    edges[len].now=b;
    edges[len].weight=w;
    Link[a]=len;
}

queue<int> Q;

int n,p,c,a[506],A,B,D,dist[806],path[806],ans=INF;
bool vis[806];

void SPFA(int x){
    for(int i=1;i<=p;i++){
        dist[i]=path[i]=INF;
        vis[i]=false;
    }
    dist[x]=0;
    path[x]=0;
    Q.push(x);
    while(!Q.empty()){
        int temp=Q.front();
        Q.pop();
        vis[temp]=false;//have to reset as well, put it here, does not really matter, can not going back to itself
        for(int i=Link[temp];i;i=edges[i].next){//non negative loops
            if(dist[edges[i].now]>edges[i].weight+dist[temp]){
                dist[edges[i].now]=edges[i].weight+dist[temp];
                path[edges[i].now]=path[temp]+1;
                if(!vis[edges[i].now]){
                    Q.push(edges[i].now);
                    vis[edges[i].now]=true;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    //freopen("butter.in","r",stdin);
    //freopen("butter.out","w",stdout);
    
    cin>>n>>p>>c;
    for(int i=1;i<=n;i++) cin>>a[i];    

    for(int i=1;i<=c;i++){
        cin>>A>>B>>D;
        insert(A,B,D);
        insert(B,A,D);
    }

    for(int i=1;i<=p;i++){
        SPFA(i);
        int summ=0;
        for(int j=1;j<=n;j++){
            summ+=dist[a[j]];
        }
        ans=min(ans,summ);
    }
    cout<<ans<<'\n';
}
