// Backtracking 4^n solution TLE
class Solution {
public:
    bool util(vector<int>& matchsticks,int s1,int s2,int s3,int s4,int i,int side)
    {
        if(i==matchsticks.size()&&s1==side&&s2==side&&s3==side&&s4==side)return true;
        if(i==matchsticks.size())return false;
        bool choice1=false;
        bool choice2=false;
        bool choice3=false;
        bool choice4=false;
        if(s1+matchsticks[i]<=side) choice1=util(matchsticks,s1+matchsticks[i],s2,s3,s4,i+1,side);
        if(s2+matchsticks[i]<=side) choice2=util(matchsticks,s1,s2+matchsticks[i],s3,s4,i+1,side);
        if(s3+matchsticks[i]<=side) choice3=util(matchsticks,s1,s2,s3+matchsticks[i],s4,i+1,side);
        if(s4+matchsticks[i]<=side) choice4=util(matchsticks,s1,s2,s3,s4+matchsticks[i],i+1,side);
        return choice1||choice2||choice3||choice4;
    }    
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        if(sum%4!=0)return false;
        for(auto i:matchsticks){
            sum+=i;   
        }
        sum=sum/4;
        return util(matchsticks,0,0,0,0,0,sum);
    }
};
//
//DFS +visited array
//DFS +visited
class Solution {
public:
    bool util(vector<int>& matchsticks,vector<int>&visited,int i,int k,int sum,int target)
    {
        if(k==0)return true;
        if(sum==target)return util(matchsticks,visited,0,k-1,0,target);
        for(int j=i;j<matchsticks.size();j++)
        {
            if(visited[j]||sum+matchsticks[j]>target)continue;
            visited[j]=true;
            if(util(matchsticks,visited,j+1,k,sum+matchsticks[j],target))return true;
            visited[j]=false;
        }
        return false;
    }    
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;        
        for(auto i:matchsticks){
            sum+=i;   
        }
        if(sum%4!=0)return false;
        sum=sum/4;
        vector<int>visited(matchsticks.size(),0);
        return util(matchsticks,visited,0,4,0,sum);
    }
};
