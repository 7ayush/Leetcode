class MyCalendar {
public:
    vector<pair<int,int>> p;
    MyCalendar() 
    {

    }
    bool book(int s, int e) 
    {
        for(auto x:p)
        {
            if(x.first<e && x.second>s) //33
                return false;
        }
        p.push_back({s,e});
        return true;
    }
};

