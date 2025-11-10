#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char name[100];
    int id;
    char dept[100];
    float salary;
};

void sort(struct Employee **employees, int n, int index){
    if (n <= index) return;

    int minind = index;
    
    for (int i = index; i < n-1; i++){
        if (employees[i]->id < employees[minind]->id){
            minind = i;
        }
    }

    struct Employee *temp = employees[index];
    employees[index] = employees[minind];
    employees[minind] = temp;

    sort(employees, n, index+1);
}

void maxSalary(struct Employee** employees, int n){
    if (n == 0) return;

    int max = 0;

    for (int i = 0; i < n; i++){
        if (employees[i]->salary > employees[max]->salary){
            max = i;
        }
    }

    printf("Employee with maximum salary: \n");
    printf("Name: %sID: %dDept: %sSalary: %f", employees[max]->name, employees[max]->id, employees[max]->dept, employees[max]->salary);

}

int main(void){
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    getchar();

    struct Employee** employees = malloc(n*sizeof(struct Employee*));

    for (int i = 0; i < n; i++){
        employees[i] = malloc(sizeof(struct Employee));

        printf("Enter name of employee %d: ", i+1);
        fgets(employees[i]->name, sizeof(employees[i]->name), stdin);

        printf("Enter id of employee %d: ", i+1);
        scanf("%d", &employees[i]->id);
        getchar();

        printf("Enter department of employee %d: ", i+1);
        fgets(employees[i]->dept, sizeof(employees[i]->dept), stdin);

        printf("Enter salary of employee %d: ", i+1);
        scanf ("%f", &employees[i]->salary);
        getchar();
    }

    sort(employees, n, 0);

    printf("\nSorted employees by ID: \n");

    for (int i = 0; i < n; i++){
        printf("Name: %s\n", employees[i]->name);
        printf("ID: %d\n", employees[i]->id);
        printf("Department: %s\n", employees[i]->dept);
        printf("Salary: %f\n", employees[i]->salary);
        printf("--------------------------------\n");
    }

    maxSalary(employees, n);
}