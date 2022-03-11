class Solution(object):
    def toHex(self, num):
        x=""
        if num==0:
            return "0"
        
        if num<0:
            num=num+pow(2,32)
        
        while num>0:
            a=num%16
            if a>9:
                x+=chr(a+87)
            else :
                x+=str(a)
            num=num//16 
        
        return x[::-1]

