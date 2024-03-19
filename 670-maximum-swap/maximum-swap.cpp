class Solution {
public:
    int maximumSwap(int num) {
        int i =0; 
        int j =1;
        int k =1;
        int f =-1;
        string nu = to_string(num);
        char m = nu[i]; 
        while(k>0&&i<nu.size()-1){
            if(m<=nu[j]){
                m=nu[j];
                while(nu[j]==nu[j+1]){
                    j++;
                 
                }if(nu[i]!=nu[j])f=j;
            }
            if(j==nu.size()-1){
                if(f!=-1){
                    swap(nu[f],nu[i]);
                    k--;
                }
                i++;
                m=nu[i];
                j=i+1;
            }else j++;

        } 
        int n = stoi(nu);
        return n;
    }
};