
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vp;
typedef vector<long long int> vll;
typedef vector<char> vc;
typedef long double ld;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _ % MOD
#define __ %= MOD

#define fori(i, n) for (int i = 0; i < (n); ++i)
#define fora(i, a, n) for (int i = a; i <= (n); ++i)
#define ford(i, a, n) for (int i = a; i >= (n); --i)

struct Trie
{
    unordered_map<char, Trie *> leaves;
    vector<string> matched_words;
};

void insertTrie(Trie *root, string word)
{
    for (const char &c : word)
    {
        if (root->leaves.find(c) == root->leaves.end())
            root->leaves[c] = new Trie();
        root = root->leaves[c];

        // Add the current word as suggestion if we dont have enough suggestions
        if (root->matched_words.size() < 3)
            root->matched_words.emplace_back(word);
    }
}

vector<vector<string>> suggestionTrie(vector<string> &products, string searchWord)
{
    vector<vector<string>> result;
    sort(begin(products), end(products));
    // Create the Trie, since the words are sorted
    // so the suggestions are also lexographically sorted
    Trie *root = new Trie();

    fori(i, int(products.size()))
    {
        insertTrie(root, products[i]);
    }

    string prefix = "";
    for (const auto &ch : searchWord)
    {
        auto it = root->leaves.find(ch);
        if (it != root->leaves.end())
        {
            root = it->second;
        } else {
            break;
        }
        fori(i, int(root->matched_words.size())) {
            cout << ch << "--" << root->matched_words[i] << endl;
        }
        result.push_back(root->matched_words);
    }

    return result;
}

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        return suggestionTrie(products, searchWord);
    }
};