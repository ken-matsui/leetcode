class Logger {
    unordered_map<string, int> restriction;
    
public:
    Logger() {}
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (restriction.find(message) == restriction.end()) {
            restriction[message] = timestamp + 10;
            return true;
        } else {
            int rest = restriction[message];
            if (timestamp >= rest) {
                restriction[message] = timestamp + 10;
                return true;
            } else {
                return false;
            }
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */