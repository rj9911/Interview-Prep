class Solution {
public:
    string maximumBinaryString(string binary) {
        int cnt = 0;
        int n = binary.size();
        for(int i=0; i<n; i++){
            cnt += binary[i]=='0' ? 1 : 0;
        }
        if(cnt<=1){
            return binary;
        }
        int index = -1;
        for(int i=0; i<n; i++){
            if(binary[i]=='0' && index==-1){
                index = i;
            }
            binary[i] = '1';
        }
        // if(index==-1){
        //     return binary;
        // }
        binary[index+cnt-1] = '0';
        return binary;
    }

};