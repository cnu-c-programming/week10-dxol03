#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    int score;
    struct Node* next;
};

struct Node* head = NULL;

void add(char* name, int score) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void delete(char* name) {
    struct Node* curr = head;
    struct Node* prev = NULL;

    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            if (prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void print() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%s %d\n", temp->name, temp->score);
        temp = temp->next;
    }
}

void quit() {
    struct Node* curr = head;
    while (curr != NULL) {
        struct Node* next = curr->next;
        free(curr);
        curr = next;
    }
    exit(0);
}

int main() {
    char command[20];
    char name[50];
    int score;

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s %d", name, &score);
            add(name, score);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            delete(name);
        } else if (strcmp(command, "print") == 0) {
            print();
        } else if (strcmp(command, "quit") == 0) {
            quit();
        }
    }

    return 0;
}
