class ATM {
public:

    vector<int> mp;
    vector<int> cnt;
    ATM() {
        mp.resize(5, 0);
        cnt.resize(5, 0);
        mp[0] = 20;
        mp[1] = 50;
        mp[2] = 100;
        mp[3] = 200;
        mp[4] = 500;
    }
    
    void deposit(vector<int> b) {
        for(int i = 0;i<b.size();i++) {
            cnt[i] += b[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        for(int i = 0;i<5;i++) {
            cout<<cnt[i]<<" ";
        }cout<<endl;
        vector<int> ans(5, 0);
        for(int i = 4;i >= 0;i--) {
            if(amount < mp[i]) continue;
            else {
                int usedcnt = min(cnt[i], (int)(amount / mp[i]));
                amount -= usedcnt * mp[i];
                cnt[i] -= usedcnt;
                ans[i] = usedcnt;
            }
        }
        if(amount > 0){
            for(int i = 0;i<5;i++) {
                cnt[i] += ans[i];
            }
            return {-1};
        }
        else return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */