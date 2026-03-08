#include <stdio.h>
#include <stdlib.h>
void addRecord(char *addName, int addAge);

int main() {
char name[64]; int age;
printf("Enter name: "); scanf("%s", name);
printf("Enter age: "); scanf("%d", &age);
addRecord(name, age);
return 0;
}
void addRecord(char *addName, int addAge) {
	FILE *fptr;
	fptr = fopen(".\\lab11\\no1\\first.txt","a");
	if (fptr==NULL){
		exit(1);
	}
	fprintf(fptr,"Name: %s Age %d\n",addName,addAge);
	fclose(fptr);
}
