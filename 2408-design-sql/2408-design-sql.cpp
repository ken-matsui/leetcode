class SQL {
public:
    unordered_map<string, vector<vector<string>>> data;

    SQL(vector<string>& names, vector<int>& columns) {}

    void insertRow(string name, vector<string> row) {
        data[name].emplace_back(row);
    }

    void deleteRow(string name, int rowId) {
        data[name][rowId - 1].clear();
    }

    string selectCell(string name, int rowId, int columnId) {
        return data[name][rowId - 1][columnId - 1];
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * obj->insertRow(name,row);
 * obj->deleteRow(name,rowId);
 * string param_3 = obj->selectCell(name,rowId,columnId);
 */
