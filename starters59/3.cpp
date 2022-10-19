#include<bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define allr(X) (X).rbegin(), (X).rend()
#define F(i,a,n) for(ll i=a;i<n;i++)
#define B(i,a,n) for(ll i=n-1;i>=a;i--)
#define setbits(x)  __builtin_popcountll(x)
#define zrobits(x)  __builtin_ctzll(x)
#define ps(x,y)  fixed<<setprecision(y)<<x
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define vll vector<ll>
constexpr ld PI = 3.141592653589793238462;
ll mod = 1e9 + 7;
using namespace std;

/* inline bool isPalindrome(const string& s) {
    return equal(s.begin(), s.end(), s.rbegin());
}*/

template<typename T>
bool allEqual(std::vector<T> const &v) {
    if (v.size() == 0) {
        return false;
    }
    return std::equal(v.begin() + 1, v.end(), v.begin());
}

ll n_uniq(vector<ll> v)
{
    sort(all(v));
    return distance(v.begin(),unique(v.begin(), v.end()));
}

// xor of a nber x with a nber with all 1's gives the nber with every bit of x flipped.
ll bit_all_1 = 4294967295;


// Very large power very large nber modulo...
ll long_power_long(ll x, ll n)
{
    ll result = 1;
    while (n) {
        if (n & 1)
            result = result * x % mod;
        n = n / 2;
        x = x * x % mod;
    }
    return result;
}

ll btd(string n)
{
    ll dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    ll base = 1;
 
    ll len = n.length();
    for (ll i = len - 1; i >= 0; i--) {
        if (n[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}

// Short o(logn) code for btd
// But this works only if input is in integer range;

/*
int btds(int n)
{
    int num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}
*/




// TO REMOVE ALL nS ALSO THEN USE "isalpha" instead of "isaln".
// To apply this -> str.erase(it,str.end());

/*
auto it = std::remove_if(str.begin(), str.end(), [](char const &c) {
        return !std::isaln(c);
    });
*/

// std::rotate(ns.begin(),ns.begin() + n-(k%n), ns.end()); to rotate vector to right k steps.
// if we want an element at "index" 'Z' to become 1st element after rotations we replace n-(k&n) with z;

// vector<vll> v(n, vll(n));


// sort with lambdas
// sort(v.begin(), v.end(), [](int a, int b) { return abs(a)<abs(b); });



// cout << "hex_num = " << stoll(hex_num, nullptr, 16) << "\n";
// cout << "binary_num = " << stoll(binary_num, nullptr, 2) << "\n";
// cout << "dec_num = " << stoll(dec_num, nullptr, 10) << "\n ";
  


pair<ll,pair<ll,ll>> maxSubArraySum(vll a, ll n)
{
    int max_so_far = INT_MIN, max_ending_here = 0,
        start = 0, end = 0, s = 0;
 
    for (int i = 0; i < n; i++) {
        max_ending_here += a[i];
 
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
 
        if (max_ending_here < 0) {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    return {max_so_far,{start,end}};
}





int main()
{
	// your code goes here.
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
  
    ll t;
    cin >> t;


    while(t--)
    {
        
        ll i,j,k;
        ll n,m;
        cin >> n;

        vll v,v1;
        for(i=0;i<n;i++)
        {
            cin >> k;
            v.pb(k);
        }
        cin >> m;
        for(i=0;i<m;i++)
        {
            cin >> k;
            v1.pb(k);
        }

        pair<ll,pair<ll,ll>> pr;
        pr = maxSubArraySum(v,n);

        ll f = pr.first;
        pair<ll,ll> qr = pr.second;

        ll s,e;
        s = qr.first;
        e = qr.second;

        ll psum = 0;
        for(i=0;i<m;i++)
        {
            if(v1[i] >0)
                psum+=v1[i];
        }
        vll v2;
        //cout << s << " " << e << endl;
        if(*max_element(all(v)) <= 0)
        {
            if(*max_element(all(v1)) <= 0)
            {
                cout << max(*max_element(all(v)),*max_element(all(v1))) << endl;
            }
            else
            {
                pair<ll,pair<ll,ll>> br;
                br = maxSubArraySum(v1,m);
                cout << br.first << endl;
            }
        }
        else if(s==0 or e==n-1)
        {
            
            cout << f+psum << endl;
        }
        else
        {
            ll sum1=0,sum2=0;
            for(i=0;i<n;i++)
            {
                if(i<s)
                    sum1 += v[i];
                else if(i>e)
                    sum2 += v[i];
            }
            if(sum1 >= sum2)
            {
                for(i=0;i<m;i++)
                {
                    if(v1[i] >0)
                    {
                        v2.pb(v1[i]);
                    }
                }
                for(i=0;i<n;i++)
                {
                    v2.pb(v[i]);
                }
                pair<ll,pair<ll,ll>> br;
                br = maxSubArraySum(v2,sz(v2));
                cout << br.first << endl;
            }
            else
            {
                for(i=0;i<n;i++)
                {
                    v2.pb(v[i]);
                }
                for(i=0;i<m;i++)
                {
                    if(v1[i] >0)
                    {
                        v2.pb(v1[i]);
                    }
                }
                pair<ll,pair<ll,ll>> br;
                br = maxSubArraySum(v2,sz(v2));
                cout << br.first << endl;
            
            }
        
        }

        

    }


	return 0;
}