#include <bits/stdc++.h>
using namespace std ;
using namespace std::chrono;

#define ll long long 
#define pb push_back 
#define yes cout << "YES" 
#define no cout << "NO" 
#define all(x) (x).begin(),(x).end()

const long long int mod = 1e9 + 7 ;
const long long int INF = 1e18 ;

void readvec(vector<ll> &v){
    for(int i = 0 ; i < v.size() ; i++){
        cin >> v[i] ;
    }
}

void printvec(vector<ll> &v){
    for(int i = 0 ; i < v.size() ; i++){
        cout << v[i] << " ";
    }
}

//For debugging :
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(long long t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//binary exponentiation 
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

void solve(ll test_case){
    ll n ; cin >> n ;
    string s ; cin >> s ;
    vector<ll> v ;
    ll ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '1'){
            v.pb(i);
        }
    }
    debug(v)
    if(v[0] != 0){
        ans += (v[0]*(v[0] + 1)/2);
    }

    if(v[v.size()-1] != n-1){
        ll left = n - v[v.size()-1] - 1 ;
        debug(left)
        ans += (left)*(left+1)/2 ;
    }

    for(int i = 0 ; i < v.size()-1 ; i++){
        ll diff = v[i+1] - v[i] - 1;
        if(diff == 0){
            continue;
        }
        if(diff%2 == 0){
            ans += (diff/2)*(diff/2 + 1);
        }else{
            ans += (diff/2 + 1)*(diff/2 + 1);
        }
    }
     cout << "Case #" << test_case << ": " << ans << '\n' ;
}

int main(){
    auto start = high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
 
    int tests = 1 , test_case = 1;
    cin >> tests ;
    while(tests--){
        cout << setprecision(15) << fixed ;
        solve(test_case) ;
        test_case++;
        // cout << '\n' ;
        // cout << "Case #" << test_case << ": " << ans << '\n' ;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "\n\nTime taken : " << fixed << duration.count() / 1000000.0 << "seconds" << "\n";
}

