//Hashmap
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
public:
  vector<string> invalidTransactions(vector<string> &t)
  {
    int n = t.size();
    map<string, map<string, vector<pair<int, int>>>> all; 
    map<string, vector<pair<int, int>>> p;            

    vector<string> peo(n);
    vector<int> ti(n);
    vector<int> am(n);
    vector<string> ci(n);
    for (int index = 0; index < n; ++index)
    {
      auto &str = t[index];
      int i = 0;
      while (str[i] != ',')
        ++i;
      int j = i + 1;
      while (str[j] != ',')
        ++j;
      int k = j + 1;
      while (str[k] != ',')
        ++k;
      const string &name = str.substr(0, i);
      int time = stoi(str.substr(i + 1, j - i - 1));
      int amount = stoi(str.substr(j + 1, k - j - 1));
      const string &city = str.substr(k + 1);

      peo[index] = name;
      ti[index] = time;
      am[index] = amount;
      ci[index] = city;
      all[name][city].push_back({time, amount});
      p[name].push_back({time, amount});
    }

    for (auto &a : all)
      for (auto &vec : a.second)
        sort(vec.second.begin(), vec.second.end());
    for (auto &a : p)
      sort(a.second.begin(), a.second.end());

    vector<string> res;
    for (int i = 0; i < n; ++i)
    {
      if (am[i] > 1000)
      {
        res.push_back(t[i]);
        continue;
      }
      const string &name = peo[i];
      int time = ti[i];
      int amount = am[i];
      const string &city = ci[i];

      pair<int, int> l = {time - 60, -1};
      pair<int, int> u = {time + 60, 1000};
      int cnt = upper_bound(p[name].begin(), p[name].end(), u) - lower_bound(p[name].begin(), p[name].end(), l);
      int cnt_same = upper_bound(all[name][city].begin(), all[name][city].end(), u) - lower_bound(all[name][city].begin(), all[name][city].end(), l);
      if (cnt - cnt_same > 0)
        res.push_back(t[i]);
    }
    return res;
  }
};
