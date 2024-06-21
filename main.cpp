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
#define FILEIO freopen("input.txt","r", stdin); freopen("output.txt","w", stdout);

// Constants
const ll MAX_N = 1e5 + 5;
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

vector<ll> to_base(ll n, ll base) {
    vector<ll> res;
    while (n) {
        res.push_back(n % base);
        n /= base;
    }
    return res;
}

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

    for (ll p=2; p*p <= n; ++p)
        if (marked[p])
            for (ll i=p*p; i<=n; i+=p)
                marked[i] = false;

    for (ll p=2; p<=n; ++p)
        if (marked[p])
            primes.push_back(p);

    return primes;
}

ll S(ll a, ll b){
    a=a+b;
    if(a>=MOD) a-=MOD;
    if(a<0) a+=MOD;
    return a;
}
ll S(ll a, ll b, ll c){return S(a,S(b,c));}
ll P(ll a,ll b){return (a * b) % MOD;}
ll P(ll a, ll b,ll c){return P(a,P(b,c));}
ll R(ll a, ll b){return S(a,MOD-b);}

ll pot(ll a, ll x){
    if(x==0) return 1;
    if(x==1) return a;
    ll y=pot(a,x/2);
    y=P(y,y,pot(a,x%2));
    return y;
}

ll inv(ll a){
    return pot(a,MOD-2);
}

array<ll, MAX_N> r_;
array<ll, MAX_N> fact;
array<ll, MAX_N> rfact;

ll choose(ll n, ll k){
    if(n==k) return 1;
    if(k<0||k>n) return 0;
    if(k==0) return 1;
    return P(fact[n],rfact[k],rfact[n-k]);
}

void precompute() {
    r_[1]=1;
    fact[0]=fact[1]=1;
    rfact[0]=rfact[1]=1;

    for(ll i=2; i<MAX_N; i++) {
        r_[i]=P(MOD-1,(MOD/i), r_[MOD%i]);
        fact[i]=P(fact[i-1],i);
        rfact[i]=P(rfact[i-1],r_[i]);
    }
}

struct SegmentTreeNode {
    ll seg, pref, suf, sum;
};

// 1-indexed array
class SegmentTree {
    ll n;
    // min, cnt
    vector<SegmentTreeNode> tree;
    SegmentTreeNode neutral = {0, 0, 0, 0};
    void build(const vector<ll> &v, ll i, ll l, ll r) {
        if (l == r) {
            tree[i] = single(v[l]);
        } else {
            ll mid = (l + r) / 2;
            build(v, i * 2, l, mid);
            build(v, i * 2 + 1, mid + 1, r);
            // Change operation as desired
            tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);
        }
    }
    SegmentTreeNode calc(ll i, ll tl, ll tr, ll l, ll r) {
        // cut recursion (out of range)
        if (l > r) {
            return neutral;
        }
        // cut recursion, interval in segtree
        if (l <= tl && tr <= r) {
            return tree[i];
        }
        // search both sides
        ll tmid = (tl + tr) / 2;
        SegmentTreeNode a = calc(i * 2, tl, tmid, l, min(r, tmid)), b = calc(i * 2 + 1, tmid + 1, tr,max(l, tmid + 1), r);
        return merge(a, b);
    }
    void update(ll i, ll tl, ll tr, ll val, ll pos) {
        if (tl == tr) {
            tree[i] = single(val);
            return;
        }
        ll tmid = (tl + tr) / 2;
        if (pos <= tmid) {
            update(i * 2, tl, tmid, val, pos);
        } else {
            update(i * 2 + 1, tmid + 1, tr, val, pos);
        }
        tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);
    }
    SegmentTreeNode single(ll v) {
        if (v > 0) {
            return {v, v, v, v};
        } else {
            // handle negative case
            return {0, 0, 0, v};
        }
    }
    SegmentTreeNode merge(const SegmentTreeNode &a, const SegmentTreeNode &b) {
        return {
                max(a.seg, max(b.seg, a.suf + b.pref)),
                max(a.pref, a.sum + b.pref),
                max(b.suf, b.sum + a.suf),
                a.sum + b.sum,
        };
    }
public:
    explicit SegmentTree(const vector<ll> &v) {
        n = v.size() - 1;
        tree = vector<SegmentTreeNode>(4 * n + 1, neutral);
        build(v, 1, 1, n);
    }
    SegmentTreeNode calc(ll l, ll r) {
        return calc(1, 1, n, l, r);
    }
    void update(ll idx, ll value) {
        update(1, 1, n, value, idx);
    }
};

template <typename T>
class DisjointSetArray
{
private:
    // define the structures
    vector<T> dt;
    int *parent = nullptr;
    int *rank = nullptr;
    int *sizes = nullptr;
    size_t sz;
    ll n_sets;
    int biggest_set = 1;
public:
    // implement all functions
    explicit DisjointSetArray(const vector<T> &data) {
        dt = data;
        parent = new int[data.size()];
        rank = new int[data.size()];
        sizes = new int[data.size()];
        sz = data.size();
        n_sets = sz;

        // make all sets
        for (int i = 0; i < sz; ++i) {
            MakeSet(i);
        }
    }
    ~DisjointSetArray() {
        delete[] parent;
        delete[] rank;
    }
    /*
    * x, y are indexes
    */
    //MakeSet the element with index x
    void MakeSet(int x) {
        parent[x] = x;
        rank[x] = 0;
        sizes[x] = 1;
    }
    //Find the root of x (with optimization by rank)
    int Find(int x) {
        if (parent[x] == x) {
            return x;
        }
        else {
            return Find(parent[x]);
        }
    }
    //Find the root of x (with optimization path compression)
    int FindPathCompression(int x) {
        if (parent[x] == x) {
            return x;
        }
        else {
            parent[x] = FindPathCompression(parent[x]);
            return parent[x];
        }
    }
    //Union two sets represented by x and y (apply rank)
    void Union(int x, int y) {
        int xRoot = FindPathCompression(x);
        int yRoot = FindPathCompression(y);
        if (xRoot == yRoot) return;
        n_sets--;
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
            sizes[yRoot] += sizes[xRoot];
            biggest_set = max(biggest_set, sizes[yRoot]);
        }
        else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
            sizes[xRoot] += sizes[yRoot];
            biggest_set = max(biggest_set, sizes[xRoot]);

        }
        else {
            parent[xRoot] = yRoot;
            sizes[yRoot] += sizes[xRoot];
            rank[yRoot] += 1;
            biggest_set = max(biggest_set, sizes[yRoot]);

        }
    }
    ll get_count_sets() {
        return n_sets;
    }
    ll get_biggest_set() {
        return biggest_set;
    }
    //check whether there is a path between x and y
    bool isConnected(int x, int y) {
        return Find(x) == Find(y);
    }
    //total number of elements
    int size() {
        return sz;
    }
    //number of sets
    int sets() {
        int cnt = 0;
        for (int i = 0; i < sz; ++i) {
            // find elements whose parent is itself
            if (parent[i] == i) ++cnt;
        }
        return cnt;
    }
    //total number of elements that belong to the set of x
    int size(int x) {
        // search for all elements with parent equal to x
        int s = 0;
        for (int i = 0; i < sz; ++i) {
            if (Find(i) == Find(x)) ++s;
        }
        return s;
    }
    //return all elements that belong to the set of x
    vector<T> getElementsSet(int x) {
        vector<T> elements;
        for (int i = 0; i < sz; ++i) {
            if (Find(i) == Find(x)) elements.push_back(dt[i]);
        }
        return elements;
    }
};

void solve() {

}

int main() {
    IOS
    FILEIO
    precompute();

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
