//heap sort
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

// quick sort
#include <stdio.h>

struct Student{
	int marks,rollno;
	char name[20];
};

void quickSort(struct Student *students,int f, int l){
	int j;
	if(f<l){
		j = partition(students, f, l);
		quickSort(students,f, j-1);
		quickSort(students, j+1, l);
	}
}

int partition(struct Student *students,int f, int l){ // f=0, l = 8;
	int i,j,p;
	struct Student temp;
	struct Student temp2 = *(students+f);
	p = (students+f)->marks;
	i = f+1;
	j = l-1;
	while(i<j){
		while(p>(students+i)->marks && i<l)
			i++;
		while(p<(students+j)->marks)
			j--;
		if(i<j){
			temp = *(students+i);
			*(students+i)= *(students+j);
			*(students+j) = temp;
		}
	}
	*(students+f)= *(students+j);
	*(students+j)= temp2;
	return j;
}

int main(){
	struct Student students[8];
	int i;
	printf("Enter Student Details (8):\n");
	for(i = 0; i<8; i++){
		printf("%d:- \n",(i+1));
		printf(" Name: ");
		scanf("%s",&students[i].name);
		printf(" Roll: ");
		scanf("%d",&students[i].rollno);
		printf(" Marks: ");
		scanf("%d",&students[i].marks);
	}
	quickSort(&students,0,8);
	printf("Marks:- \n\n\n");
	for(i = 0;i<8;i++){
		printf("Name:-%s,RollNo:-%d,Marks:-%d\n\n",students[i].name,students[i].rollno,students[i].marks);
	}
}

// Quick Sort#include<stdio.h>

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
