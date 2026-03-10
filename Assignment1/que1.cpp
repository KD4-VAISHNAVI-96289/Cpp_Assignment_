#include <stdio.h>
struct Date
{
    int day;
    int month;
    int year;
};
void initDate(struct Date *ptrDate)
{
    ptrDate->day = 18;
    ptrDate->month = 02;
    ptrDate->year = 2003;
    // printf("Initialized successfully date");
    printf("Initialized successfully date: %d - %d -%d ",ptrDate->day,ptrDate->month,ptrDate->year);
}
void acceptDateFromConsole(struct Date *ptrDate)
{
    printf("Enter Day: ");
    scanf("%d\n", &ptrDate->day);
    printf("Enter month: ");
    scanf("%d\n", &ptrDate->month);
    printf("Enter year: ");
    scanf("%d\n", &ptrDate->year);
}
void printDateOnConsole(struct Date *ptrDate)
{
    printf("%d - %d - %d ", ptrDate->day, ptrDate->month, ptrDate->year);
}
int menuList(void)
{
    int choice;
    printf("0.Exit.\n");
    printf("1.initDate.\n");
    printf("2.acceptDateOnConsole.\n");
    printf("3.printDateOnConsole.\n");
    printf("Enter the choice : ");
    scanf("%d", &choice);
    return choice;
}
int main()
{
    int choice;
    struct Date dt;

    while ((choice = menuList()) != 0)
    {
        switch (choice)
        {
        case 1:
            initDate(&dt);
            break;
        case 2:
            acceptDateFromConsole(&dt);
            break;
        case 3:
            printDateOnConsole(&dt);
            break;
        }
    }
    return 0;
}
