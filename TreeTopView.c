#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

struct node* insert( struct node* root, int data ) {
		
	if(root == NULL) {
	
        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
	  
	} else {
      
		struct node* cur;
		
		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		} else {
            cur = insert(root->right, data);
            root->right = cur;
		}
	
		return root;
	}
}

/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/
void topView(struct node* root) {
    if (root == NULL)
        return;

    struct node* nodeQueue[1000];
    int hdQueue[1000];
    int front = 0, rear = 0;

    int value[2000];
    int visited[2000] = {0};

    int offset = 1000;

    nodeQueue[rear] = root;
    hdQueue[rear] = 0;
    rear++;

    int minHD = 0, maxHD = 0;

    while (front < rear) {
        struct node* curr = nodeQueue[front];
        int hd = hdQueue[front];
        front++;

        if (!visited[hd + offset]) {
            value[hd + offset] = curr->data;
            visited[hd + offset] = 1;

            if (hd < minHD) minHD = hd;
            if (hd > maxHD) maxHD = hd;
        }

        if (curr->left) {
            nodeQueue[rear] = curr->left;
            hdQueue[rear] = hd - 1;
            rear++;
        }

        if (curr->right) {
            nodeQueue[rear] = curr->right;
            hdQueue[rear] = hd + 1;
            rear++;
        }
    }

    for (int i = minHD; i <= maxHD; i++) {
        printf("%d ", value[i + offset]);
    }
}



int main() {
  
    struct node* root = NULL;
    
    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }
  
	topView(root);
    return 0;
}
