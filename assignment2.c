#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contacts {
    int id;
    char phone_no[11];
    char email[20];
    char name[20];
    char company[30];
};

struct Contacts list[1000];
int n, i;
int flag = 0;
int create_flag=0;

void Create() {
    
    printf("Enter number of contacts to add: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        list[i].id=i+1;
        printf("Enter phone number of %d: ", i + 1);
        scanf("\n");
        gets(list[i].phone_no);
        printf("Enter Name of %d: ", i + 1);
        scanf("\n");
        gets(list[i].name);
        printf("Enter email of %d: ", i + 1);
        scanf("\n");
        gets(list[i].email);
         printf("Enter company name of %d: ", i + 1);
        scanf("\n");
        gets(list[i].company);
    }
    create_flag=1;
   
}

void Display() {
    if(create_flag==1)
    {
    printf("\n%5s %20s %25s %25s %20s", "ID", "Phone Number", "Name", "Email", "Company");
    for (i = 0; i < n + flag; i++) {
        printf("\n%5d %20s %25s %25s %20s", list[i].id, list[i].phone_no, list[i].name, list[i].email, list[i].company);
    }
    printf("\n");
    }
    else if(create_flag==0)
    {
        printf("List is Empty!!!\n");
    }
}

void Insert() {
    list[i].id=n+flag+1;
    printf("Enter phone number: ");
    scanf("\n");
    gets(list[n + flag].phone_no);
    printf("Enter name: ");
    scanf("\n");
    gets(list[n + flag].name);
    printf("Enter Email: ");
    scanf("\n");
    gets(list[n + flag].email);
    printf("Enter Company: ");
    scanf("\n");
    gets(list[n + flag].company);
    flag++;
}

void Delete() {
    int flag_delete=0;
    if (n == 0) {
        printf("List is Empty\n");
    } else {
       {
        int pos, i;
       char value[30];
        printf("Enter the name of contact to delete: ");
        scanf("\n");
        gets(value);
        for (i = 0; i < n; i++) {
            if ((strcmp(list[i].name,value))==0) {
                pos=i+1;
          
            for (i = pos - 1; i < n; i++) {
                list[i] = list[i + 1];
            }
            n--;
            flag_delete=1;
            break;
            }
        else{
            flag_delete=0;
        }
    }
    if(flag_delete==1) 
    {
        printf("Contact Deleted!!!\n");
    }
    else if(flag_delete==0) 
    {
        printf("Contact not found!!!\n"); 
    }
    }
}
}

void Search() {
    if (n == 0) {
        printf("List is Empty!!!\n");
    } else {
        int flag1 = 0;
        char value[30];
        printf("Enter the name to be searched: ");
        scanf("\n");
        gets(value);
        for (i = 0; i < n; i++) {
            if ((strcmp(list[i].name,value))==0) {
                printf("Contact Record found: \n");
                 printf("\n%5s %20s %25s %25s %20s", "ID", "Phone Number", "Name", "Email", "Company");
                  printf("\n%5d %20s %25s %25s %20s", list[i].id, list[i].phone_no, list[i].name, list[i].email, list[i].company);
                flag1 = 1;
                printf("\n");
                break;
            }
        }
        if (flag1 == 0) {
            printf("Contact Not Found!!!\n");
        }
    }
}

void Edit()
{
    int flag_search=0;
   if (n == 0) {
        printf("List is Empty!!!\n");
    } else {
        int x;
        char value[30];
        printf("Enter the name of contact to edit: ");
        scanf("\n");
        gets(value);
        for (int i = 0; i < n; i++) {
            if ((strcmp(list[i].name,value))==0) {
                x=i;
                flag_search=1;
            }
        }
            if(flag_search==1){
                int choice;
                printf("Enter \n 1 to edit phone number\n 2 to edit name\n 3 to edit email\n 4 to edit company\n");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                printf("Enter phone number: ");
                scanf("\n");
                gets(list[x].phone_no);
                    break;
                 case 2:
                printf("Enter Name: ");
                scanf("\n");
                gets(list[x].name);
                    break;
                   case 3:
                printf("Enter email: ");
                scanf("\n");
                gets(list[x].email);
                    break;
                    case 4:
                printf("Enter company name: ");
                scanf("\n");
                gets(list[x].company);
                    break;
                default:
                    printf("Wrong Input!!!");
                    break;
                }
                
            }
        else if(flag_search==0){
            printf("Contact Not Found!!!\n");
            
        }
    } 
}


int main() {
    int choice;
    while (1) {
        system("cls");
        printf("1. Add new contacts to create list.\n");
        printf("2. Add new contact after list being created.\n");
        printf("3. List all Contacts.\n");
        printf("4. Delete a Contact\n");
        printf("5. Search Contacts.\n");
        printf("6. Edit a Contact\n");
        printf("7. Exit.\n");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Create();
                break;
            case 2:
                Insert();
                break;
            case 3:
                Display();
                break;
            case 4:
                Delete();
                break;
            case 5:
                Search();
                break;
            case 6:
                Edit();
                break;
            case 7:
                exit(0);
                return 0;
            default:
                printf("Invalid Choice...\n");
        }
        system("pause"); // press any key to continue
    }

    return 0;
}
