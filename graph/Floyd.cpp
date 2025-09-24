#include <bits/stdc++.h>

using namespace std;

const int INF=99999999;
int p,f,c,lst[506],a,b,t,dist[506][506],mini=INF,ans;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    //freopen("input.in","r",stdin); ska generalisera
    //freopen("input.out","w",stdout);
    
    cin>>p>>f>>c;
    for(int i=1;i<=p;i++) for(int j=1;j<=p;j++) dist[i][j]=INF;
    for(int i=1;i<=p;i++){
        dist[i][i]=0;
    }
    
    for(int i=1;i<=f;i++) cin>>lst[i];

    for(int i=1;i<=c;i++){
        cin>>a>>b>>t;
        dist[a][b]=dist[b][a]=t;
    }

    for(int k=1;k<=p;k++){
        for(int i=1;i<=p;i++){
            for(int j=1;j<=p;j++){
                dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
            }
        }
    }
    for(int i=1;i<=p;i++){
        int summ=0;
        for(int j=1;j<=f;j++){
            summ+=dist[i][lst[j]];
        }
        if(summ<mini){
            mini=summ;
            ans=i;
        }
    }
    cout<<ans<<'\n';
}
