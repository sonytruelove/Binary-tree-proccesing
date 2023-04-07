#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
struct Detail {
  string code;          
  string title;
  double price;
  double weight;  
};
struct dstructure {

  Detail detail;           

  dstructure *left;  

  dstructure *right; 

};
void addNode(Detail detail, dstructure* root) {
  
  if(root==NULL){
    dstructure** cur = &root; 
    *cur = new dstructure();
    (*cur)->detail = detail;
    (*cur)->left = NULL;
    (*cur)->right = NULL;
}else{
  
    dstructure** cur = &root; 

    while (*cur) {
        dstructure& node = **cur; 
        if (detail.code.size()>node.detail.code.size()) {
            cur = &node.right;
        }
        else {
            cur = &node.left;
        }
      }
    
    *cur = new dstructure();
    (*cur)->detail = detail;
    (*cur)->left = NULL;
    (*cur)->right = NULL;
}}
void treeCoutRecursively(dstructure* tree, string move) {

    if (tree != NULL && tree->detail.code!="") { 

        cout << move << "my code is " << tree->detail.code
            << endl; 

        move += "\t";

        cout << move << " left: " << endl;

        treeCoutRecursively(tree->left,
            move); 

        cout << move << " right: " << endl;

        treeCoutRecursively(tree->right,
            move); 
    }
}
void BFS(dstructure* tree){
    queue<dstructure *> q;
   q.push(tree);
   while (q.empty() == false) {
      dstructure *node = q.front();
      cout << node->detail.code << " ";
      q.pop();
      if (node->left != NULL)
         q.push(node->left);
      if (node->right != NULL)
         q.push(node->right);
   }
}
void LRN(dstructure* tree) {
   if (tree == NULL)
      return;
   LRN(tree->left);
   LRN(tree->right);
   cout << tree->detail.code << " ";
}
void LNR(dstructure* tree) {
   if (tree == NULL)
      return;
   LNR(tree->left);
   cout << tree->detail.code << " ";
   LNR(tree->right);
}
void NLR(dstructure* tree) {
   if (tree == NULL)
      return;
   cout << tree->detail.code << " ";
   NLR(tree->left);
   NLR(tree->right);
}
void findCode(dstructure* tree,string code) {
   if (tree == NULL)
      return;
   if(tree->detail.code==code){cout<<tree->detail.code<<endl;
     cout<<tree->detail.title<<endl;
     cout<<tree->detail.weight<<endl;
     cout<<tree->detail.price<<endl;
     }
   findCode(tree->left,code);
   findCode(tree->right,code);
}
dstructure* findWithParent(string code, dstructure* tree, dstructure** outParent) {


    if (tree == NULL)
        return NULL;
    if (code.size() < tree->detail.code.size())
    {
        (*outParent) = tree;
        return findWithParent(code, tree->left, outParent);
    }

    if (code.size() > tree->detail.code.size())
    {
        (*outParent) = tree;
        return findWithParent(code, tree->right, outParent);
    }


    return tree;
}
void deleteNode(dstructure* tree,string code) {
    
    dstructure** parent = &tree;
    dstructure* node2Del = findWithParent(code, tree, parent);
    if (!node2Del)   return;
   

    dstructure* tempNode;


      
    if (node2Del->right == nullptr && node2Del->left == nullptr) {

        if (*parent == node2Del)
        {          
            delete node2Del;
            return;
        }

        if ((*parent)->detail.code.size() < node2Del->detail.code.size()) 
        {
            (*parent)->right = NULL;
        }
        else {
            (*parent)->left = NULL;
        }
        delete node2Del;
        return;
    }

    if (node2Del->right == nullptr) {
        tempNode = node2Del->left;
        node2Del->detail = tempNode->detail;
        node2Del->left = tempNode->left;
        node2Del->right = tempNode->right;
        delete tempNode;
        return;
    }
    if (node2Del->right->left == nullptr) {
        tempNode = node2Del->right;
        node2Del->detail = tempNode->detail;
        node2Del->right = tempNode->right;
        delete tempNode;
        return;
    }

    dstructure* tempNodeParent = node2Del->right;
    tempNode = node2Del->right->left;

    while (tempNode->left != nullptr) {
        tempNodeParent = tempNode;
        tempNode = tempNode->left;
    }

    node2Del->detail = tempNode->detail;

    tempNodeParent->left = tempNode->right;

    delete tempNode;
    return;
}
void deleteLowerWeight(dstructure* tree,double weight){
   if(tree==NULL) return;
    if(tree->detail.weight<weight){
      deleteNode(tree,tree->detail.code);
      deleteLowerWeight(tree,weight);
      }
     deleteLowerWeight(tree->left,weight);
  }