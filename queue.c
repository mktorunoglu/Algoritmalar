#include <stdio.h>
#include <stdlib.h>
#define QUEUESIZE 3

int studentNumbers[] = {1111, 2222, 3333};
char* studentNames[] = {"AAAA", "BBBB", "CCCC"};

struct student{
    int studentNumber;
    char* studentName;
    struct student* nextStudent;
};

typedef struct student Student;

void printQueue(Student* headOfQueue){
    Student* currentStudent = headOfQueue;

    if(currentStudent == NULL){
        printf("There is no student in queue.\n\n");
    }
    else{
        while(currentStudent != NULL){
            printf("Number:%-d Name:%-s\n", currentStudent->studentNumber, currentStudent->studentName);
            currentStudent = currentStudent->nextStudent;
        }
        printf("\n");
    }
}
void dequeueStudent(Student** headOfQueue, Student* tempStudent){
    if ((*headOfQueue) == NULL){
        printf("There is no student in queue.\n\n");
    } 
    else {
        tempStudent = (*headOfQueue);
        (*headOfQueue) = (*headOfQueue)->nextStudent;

        printf("%d removed from queue.\n", tempStudent->studentNumber);
        free(tempStudent);
    }
}
void enqueueStudent(Student** headOfQueue, int studentNumber, char* studentName){
    Student* newStudent = (Student*)malloc(sizeof(Student));
    Student* currentStudent;

    newStudent->studentNumber = studentNumber;
    newStudent->studentName = studentName;
    newStudent->nextStudent = NULL;
 
    if((*headOfQueue) == NULL){
        (*headOfQueue) = (Student*)malloc(sizeof(Student));
        (*headOfQueue) = newStudent;
        currentStudent = (*headOfQueue);
    }
    else{
        currentStudent->nextStudent = newStudent;
        currentStudent = currentStudent->nextStudent;
    }
}
void main(){
    Student* headOfQueue = NULL;
    Student* tempStudent = (Student*)malloc(sizeof(Student));

    printQueue(headOfQueue);
    for(int studentIndex = 0; studentIndex < QUEUESIZE; studentIndex ++){
        enqueueStudent(&headOfQueue, *(studentNumbers + studentIndex), *(studentNames + studentIndex));
    }

    printQueue(headOfQueue);
    dequeueStudent(&headOfQueue, tempStudent);

    printQueue(headOfQueue);
    dequeueStudent(&headOfQueue, tempStudent);

    printQueue(headOfQueue);
}

