#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  char *name;
  int marks;
} student;

bool grade(int count, student students[]);
bool stats(int count, student students[]);

int main(int argc, char *argv[]) {
  int count = argc - 1;
  student students[count];

  if (argc < 3) {
    printf("Please Enter Names of Two Students\n");
    return 1;
  }

  for (int i = 0; i < count; i++) {
    students[i].name = argv[i + 1];
  }

  for (int i = 0; i < count; i++) {

    if ((strcmp(students[i].name, "NULL")) == 0) {
      break;
    }

    else {
      printf("Enter the marks of %s: ", students[i].name);
      scanf("%d", &students[i].marks);

      if (students[i].marks > 100 || students[i].marks < 1) {
        printf("Please Enter Marks below or equal to 100 and above 1!\n");
        printf("Enter the marks of %s: ", students[i].name);
        scanf("%d", &students[i].marks);
      }
    }
  }
  printf("\n");

  grade(count, students);
  stats(count, students);
}

bool grade(int count, student students[]) {
  printf("STUDENTS GRADE\n");
  for (int i = 0; i < count; i++) {

    if (students[i].marks >= 80) {
      printf("%s: A\n", students[i].name);
    }

    else if (students[i].marks >= 60) {
      printf("%s: B\n", students[i].name);
    }

    else if (students[i].marks >= 33) {
      printf("%s: C\n", students[i].name);
    } else if (students[i].marks < 33) {
      printf("%s: Fail\n", students[i].name);
    }
  }
  printf("\n");
  return true;
}
bool stats(int count, student students[]) {
  int max = students[0].marks;
  int min = students[0].marks;
  int avg = 0;

  printf("STATISTICS\n");
  for (int i = 0; i < count; i++) {

    if (max < students[i].marks) {
      max = students[i].marks;
    }

    if (min > students[i].marks) {
      min = students[i].marks;
    }
  }
  for (int i = 0; i < count; i++) {

    if (max == students[i].marks) {
      printf("Highest Score: %s(%i)\n", students[i].name, max);
    }
    if (min == students[i].marks) {
      printf("Lowest Score: %s(%i)\n", students[i].name, min);
    }
  }

  for (int i = 0; i < count; i++) {
    avg += students[i].marks;
  }

  printf("Average: %i\n", avg / count);
  return true;
}
