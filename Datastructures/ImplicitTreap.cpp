    #include <bits/stdc++.h>
    using namespace std;
     
    typedef long long ll;
    typedef pair<ll, ll> pii;
    typedef vector<ll> vi;
    typedef vector<vi> matrix;
    #define rep(i, a, b) for(int i = a; i < b; i++)
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
     
    struct item{
        bool rev = false;
        ll size = 1;
        item *l = nullptr, *r = nullptr;
     
        ll priority, val;
     
        item(){}
        item(ll value){
            val = value;
            priority = rng();
        }
    };
    typedef item* pitem;
     
    ll get_size(pitem tree){
        return tree ? tree->size : 0;
    }
     
    void update_size(pitem tree){
        if(!tree) return;
        tree->size = get_size(tree->l) + get_size(tree->r) + 1;
    }
     
    void push(pitem tree){
        if(!tree) return;
     
        if(tree->rev){
            if(tree->l)tree->l->rev ^= 1;
            if(tree->r)tree->r->rev ^= 1;
            swap(tree->l, tree->r);
            tree->rev = false;
        }
    }
     
    pair<pitem, pitem> split(pitem tree, ll index, ll ext){
        if(!tree) return {nullptr, nullptr};
     
        push(tree);
     
        pair<pitem, pitem> curr;
        
        if(index <= ext + get_size(tree->l)){
            curr = split(tree->l, index, ext);
     
            tree->l = curr.second;
            update_size(tree);
     
            return {curr.first, tree};
        }
        else{
            curr = split(tree->r, index, ext + 1 + get_size(tree->l));
            
            tree->r = curr.first;
            update_size(tree);
     
            return {tree, curr.second};
        }
    }
     
    pitem merge(pitem l, pitem r){
        if(!l || !r) return l ? l : r;
     
        push(l);
        push(r);
     
        if(l->priority < r->priority){
            r->l = merge(l, r->l);
            update_size(r);
     
            return r;
        }
        else{
            l->r = merge(l->r, r);
            update_size(l);
     
            return l;
        }
    }
     
    pitem insert(pitem tree, ll index, pitem add, ll ext){
        if(!tree) return add;
     
        push(tree);
     
        if(tree->priority < add->priority){
            pair<pitem, pitem> s = split(tree, index, ext);
     
            add->l = s.first;
            add->r = s.second;
     
            update_size(add);
     
            return add;
        }
        else{
            if(index <= ext + get_size(tree->l)){
                pitem curr = insert(tree->l, index, add, ext);
     
                tree->l = curr;
            }
            else{
                pitem curr = insert(tree->r, index, add, ext + 1 + get_size(tree->l));
     
                tree->r = curr;
            }
     
            update_size(tree);
     
            return tree;
        }
    }
     
    pitem search(pitem tree, ll index, ll ext){
        if(!tree) return nullptr;
        push(tree);
        if(index == ext + get_size(tree->l)){
            return tree;
        }
        else if(index < ext + get_size(tree->l)){
            return search(tree->l, index, ext);
        }
        else return search(tree->r, index, ext + 1 + get_size(tree->l));
    }
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
     
        ll n, q, m;
        cin >> n >> q >> m;
     
        vi arr(n);
        rep(i, 0, n) cin >> arr[i];
     
        pitem tree = nullptr;
     
        rep(i, 0, n){
            tree = insert(tree, i, new item(arr[i]), 0);
        }
     
        rep(t, 0, q){
            ll i, l, r;
            cin >> i >> l >> r;
            l--; r--;
     
            if(i == 1){
                pitem t1, t2, t3, t4;
                pair<pitem, pitem> temp; 
                temp = split(tree, l, 0);     
                t1 = temp.first; t2 = temp.second;
                temp = split(t2, r - l, 0);  
                t2 = temp.first; t3 = temp.second; 
     
                temp = split(t3, 1, 0); 
                t4 = temp.first; t3 = temp.second;
     
                tree = merge(merge(merge(t1, t4), t2), t3);
            }
            else{
                pair<pitem, pitem> f = split(tree, l, 0);
                pair<pitem, pitem> s = split(f.second, r - l + 1, 0);
     
                if(s.first)s.first->rev ^= 1;
     
                f.second = merge(s.first, s.second);
                tree = merge(f.first, f.second);
            }
        }
     
        rep(i, 0, m){
            ll k;
            cin >> k;
            k--;
     
            pitem r = search(tree, k, 0);
     
            cout << r->val << " ";
        }
        cout << endl;
    }
