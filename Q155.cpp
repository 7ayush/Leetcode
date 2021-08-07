class MinStack {
public:

    stack<long long int>s;
    long long int min;

    void push(long long int val) 
    {
        if(s.empty())
        {
            min=val;
            s.push(val);
        }
          else if(val<=min)
          {
            s.push(2*val-min);
            min=val;
          }
        else s.push(val);
    }

    void pop() 
    {
        long long int t=s.top();
        int res=t;
            if(t<=min)
            {
              res=min;
              min=2*min-t;
              s.pop();
            }
          else s.pop();
    }

    int top() 
    {
        long long int t=s.top();
        return(t<=min)? min : t;
    }

    int getMin() {
        return min;
    }
};
