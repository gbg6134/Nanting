#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> matrix;
#define rep(i, a, b) for(int i = a; i < b; i++)

ll gcd(ll x,ll y){
    while(x!=y){
        if(x>y) swap(x,y);
        if(y%x==0) return x;
        y-=x*(y/x);
    }
    return x;
}
