#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   char x;
   struct node *next;
} node;

void append(char x, node* root) {
   if(x == 0) return;
   while(root->next != 0) {
	  root = root->next;
   }
   node *next = malloc(sizeof(root));
   root->next = next;
   next->next = 0;
   next->x = x;
//   printf("Appending %c after %c\n", x, root->x);
}

node* reverse(node* root) {
   node *new_root = 0;
   while(root) {
      node *next = root->next;
	  root->next = new_root;
	  new_root = root;
	  root = next;
   }
   return new_root;
}

void print_list(node* root) {
   while(root) {
      printf("%c", root->x);
	  root = root->next;
   }
   printf("\n");
}

void appendList(node* novo, node* root) {
   while(novo) {
      append(novo->x,root);
	  novo = novo->next;
   }
}

void clear(node* root) {
   node* next;
   node* deleteMe = root;
   while(root) {
      next = deleteMe->next;
	  free(deleteMe);
	  deleteMe = next;
   }
}

node* getStringAsList(node* root) {
   char input[256];
   int i;

   fgets(input, 256, stdin);

   for(i = 0; i < 256; i++) {
      if(input[i] == '\n' || input[i] == '\0' || input[i] == '\r') break;
	  append(input[i], root);
   }
   append(0, root);
//0   print_list(root);
   return root;
}

node* caoCrypt(node* root) {
   char a = 0;
   node* new_list = malloc(sizeof(new_list));
   new_list->next = 0;
   new_list->x = 0;
   while(root) {
      node* new_root = malloc(sizeof(new_root));
      new_root->next = 0;
      new_root->x = 0;
      a = root->x;
      root = root->next;
	  while(!(a=='a'||a=='A'||a=='e'||a=='E'||a=='i'||a=='I'||a=='o'||a=='O'||a=='u'||a=='U') && root) {
	     append(a, new_root);
         a = root->x;
         root = root->next;
	  }
	  new_root = reverse(new_root);
	  appendList(new_root, new_list);
	  append(a, new_list);
   }
   new_list = reverse(new_list);
   return new_list;
}

int main() {
   node* root = malloc(sizeof(root));
   root->next = 0;
   root->x = 0;
   printf("Escreva a mensagem: ");
   root = getStringAsList(root);
   root = caoCrypt(root);
   print_list(root);
   system("pause");

   return 0;
}
