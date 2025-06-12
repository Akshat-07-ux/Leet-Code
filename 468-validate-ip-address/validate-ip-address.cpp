class Solution {
public:
    string validIPAddress(string queryIP) {
        if (queryIP.find('.') != string::npos) {
            if (isValidIPv4(queryIP)) return "IPv4";
        } else if (queryIP.find(':') != string::npos) {
            if (isValidIPv6(queryIP)) return "IPv6";
        }
        return "Neither";
    }

private:
    bool isValidIPv4(string ip) {
        vector<string> parts = customSplit(ip, '.');
        if (parts.size() != 4) return false;

        for (const string& part : parts) {
            if (part.empty() || part.size() > 3) return false;
            if (part[0] == '0' && part.size() > 1) return false;
            for (char ch : part) {
                if (!isdigit(ch)) return false;
            }
            int num = stoi(part);
            if (num < 0 || num > 255) return false;
        }
        return true;
    }

    bool isValidIPv6(string ip) {
        vector<string> parts = customSplit(ip, ':');
        if (parts.size() != 8) return false;

        for (const string& part : parts) {
            if (part.empty() || part.size() > 4) return false;
            for (char ch : part) {
                if (!isxdigit(ch)) return false;
            }
        }
        return true;
    }

    vector<string> customSplit(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        int start = 0;
        int end = 0;

        while (end <= s.size()) {
            if (end == s.size() || s[end] == delimiter) {
                tokens.push_back(s.substr(start, end - start));
                start = end + 1;
            }
            end++;
        }

        return tokens;
    }
};