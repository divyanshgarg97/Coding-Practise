struct mycomp{
    bool operator()(pair<int,int> p1,pair<int,int> p2){
        if( p1.second < p2.second)
            return true;
        return false;
    }
};
struct mycomp1{
    bool operator()(vector<int> & a, vector<int> & b ) {
        if( a[1] < b[1])
            return true;
        return false;
    }
};
class Solution {
public:
    /**
     * @param points: a 2D array
     * @return: the minimum number of arrows that must be shot to burst all balloons
    */
    int findMinArrowShots(vector<vector<int>> &points) {
        // Write your code here
        //sort according to the end of the points
        //vector<pair<int,int> > store;
        int n = points.size();
        if( n == 0 )
            return 0 ; 
        //for( int i =0 ; i < n;i++ ) {
        //    store.push_back({points[i][0],points[i][1]});
        //}
        //sort(store.begin(),store.end(),mycomp());
        sort(points.begin(),points.end(),mycomp1());
        int ans =1;
        int leftend = points[0][1];
        for(int i = 0; i < n;i++ ) {
            if( points[i][0] > leftend){
                ans ++ ; 
                leftend = points[i][1];
            }
        }
        return ans;
    }
};