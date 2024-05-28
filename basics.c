//Factorial and Fibonacci
#include <stdio.h>

int stack[50], top=-1;

void push(int key){
    stack[++top] = key;
}

int pop(){
    return stack[top--];
}

int getTop(){
  return stack[top];
}

void fact(int num){
  push(1);
  for(int i=2;i<=num;i++){
    push(getTop() * i);
  }
  
  printf("Factorial is: %d", getTop());
}


void fibo(int num){
  
  push(0);
  push(1);
  
  printf(" 0  1 ");
  
  for(int i=0;i<num;i++){
    int second = pop();
    int first = pop();
    
    int next = first+second;
    printf(" %d ", next);
    
    push(first);
    push(second);
    push(next);
  }
}


int main()
{
  int num;
  scanf("%d", &num);
  fact(num);
  fibo(num);
  
  return 0;
}

// circular deque
#include <stdio.h>

int size = 10;
int queue1[10];
int front = -1, rear = -1;

int deleteRear(){
  
  int ele = queue1[rear];
  
  if(rear == -1){
    printf("Queue underflow");
    return -1;
  }
  
  if(rear == front){
    front = -1;
    rear = -1;
  }else if(rear == 0){
    rear= size -1;
  }else{
    rear = rear-1;
  }
  
  return ele;
}

int deleteFront(){
  
  int ele = queue1[front];
  
  if(front == -1){
    printf("Queue underflow");
    return -1;
  }
  
  if(front == rear){
    front = -1;
    rear = -1;
  }else{
    // back to first position
    if(front == size-1){
      front = 0;
    }else{
      front++;
    }
  }
  
  return ele;
}

void insertRear(int key){
  
  if(front== -1){
    front =0;
    rear = 0;
  }
  
  if(rear == size-1){
    rear = 0;
  }else{
    rear++;
  }
  
  queue1[rear] = key;
  
}

void insertFront(int key){
  if(front==-1){
    rear = 0;
    front = 0;
  }
  
  if(front == 0){
    front = size -1;
  }
  else{
    front = front -1;
  }
  
    queue1[front] = key;
  
}

int main(){
  
  int option;
  
  // printf("1. Insertfront 2.InsertRear 3.Delete Front 4.Delete Rear 5.Exit");
  // printf("\nEnter option: ");
  // scanf("%d", &option);
  
  insertFront(10);
  insertRear(20);
  insertFront(30);
  insertRear(40);
  insertFront(50);
  insertRear(60);
  
  printf("deleted at front: %d ", deleteFront());
  printf("\ndeleted at rear: %d ", deleteRear());
  printf("\ndeleted at front: %d ", deleteFront());
  printf("\ndeleted at rear: %d ", deleteRear());  
}

// two queue
#include <stdio.h>

int size=10;
int arr[10];
int rear1, front1;
int rear2, front2;

int delQ2(){
  if(front2<rear2 || front1 == size){
    printf("Queue underflow");
    front2=size;
    rear2= size;
  }
  
  return arr[front2--];
}

int delQ1(){
  if(front1>rear1 || front1 == -1){
    printf("Queue underflow");
  }
  
  return arr[front1++];
}

void addQ2(int key){
  if(rear1>=rear2){
    printf("Queue overflow");
  }
  if(rear2 == size){
    rear2 = size-1;
    front2 = size-1;
  }else{
    rear2--;
  }
  arr[rear2] = key;
}

void addQ1(int key){
  if(rear1>=rear2){
    printf("Queue overflow");
  }
  
  if(rear1==-1){
    rear1=0;
    front1=0;
  }
  else{
    rear1++;
  }
  arr[rear1]=key;
}

int main()
{
  rear1=-1;
  front1=-1;
  rear2 = size;
  front2= size;
  
  addQ1(10);
  addQ1(20);
  addQ1(30);
  addQ2(90);
  addQ2(100);
  
  printf("%d ", delQ2());
  printf("%d ", delQ1());
  printf("%d ", delQ1());   
}

// polynomial addition
#include <stdio.h>
#include<stdlib.h>

struct node{
  int coe;
  int expo;
  struct node *next;
};

void addition(struct node *poly1, struct node *poly2, struct node **result){
  
  while(poly1!=NULL && poly2!=NULL){
    
    struct node *n = (struct node *)malloc(sizeof(struct node));
    
    if(poly1->expo==poly2->expo){
      n->coe = poly1->coe + poly2->coe;
      n->expo = poly1->expo;
      poly1 = poly1->next;
      poly2 = poly2->next;
    }else if(poly1->expo <= poly2->expo){
      n->coe = poly2->coe;
      n->expo = poly2->expo;
      poly2 = poly2->next;
      
    }else{
      n->coe = poly1->coe;
      n->expo = poly1->expo;
      poly1=poly1->next;
    }
    
    struct node *temp;
    
    if(*result==NULL){
      *result = temp = n;
    }else{
      temp->next = n;
      temp = n;
    }
  }
}

void display(struct node *head){
  struct node *temp = head;
  
  printf("\n");
  
  while(temp!=NULL){
    printf(" |%d %d|  ", temp->coe, temp->expo);
    temp = temp->next;
  }
  
  printf("\n");
  
}

void insert(struct node **head){
  int coef, expo1;
  struct node *n1 = (struct node *)malloc(sizeof(struct node));
  
  // printf("Enter coeficient: ");
  scanf("%d", &coef);
  scanf("%d", &expo1);
  
  n1->coe = coef;
  n1->expo = expo1;
  n1->next= NULL;
 
  struct node *temp;
  
  if(*head==NULL){
    *head = temp = n1;
  }
  else{
    temp->next = n1;
    temp= n1;
  }
}

int main()
{
  struct node *poly1, *poly2, *result;
  
  poly1=NULL;
  poly2=NULL;
  result = NULL;
  
  int term;
  printf("Enter no. of terms in polynomial 1: ");
  scanf("%d", &term);
  for(int i=0;i<term;i++){
    insert(&poly1);
    printf("Added poly1 %d",i);
  }
  
  printf("Enter no. of terms in polynomial 2: ");
  scanf("%d", &term);
  for(int i=0;i<term;i++){
    insert(&poly2);
    printf("Added poly2 %d",i);
  }
  
  display(poly1);
  display(poly2);
  
  addition(poly1, poly2, &result);
  
  display(result);
  
  return 0;
}

// reverse LL
#include <stdio.h>
#include<stdlib.h>

struct LL{
  int data;
  struct LL *next;
};

void display(struct LL *temp){
  
  printf("\n");
  
  while(temp!=NULL){
    printf(" %d ", temp->data);
    temp = temp->next;
  }
  
  printf("\n");
  
}

void reverse(struct LL **head){
  struct LL *temp, *prev, *front;
  
  prev = NULL;
  temp = *head;
  
  while(temp!=NULL){
    front = temp->next;
    temp->next = prev;
    prev = temp;
    temp = front;
  }
  *head = prev;
}

void insert(struct LL **head, int key){
  struct LL *node = (struct LL*) malloc(sizeof(struct LL));
  
  node->data = key;
  node->next = NULL;
  
  struct LL *temp;
  
  if(*head==NULL){
    *head = temp = node;
  }else{
    temp->next = node;
    temp = node;
  }
  
}

int main()
{
  // =(struct LL*) malloc(sizeof(struct LL))
  struct LL *head;
  head=NULL;
  
  insert(&head,20);
  insert(&head,30);
  insert(&head,40);
  display(head);
  
  reverse(&head);
  display(head);
  
  return 0;
}


// double linked list perform all insertion and deletion operations
// Function to insert a node at the beginning of the doubly linked list
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Function to insert a node after a given node in the doubly linked list
Node* insertAfter(Node* head, Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return head;
    }
    Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
    newNode->prev = prevNode;
    return head;
}

// Function to delete a node from the doubly linked list
Node* deleteNode(Node* head, Node* delNode) {
    if (head == NULL || delNode == NULL) {
        printf("Cannot delete node. List is empty or node does not exist.\n");
        return head;
    }
    if (head == delNode) {
        head = delNode->next;
    }
    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }
    free(delNode);
    return head;
}

// Function to display the doubly linked list
void displayList(Node* head) {
    Node* temp = head;
    printf("Doubly linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data, prevData;
    Node* prevNode;

    while (1) {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert after a node\n");
        printf("4. Delete first node\n5. Delete last node\n6. Delete a node after a given node\n");
        printf("7. Display list\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter data of the node after which to insert: ");
                scanf("%d", &prevData);
                prevNode = head;
                while (prevNode != NULL && prevNode->data != prevData) {
                    prevNode = prevNode->next;
                }
                if (prevNode != NULL) {
                    head = insertAfter(head, prevNode, data);
                } else {
                    printf("Node with given data not found. Cannot insert.\n");
                }
                break;
            case 4:
                head = deleteNode(head, head);
                break;
            case 5:
                if (head != NULL) {
                    Node* temp = head;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    head = deleteNode(head, temp);
                } else {
                    printf("List is empty. Cannot delete last node.\n");
                }
                break;
            case 6:
                if (head != NULL) {
                    printf("Enter data of the node after which to delete: ");
                    scanf("%d", &prevData);
                    prevNode = head;
                    while (prevNode != NULL && prevNode->data != prevData) {
                        prevNode = prevNode->next;
                    }
                    if (prevNode != NULL && prevNode->next != NULL) {
                        head = deleteNode(head, prevNode->next);
                    } else {
                        printf("Node not found or it is the last node. Cannot delete.\n");
                    }
                } else {
                    printf("List is empty. Cannot delete.\n");
                }
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}

// polynomial addition of linked list
#include <stdio.h>
#include<stdlib.h>

struct node{
  int coe;
  int expo;
  struct node *next;
};

void addition(struct node *poly1, struct node *poly2, struct node **result){
  
  while(poly1!=NULL && poly2!=NULL){
    
    struct node *n = (struct node *)malloc(sizeof(struct node));
    
    if(poly1->expo==poly2->expo){
      n->coe = poly1->coe + poly2->coe;
      n->expo = poly1->expo;
      poly1 = poly1->next;
      poly2 = poly2->next;
    }else if(poly1->expo <= poly2->expo){
      n->coe = poly2->coe;
      n->expo = poly2->expo;
      poly2 = poly2->next;
      
    }else{
      n->coe = poly1->coe;
      n->expo = poly1->expo;
      poly1=poly1->next;
    }
    
    struct node *temp;
    
    if(*result==NULL){
      *result = temp = n;
    }else{
      temp->next = n;
      temp = n;
    }
  }
}

void display(struct node *head){
  struct node *temp = head;
  
  printf("\n");
  
  while(temp!=NULL){
    printf(" |%d %d|  ", temp->coe, temp->expo);
    temp = temp->next;
  }
  
  printf("\n");
  
}

void insert(struct node **head){
  int coef, expo1;
  struct node *n1 = (struct node *)malloc(sizeof(struct node));
  
  // printf("Enter coeficient: ");
  scanf("%d", &coef);
  scanf("%d", &expo1);
  
  n1->coe = coef;
  n1->expo = expo1;
  n1->next= NULL;
 
  struct node *temp;
  
  if(*head==NULL){
    *head = temp = n1;
  }
  else{
    temp->next = n1;
    temp= n1;
  }
}

int main()
{
  struct node *poly1, *poly2, *result;
  
  poly1=NULL;
  poly2=NULL;
  result = NULL;
  
  int term;
  printf("Enter no. of terms in polynomial 1: ");
  scanf("%d", &term);
  for(int i=0;i<term;i++){
    insert(&poly1);
    printf("Added poly1 %d",i);
  }
  
  printf("Enter no. of terms in polynomial 2: ");
  scanf("%d", &term);
  for(int i=0;i<term;i++){
    insert(&poly2);
    printf("Added poly2 %d",i);
  }
  
  display(poly1);
  display(poly2);
  
  addition(poly1, poly2, &result);
  
  display(result);
  
  return 0;
}

// merge two sorted doubly linked list
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to merge two sorted doubly linked lists
struct Node* mergeSortedLists(struct Node* head1, struct Node* head2) {
    // If either list is empty, return the other list
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* mergedHead = NULL; // Head of the merged list
    struct Node* mergedTail = NULL; // Tail of the merged list

    // Initialize the merged list with the smaller of the two heads
    if (head1->data <= head2->data) {
        mergedHead = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        head2 = head2->next;
    }
    mergedTail = mergedHead;

    // Merge the lists
    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            mergedTail->next = head1;
            head1->prev = mergedTail;
            head1 = head1->next;
        } else {
            mergedTail->next = head2;
            head2->prev = mergedTail;
            head2 = head2->next;
        }
        mergedTail = mergedTail->next;
    }

    // Attach the remaining elements
    if (head1 != NULL) {
        mergedTail->next = head1;
        head1->prev = mergedTail;
    } else if (head2 != NULL) {
        mergedTail->next = head2;
        head2->prev = mergedTail;
    }

    return mergedHead;
}

// Function to insert a node at the end of the doubly linked list
void insertEnd(struct Node **head, int key){
  struct Node *node = (struct Node*) malloc(sizeof(struct Node));
  
  node->data = key;
  node->next = NULL;
  
  struct Node *temp;
  
  if(*head==NULL){
    *head = temp = node;
  }else{
    temp->next = node;
    temp = node;
  }
  
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Create first sorted list: 1 <-> 3 <-> 5
    insertEnd(&list1, 1);
    insertEnd(&list1, 3);
    insertEnd(&list1, 5);

    // Create second sorted list: 2 <-> 4 <-> 6
    insertEnd(&list2, 2);
    insertEnd(&list2, 4);
    insertEnd(&list2, 6);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    // Merge the two sorted lists
    struct Node* mergedList = mergeSortedLists(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}

// stack using doubly linked list
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("Pushed %d onto the stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Node** head) {
    if (*head == NULL) {
        printf("Stack underflow\n");
        return -1;  // Indicating an error
    } else {
        struct Node* temp = *head;
        int data = temp->data;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        printf("Popped %d from the stack\n", data);
        return data;
    }
}

// Function to print the stack
void printStack(struct Node* head) {
    struct Node* temp = head;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* stack = NULL;

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Print the stack
    printStack(stack);

    // Pop elements from the stack
    pop(&stack);
    pop(&stack);

    // Print the stack
    printStack(stack);

    // Pop remaining elements
    pop(&stack);
    pop(&stack);  // Attempt to pop from an empty stack

    return 0;
}
// doubly linked list queue
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to add (enqueue) an element to the queue
void enqueue(struct Node** head, struct Node** tail, int data) {
    struct Node* newNode = createNode(data);
    if (*tail == NULL) {
        // If the queue is empty
        *head = *tail = newNode;
    } else {
        // Attach the new node to the end of the queue
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
    printf("Added %d to the queue\n", data);
}

// Function to delete (dequeue) an element from the queue
int dequeue(struct Node** head, struct Node** tail) {
    if (*head == NULL) {
        printf("Queue underflow\n");
        return -1;  // Indicating an error
    } else {
        struct Node* temp = *head;
        int data = temp->data;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        } else {
            // If the queue becomes empty after dequeuing
            *tail = NULL;
        }
        free(temp);
        printf("Deleted %d from the queue\n", data);
        return data;
    }
}

// Function to print the queue
void printQueue(struct Node* head) {
    struct Node* temp = head;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    // Enqueue elements to the queue
    enqueue(&head, &tail, 10);
    enqueue(&head, &tail, 20);
    enqueue(&head, &tail, 30);

    // Print the queue
    printQueue(head);

    // Dequeue elements from the queue
    dequeue(&head, &tail);
    dequeue(&head, &tail);

    // Print the queue
    printQueue(head);

    // Dequeue remaining elements
    dequeue(&head, &tail);
    dequeue(&head, &tail);  // Attempt to dequeue from an empty queue

    return 0;
}

// swapped elements
#include <stdio.h>

// Function to identify the swapped pair of elements and their positions
void findSwappedPair(int arr[], int n) {
    int x = -1, y = -1; // Swapped elements
    int pos1 = -1, pos2 = -1; // Positions of the swapped elements

    // Traverse the array to find the swapped elements
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            if (x == -1) {
                // First occurrence
                x = arr[i];
                y = arr[i + 1];
                pos1 = i;
                pos2 = i + 1;
            } else {
                // Second occurrence
                y = arr[i + 1];
                pos2 = i + 1;
                break;
            }
        }
    }

    // Print the results
    printf("Swapped elements are: %d and %d\n", x, y);
    printf("Positions of swapped elements are: %d and %d\n", pos1, pos2);
}

int main() {
    int arr[] = {3, 5, 6, 9, 8, 7, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    findSwappedPair(arr, n);

    return 0;
}

// Quick sort 
#include<stdio.h>

struct Stud{
    int rollNo;
    char name[20];
    float marks;
};

int findPartition(struct Stud students[], int low, int high){

    int i=low;
    int j=high;
    int pivot=low;

    while(i<j){
        while(students[i].rollNo <= students[pivot].rollNo && low <= high){
            i++;
        }
        while(students[j].rollNo > students[pivot].rollNo && high >=low){
            j--;
        }
        if(i<j){
            struct Stud temp = students[i];
            students[i] = students[j];
            students[j] = temp;
        }
    }
    struct Stud temp = students[low];
    students[low] = students[j];
    students[j] = temp;

    return j;
}

void quickSort(struct Stud students[], int low, int high){
    
    if(low<high){
    int partitionIndex = findPartition(students, low, high);

    quickSort(students, low, partitionIndex);
    quickSort(students, partitionIndex+1, high);
    }
}

int main(){
    struct Stud students[5];
    printf("Enter data for 5 students");

    for(int i=0;i<5;i++){
        printf("\nData for student %d\n", i+1);
        printf("Enter roll no: ");
        scanf("%d", &students[i].rollNo);

        printf("Enter Name: ");
        scanf("%s", students[i].name);

        printf("Enter Marks: ");
        scanf("%f", &students[i].marks);
    }

    quickSort(students, 0, 4);

    printf("students data: \n");
    for(int i=0;i<5;i++){
        printf("Roll No: %d ",students[i].rollNo);
        printf("Name:%s ", students[i].name);
        printf("Marks:%f ",students[i].marks);
        printf("\n");
    }

    return 0;
}

// heap sort
#include <stdio.h>

struct Stud {
    int rollNo;
    float cgpa;
    char name[20];
};

void maxHeap(struct Stud arr[], int i, int size) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < size && arr[left].rollNo > arr[largest].rollNo) {
        largest = left;
    }
    if (right < size && arr[right].rollNo > arr[largest].rollNo) {
        largest = right;
    }
    if (i != largest) {
        struct Stud temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeap(arr, largest, size);
    }
}

void heapSort(struct Stud student[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeap(student, i, size);
    }

    for (int i = size - 1; i > 0; i--) {
        struct Stud temp = student[0];
        student[0] = student[i];
        student[i] = temp;

        maxHeap(student, 0, i);
    }
}

int main() {
    struct Stud student[5];

    for (int i = 0; i < 5; i++) {
        printf("\nEnter data for student%d \n", i + 1);

        printf("Enter student roll: ");
        scanf("%d", &student[i].rollNo);

        printf("Enter student name: ");
        scanf("%s", student[i].name);

        printf("Enter student cgpa: ");
        scanf("%f", &student[i].cgpa);
    }

    heapSort(student, 5);

    printf("\nSorted student data:\n");
    for (int i = 0; i < 5; i++) {
        printf("Student roll: %d ", student[i].rollNo);
        printf("Student cgpa: %f ", student[i].cgpa);
        printf("Student name: %s ", student[i].name);
        printf("\n");
    }

    return 0;
}

//linear probing with chaining
#include<stdio.h>
#include<stdlib.h>
#define size 10

void insert(int data[], int flag[], int chain[], int x){
	int i=0, start, j;
	start = x%size;
	while(flag[start] && i<size){
		if(data[start]%size == x%size) // breaks when chain detected
			break;
		i+=1;
		start = (start+1)%size;  // increments if no chaining found
	} 
	if(size == i){
		printf("Hash Table is Full");
		return;
	}
	while(chain[start] != -1){ // finding last chain for given data
    	start = chain[start];
	}

	j = start;

	while(flag[j] && i<size){
		j = (j+1)%size;
		i++;
	}
	if(size == i){
		printf("Hash Table is Full");
		return;
	}
	data[j] = x;
	flag[j] = 1;
	if(start!=j)
		chain[start] = j;
}

void display(int data[], int flag[], int chain[]){
	int i;
	for(i=0; i<size; i++){
		printf("%d\t%d\t%d\t%d\t\n",i,data[i],chain[i],flag[i]);
	}
}

int main(){
	int n, i, data[size], flag[size], chain[size], x;
	printf("Enter the Number of Elements to be Inserted in the table: ");
	scanf("%d",&n);
	for(i=0; i<size; i++){
		data[i] = -1;
		flag[i] = 0;
		chain[i] = -1;
	}
	for(i=0; i<n; i++){
		printf("Enter Element Number %d:- ",(i+1));
		scanf("%d",&x);
		insert(data,flag,chain,x);
	}
	printf("\n\n~~~~~~~ HASH TABLE ~~~~~~~\n\n");
	display(data, flag, chain);
}
