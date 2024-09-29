#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[50];  // Fixed-length buffer for name
    int age;
    float ave;
} school;

int write_binary(char *filename, int total, school *students);
school *read_binary(char *filename, int total);

int main() {
    int total = 3;
    school *students = (school *)malloc(sizeof(school) * total);

    strcpy(students[0].name, "halit");
    students[0].age = 18;
    students[0].ave = 98.2;

    strcpy(students[1].name, "batuhan");
    students[1].age = 19;
    students[1].ave = 98.9;

    strcpy(students[2].name, "aslan");
    students[2].age = 89;
    students[2].ave = 97.6;

    if (write_binary("bin_file.bin", total, students)) {
        printf("writing data is ok\n");
    } else {
        printf("writing data failed\n");
    }

    for (int i = 0; i < total; i++) {
        printf("%s student %d age %.2f average\n", students[i].name, students[i].age, students[i].ave);
    }

    school *s2 = read_binary("bin_file.bin", total);

    for (int i = 0; i < total; i++) {
        printf("%s student %d age %.2f average\n", s2[i].name, s2[i].age, s2[i].ave);
    }

    free(students);
    free(s2);

    return 0;
}

int write_binary(char *filename, int total, school *students) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("File opening failed");
        return 0;
    }

    fwrite(&total, sizeof(int), 1, file); // Write the total number of students
    fwrite(students, sizeof(school), total, file); // Write all student data

    fclose(file);
    return 1;
}

school *read_binary(char *filename, int total) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("File opening failed");
        return NULL;
    }

    int read_total;
    fread(&read_total, sizeof(int), 1, file); // Read the total number of students
    if (read_total != total) {
        printf("Total number of students mismatch\n");
        fclose(file);
        return NULL;
    }

    school *students = (school *)malloc(sizeof(school) * total);
    fread(students, sizeof(school), total, file); // Read all student data

    fclose(file);
    return students;
}
