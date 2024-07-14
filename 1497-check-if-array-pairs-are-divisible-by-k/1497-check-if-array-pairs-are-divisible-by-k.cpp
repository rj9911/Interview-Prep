class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
            unordered_map<int, int> mp;  // rem => freq of remainder

    for(auto num: arr){
        int rem = (num%k + k)%k;
        mp[rem]++;
    }


    for(auto num: arr){
        int rem = num%k;

        if(rem == 0){
            int freq = mp[rem];
            if(freq%2 != 0){
                return false;
            }
        }
        else if(rem*2 == k){  // instead of writing rem=k/2, write 2*rem=k since rem==k/2 wont work when k=11
            int freq = mp[rem];
            if(freq%2 != 0){
                return false;
            }
        }
        else{
            int f1 = mp[rem];
            int f2 = mp[k-rem];
            if(f1 != f2){
                return false;
            }
        }
    }

    return true;

    }
};