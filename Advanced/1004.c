#include <stdio.h>
#include <stdlib.h>
typedef struct node *p_Node;
struct node {
  int d;
  struct node *next;
};
int n, m, not_leaf[100];
int main() {
  scanf("%d%d", &n, &m);
  int temp_id, temp_k, temp_d;
  p_Node p_node[100], p_temp, p_temp2;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &temp_id, &temp_k);
    not_leaf[temp_id] = 1;
    p_node[temp_id] = (p_Node)malloc(sizeof(struct node));
    p_node[temp_id]->next = NULL;
    p_temp = p_node[temp_id];
    for (int j = 0; j < temp_k; ++j) {
      p_temp2 = (p_Node)malloc(sizeof(struct node));
      p_temp2->next = p_temp->next;
      p_temp->next = p_temp2;
      scanf("%d", &temp_d);
      p_temp2->d = temp_d;
      p_temp = p_temp->next;
    }
  }
  if (n == 1) {
    printf("1\n");
    return 0;
  }
  int front = 0, rear = 0;
  int queue[100];
  queue[rear++] = 1;
  printf("0"); 
  while (front != rear) {
    int sum = 0;
    int old_rear = rear;
    while (front < old_rear) {
      temp_id = queue[front++];
      p_temp = p_node[temp_id]->next;
      while (p_temp != NULL) {
        if (not_leaf[p_temp->d]) {
          queue[rear++] = p_temp->d;
        } else {
          sum++;
        }
        p_temp = p_temp->next;
      }
    }
    printf(" %d", sum);
  }
  printf("\n");
  /*
  for (int i = 1; i <= n; ++i) {
    // printf("iflead:%d\n", not_leaf[i]);
    if (not_leaf[i]) {
      p_temp = p_node[i]->next;
      while (p_temp != NULL) {
        printf("%d ", p_temp->d);
        p_temp = p_temp->next;
      }
    }
  }
  */
  return 0;
}
