#include <stdio.h>
#define NO_SCORE 5
#define NO_student 4
typedef struct {
    char name[25];
    char surname[30];
    int score[NO_SCORE];
} Student;

void readStudentData(Student *);
void recordstudent(Student *);
void rfile(Student *);
void findTotalScore(Student *);
void findLessThanTen(Student *);

void main() {
    Student std[NO_student],rfstd[NO_student];
    int i;
    for (i=0;i<NO_student;i++){
        readStudentData(&std[i]);
        recordstudent(&std[i]);
    }
    rfile(rfstd);
    for (i=0;i<NO_student;i++){
        findTotalScore(&rfstd[i]);
    }
}

void readStudentData(Student *pStd) {
    int i;
    printf("Enter student data\n");
    printf("\tName : ");
    scanf("%s", &pStd->name);
    printf("\tSurname : ");
    scanf("%s", &pStd->surname);
    for (i=0; i<NO_SCORE; i++) {
        printf("\tScore %d : ", i+1);
        scanf("%d", &pStd->score[i]);
    }
}

void recordstudent(Student *std){
    FILE *fpt;
    fpt = fopen(".\\lab11\\no2\\std10.dat","a");
    fprintf(fpt,"%s %s",std->name,std->surname);
    for(int i = 0;i<NO_SCORE;i++){
        fprintf(fpt," %d",std->score[i]);
    }
    fprintf(fpt,"\n");
    fclose(fpt);
}

void rfile(Student *rs){
    int i;
    FILE *rsf;
    rsf = fopen(".\\lab11\\no2\\std10.dat","r");
    for (i=0;i<NO_student;i++){
        fscanf(rsf,"%s %s",rs[i].name,rs[i].surname);
        fscanf(rsf,"%d %d %d %d %d",&rs[i].score[0],&rs[i].score[1],&rs[i].score[2],&rs[i].score[3],&rs[i].score[4]);
    }
    fclose(rsf);
}

void findTotalScore(Student *pStd) {
    int i;
    float avg,total=0.0;
    printf("\n\nPrint student data");
    printf("\n\t%s %s got score ", pStd->name, pStd->surname);
    for (i=0; i<NO_SCORE; i++) {
        printf("%6d", pStd->score[i]);
        total += pStd->score[i];
    }
    printf("\n\tTotal score is %.2f",total);
    avg = total / NO_SCORE;
    printf("\n\tAverage score is %.2f", avg);
    findLessThanTen(pStd);
}

void findLessThanTen(Student *s) {
    int i,count=0;
    printf("\n\tScore less than 10");
    for (i=0; i<NO_SCORE; i++) {
        if (s->score[i] < 10) {
            printf("\n\tTest no.%d - %d", i+1, s->score[i]);
            count++;
        }
    }
    if (count==0)
        printf(" -> None");
}