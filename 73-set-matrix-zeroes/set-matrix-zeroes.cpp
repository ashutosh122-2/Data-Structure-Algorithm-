class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size(); // row length 
        int n = matrix[0].size(); // column length 
        
        // ye dono marker hai jo ki first row or first column ka data rakhe hai initially inko false pr set kia hai 

        bool firstRow = false;
        bool firstCol = false;

        // check first row
        for(int j = 0; j < n; j++)
        {
            if(matrix[0][j] == 0)
                firstRow = true;
        }

        // check first column
        for(int i = 0; i < m; i++)
        {
            if(matrix[i][0] == 0)
                firstCol = true;
        }

        // mark rows and columns
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // update matrix
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // first row
        //ab first row or first column ko check kro agat vo true hai to matlab ki firstrow ya column me bhi zero hai to usko poora zero set kr do ..
        if(firstRow)
        {
            for(int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }

        // first column
        if(firstCol)
        {
            for(int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
    }
};