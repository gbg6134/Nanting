#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> matrix;
#define rep(i, a, b) for(int i = a; i < b; i++)

struct node{
    //information
    node(){}
};

struct SegmentTree{
    vector<node> seg;
    ll n;

    SegmentTree(ll _n){
        seg.assign(4 * _n, node());
        n = _n;
    }

    void assignValue(ll l, ll r){
        SecretAssignValue(0, n - 1, l, r, 0);
    }

    node SecretAssignValue(ll l, ll r, ll ls, ll rs, ll i){
        if(l > r) return node();
        if(r < ls || l > rs) return node();

        if(l <= ls && rs <= r){
            //assign value  

            return seg[i];
        }

        ll m = (l + r) / 2;
        
        node a = SecretAssignValue(l, m, ls, rs, i * 2 + 1);
        node b = SecretAssignValue(m + 1, r, ls, rs, i * 2 + 2);

        //do something with seg[i]

        return seg[i];
    }

    node getValue(ll l, ll r){
        return SecretGetValue(0, n - 1, l, r, 0);
    }

    node SecretGetValue(ll l, ll r, ll ls, ll rs, ll i){
        if(l > r) return node();
        if(r < ls || l > rs) return node();

        if(l <= ls && rs <= r) return seg[i];

        ll m = (l + r) / 2;

        node a = SecretGetValue(l, m, ls, rs, i * 2 + 1);
        node b = SecretGetValue(m + 1, r, ls, rs, i * 2 + 2);

        //Change this depending on what you want c to be
        node c = node();

        return c;
    }
};