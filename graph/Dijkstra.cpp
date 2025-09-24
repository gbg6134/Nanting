#include <bits/stdc++.h>

using namespace std;

const int INF=99999999;
int n,dist[600],Link[10006],len,w,x,y;
bool vis[600];
char a,b;

struct node{
    int now,next,weight;
}edges[20012];

void insert(int a,int b, int w){
    len++;
    edges[len].next=Link[a];
    edges[len].now=b;
    edges[len].weight=w;
    Link[a]=len;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("input.out","w",stdout);
    
    cin>>n;
    for(int i=1;i<=599;i++) dist[i]=INF;

    for(int i=1;i<=n;i++){
        cin>>a>>b>>w;
        x=a;
        y=b;
        insert(x,y,w);
        insert(y,x,w);
        if(x=='Z'){
            dist[y]=min(dist[y],w);//maybe same sides
        }
        if(y=='Z'){
            dist[x]=min(dist[x],w);
        }
    }

    /*for(int i=1;i<=166;i++){
        bool p=false;
        for(int j=Link[i];j;j=edges[j].next){
            char c=edges[j].now;
            cout<<c<<' ';
            p=true;
        }
        if(p){
            char c=i;
            cout<<c<<'\n';
        }
    }*/
    vis['Z']=true;
    
    for(int i=1;i<=n-1;i++){
        int mini=INF,tar=0;
        for(int j='A';j<='z';j++){
            if(j=='Z') continue;

            if(dist[j]<mini&&!vis[j]){
                mini=dist[j];
                tar=j;
            }
        }

        vis[tar]=true;
        for(int j=Link[tar];j;j=edges[j].next){
            if(!vis[j]) dist[edges[j].now]=min(dist[edges[j].now],dist[tar]+edges[j].weight);
        }
    }

    int cand=0,length=INF;
    for(int i='A';i<='Y';i++){
        if(dist[i]<length){
            length=dist[i];
            cand=i;
        }
    }
    char c=cand;//R->A
    cout<<c<<' '<<length<<'\n';
}
