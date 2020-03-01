#include <iostream>
#include <queue>
using namespace std;

class node{

    public:
    int data;
    node *left;
    node *right;

    node(int data){
        this->data = data;
        left = right = NULL;
    }
};

node * buildTree(){

    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    node *root = new node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

// top-down approach
void printPre(node *root){

    if(root == NULL){
        return;
    }
    
    // otherwise, print root first follwed by subtrees(children)
    cout<<root->data<<" ";
    printPre(root->left);
    printPre(root->right);
    return;
}

void printIn(node *root){

    if(root == NULL){
        return;
    }

    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
    return;
}

// bottom-up approach
void printPost(node *root){

    if(root == NULL){
        return;
    }

    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
    return;
}

int height(node *root){

    if(root == NULL){
        return 0;
    }
    int lH = height(root->left);
    int rH = height(root->right);

    int tH = max(lH, rH) + 1;
    return tH;

}

void printKthLevel(node *root, int k){

    if(root == NULL){
        return;
    }

    if(k == 1){
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
    return;
}

void printAllLevel(node *root){

    int H = height(root);
    
    for(int i=1; i<=H; i++){
        printKthLevel(root, i);
        cout<<endl;
    }
    
}

// void bfs(node *root){

//     queue<node *> q;

//     q.push(root);
//     while(!q.empty()){
//         node *f = q.front();
//         cout<<f->data<<" ";
//         q.pop();
//         if(f->left != NULL){
//             q.push(f->left);
//         }
//         if(f->right != NULL){
//             q.push(f->right);
//         }
//        
//     }
// }

// void bfs(node *root){

//     queue<node *> q;

//     q.push(root);
//     q.push(NULL);

//     while(!q.empty()){

//         node *f = q.front();

//         if(f == NULL){
//             cout<<endl;
//             q.pop();

//             if(!q.empty()){
//                 q.push(NULL);
//             }
//         }
//         else{
//             cout<<f->data<<" ";
//             q.pop();
//             if(f->left != NULL){
//                 q.push(f->left);
//             }
//             if(f->right != NULL){
//                 q.push(f->right);
//             }
            
//         }
        
//     }
// }

void bfs(node *root){

    queue< pair<node *, int> > q;

    int l = 0;
    q.push(make_pair(root, l));

    while(!q.empty()){
      
        pair<node *, int> f = q.front();
        cout<<(f.first)->data<<" ";
        q.pop();

        l = (f.second);

        if((f.first)->left != NULL){
            q.push(make_pair((f.first)->left, l+1));
        }
        if((f.first)->right != NULL){
            q.push(make_pair((f.first)->right,l+1));
        }

        pair<node *, int> f2 = q.front();
        if(f.second != f2.second){
            cout<<endl;
        }

    }
    
}

int count(node *root){

    if(root == NULL){
        return 0;
    }

    int cL = count(root->left);
    int cR = count(root->right);

    int cT = 1 + cL + cR;
    return cT;
}

int sum(node *root){

    if(root == NULL){
        return 0;
    }

    int sL = sum(root->left);
    int sR = sum(root->right);

    int sT = root->data + sL + sR;
    return sT;
}

int diameter(node *root){

    if(root == NULL){
        return 0;
    }

    int hL = height(root->left);
    int hR = height(root->right);

    int q1 = hL + hR;
    int q2 = diameter(root->left);
    int q3 = diameter(root->right);

    int ans = max(q1, max(q2, q3));
    return ans;
}

class Pair{
    
    public:
        int height;
        int diameter;
};

Pair fastDiameter(node *root){

    Pair p;
    if(root == NULL){
        p.height = p.diameter = 0;
        return p;
    }

    // Otherwise
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
    return p;
}

// pair <int, int> fastDaimeter(node *root){
    
//     pair <int, int> p;
//     if(root == NULL){
//         p.first = p.second = 0;
//         return p;
//     }

//     // Otherwise
//     pair <int, int> left = fastDaimeter(root->left);
//     pair <int, int> right = fastDaimeter(root->right);

//     p.first = max(left.first, right.first) + 1;
//     p.second = max(left.first + right.first, max(left.second, right.second));
//     return p;

// }

int main(){

    node *root = buildTree();
    printPre(root);
    cout<<endl;
    // printIn(root);
    // cout<<endl;
    // printPost(root);

    // cout<<height(root);
    // printKthLevel(root, 3);

    printAllLevel(root);
    cout<<endl;
    bfs(root);

    cout<<count(root)<<endl;
    cout<<sum(root)<<endl;
    
    cout<<diameter(root)<<endl;

    Pair p = fastDiameter(root);
    cout<<p.height<<endl;
    cout<<p.diameter<<endl;
    // pair <int, int> p = fastDaimeter(root);
    // cout<<p.first<<endl;
    // cout<<p.second<<endl;
    return 0;
}