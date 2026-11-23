#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Book{
    int Book_ID;
    char Title[50];
    char Author[50];
    char Status[10];
    float Price;
};
struct Book *b;
int n;
void create()
{
    int i;
    printf("Enter no. of books:");
    scanf("%d",&n);
    b=(struct Book *)malloc(n * sizeof(struct Book));
    for(i=0;i<n;i++)
    {
        printf("\n Enter Book %d details \n",i+1);
        printf("Book ID :- ");
        scanf("%d", &b[i].Book_ID);
        printf("Title : ");
        scanf("%s", b[i].Title);
        printf("Author: ");
        scanf("%s", b[i].Author);
        printf("price: ");
        scanf("%f",&b[i].Price);

        strcpy(b[i].Status,"Available");
        
    }
}
//display available books
void display()
{
    int i ;
    printf("\n---Available Books---\n");
    for(i=0;i<n;i++)
    {
        if(strcmp(b[i].Status,"Available")==0)
        {
            printf("\nBook ID: %d", b[i].Book_ID);
            printf("\nAuthor: %s", b[i].Author);
            printf("\nPrice: %.2f", b[i].Price);
            printf("\nStatus: %s\n", b[i].Status);
            printf("\nTitle: %s", b[i].Title);
           
        
    }
}
}

/* Search book */ 

void search() 
{ 
int id, i; 
 printf("Enter Book ID: "); 
 scanf("%d", &id); 
 for(i = 0; i < n; i++) 
    { 
       if(b[i].Book_ID == id) 

        { 
            printf("\nBook Found!\n"); 
            printf("Title: %s\n", b[i].Title); 
            printf("Author: %s\n", b[i].Author); 
            printf("Price: %.2f\n", b[i].Price); 
            printf("Status: %s\n", b[i].Status); 
            return; 

        } 

    } 
    printf("Book not found!\n"); 

} 
/* Issue book */ 
void issueBook() 
{ 
    int id, i; 
    printf("Enter Book ID to issue: "); 
    scanf("%d", &id); 
    for(i = 0; i < n; i++) 

    { 
        if(b[i].Book_ID == id) 

        { 

            if(strcmp(b[i].Status, "Available") == 0) 
            { 
                strcpy(b[i].Status, "Issued"); 
                printf("Book issued successfully!\n"); 

            } 
            else 
            { 
                printf("Book is already issued!\n"); 
            } 
            return; 
        } 
    } 
    printf("Book not found!\n"); 

} 
/* Return book */ 
void returnBook() 
{ 
    int id, i; 
    printf("Enter Book ID to return: "); 
    scanf("%d", &id); 
    for(i = 0; i < n; i++) 

    { 
        if(b[i].Book_ID == id) 
        { 
            if(strcmp(b[i].Status, "Issued") == 0) 

            { 
                strcpy(b[i].Status, "Available"); 
                printf("Book returned successfully!\n"); 

            } 
            else 
            { 
                printf("Book is already available!\n"); 
            } 
            return; 
        } 
    } 
    printf("Book not found!\n"); 

} 
/* Main function */ 
int main() 
{ 
    int choice; 
    do 
    { 
        printf("\n===== LIBRARY MENU =====\n"); 
        printf("1. Add Book Records\n"); 
        printf("2. Display Books\n"); 
        printf("3. Search Book\n"); 
        printf("4. Issue Book\n"); 
        printf("5. Return Book\n"); 
        printf("6. Exit\n"); 
        printf("Enter choice: "); 
        scanf("%d", &choice); 

        switch(choice) 
        { 
            case 1: 
                create(); 
                break; 
            case 2: 
                display(); 
                break; 
            case 3: 
                search(); 
                break; 
            case 4: 
                issueBook(); 
                break; 
            case 5: 
                returnBook(); 
                break; 
            case 6: 
                printf("Thank you!\n"); 
                free(b); 
                break; 
            default: 
                printf("Invalid choice!\n"); 
        } 
    } 
    while(choice != 6); 
 return 0; 

}