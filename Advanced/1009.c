#include <stdio.h>
#include <stdlib.h>
typedef struct node *Poly;
typedef struct node *p_Node;
struct node {
  int n;
  double a;
  struct node *next;
};
Poly insert_node(p_Node p_node) {  // creat and insert a node after p_node
  Poly p_temp = (Poly)malloc(sizeof(struct node));
  p_temp->next = p_node->next;
  p_node->next = p_temp;
  return p_temp;
}
int input_poly(Poly poly) {
  int k, temp;
  double temp_f;
  scanf("%d", &k);
  Poly p_temp = poly, p_temp2;
  for (int i = 0; i < k; ++i) {
    scanf("%d%lf", &temp, &temp_f);
    if (temp_f == 0)
      continue;
    p_temp2 = insert_node(p_temp);
    p_temp2->n = temp;
    p_temp2->a = temp_f;
    p_temp = p_temp2;
  }
  return k;
}
Poly multi_poly(Poly poly, p_Node p_node) {
  Poly poly_ans = (Poly)malloc(sizeof(struct node)), p_temp = poly->next, p_temp2, p_temp_ans;
  poly_ans->next = NULL;
  p_temp_ans = poly_ans;
  while (p_temp != NULL) {
    p_temp2 = insert_node(p_temp_ans);
    p_temp2->n = p_temp->n + p_node->n;
    p_temp2->a = p_temp->a * p_node->a;
    p_temp = p_temp->next;
    p_temp_ans = p_temp2;
  }
  return poly_ans;
}
Poly add_poly(Poly poly1, Poly poly2) {
  Poly poly_ans = (Poly)malloc(sizeof(struct node)), p1 = poly1->next, p2 = poly2->next, p_temp, p_temp2;
  poly_ans->next = NULL;
  p_temp = poly_ans;
  while (p1 != NULL && p2 != NULL) {
    if (p1->n == p2->n) {
      if (p1->a + p2->a != 0) {
        p_temp2 = insert_node(p_temp);
        p_temp = p_temp2;        
        p_temp2->n = p1->n;
        p_temp2->a = p1->a + p2->a;
        p1 = p1->next;
        p2 = p2->next;
      } else { // 这一步极其重要，非常容易忽视！！！如果指数相同，系数和为0，这一项是不能作为结果的！！！！！！！！！
        p1 = p1->next;
        p2 = p2->next;
      }
    } else if (p1->n > p2->n) {
      p_temp2 = insert_node(p_temp);
      p_temp = p_temp2;
      p_temp2->n = p1->n;
      p_temp2->a = p1->a;
      p1 = p1->next;
    } else {
      p_temp2 = insert_node(p_temp);
      p_temp = p_temp2;      
      p_temp2->n = p2->n;
      p_temp2->a = p2->a;
      p2 = p2->next;
    }
  }
  if (p1 == NULL) {
    while (p2 != NULL) {
      p_temp2 = insert_node(p_temp);
      p_temp = p_temp2;
      p_temp2->n = p2->n;
      p_temp2->a = p2->a;
      p2 = p2->next;
    }
  }
  if (p2 == NULL) {
    while (p1 != NULL) {
      p_temp2 = insert_node(p_temp);
      p_temp = p_temp2;
      p_temp2->n = p1->n;
      p_temp2->a = p1->a;
      p1 = p1->next;
    }
  }
  return poly_ans;
}
void free_poly(Poly poly) {
  Poly p_temp = poly->next;
  while (poly != NULL) {
    free(poly);
    poly = p_temp;
    if (p_temp != NULL) 
      p_temp = p_temp->next;
  }
}
void print_poly(Poly poly) {
  int sum = 0;
  Poly p_temp = poly->next;
  while (p_temp != NULL) {
    sum++;
    p_temp = p_temp->next;
  }
  printf("%d", sum);
  p_temp = poly->next;
  while (p_temp != NULL) {
    printf(" %d %.1lf", p_temp->n, p_temp->a);
    p_temp = p_temp->next;
  }
  printf("\n");
}
  
int main() {
  // 下面这句定义，刚开始没给poly_c分配空间，导致很长时间的调试，debug！！！临时变量如果下面有确切赋值的，可以不初始化，但是这里的poly_c是一定要初始化的！！！！！！！！！！！！！！！！
  Poly poly_a = (Poly)malloc(sizeof(struct node)), poly_b = (Poly)malloc(sizeof(struct node)), poly_c = (Poly)malloc(sizeof(struct node)), p_temp, p_temp2;
  poly_a->next = NULL;
  poly_b->next = NULL;
  poly_c->next = NULL;
  int k1 = input_poly(poly_a), k2 = input_poly(poly_b);
  if (k2 < k1) {
    p_temp = poly_a;
    poly_a = poly_b;
    poly_b = p_temp;
  }
  p_temp = poly_a->next;
  Poly p_temp3;
  while (p_temp != NULL) {
    p_temp2 = multi_poly(poly_b, p_temp);
    p_temp3 = poly_c;
    poly_c = add_poly(poly_c, p_temp2);
    free_poly(p_temp3);
    free_poly(p_temp2);
    p_temp = p_temp->next;
  }
  free_poly(poly_a);
  free_poly(poly_b);
  print_poly(poly_c);
  free_poly(poly_c);
  return 0;
}
  
