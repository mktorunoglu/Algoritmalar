#include <stdio.h>
#include <stdlib.h>
#define NUMBEROFSTUDENTS 5
long studentNumbers[] = {1071, 1074, 9000, 10001, 1000};
char* studentNames[] = {"AAAA", "BBBB", "CCCC", "DDDD", "EEEE"};
struct student{
    char* studentName;
    long studentNumber;
    struct student* nextStudent;
};
typedef struct student Student;
int checkForEmptyList(Student* headOfLinkedList){
    if(headOfLinkedList == NULL){
        return 0; 
    }else{
        return 1;
    }
}
int findStudent(Student* headOfLinkedList, long studentNumber){
    if(checkForEmptyList(headOfLinkedList) == 1){
        Student* currentStudent = headOfLinkedList;
        while(currentStudent != NULL && currentStudent->studentNumber != studentNumber){
            currentStudent = currentStudent->nextStudent;
        }
        if(currentStudent == NULL){
            return 0;
        }else{
            return 1;
        }
    }else{
        return 0;
    }
}
void insertList(Student** headOfLinkedList, long studentNumber, char* studentName){
    Student* newStudent = NULL;
    Student* currentStudent = NULL;
    newStudent = (Student*)malloc(sizeof(Student));
    if(newStudent != NULL){
        newStudent->studentName = studentName;
        newStudent->studentNumber = studentNumber;
        newStudent->nextStudent = NULL;
        currentStudent = (*headOfLinkedList);
        if(currentStudent == NULL){
            (*headOfLinkedList) = newStudent;
        }else{
            while(currentStudent->nextStudent != NULL){ 
                currentStudent = currentStudent->nextStudent;
            }
            currentStudent->nextStudent = newStudent;
        }
    }else{
        printf("There is no memory space for new student...\n");
        exit(EXIT_FAILURE);
    }
}
void deleteList(Student** headOfLinkedList, long studentNumber){
    if(findStudent((*headOfLinkedList), studentNumber) == 1){
        Student* currentStudent = NULL;
        Student* previousStudent = NULL;
        Student* temporaryStudent = NULL;
        if((*headOfLinkedList)->studentNumber == studentNumber){
            temporaryStudent = (*headOfLinkedList);
            (*headOfLinkedList) = (*headOfLinkedList)->nextStudent;
            free(temporaryStudent);
        }else{
			previousStudent = (*headOfLinkedList);
			currentStudent = (*headOfLinkedList)->nextStudent;
			while(currentStudent != NULL && currentStudent->studentNumber != studentNumber){
				previousStudent = currentStudent;
				currentStudent = currentStudent->nextStudent;
			}
			temporaryStudent = currentStudent;
			previousStudent->nextStudent = currentStudent->nextStudent;
			free(temporaryStudent);
		}
	}else{
        printf("Student is not in the linked list...\n");
    }
}
void printLinkedList(Student* headOfLinkedList){
    if(headOfLinkedList == NULL){
        printf("The list is empty...\n");
    }else{
        Student* currentStudent = headOfLinkedList;
        while(currentStudent != NULL){
            printf("Name:%-s Number:%-ld\n", currentStudent->studentName, currentStudent->studentNumber);
            currentStudent = currentStudent->nextStudent;
        } 
    }
}
int main(void){
    Student* headOfStudentList = NULL;
    printLinkedList(headOfStudentList);
    for(int studentIndex = 0; studentIndex < NUMBEROFSTUDENTS; studentIndex ++){
        insertList(&headOfStudentList, *(studentNumbers + studentIndex), *(studentNames + studentIndex));
    }
    printLinkedList(headOfStudentList);
    printf("\n");
    deleteList(&headOfStudentList, 9000);
    printLinkedList(headOfStudentList);
    printf("\n");
    deleteList(&headOfStudentList, 1071);
    printLinkedList(headOfStudentList);
    return 0;
}

