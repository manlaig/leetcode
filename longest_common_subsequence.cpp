#include <unordered_map>
#include <string>
using namespace std;

struct hash_pair 
{ 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

// Time limit exceeded on this recursive solution
int helper(const string& s1, const string& s2, int i1, int i2,
            unordered_map<pair<int,int>, int, hash_pair>& m)
{
    if(i1 == s1.size() || i2 == s2.size())
        return 0;
    
    auto p = make_pair(i1,i2);
    if(m.find(p) != m.cend())
        return m[p];
    
    if(s1[i1] == s2[i2])
        m[p] = 1 + helper(s1, s2, i1+1, i2+1, m);
    else
        m[p] = max(max(helper(s1, s2, i1+1, i2, m),
                        helper(s1, s2, i1, i2+1, m)),
                    helper(s1,s2,i1+1,i2+1,m));
    return m[p];
}

int longestCommonSubsequence(string text1, string text2)
{
    unordered_map<pair<int,int>, int, hash_pair> m;
    return helper(text1, text2, 0, 0, m);
}

int main()
{

}