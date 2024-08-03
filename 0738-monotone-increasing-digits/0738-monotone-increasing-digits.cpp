class Solution {
public:
    int monotoneIncreasingDigits(int n) 
    {
        long long num=n;
        if(num==0) return 0;
        if(num<=10)return 9;
        priority_queue<long long>pq;
        for(int i=1; i<=9; i++)
        {
            pq.push(i);
        }
        
        long long ans=0;
        int s= to_string(num).size();
        int c=0;
        while(!pq.empty())
        {
            long long it= pq.top();
            pq.pop();
            c++;
            ans=max(ans, it);
            if(to_string(it).size()==s)
            {
                break;
            }
            int last= it%10;
            for(int i=last; i<=9; i++)
            {
                if(((1ll*it*10) +i) <=num) pq.push(it*10+i);
            }
        }
        
        return (int)ans;
        
        
    }

};