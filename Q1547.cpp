class Solution {
public:
    int util(vector<int>& cuts,int i,int j,vector<vector<int>>&dp)
    {
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini=INT_MAX;
        for(int ind=i;ind<=j;ind++)
        {
            int val=cuts[j+1]-cuts[i-1]+util(cuts,i,ind-1,dp)+util(cuts,ind+1,j,dp);
            mini=min(mini,val);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int len = cuts.size(); 
        sort(cuts.begin(), cuts.end()); 
        cuts.push_back(n);         
        cuts.insert(cuts.begin(), 0);
        vector<vector<int>>dp(len+1,vector<int>(len+1,-1));
        return util(cuts,1,len,dp);
    }
};




// invalid transaction
struct Transaction
{
  int id;
  int time;
  int amount;
  string city;
  string full;

  Transaction(int id, int time, int amount, string city, string &full) : id(id), time(time), amount(amount), city(city), full(full)
  {
  }

};

class Solution
{
private:
  vector<string> SplitStrings(const string &str)
  {
    vector<string> res;
    stringstream ss(str);
    string curr;
    while (std::getline(ss, curr, ','))
    {
      res.push_back(curr);
    }
    return res;
  }

public:
  vector<string> invalidTransactions(vector<string> &transactions)
  {

    unordered_map<string, vector<Transaction>> name2transactions;
    vector<string> res;

    int n = transactions.size();
    bool hasReturn[n];
    memset(hasReturn, 0, sizeof(hasReturn));

    for (int i = 0; i < n; ++i)
    {
      vector<string> strs = SplitStrings(transactions[i]);
      string name = strs[0];
      int time = stoi(strs[1]);
      int amount = stoi(strs[2]);
      string city = strs[3];

      if (amount > 1000)
      {
        hasReturn[i] = true;
        res.push_back(transactions[i]);
      }

      for (Transaction &t : name2transactions[name])
      {
       
        if (abs(time - t.time) <= 60 && city != t.city)
        {
  
          if (!hasReturn[t.id])
          {
            hasReturn[t.id] = true;
            res.push_back(t.full);
          }
          if (!hasReturn[i])
          {
            hasReturn[i] = true;
            res.push_back(transactions[i]);
          }
        }
      }

      name2transactions[name].emplace_back(Transaction(i, time, amount, city, transactions[i]));
    }

    return res;
  }
};

