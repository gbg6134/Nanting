#include <bits/stdc++.h>
using namespace std;

typedef long long ll
typedef vector<ll> vi

ll LCA(vector<vi> &steps, vi &depthForAll, ll u, ll v){
    if(depthForAll[u] < depthForAll[v]) swap(u, v);
    ll diffrence = depthForAll[u] - depthForAll[v];
    for(int i = 19; i >= 0; i--){
        ll power = pow(2, i);
        if(power <= diffrence){
            u = steps[u][i];
            diffrence -= power;
        }
    }

    for(int i = 19; i >= 0; i--){
        if(steps[u][i] != steps[v][i]){
            u = steps[u][i];
            v = steps[v][i];
        }
    }
    
    if(u != v) return steps[v][0];
    return v;
}
