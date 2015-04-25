#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct player
{
    string ign;
    int mmr;
    int pWins;
    string rankt;
    struct player* left;
    struct player* right;
    struct player* parent;
};


 player* newPlayer(string pname, int pmmr, int wins )
{
  player *newp = new player;
  newp->ign = pname;
  newp->mmr   = pmmr;
  newp->pWins = wins;
  newp->rankt = "Unranked";
  newp->left   = NULL;
  newp->right  = NULL;
  newp->parent = NULL;

  return newp;
}

player* rankdeter(player* node){
int nw = 0;
node->pWins = nw;
if (nw == 1 || nw == 2){
    node->rankt = "Bronze";
}
if (nw == 3 || nw == 4) {
    node->rankt = "Silver";
}
if (nw == 5 || nw == 6){
    node->rankt = "Gold";
}
if (nw == 7 ){
    node->rankt = "Platinum";
    }
if (nw == 8){
    node->rankt = "Diamond";
}
if (nw == 9){
    node->rankt = "Master";
}
if (nw >= 10){
    node->rankt = "Challenger";
}
}

void displayPlayer (player* node){
cout<< "In Game Name:" << node->ign << endl;
cout<< "Player Match Making Rating:" << node->mmr << endl;
cout<< "Player Rank:" << node->rankt << endl;
cout<< "Placement Wins:" << node->pWins << endl;
}

/*player* enterQue(player* node, int mmr)
{
  if (node == NULL)
    return(newPlayer(mmr));
  else
  {
     player *temp;

    if (data <= node->data)
    {
         temp = insert(node->left, data);
         node->left  = temp;
         temp->parent= node;
    }
    else
    {
        temp = insert(node->right, data);
        node->right = temp;
        temp->parent = node;
    }
    return node;
  }
}
void Inorder(player *root) {
	if(root == NULL) return;

	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}

void Postorder(player *root) {
	if(root == NULL) return;
	Postorder(root->left);       //Visit left subtree
	Postorder(root->right);      // Visit right subtree
	printf("%d ",root->data);  //Print data
}

void Preorder(player *root) {
	if(root == NULL) return;
	printf("%d ",root->data);  //Print data
	Preorder(root->left);       //Visit left subtree
	Preorder(root->right);      // Visit right subtree

}*/

int main()
{
  struct node* root = NULL, *temp, *succ, *min;


deleteAndReplaceRightMax(root, 50);
std::cout<<"Inorder: ";
  Inorder(root);
    std::cout<<"\n";

std::cout<<"Postorder: ";
  Postorder(root);
    std::cout<<"\n";

std::cout<<"Preorder: ";
Preorder(root);
std::cout << "\n";
  return 0;
}
