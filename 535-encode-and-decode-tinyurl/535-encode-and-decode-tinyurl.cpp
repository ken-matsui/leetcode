class Solution {
public:
    string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    unordered_map<string, string> m;

    random_device rd;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        mt19937 generator(rd());
        std::shuffle(str.begin(), str.end(), generator);
        const string encoded = str.substr(0, 6);
        m[encoded] = longUrl;
        return "http://tinyurl.com/" + encoded;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        const string encoded = shortUrl.substr(19, shortUrl.size());
        return m[encoded];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));