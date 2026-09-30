class Solution {
    bool iscount(vector<int>& count,int& k, int& max_char, int& max_freq, int len) {
        max_freq = 0;
        for(int i=0;i<26;i++) {
            if(count[i] > max_freq) {
                max_freq = count[i];
                max_char = i;
            }
        }
        if(k >= len-max_freq) return false;
        return true;
    }

    void move_ptr(string& s, vector<int>& count,int& k, int& max_char, int& max_freq, int& l, int r) {
        while(l < r) {
            count[s[l]-'A']--;
            l++;
            if(!iscount(count,k,max_char,max_freq,r-l+1))
                break;
        }
    }
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ptr = 0, ans = 0;
        vector<int> count(26,0);
        for(int i=0;i<n;i++) {
            count[s[i]-'A']++;
            int max_char, max_freq, len;
            len = i-ptr+1;
            cout<<ptr<<endl;
            if(iscount(count,k,max_char, max_freq,len)) {
                //cout<<i<<endl;
                move_ptr(s,count,k,max_char,max_freq,ptr,i);
            }
            ans = max(ans,i-ptr+1);
        }
        return ans;
    }
};
