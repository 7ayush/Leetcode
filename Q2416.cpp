//TLE
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int>scores;
        unordered_map<string,int>mp;
        for(auto word:words)
        {
            for(int i=1;i<=word.size();i++)
            {
                mp[word.substr(0,i)]++;
            }
        }
        for(int i=0;i<words.size();i++)
        {
            int ans=0;
            for(int j=1;j<=words[i].size();j++)
            {
                ans+=mp[words[i].substr(0,j)];
            }
            scores.push_back(ans);
        }
        return scores;
    }
};

class Solution {
public:
	struct Trie{
		vector<Trie*> child;
		int score;
		Trie() {
			child=vector<Trie*>(26);
			score=0;
		}
	};

	void insert(Trie* root,string str) {
		Trie* cur=root;
		for(int i=0;i<str.length();i++) {
			if(!cur->child[str[i]-'a']) {
				cur->child[str[i]-'a']=new Trie();
			}
			cur=cur->child[str[i]-'a'];
			cur->score++;
		}
	}
	vector<int> res;
	void fndScore(Trie* root,string str) {
		Trie* cur=root;
		int sum=0;
		for(int i=0;i<str.length();i++) {
			cur=cur->child[str[i]-'a'];
			sum+=cur->score;
		}
		res.push_back(sum);
	}

	vector<int> sumPrefixScores(vector<string>& a) {
		Trie* root=new Trie();
		for(int i=0;i<a.size();i++) insert(root,a[i]);
		for(int i=0;i<a.size();i++) fndScore(root,a[i]);
		return res;
	}
};
class Trie
{
    public:
    int score;
    vector<Trie*>nodes;
    Trie(){
        score=0;
        nodes=vector<Trie*>(26);
    }
};
class Solution {
public:
    
    Trie *root;
    
    void insert(string word)
    {
        Trie *temp=root;
        for(char c:word)
        {
            if(temp->nodes[c-'a']==NULL)
            {
                temp->nodes[c-'a']=new Trie();
            }
            temp=temp->nodes[c-'a'];
            temp->score++;
        }
    }
    int findScore(string word)
    {
        Trie *temp=root;
        int ans=0;
        for(char c:word)
        {
            temp=temp->nodes[c-'a'];
            ans+=temp->score;
        }
        return ans;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        root=new Trie();
        vector<int>ans;        
        for(auto word:words)
        {
            insert(word);
        }
        for(auto word:words)
        {
            ans.push_back(findScore(word));
        }
        return ans;
    }
};
