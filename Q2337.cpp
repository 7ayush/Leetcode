class Solution {
public:
    bool checkFreq(string start,string target)
    {
        int a1=0,a2=0,a3=0,b1=0,b2=0,b3=0;
        for(int i=0;i<start.size();i++)
        {
            if(start[i]=='L')a1++;
            if(start[i]=='R')a2++;
            if(start[i]=='_')a3++;
            
            if(target[i]=='L')b1++;
            if(target[i]=='R')b2++;
            if(target[i]=='_')b3++;
            
        }
        return a1==b1&&a2==b2&&a3==b3;
    }
    bool canChange(string start, string target) {
        if(checkFreq(start,target)==false)return false;
        
        vector<int>prevR;
        vector<int>afterL;
        
        vector<int>prevR1;
        vector<int>afterL1;
        
        int count1=0,count2=0;
        for(int i=0;i<start.size();i++)
        {
            if(start[i]=='R')count1++;
            if(start[i]=='L')prevR.push_back(count1);
            
            if(target[i]=='R')count2++;
            if(target[i]=='L')prevR1.push_back(count2);
            
        }
        for(int i=0;i<prevR.size();i++)
        {
            if(prevR1[i]!=prevR[i])return false;
        }
        
        count1=0;count2=0;
        
        for(int i=start.size()-1;i>=0;i--)
        {
            if(start[i]=='L')count1++;
            if(start[i]=='R')afterL.push_back(count1);
            
            if(target[i]=='L')count2++;
            if(target[i]=='R')afterL1.push_back(count2);            
        }
        for(int i=0;i<afterL1.size();i++)
        {
            if(afterL1[i]!=afterL[i])return false;
        }
        
    
        vector<int>prevDashesStart;
        vector<int>afterDashesStart;
        vector<int>prevDashesTarget;
        vector<int>afterDashesTarget;
        
        count1=0;count2=0;
        for(int i=0;i<start.size();i++)
        {
            if(start[i]=='_')count1++;
            if(start[i]=='L')prevDashesStart.push_back(count1);
            
            if(target[i]=='_')count2++;
            if(target[i]=='L')prevDashesTarget.push_back(count2); 
        }
        for(int i=0;i<prevDashesStart.size();i++)
        {
            if(prevDashesStart[i]<prevDashesTarget[i])return false;
        }
        count1=0;count2=0;
        for(int i=start.size()-1;i>=0;i--)
        {
            if(start[i]=='_')count1++;
            if(start[i]=='R')afterDashesStart.push_back(count1); 
            
            if(target[i]=='_')count2++;
            if(target[i]=='R')afterDashesTarget.push_back(count2); 
        }
        
        for(int i=0;i<afterDashesTarget.size();i++)
        {
            if(afterDashesStart[i]<afterDashesTarget[i])return false;
        }
        
        return true;        
    }
};
