#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char *name;
    int age;
    float ave;
}school;
int write_binary(char *filename,int total,school *student);
school *read_binary(char *filename,int total);
int main()
{
    int total = 3;
    school *students;
    students = (school *)malloc(sizeof(school)*total);
    students[0].name = malloc(sizeof(char)*10);
    strcpy(students[0].name,"halit");
    students[0].age = 18;
    students[0].ave = 98.2;

    students[1].name = malloc(sizeof(char)*10);
    strcpy(students[1].name,"batuhan");
    students[1].age = 19;
    students[1].ave = 98.9;
    
    students[2].name = malloc(sizeof(char)*10);
    strcpy(students[2].name,"aslan");
    students[2].age = 89;
    students[2].ave = 97.6;

    school *s2;
    if(write_binary("bin_file.bin",total,students)) printf("writing data is ok\n");
    int i;
    for(i = 0;i<total;i++)
        printf("%s student %d age %.2f average\n",students[i].name,students[i].age,students[i].ave);
    
    s2 = read_binary("bin_file.bin",total);
    for(i = 0;i<total;i++)
        printf("%s student %d age %.2f average\n",s2[i].name,s2[i].age,s2[i].ave);
    free(students[0].name);
    free(students[1].name);
    free(students[3].name);
    free(students);
    free(s2);
}
int write_binary(char *filename,int total,school *student)
{
    FILE *file = fopen(filename,"wb");
    fwrite(student,sizeof(school),total,file);
    fclose(file);
}
school *read_binary(char *filename,int total)
{
    FILE *file = fopen(filename,"rb");
    school *student = malloc(sizeof(school) * total);
    fread(student, sizeof(school), total, file);

    /*student[0].name = malloc(sizeof(char)*10);
    student[1].name = malloc(sizeof(char)*10);
    student[2].name = malloc(sizeof(char)*10);
    int i;
    for(i = 0;i<total;i++)
    {
        fread(student[i].name,sizeof(char),5,file);
        fread(&student[i].age,sizeof(int),1,file);
        fread(&student[i].ave,sizeof(float),1,file);
    }*/
    return student;
    fclose(file);
}   