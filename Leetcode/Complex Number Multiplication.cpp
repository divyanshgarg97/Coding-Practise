class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        //https://www.geeksforgeeks.org/stringstream-c-applications/
        stringstream s1(a), s2(b), ans;
        int x ,y ,z , w ; 
        char character; 
        s1 >> x >> character >> y >> character; // >> is used to extract content from stringstream 
        s2 >> z >> character >> w >> character; 
        ans << (x * z - y*w) << "+" << (y * z + x * w) << "i"; // << used to add content in the stringstream
        return ans.str(); // converting a string stream to string
    }
};