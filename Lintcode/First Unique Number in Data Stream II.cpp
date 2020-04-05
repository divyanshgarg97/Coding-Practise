class DataStream {
public:
    vector<int> v;
    unordered_map<int,int>ump;
    DataStream(){
        // do intialization if necessary
    }
    /**
     * @param num: next number in stream
     * @return: nothing
     */
    void add(int num) {
        // write your code here
        if(ump[num] == 0)
            v.push_back(num);
        ump[num]++;
    }
    /**
     * @return: the first unique number in stream
     */
    int firstUnique() {
        // write your code here
        for( int i = 0  ; i < v.size() ;i++ ){
            if( ump[v[i]] ==1 )
                return v[i];
        }
        return -1;
    }
};