class Solution {
public:
    string minimizeStringValue(string s) {
        int arr[26]={0};
        vector<int>index;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='?'){
                arr[s[i]-'a']+=1;
            }
            else{
                index.push_back(i);
            }
        }
        //vector<int> index; store the index value
        for(int j=0;j<index.size();j++){
            int minfreq=0,freq=INT_MAX;
            for(int i=0;i<26;i++){
                if (arr[i] < freq) {
                    freq = arr[i];
                    minfreq = i; //used to store the index.
                }
            }
            temp+='a'+minfreq;
            arr[minfreq]++;
        }        
        sort(temp.begin(),temp.end());
        for(int i=0;i<index.size();i++){
            s[index[i]]=temp[i];
        }
        return s;
    }

};