#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

/*
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <stdio.h>
#include <math.h>
#include <assert.h>
*/

typedef long long ll;
typedef long double ld;

#define Hu {ios_base::sync_with_stdio(false);}
#define Tao {cin.tie(NULL);}
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define sz(x) (int)((x).size())
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define uniq(v) v.erase(unique(all(v)), v.end())
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lowercase(s) transform(all(s), s.begin(), ::tolower)
#define uppercase(s) transform(all(s), s.begin(), ::toupper)
// cout << boolalpha for printing true/false

using namespace std;

bool palindrome(const string &s){
	ll n = s.size();
	for (ll i = 0; i < n; i++){
		if (s[i] != s[n - i - 1]){
			return false;
		}
	}
	return true;
}

vector<ll> sieve(ll n) {
    vector<ll> primes;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    FOR(i, 2, n + 1){
        if (is_prime[i] && (ll)i * i <= n){
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    FOR(i, 2, n + 1){
        if (is_prime[i]){
            primes.push_back(i);
        }
    }
    return primes;
}

// sort(arr, arr + N, by<Item, int, &Item::a>());
template<class T, class R, R T::* x> struct by {
    bool operator()(const T& a, const T& b) { return a.*x < b.*x; }
};

vector<ll> edges[100005];
bool visited[100005];
vector<ll> nums;

ll dfs(ll n){
	ll mn = nums[n];
	visited[n] = true;
	for (ll u : edges[n]){
		if (!visited[u]){
			mn = min(mn, dfs(u));
		}
	}
	return mn;
}

vector<string> simple_tokenizer(string s)
{
    stringstream ss(s);
    string word;
    vector<string> words;
    while (ss >> word) {
    	words.pb(word);
    }
    return words;
}

vector<pair<string, ll>> readIn(string file){
	string d;
	ll i;
	vector<pair<string, ll>> input;
	ifstream inpf;
	inpf.open(file);
	while (inpf >> d >> i){
		input.pb(make_pair(d, i));
	}
	inpf.close();
	return input;
}

void solve(){
	vector<pair<string, ll>> directions = readIn("input2.txt");
	// PART 1
	/*
	ll hpos = 0, depth = 0;
	FOR(i, 0, sz(directions)){
		if (directions[i].first == "forward"){
			hpos += directions[i].second;
		}
		else if (directions[i].first == "up"){
			depth -= directions[i].second;
		}
		else{
			depth += directions[i].second;
		}
	}
	cout << hpos * depth;
	*/

	// PART 2
	ll aim = 0, hpos = 0, depth = 0;
	FOR(i, 0, sz(directions)){
		if (directions[i].first == "forward"){
			hpos += directions[i].second;
			depth += (aim * directions[i].second);
		}
		else if (directions[i].first == "up"){
			aim -= directions[i].second;
		}
		else{
			aim += directions[i].second;
		}
	}
	cout << hpos * depth;
}

int main(){
	Hu Tao
	int t = 1;
	//cin >> t;
	while (t--) solve();
}
