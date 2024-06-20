// look at the last step for getting true

class Solution{
public:
    int countWays(int n, string s){
        string tf = "";
        string op = "";
        
        for(int i = 0; i < n; i++){
            if(s[i] == '&' || s[i] == '|' || s[i] == '^') op.push_back(s[i]);
            else tf.push_back(s[i]);
        }
        
        int size = tf.size();
        
        vector<vector<int>> dpt(size, vector<int>(size, 0));
        vector<vector<int>> dpf(size, vector<int>(size, 0));
        
        for(int m = 0; m < size; m++){
            for(int i = 0, j = m; j < size; i++, j++){
                if(i == j){
                    dpt[i][j] = (tf[i] == 'T');
                    dpf[i][j] = (tf[i] == 'F');
                }
                else{
                   for(int k = i; k < j; k++){
                       char oper = op[k];
                       if(oper == '&'){
                           dpt[i][j] += dpt[i][k] * dpt[k+1][j];
                           dpf[i][j] += dpf[i][k] * dpf[k+1][j] + dpt[i][k] * dpf[k+1][j] + dpf[i][k] * dpt[k+1][j];
                       }
                       else if(oper == '|'){
                           dpt[i][j] += dpt[i][k] * dpt[k+1][j] + dpt[i][k] * dpf[k+1][j] + dpf[i][k] * dpt[k+1][j];
                           dpf[i][j] += dpf[i][k] * dpf[k+1][j];
                       }
                       else{ // oper == '^'
                           dpt[i][j] += dpt[i][k] * dpf[k+1][j] + dpf[i][k] * dpt[k+1][j];
                           dpf[i][j] += dpt[i][k] * dpt[k+1][j] + dpf[i][k] * dpf[k+1][j];
                       }
                   }
                }
            }
        }
        
        return dpt[0][size-1];
    }
};