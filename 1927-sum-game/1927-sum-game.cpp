class Solution {
public:
    bool sumGame(string num) {
        int n=num.length();
        int mid=n/2;
        int fSum=0,lSum=0;
        int fqMark=0,lqMark=0;
        for(int i=0;i<n;i++){
            if(i<mid){
                if(isdigit(num[i]))
                    fSum+=num[i]-'0';
                else
                    fqMark++;
            }
            else{
                if(isdigit(num[i]))
                    lSum+=num[i]-'0';
                else
                    lqMark++;
            }
        }
        if((lqMark+fqMark)%2)
            return true; //Alice will win(odd question marks)

        int reqPoints=fSum-lSum;
        int unevenQMark=fqMark-lqMark;
        unevenQMark/=2;
        return reqPoints != -unevenQMark*9; //Alice can place 9 in half of the qMarks and win
    }

};