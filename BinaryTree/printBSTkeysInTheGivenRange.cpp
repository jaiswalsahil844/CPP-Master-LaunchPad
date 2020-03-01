#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void buildBST(node *&root, int *arr, int n)
{

    root = new node(arr[0]);

    for (int i = 1; i < n; i++)
    {

        node *temp = root;
        node *n = new node(arr[i]);
        node *prev = NULL;
        while (temp != NULL)
        {
            prev = temp;
            if (n->data <= temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        if (n->data <= prev->data)
        {
            prev->left = n;
        }
        else
        {
            prev->right = n;
        }
    }
}
void printBST(node *root)
{

    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    printBST(root->left);
    printBST(root->right);
    return;
}

void printRange(node *root, int k1, int k2){

    if(root == NULL){
        return;
    }

    printRange(root->left, k1, k2);
    if(root->data >= k1 && root->data <= k2){
        cout<<root->data<<" ";
    }
    printRange(root->right, k1, k2);
}

int main()
{

  int t;
  cin>>t;

  while(t--){
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k1, k2;
    cin >> k1 >> k2;

    node *root = NULL;
    buildBST(root, arr, n);

    cout<<"# Preorder : ";
    printBST(root);
    cout<<endl;
    
    cout<<"# Nodes within range are : ";
    printRange(root, k1, k2);
    cout<<endl;
   }
    return 0;
}