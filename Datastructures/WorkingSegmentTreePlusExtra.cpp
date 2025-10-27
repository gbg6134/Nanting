  #include <bits/stdc++.h>
  using namespace std;
   
  typedef long long ll;
  typedef pair<ll, ll> pii;
  typedef vector<ll> vi;
  typedef vector<vi> matrix;
  #define rep(i, a, b) for(ll i = a; i < b; i++)
   
  void update(vi &seg, ll l, ll r, ll i, ll ind){
      if(l > ind || r < ind) return;
      
      seg[i]++;
   
      if(l == r) return;
   
      ll m = (l + r) / 2;
   
      update(seg, l, m, i * 2 + 1, ind);
      update(seg, m + 1, r, i * 2 + 2, ind);
  }
   
  ll get(vi &seg, ll ls, ll rs, ll l, ll r, ll i){
      if(l > rs || r < ls) return 0;
   
      if(ls <= l && r <= rs) {
          return seg[i];
      }
   
      ll m = (l + r) / 2;
   
      ll a = get(seg, ls, rs, l, m, i * 2 + 1);
      ll b = get(seg, ls, rs, m + 1, r, i * 2 + 2);
   
      return a + b;
  }
   
  int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      ll mod = 1e9 + 7;
   
      ll t;
      cin >> t;

      vector<vi> c(2e5 + 6, vi(106, -1));

      c[0][0]=1;

      for(ll i=1;i<2e5 + 6;i++){
          c[i][0]=1;
          c[i][min(i, (ll)105)]=1;

          for(ll j=1;j<min(i, (ll)106);j++){
              c[i][j]=c[i-1][j]+c[i-1][j-1];
              c[i][j]%=mod;
          }
      }
   
      rep(q, 0, t){
          ll n, m, k;
          cin >> n >> m >> k;
   
          vi a(n);
          rep(i, 0, n) cin >> a[i];
   
          vi seg(4 * n + 4, 0);
   
          rep(i, 0, n){
              update(seg, 0, n, 0, a[i]);
          }
   
          ll tot = 0;
   
          rep(i, 1, n + 1){
              ll val = get(seg, max((ll)0, i - k), i, 0, n, 0);
              if(val >= m){
                  tot += c[val][m];
                  val = get(seg, max((ll)0, i - k), i - 1, 0, n, 0);
                  if(val >= m) tot -= c[val][m];
                  if(tot < 0) tot += mod;
                  tot %= mod;
              }
          }
          cout << tot << endl;
      }
  }
