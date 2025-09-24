#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> matrix;
#define rep(i, a, b) for(int i = a; i < b; i++)

struct item{
    ll x, y;
    item *l = nullptr, *r = nullptr;

    item(ll _x){
        x = _x;
        y = rand();
    }
};

pair<item*, item*> split(item *curr, ll x){
    if(!curr) return {nullptr, nullptr};

    if(curr->x <= x){
        pair<item*, item*> right = split(curr->r, x);

        curr->r = right.first;

        return {curr, right.second};
    }
    else{
        pair<item*, item*> left = split(curr->l, x);

        curr->l = left.second;

        return {left.first, curr};
    }
}

item* insert(item *curr, item *add){
    if(!curr) return add;

    if(curr->y < add->y){
        pair<item*, item*> res = split(curr, add->x);

        add->l = res.first;
        add->r = res.second;

        return add;
    }

    if(curr->x <= add->x){
        item *res = insert(curr->r, add);

        curr->r = res;
    }
    else{
        item *res = insert(curr->l, add);

        curr->l = res;
    }

    return curr;
}

item* merge(item* left, item* right){
    if(!left || !right) return left ? left : right;

    if(left->y > right->y){
        left->r = merge(left->r, right);
        return left;
    }
    else{
        right->l = merge(left, right->l);
        return right;
    }
}

item* erase(item* t, ll x){
    if(t->x == x){
        item* res =  merge(t->l, t->r);

        delete t;

        return res;
    }

    if(t->x < x){
        item* res = erase(t->r, x);

        t->r = res;
    }
    else{
        item* res = erase(t->l, x);
        t->l = res;
    }

    return t;
}

ll searchSmallerOrEqual(item* t, ll x){
    if(!t) return -1;

    if(t->x <= x){
        ll res = searchSmallerOrEqual(t->r, x);

        return max(t->x, res);
    }
    else{
        ll res = searchSmallerOrEqual(t->l, x);

        return res;
    }
}

ll searchLarger(item *t, ll x){
    if(!t) return LONG_LONG_MAX;

    if(t->x > x){
        ll res = searchLarger(t->l, x);

        return min(t->x, res);
    }
    else{
        ll res = searchLarger(t->r, x);

        return res;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;

    vi arr(n);
    rep(i, 0, n) cin >> arr[i];

    item* tree = nullptr;

    rep(i, 0, n){
        item* newItem = new item(arr[i]);

        tree = insert(tree, newItem);
    }

    rep(j, 0, q){
        ll t, d;
        cin >> t >> d;

        if(t == 1){
            ll res = searchLarger(tree, d);
            if(res == LONG_LONG_MAX){
                cout << "-1" << endl;
            }
            else{
                cout << res << endl;

                tree = erase(tree, res);
            }
        }
        else{
            ll res = searchSmallerOrEqual(tree, d);

            cout << res << endl;

            if(res != -1){
                tree = erase(tree, res);
            }
        }
    }
}
