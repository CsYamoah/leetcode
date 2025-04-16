int i=0;
int arr[101]={0};
void inorder(struct TreeNode* s)
{
    if(s!=NULL)
    {
        inorder(s->left);
        arr[i++]=s->val;
        inorder(s->right);
    }
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    inorder(root);
    int* ans=malloc(i*sizeof(int));
    for(int j=0;j<i;j++) ans[j]=arr[j];
    *(returnSize)=i;
    i=0;
    return ans;
}
 void preOrder(struct TreeNode* root, int *arr, int *returnSize){
    if(root!=NULL){
        arr[(*returnSize)++]=root->val;
        preOrder(root->left, arr, returnSize);
        preOrder(root->right, arr, returnSize);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr=(int*)malloc(sizeof(int)*100);
    *returnSize=0;
    preOrder(root, arr, returnSize);
    return arr;
    free(arr);
}
