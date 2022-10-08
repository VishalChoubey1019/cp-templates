using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define fi first
#define se second

// MXS jo h uska scene dekhlena

namespace Hashing{
    const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
    const int mxs = 1e6 + 10;
    const int p1 = 28, p2 = 30;
    ll mod1_a(ll a,ll b){a %= MOD1;b %= MOD1;return (((a + b) % MOD1) + MOD1) % MOD1;}
    ll mod1_m(ll a,ll b){a %= MOD1;b %= MOD1;return (((a * b) % MOD1) + MOD1) % MOD1;}
    ll mod1_s(ll a,ll b){a %= MOD1;b %= MOD1;return (((a - b) % MOD1) + MOD1) % MOD1;}
    ll mod2_a(ll a,ll b){a %= MOD2;b %= MOD2;return (((a + b) % MOD2) + MOD2) % MOD2;}
    ll mod2_m(ll a,ll b){a %= MOD2;b %= MOD2;return (((a * b) % MOD2) + MOD2) % MOD2;}
    ll mod2_s(ll a,ll b){a %= MOD2;b %= MOD2;return (((a - b) % MOD2) + MOD2) % MOD2;}
    ll pow1_m(ll a,ll b){ll r=1;while(b){if(b&1){r=mod1_m(a,r);}a=mod1_m(a,a);b>>=1;}return r;}
    ll pow2_m(ll a,ll b){ll r=1;while(b){if(b&1){r=mod2_m(a,r);}a=mod2_m(a,a);b>>=1;}return r;}
    ll mod1_i(ll a){return pow1_m(a,MOD1-2);}
    ll mod2_i(ll a){return pow2_m(a,MOD2-2);}
    ll mod1_d(ll a,ll b){a %= MOD1;return mod1_m(a,mod1_i(b));}
    ll mod2_d(ll a,ll b){a %= MOD2;return mod2_m(a,mod2_i(b));}
    int p1_pow[mxs],p2_pow[mxs],p1_powinv[mxs],p2_powinv[mxs];

    void Build(){
        int t_p1 = p1, t_p2 = p2, t_p1inv = mod1_i(p1), t_p2inv = mod2_i(p2);
        p1_powinv[0] = p2_powinv[0] = p1_pow[0] = p2_pow[0] = 1;
        for(int i=1;i<mxs;i++){
            p1_pow[i] = t_p1;
            p2_pow[i] = t_p2;
            p1_powinv[i] = t_p1inv;
            p2_powinv[i] = t_p2inv;
            t_p1 = mod1_m(t_p1,p1_pow[1]);
            t_p2 = mod2_m(t_p2,p2_pow[1]);
            t_p1inv = mod1_m(t_p1inv,p1_powinv[1]);
            t_p2inv = mod2_m(t_p2inv,p2_powinv[1]);
        }
    }

    bool isEqual(pii a, pii b){
        return a.fi==b.fi && a.se==b.se;
    }

    struct SHash{
        int N;
        vi S1Hash,S2Hash,S1Hrev,S2Hrev;
        SHash(string S){
            N = S.length();
            S1Hash.assign(N+2, 0);
            S2Hash.assign(N+2, 0);
            S1Hrev.assign(N+2, 0);
            S2Hrev.assign(N+2, 0);
            this->build(S);
        }
        void build(string S){
            for(int i=0;i<N;i++){
                S1Hash[i] = mod1_a(mod1_m((S[i]-'a'+1),p1_pow[i]),(i ? S1Hash[i-1] : 0));
                S2Hash[i] = mod2_a(mod2_m((S[i]-'a'+1),p2_pow[i]),(i ? S2Hash[i-1] : 0));
            }
            for(int i=N-1;i>=0;i--){
                S1Hrev[i] = mod1_a(mod1_m((S[i]-'a'+1),p1_pow[N-i-1]),S1Hrev[i+1]);
                S2Hrev[i] = mod2_a(mod2_m((S[i]-'a'+1),p2_pow[N-i-1]),S2Hrev[i+1]);
            }
        }
        pii Hash(int l,int r){
            // if(l>r)return {0, 0}; // add if needed
            pii H;
            H.fi = mod1_m(mod1_s(S1Hash[r],(l ? S1Hash[l-1] : 0)),p1_powinv[l]);
            H.se = mod2_m(mod2_s(S2Hash[r],(l ? S2Hash[l-1] : 0)),p2_powinv[l]);
            return H;
        }
        pii Hashrev(int l,int r){
            // if(l>r)return {0, 0}; // add if needed
            pii H;
            H.fi = mod1_m(mod1_s(S1Hrev[l],S1Hrev[r+1]),p1_powinv[N-1-r]);
            H.se = mod2_m(mod2_s(S2Hrev[l],S2Hrev[r+1]),p2_powinv[N-1-r]);
            return H;
        }
        bool isPalindrome(int l,int r){
            pii H1 = Hash(l,r), H2 = Hashrev(l,r);
            return isEqual(H1, H2);
        }
    };
}

// Can Work with string upto 10^6 in > 1s
// Hashing::Build();  to precompute

void solve(){
    string s;
    cin >> s;
    
    Hashing::SHash hash(s);

    cout << hash.isPalindrome(0, 5) << '\n';

}