import sys
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        ans=0
        diff=sys.maxsize
        n=len(nums)
        for i in range(0,n-2):
            j=i+1
            k=n-1
            while j<k:
                sum1=nums[i]+nums[j]+nums[k]
                if sum1==target:
                    return target
                elif sum1>target:
                    k-=1
                else:
                    j+=1
                
                if diff>abs(sum1-target):
                    ans=sum1
                    diff=abs(sum1-target)
        return ans
                
        
