/*
https://leetcode.com/problems/encode-and-decode-tinyurl/

*/
class Solution {
private:
    const string charset="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    unordered_map<string,string> url_code,code_url;
    random_device rd;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code="";
        if(!url_code.count(longUrl)){
            for(int i=0;i<6;i++) code+=string(1,charset[rd()%charset.size()]);
            url_code[longUrl]=code;
            code_url[code]=longUrl;
        }
        else code=url_code[longUrl];
        return "http://tinyurl.com/"+code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if(shortUrl.size()!=25||!code_url.count(shortUrl.substr(19,6))) return "";
        return code_url[shortUrl.substr(19,6)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
