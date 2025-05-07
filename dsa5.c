void dfs(char** grid, int gridSize, int* gridColSize, int i, int j) {
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize[i] || grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0'; 
    dfs(grid, gridSize, gridColSize, i + 1, j);
    dfs(grid, gridSize, gridColSize, i - 1, j);
    dfs(grid, gridSize, gridColSize, i, j + 1);
    dfs(grid, gridSize, gridColSize, i, j - 1);
}
int numIslands(char** grid, int gridSize, int* gridColSize) {int count=0;
    for(int i=0;i<gridSize;i++){for(int j=0;j<gridColSize[i];j++){
                    if(grid[i][j]=='1'){count+=1;}  dfs(grid, gridSize, gridColSize, i, j);           }    }
                    return count;
}

typedef struct TreeNode NODE;
 bool isMirror(NODE* rt1, NODE* rt2) {
    if (rt1 == NULL && rt2 == NULL)
        return true;
    else if (rt1 == NULL || rt2 == NULL)
        return false;
    return (rt1->val == rt2->val) && isMirror(rt1->left, rt2->right) &&
           isMirror(rt1->right, rt2->left);
}
bool isSymmetric(struct TreeNode* root) {
    return isMirror(root->left, root->right);
}
    
