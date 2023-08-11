#include "AVLTree.h"

void AVLTree::printRoot()
{
    cout << root << endl;
}

bool AVLTree::isEmpty()
{
    return (root == NULL);
}

AVLTree::AVLTree()
{
    root = NULL;
}


ItemType* AVLTree::binarySearch(string username)
{
    return binarySearch(root, username);;
}

ItemType* AVLTree::binarySearch(BinaryNode* root, string userName) // so search in the AVL for Searching in the Table
{
    if (root == NULL)
    {
 
        return NULL;
    }

    else
    {
        if (root->item.viewEmailUserName() == userName)
        {
            ItemType* searched = &root->item;
            return searched;
        }
        else
        {
            if (root->item.viewEmailUserName() < userName)
            {
                return binarySearch(root->left, userName);
            }
            else
            {
                return binarySearch(root->right, userName);
            }
        }



    }
}

void AVLTree::insert(ItemType user)
{
    insert(root, user);
}

void AVLTree::insert(BinaryNode*& root, ItemType user)
{
    

    if (root == NULL)
    {
        BinaryNode* newNode = new BinaryNode;
        newNode->item = user;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
    }

    else
    {
        cout << "The root userName: " << root->item.viewEmailUserName() << endl;
        cout << "Inserting name: "<< user.viewEmailUserName() << endl;
        bool test = user.viewEmailUserName() < root->item.viewEmailUserName();
        cout << user.viewEmailUserName() << "lesser than " << test<< endl ;
        if (user.viewEmailUserName() < root->item.viewEmailUserName())
        {
            cout << "ADDed to left" << endl;
            insert(root->left, user);
        }
        else
        {
            insert(root->right, user);
        }

    }
}

void AVLTree::binaryRemove(string target)
{
    binaryRemove(root, target);
}

void AVLTree::binaryRemove(BinaryNode*& currentNode, string target)
{
    // traversal
    if (currentNode != NULL)
    {
        string currentNodeUsername = currentNode->item.viewEmailUserName();
        if (target < currentNodeUsername)
        {
            binaryRemove(currentNode->left, target);
        }
        else if (target > currentNodeUsername)
        {
            binaryRemove(currentNode->right, target);
        }
        else // base case
        {
            // case if the Node has no children
            if (currentNode->left == NULL && currentNode->right == NULL)
            {
                BinaryNode* tempNode = currentNode;
                currentNode = NULL;
                delete tempNode;
            }
            // node has 1 right child
            else if (currentNode->left == NULL)
            {
                BinaryNode* tempNode = currentNode;
                if (currentNode->item.viewEmailUserName() == target)
                {
                    if (tempNode == root)
                    {
                        root = tempNode->right;
                    }
                    else
                    {
                        tempNode = tempNode->right;
                    }
                    delete tempNode;
                }
            }
            // node has 1 left child
            else if (currentNode->right == NULL)
            {
                BinaryNode* tempNode = currentNode;
                if (currentNode->item.viewEmailUserName() == target)
                {
                    if (tempNode == root)
                    {
                        root = tempNode->left;
                    }
                    else
                    {
                        tempNode = tempNode->left;
                    }
                    delete tempNode;
                }
            }
            // the node has 2 children both L and R
            else
            {
                BinaryNode* successor = currentNode->left;
                while (successor->right != NULL) // helps me find most right node aka the largest no but not larger than current node
                {
                    successor = successor->right;
                }
                string item = successor->item.viewEmailUserName();
                binaryRemove(currentNode->left, item);
            }
        }
    }
}

int AVLTree::getHeights()
{
    return getHeights(root);
}

int AVLTree::getHeights(BinaryNode* t)
{
    if (t == NULL) {
        return -1; // Height of an empty node is -1
    }

    int leftHeight = getHeights(t->left);
    int rightHeight = getHeights(t->right);

    return max(leftHeight, rightHeight) + 1;
}


bool AVLTree::isBalanced()
{
    return isBalanced(root);
}

bool AVLTree::isBalanced(BinaryNode* t)
{
    if (isEmpty())
    {
        return true;
    }

    int rootNodeLeftHeight = getHeights(t->left);
    int rootNodeRightHeight = getHeights(t->right);

    if ((abs(rootNodeLeftHeight - rootNodeRightHeight) <= 1 ) && isBalanced(t->left) && isBalanced(t->right)) // if its not balanced
    {
        return true;  
    }
    else
    {
        return false;
    }
}

BinaryNode* AVLTree::rightRightRotate(BinaryNode*& t)
{
    BinaryNode* C = t->left;
    t->left = C->right;
    C->right = t;

    return C;
}

BinaryNode* AVLTree::rightLeftRotate(BinaryNode*& t)
{
    BinaryNode* C = t->right;
    t->right = rightRightRotate(C);

    return leftLeftRotate(t);
}

BinaryNode* AVLTree::leftLeftRotate(BinaryNode*& t)
{
    BinaryNode* C = t->right;
    t->right = C->left;
    C->left = t;

    return C;
}

BinaryNode* AVLTree::leftRightRotate(BinaryNode*& t)
{
    BinaryNode* C = t->left;
    t->left = leftLeftRotate(C);

    return rightRightRotate(t);
}


int AVLTree::diffInWeight(BinaryNode* t)
{
    return (getHeights(t->left) - getHeights(t->right));
    // if +ve mean left heavy -ve mean right heavy
}

BinaryNode* AVLTree::rebalance()
{
    return rebalance(root);
}

BinaryNode* AVLTree::rebalance(BinaryNode*& Nnode)
{
    if (Nnode == nullptr)
    {
        return nullptr;
    }

    int diffOfSides = diffInWeight(Nnode);
    cout << "DiffOFSIDES" << diffOfSides << endl;

    // Left subtree is heavier
    if (diffOfSides > 1)
    {
        cout << "Left" << endl;
        if (diffInWeight(Nnode->left) >= 1)
        {
            cout << "Left-Left" << endl;
            Nnode= rightRightRotate(Nnode);
        }
        else if (diffInWeight(Nnode->left) <= -1)
        {
            cout << "Left-Right" << endl;
            Nnode = leftRightRotate(Nnode);
        }
    }
    // Right subtree is heavier
    else if (diffOfSides < -1)
    {
        cout << "Right" << endl;
        cout << diffInWeight(Nnode->right) << endl;
        if (diffInWeight(Nnode->right) >= 1)
        {
            cout << "Right-Left" << endl;
            Nnode = rightLeftRotate(Nnode);
        }
        else if (diffInWeight(Nnode->right) <= -1)
        {
            cout << "Right-Right" << endl;
            Nnode = leftLeftRotate(Nnode);
        }
    }

    return Nnode; // No rebalancing needed for this node
}

void AVLTree::PrintTree() { PrintTree(root); }

void AVLTree::PrintTree(BinaryNode* r)
{
    if (!r==NULL)
    {
        PrintTree(r->left);
        PrintTree(r->right);

        cout << r->item.viewEmailUserName() << endl;
    }
}

