//UPDATERA ARRAY STORLEKEN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> matrix;
#define rep(i, a, b) for(int i = a; i < b; i++)
 
const ll MAXN=100006;//UPDATERA ARRAY STORLEKEN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

ll n;

struct node{
    ll in,out,id;
}lst[MAXN];

class Compare {
public:
    bool operator()(node a, node b)
    {
        return a.in<b.in;
    }
};

priority_queue<node,vector<node>,Compare> Q;
