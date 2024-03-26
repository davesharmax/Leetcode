class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> v;int res = 0;
        int c = 1;
        int n = s.size();
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                v.push_back(c);
                c=1;
            }
            else c++;
        }
        v.push_back(c);
        
        for(int i=0;i<v.size()-1;i++){
            res+= min(v[i],v[i+1]);
        }
        return res;
    }
};