class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans=0;
        for(int i=0;i<energy.size();i++)
        {
            if(initialEnergy<=energy[i])
            {
                ans+=energy[i]-initialEnergy+1;
                initialEnergy=1;
            }
            else
            {
                initialEnergy-=energy[i];
            }
            if(initialExperience<=experience[i])
            {
                ans+=experience[i]-initialExperience+1;                
                initialExperience=experience[i]+1;
            }                
            initialExperience+=experience[i];
            
        }
        return ans;
    }
};
