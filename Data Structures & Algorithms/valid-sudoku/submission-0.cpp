class Solution {
    struct PairHash{
        template<class T1, class T2>
        size_t operator()(const pair<T1, T2>& p)const{
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row;
        for(int i = 0; i < board.size(); i++){
            row.clear();
            for(int j = 0; j < board.size(); j++){
                if(board[i][j] != '.'){
                    if(row.count(board[i][j])) return false;
                    row.insert(board[i][j]);
                }
            }
        }
        unordered_set<char> col;
        for(int i = 0; i < board.size(); i++){
            col.clear();
            for(int j = 0; j < board.size(); j++){
                if(board[j][i] != '.'){
                    if(col.count(board[j][i])) return false;
                    col.insert(board[j][i]);
                }
            }
        }
        unordered_map<pair<int, int>, unordered_set<char>, PairHash>mapbox;
        for(int i= 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                if(board[i][j] != '.'){
                    pair<int, int>boxkey{i/3, j/3};
                    if(mapbox[boxkey].count(board[i][j])) return false;
                    mapbox[boxkey].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};
