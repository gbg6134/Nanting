#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> matrix;
#define rep(i, a, b) for(int i = a; i < b; i++)

string Bigadd(string x,string y){
    //if(x[0]!='-'&&y[0]=='-') return Bigsub(x,y.substr(1,y.size()-1));
    //if(x[0]=='-'&&y[0]!='-') return Bigsub(y,x.substr(1,x.size()-1));
    if(x[0]=='-'&&y[0]=='-') return "-"+Bigadd(y.substr(1,y.size()-1),x.substr(1,x.size()-1));
    
    int s=max(x.size(),y.size()),a[s+6],b[s+6];
    int res[s+6];
    memset(res,0,sizeof(res));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));

    for(int i=0;i<x.size();i++) a[i]=x[x.size()-1-i]-'0';
    for(int i=0;i<y.size();i++) b[i]=y[y.size()-1-i]-'0';

    for(int i=0;i<s;i++){
        res[i]+=a[i]+b[i];
        res[i+1]=res[i]/10;
        res[i]%=10;
    }
    string ans="";
    bool first=false;
    for(int i=s+1;i>=0;i--){
        if(res[i]==0&&!first) continue;
        else{
            ans+=res[i]+'0';
            first=true;
        }
    }
    if(ans=="") return "0";
    return ans;
}

string Bigsub(string x,string y){
    if(x[0]!='-'&&y[0]=='-') return Bigadd(x,y.substr(1,y.size()-1));
    if(x[0]=='-'&&y[0]!='-') return '-' + Bigadd(x.substr(1,x.size()-1),y);
    if(x[0]=='-'&&y[0]=='-') return Bigsub(y.substr(1,y.size()-1),x.substr(1,x.size()-1));
    

    bool neg=false;
    if(y.size()>x.size()){
        swap(x,y);
        neg=true;
    }

    if(y.size()==x.size()&&y>x){
        swap(x,y);//ensures y>x
        neg=true;
    }

    int s=max(x.size(),y.size()),a[s+6],b[s+6];
    int res[s+6];
    memset(res,0,sizeof(res));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));

    for(int i=0;i<x.size();i++) a[i]=x[x.size()-1-i]-'0';
    for(int i=0;i<y.size();i++) b[i]=y[y.size()-1-i]-'0';

    for(int i=0;i<s;i++){
        res[i]+=a[i]-b[i];
        while(res[i]<0){
            res[i]+=10;
            res[i+1]--;
        }
    }
    string ans="";
    if(neg) ans+="-";
    bool first=false;
    for(int i=s+1;i>=0;i--){
        if(res[i]==0&&!first) continue;
        else{
            ans+=res[i]+'0';
            first=true;
        }
    }
    if(ans==""||ans=="-") return "0";
    return ans;
}

string Bigmul(string x,string y){// multiplication not done like this
    if(x=="0"||y=="0") return "0";

    if(x[0]!='-'&&y[0]=='-') return "-"+Bigmul(x,y.substr(1,y.size()-1));
    if(x[0]=='-'&&y[0]!='-') return "-"+Bigmul(y,x.substr(1,x.size()-1));
    if(x[0]=='-'&&y[0]=='-'){
        x=x.substr(1,x.size()-1);
        y=y.substr(1,y.size()-1);
    }
    
    int s=max(x.size(),y.size()),a[2*s+6],b[2*s+6];
    int res[2*s+6];
    memset(res,0,sizeof(res));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));

    for(int i=0;i<x.size();i++) a[i]=x[x.size()-1-i]-'0';
    for(int i=0;i<y.size();i++) b[i]=y[y.size()-1-i]-'0';


    for(int i=0;i<x.size();i++){
        for(int j=0;j<y.size();j++){
            res[i+j]+=b[j]*a[i];
            res[i+j+1]+=res[i+j]/10;//will not increase 2.
            res[i+j]%=10;
        }
    }

    string ans="";
    bool first=false;
    for(int i=2*s+5;i>=0;i--){
        if(res[i]==0&&!first) continue;
        else{
            ans+=res[i]+'0';
            first=true;
        }
    }
    if(ans=="") return "0";
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("test100","r",stdin);
    //freopen("mine.txt","w",stdout);
    
    string a,b;
    cin>>a>>b;
    string c=Bigmul(a,b);
    cout<<c<<'\n';
}
