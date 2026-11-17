#include <stdio.h>

struct Employee {
    int id;
    char name[20];
    float salary;
};

int main() {
    FILE *fp;
    struct Employee e;
    int n, i;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    fp = fopen("emp.dat", "wb");

    for(i = 0; i < n; i++) {
        scanf("%d %s %f", &e.id, e.name, &e.salary);
        fwrite(&e, sizeof(e), 1, fp);
    }

    fclose(fp);

    fp = fopen("emp.dat", "rb");

    while(fread(&e, sizeof(e), 1, fp)) {

        if(e.salary > 50000)
            e.salary += e.salary * 0.05;
        else if(e.salary > 20000)
            e.salary += e.salary * 0.10;
        else
            e.salary += e.salary * 0.15;

        printf("%d %s %.2f\n", e.id, e.name, e.salary);
    }

    fclose(fp);

    return 0;
}