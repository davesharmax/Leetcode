class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
                if(points.empty()) return 0;
        
        
        sort(points.begin(),points.end(),[](auto a,auto b){
            return a[1] < b[1]; 
        });
        
        int count = 0; 
        int end = points[0][1]; 

        for(int i = 1; i < points.size(); i++) {
     
            
            if(points[i][0] <= end) {
                continue;
            } else { 
                count++;
                end = points[i][1];
            }
        }
        count++; 
        return count; 
    }
};