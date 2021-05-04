//MENU DRIVEN BST

#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node* p;
	struct node* left;
	struct node* right;
	long int key ;
};

struct node* CREATE_NODE(long int k){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->p = NULL;
	temp->left = NULL;
	temp->right = NULL;
	temp->key = k;
	return temp;
}

struct node* INSERT(struct node* root ,struct node* z){
	if(root == NULL){
		root = z;
		return root;}
	struct node* x = NULL;
	struct node* y = root;
	while(y!=NULL){
		x=y;
		if(z->key<y->key){
			y = y->left;
		}
		else{
			y = y->right;
		}
	}
	z->p = x;
	if(z->key<x->key){x->left = z;}
	else {x->right = z;}
	return root;
}
struct node* SEARCH(struct node* root,long int key){
	if(root == NULL){return NULL;}
	struct node* temp =root;
	while(temp != NULL){
		if(key == temp->key)return temp;
		else if(key<temp->key) temp=temp->left;
		else temp = temp->right;
	}
	if(temp == NULL)return NULL;
}
struct node* TRANSPLANT(struct node* root,struct node* u, struct node* v){
	if(u->p == NULL)root =v;
	else if( u  == u->p->left)u->p->left = v;
	else u->p->right = v;
	if(v!=NULL){
	v->p = u-> p;
	}
	return root;
}
struct node* TREEMINIMUM(struct node* temp){
	if(temp->left==NULL)return temp;
	return TREEMINIMUM(temp->left);

}
struct node* TREEMAXIMUM(struct node* temp){
	if(temp->right == NULL)return temp;
	return TREEMAXIMUM(temp->right);
}
struct node* DELETE(struct node* root,struct node* z){
	if(z->left == NULL)root = TRANSPLANT(root,z,z->right);
	else if(z->right == NULL)root = TRANSPLANT(root,z,z->left);
	else {
		struct node* y = TREEMINIMUM(z->right);
		if(y->p != z){
		root = TRANSPLANT(root,y,y->right);
		y->right = z->right;
		y->right->p = y;
		}
		root = TRANSPLANT(root,z,y);
		y->left = z->left;
		y->left->p = y;
	}
	printf("%ld\n",z->key);
	z->p =NULL;
	z->left=NULL;
	z->right=NULL;
	free(z);
		
	return root;



}


void GetLevel(struct node* root,struct node* temp){
	int lev = 1;
	if(root == temp)printf("1\n");
	else{
		while(root != temp){
		if(root->key > temp->key){
			root = root->left;
		}
		else {root = root->right;}
		
		lev++;
		
		}
		printf("%d\n",lev);
	}
	

}


void PRED(struct node* temp){
	if(temp->left==NULL){
		printf("-1\n");
	}
	else{
		temp = temp->left;
		while(temp->right !=NULL){
		temp = temp->right;}
		printf("%ld\n",temp->key);
	}

}

void SUCS(struct node* temp){
	if(temp->right==NULL){
		printf("-1\n");
	}
	else{
		temp=temp->right;
		while(temp->left != NULL)temp=temp->left;
		printf("%ld\n",temp->key);
	}
}
void INORDER(struct node* root){
	if(root == NULL)return;
	INORDER(root->left);
	printf("%ld ",root->key);
	INORDER(root->right);
}
void PREORDER(struct node* root){
	if(root == NULL)return;
	printf("%ld ",root->key);
	PREORDER(root->left);
	PREORDER(root->right);
}
void POSTORDER(struct node* root){
	if(root == NULL)return;
	
	POSTORDER(root->left);
	POSTORDER(root->right);
	printf("%ld ",root->key);
	
}
void main(){
	char x;
	long int key;
	struct node* root;
	root =NULL;
	while(1){
	scanf("%c",&x);
	if(x == 'a'){
		scanf("%ld",&key);
		//if(key  == '\n'){printf("fagrgaFR");}
		struct node* z = CREATE_NODE(key);
		root = INSERT(root,z);
		//printf("%ld",root->key);
	}
	if(x == 'd'){
		scanf("%ld",&key);
		struct node* z = SEARCH(root,key);
		if(z == NULL)printf("-1\n");
		else root = DELETE(root,z);
	}
	if(x == 's'){
		scanf("%ld",&key);
		struct node* search = SEARCH(root,key);
		if(search==NULL)printf("-1\n");
		else printf("1\n");
	}
	if(x == 'l'){
		scanf("%ld",&key);
		struct node* level = SEARCH(root,key);
		if(level == NULL)printf("-1\n");
		else{
			GetLevel(root,level);
		}
	}
	if(x == 'm'){
		
		struct node* min = TREEMINIMUM(root);
		printf("%ld\n",min->key);
	}
	if(x == 'x'){
		struct node* max = TREEMAXIMUM(root);
		printf("%ld\n",max->key);
	}
	if(x == 'r'){
		scanf("%ld",&key);
		struct node* pred = SEARCH(root,key);
		if(pred == NULL )printf("-1\n");
		else PRED(pred);
		 
	}
	if(x == 'u'){
		scanf("%ld",&key);
		struct node* succ = SEARCH(root,key);
		if(succ == NULL )printf("-1\n");
		else SUCS(succ);
	}
	if(x == 'i'){INORDER(root);
	printf("\n");}
	if(x == 'p'){PREORDER(root);
	printf("\n");}
	if(x == 't'){POSTORDER(root);
	printf("\n");}
	if(x == 'e'){break;}
	}
	

}
