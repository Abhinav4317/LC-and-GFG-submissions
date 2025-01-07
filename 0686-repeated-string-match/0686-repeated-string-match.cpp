long long power(long long x, long long y, long long p) {
    long long result = 1;
    for (; y; y >>= 1, x = x * x % p) {
        if (y & 1) {
            result = result * x % p;
        }
    }
    return result;
}

long long inverse(long long x, long long p) {
    return power(x, p - 2, p);
}

class Hash {
private:
    int length;
    const int mod1 = 1e9 + 7, mod2 = 1e9 + 9;
    const int p1 = 31, p2 = 37;
    vector<int> hash1, hash2;
    pair<int, int> hash_pair;

public:
    vector<int> inv_pow1, inv_pow2;
    int inv_size = 1;

    Hash() {}

    Hash(const string& s) {
        length = s.size();
        hash1.resize(length);
        hash2.resize(length);

        int h1 = 0, h2 = 0;
        long long p_pow1 = 1, p_pow2 = 1;
        for (int i = 0; i < length; i++) {
            h1 = (h1 + (s[i] - 'a' + 1) * p_pow1) % mod1;
            h2 = (h2 + (s[i] - 'a' + 1) * p_pow2) % mod2;
            p_pow1 = (p_pow1 * p1) % mod1;
            p_pow2 = (p_pow2 * p2) % mod2;
            hash1[i] = h1;
            hash2[i] = h2;
        }
        hash_pair = make_pair(h1, h2);

        if (inv_size < length) {
            for (; inv_size < length; inv_size <<= 1);

            inv_pow1.resize(inv_size, -1);
            inv_pow2.resize(inv_size, -1);

            inv_pow1[inv_size - 1] = inverse(power(p1, inv_size - 1, mod1), mod1);
            inv_pow2[inv_size - 1] = inverse(power(p2, inv_size - 1, mod2), mod2);

            for (int i = inv_size - 2; i >= 0 && inv_pow1[i] == -1; i--) {
                inv_pow1[i] = (1LL * inv_pow1[i + 1] * p1) % mod1;
                inv_pow2[i] = (1LL * inv_pow2[i + 1] * p2) % mod2;
            }
        }
    }

    int size() {
        return length;
    }

    pair<int, int> substr(const int l, const int r) {
        if (l == 0) {
            return {hash1[r], hash2[r]};
        }
        int temp1 = hash1[r] - hash1[l - 1];
        int temp2 = hash2[r] - hash2[l - 1];
        temp1 += (temp1 < 0 ? mod1 : 0);
        temp2 += (temp2 < 0 ? mod2 : 0);
        temp1 = (temp1 * 1LL * inv_pow1[l]) % mod1;
        temp2 = (temp2 * 1LL * inv_pow2[l]) % mod2;
        return {temp1, temp2};
    }
};

bool r_k_algo(string text, string pattern)
{
    //code here.
    if(pattern==""||text=="") return false;
    Hash h1(text);
    Hash h2(pattern);
    vector<int> ans;
    int n1 = h1.size(), n2 = h2.size();
    pair<int, int> patHash = h2.substr(0, n2 - 1);
    for (int i = 0; i <= (n1 - n2); i++) {
        int l = i, r = i + n2 - 1;
        pair<int, int> txtHash = h1.substr(l, r);
        if (txtHash.first == patHash.first && txtHash.second == patHash.second) {
            return true;
        }
    }
    return false;
}
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        //matching can be easily done using rabin karp but question lies as to how many do
        //you need to repeat string a and match it with b?
        //answer is simple=>firstly repeat it as many times till a.size()>=b.size()
        //then repeat it once more
        //if still no match,then no further repititions would produce any match
        if(a==b) return 1;
        int cnt=1;
        string src=a;
        while(src.size()<b.size()){
            src+=a;cnt++;
        }
        if(src==b) return cnt;
        if(r_k_algo(src,b)) return cnt;
        if(r_k_algo(src+a,b)) return cnt+1;
        return -1;
    }
};