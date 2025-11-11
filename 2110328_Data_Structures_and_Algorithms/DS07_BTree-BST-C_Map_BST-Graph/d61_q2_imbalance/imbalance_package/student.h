// Your code here
KeyT getMostImbalanceNodeOfSubtree(node *n, int &balanceVal, int &height)
{
    if (n == NULL)
    {
        balanceVal = -1;
        height = -1;
        return 0;
    }

    int balL = 0, balR = 0, heightL = 0, heightR = 0;

    KeyT valL = getMostImbalanceNodeOfSubtree(n->left, balL, heightL);
    KeyT valR = getMostImbalanceNodeOfSubtree(n->right, balR, heightR);

    KeyT valSelf = n->data.first;
    balanceVal = heightL > heightR ? heightL - heightR : heightR - heightL;
    height = heightL > heightR ? heightL + 1 : heightR + 1;

    if (balL >= balanceVal && balL >= balR)
    {
        balanceVal = balL;
        valSelf = valL;
    }
    else if (balR > balanceVal && balR > balL)
    {
        balanceVal = balR;
        valSelf = valR;
    }

    return valSelf;
}

KeyT getValueOfMostImbalanceNode()
{
    // Your code here
    int balanceVal = 0, height = 0;
    return getMostImbalanceNodeOfSubtree(mRoot, balanceVal, height);
}
