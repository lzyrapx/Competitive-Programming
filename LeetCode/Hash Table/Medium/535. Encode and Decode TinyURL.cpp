class Solution {
public:
    map<string,string>mp;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) { // 加密(弱)
        string url = to_string(mp.size());
        mp[url] = longUrl;
        return url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) { // 解密(弱)
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));