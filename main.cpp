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
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626;

// Debug
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

// Input
template <typename T> istream& operator >> (istream& is, vector<T>& v) {for (auto& i: v) is >> i; return is;}


void solve() {

}

int main() {
    IOS
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
