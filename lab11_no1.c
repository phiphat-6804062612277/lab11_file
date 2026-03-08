#include <stdio.h>
#include <stdlib.h>
void addRecord(char *addName, int addAge);
int main() {
    char name[64]; int age;
    printf("Enter name: "); scanf("%s",&name);
    printf("Enter age: "); scanf("%d", &age);
    addRecord(name, age);
    return 0;
}
void addRecord(char *addName, int addAge) {
    FILE *fpt;
    if(fpt != NULL){
        printf("I can successfully open my file\n");
        fpt = fopen(".\\lab11\\no1\\first.txt","a");
        fprintf(fpt,"%s : %d\n",addName,addAge);
        fclose(fpt);
    } 
    else{
        printf("Error! I can't open my file\n");
    }

}
