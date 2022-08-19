if (!A)
    return 0;
return (A->left ? abs((A->val) - (A->left->val)) < 2 : 0) + (A->right ? abs((A->val) - (A->right->val)) < 2 : 0) + consecutiveNodes(A->left) + consecutiveNodes(A->right);