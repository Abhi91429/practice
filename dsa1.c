#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void addBegin(struct Node **head, int data) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = *head;
    *head = newnode;
}

void addEnd(struct Node **head, int data) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    if (*head == NULL) {
        *head = newnode;
        return;
    }

    struct Node *tmp = *head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newnode;
}

void display(struct Node *head) {
    struct Node *tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

int maxele(int arr[], int n) {
    int maxi = arr[0];  
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxi) {
            maxi = arr[i];
        }
    }
    return maxi;
}

int digits(int n) {
    int count = 0;
    while (n) {
        n = n / 10;
        count++;
    }
    return count;
}

void radixSort(int arr[], int n) {
    int maxi = maxele(arr, n);
    int digi = digits(maxi);

    struct Node *hash[10];

    for (int i = 0; i < 10; i++) {
        hash[i] = NULL;
    }

    int divisor = 1;

    for (int k=1;k<=digi;k++) {
    for (int i = 0; i < n; i++) {
        addEnd(&hash[(arr[i] / divisor) % 10], arr[i]);
    }
    divisor *= 10;

    int i = 0;

    for (int j = 0; j < 10; j++) {
        struct Node *current = hash[j];
        while (current != NULL) {
            arr[i] = current->data;
            current = current->next;
            i++;
        }
        while (hash[j] != NULL) {
            struct Node *temp = hash[j];
            hash[j] = hash[j]->next;
            free(temp);
        }
    }
}


    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int arr[] = {188, 235, 486, 121, 321};
    radixSort(arr, 5);
    return 0;
}