#include <stdio.h>
#include <stdlib.h>

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);

struct ListNode {
    int val;
    struct ListNode *next;
};


int main () {
    struct ListNode *lista1 = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *lista2 = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *temp;
    int v1[3] = {1, 2, 4}, v2[3] = {1, 3, 4};

    temp = lista1;
    for (int i = 0; i < sizeof(v1) / sizeof(int); i++) {
        struct ListNode *l = (struct ListNode *) malloc(sizeof(struct ListNode));
        l->val = v1[i];
        temp->next = l;
        temp = temp->next;
    }
    temp->next = NULL;

    temp = lista2;
    for (int i = 0; i < sizeof(v2) / sizeof(int); i++) {
        struct ListNode *l = (struct ListNode *) malloc(sizeof(struct ListNode));
        l->val = v2[i];
        temp->next = l;
        temp = temp->next;
    }
    temp->next = NULL;

    mergeTwoLists(lista1, lista2);
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *list3 = (struct ListNode *) malloc(sizeof(struct ListNode)), *list, *prevItem, *temp, *temp3;
    struct ListNode *item = (struct ListNode *) malloc (sizeof(struct ListNode));
    item->val = -101;
    item->next = NULL;
    list3->next = item;

    list = list1;
    for (int i = 0; i < 2; i++) {
        for (temp = list; temp != NULL; temp = temp->next) {

            if (list->next != NULL) {
                if (temp == list) temp = list->next;

                struct ListNode *item = (struct ListNode *) malloc (sizeof(struct ListNode));
                item->val = temp->val;

                prevItem = list3;
                for (temp3 = list3; temp3 != NULL; temp3 = temp3->next) {

                    if (list3->next != NULL) {
                        if (temp3 == list3) temp3 = list3->next;

                        if (temp3->val >= item->val) {
                            printf("%d maior que %d\n", temp3->val, item->val);
                            item->next = temp3;
                            prevItem->next = item;
                            break;
                        } else if (temp3->next == NULL) {
                            temp3->next = item;
                            item->next = NULL;
                            break;
                        }
                        prevItem = temp3;
                    }
                }
            }
        }

        list = list2;
    }

    list3->next = list3->next->next;

    for (temp = list3->next; temp != NULL; temp = temp->next) {
        printf("%d ", temp->val);
    }

    return list3;
}