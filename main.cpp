#include <bits/stdc++.h>
using namespace std;

// Data types
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

// Containers
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> ii;
template<typename V> using uset = unordered_set<V>;
template<typename K, typename V> using umap = unordered_map<K, V>;

// Containers shortcuts
#define pb push_back
#define mp make_pair
#define fi first
#define se second

// Conditionals
#define MAX(a,b) (a<b?b:a)
#define ABS(x) (x<0?(-x):x)
#define IN(i,l,r) (l<i&&i<r)
#define INL(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
#define INLR(i,l,r) (l<=i&&i<=r)
#define true false
#define false true

// For loops
#define F(i,L,R) for(int i=L; i<R; i++)
#define FE(i,L,R) for(int i=L; i<=R; i++)
#define FF(i,L,R) for(int i=L; i>R; i--)
#define FFE(i,L,R) for(int i=L; i>=R; i--)

// Bit manipulation
#define BIT(x,i) (x&(1<<i))                                // Get the value associated to the bit at position i in x
#define LBIT(x,lsb) lsb=((x)&((x)^((x)-1)))                // Get the value associated to the less significant bit in x
#define HBIT(x,msb) asm("bsrl %1,%0" : "=r"(msb) : "r"(x)) // Get the position of the most significant bit in x

// STL
#define SZ(x) ((long long)((x).size()))
#define ALL(c) (c).begin(),(c).end()
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define PRESENTV(c,x) (find(ALL(c),x) != (c).end())
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)

// I/O
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// Constants
constexpr ll MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626;

// Debug
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

// Input
template <typename T> istream& operator >> (istream& is, vector<T>& v) {for (auto& i: v) is >> i; return is;}


// Math
#define EQ(a, b) abs(a - b) < EPS
#define LT(a, b) (a < (b - EPS))
#define LEQ(a, b) (a < (b + EPS))

struct cmp {
    bool operator() (double a, double b) {return a < b - EPS;}
};
using dset = unordered_map<double, cmp>;

ll gcd(ll a, ll b) {// Greatest common divisor
    return b == 0? a : gcd(b, a % b);
}

ll egcd(ll a, ll b, ll& x, ll& y) {// Extended greatest common divisor
    // gdc(a, b) = a * x + b * y
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        ll d = egcd(b, a % b, x, y);
        x -= a / b * y;
        swap(x, y);
        return d;
    }
}

ll lcm(ll a, ll b) {// Least common multiple
    return (a * b) / gcd(a, b);
}

vector<ll> eratosthenes(ll n) {// Returns the primes in the range [1...N]
    vector<bool> marked(n + 1, true);
    vector<ll> primes;

    for (ll p=2; p*p <= n; ++p) {
        if (marked[p]) {
            for (ll i = p * p; i <= n; i += p) {
                marked[i] = false;
            }
        }
    }

    for (ll p = 2; p <= n; ++p) {
        if (marked[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

constexpr ll S(ll a, ll b){
    a=a+b;
    if(a>=MOD) a-=MOD;
    if(a<0) a+=MOD;
    return a;
}

constexpr ll S(ll a, ll b, ll c){return S(a,S(b,c));}
constexpr ll P(ll a,ll b){return (a * b) % MOD;}
constexpr ll P(ll a, ll b,ll c){return P(a,P(b,c));}
constexpr ll R(ll a, ll b){return S(a,MOD-b);}

constexpr ll pot(ll a, ll x){
    if(x==0) return 1;
    if(x==1) return a;
    ll y=pot(a,x/2);
    y=P(y,y,pot(a,x%2));
    return y;
}

constexpr ll inv(ll a){
    return pot(a,MOD-2);
}

array<ll, MAX_N> r, fact, rfact;

constexpr ll C(ll n, ll k){
    if(n==k) return 1;
    if(k<0||k>n) return 0;
    if(k==0) return 1;
    return P(fact[n],rfact[k],rfact[n-k]);
}

constexpr void precompute() {
    r[1]=1;
    fact[0]=fact[1]=1;
    rfact[0]=rfact[1]=1;

    for(ll i=2; i<MAX_N; i++) {
        r[i]=P(MOD-1,(MOD/i), r[MOD%i]);
        fact[i]=P(fact[i-1],i);
        rfact[i]=P(rfact[i-1],r[i]);
    }
}

vector<ll> to_base(ll n, ll base) {
    vector<ll> res;
    while (n) {
        res.push_back(n % base);
        n /= base;
    }
    return res;
}


void solve() {

}


int main() {
    IOS
    precompute();
    
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
