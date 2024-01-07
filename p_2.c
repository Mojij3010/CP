// Author : Mojij Ansari
#include <stdio.h>
#include <string.h>

void swap (int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct lib {
    int acc_num;
    char tittle[100];
    char author[100];
    float price;
    int flag;
};

void sort (int *p,int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (p[i]>p[i+1]) swap(p+i,p+i+1);
        }
    }   
}

void add (struct lib l[],int num){
    
    for (int i = 0; i < num; i++)
    {
        printf("\nFor book %d\n", i + 1);
        printf("Enter acc_num\n");
        scanf("%d", &l[i].acc_num);
        printf("Enter tittle\n");
        scanf ("\n%[^\n]s",&l[i].tittle);
        printf("Enter author\n");
        scanf ("\n%[^\n]s",&l[i].author);
        printf("Enter price\n");
        scanf("%f", &l[i].price);
        printf("Enter flag\n");
        scanf("%d", &l[i].flag);
    }
}
void display (struct lib l[],int num){
    for (int i = 0; i < num; i++)
    {
        printf ("\n\n Displaying info for book %d\n",i+1);
        printf ("Acc num --> %d\n",l[i].acc_num);
        printf ("Tittle --> %s\n",l[i].tittle);
        printf ("Author --> %s\n",l[i].author);
        printf ("Price --> %f\n",l[i].price);
        printf ("Flag --> %d\n",l[i].flag);
    }
    
}
void aut (struct lib l[],int num,char auth[]){
    for (int i = 0; i < num; i++)
    {
        if (!(strcmp(auth,l[i].author))){
            printf ("Tittle name --> %s\n",l[i].tittle);
        }
    }
    
}
void book (struct lib l[],int num,int a){
    for (int i = 0; i < num; i++)
    {
        if (l[i].acc_num == a){
            printf ("Tittle --> %s\n",l[i].tittle);
        }
    }
    
}
void count (struct lib l[],int num){
    printf ("Number of books : %d\n",num);
}
void order (struct lib l[],int num){
    int arr[100];
    for (int i = 0; i < num; i++)
    {
        arr[i] = l[i].acc_num;
    }
    sort (arr,num);
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (arr[i] == l[j].acc_num){
                printf ("Acc num is %d and tittle of the book is %s\n",arr[i],l[j].tittle);
            }
        }   
    }
}
 
int main()
{
    struct lib l[100];
    int i = 1;
    char auth[100];
    int num;
    while (i!=7){
        printf ("\n\n1. Add book information\n2. Display book information\n3. List all books of given author\n4. List the title of specified book\n5. List the count of books in the library\n6. List the books in the order of accession number\n7. Exit\n");
        printf ("Choose an option from above choice\n");
        scanf ("%d",&i);
        if (!(i>0 && i<8)){
            printf ("ERROR : Enter number from list\n");
        }
        switch (i){
            case 1:
                printf ("Enter number of books\n");
                scanf ("%d",&num);
                add(l,num);
                break;
            case 2:
                display(l,num);
                break;
            case 3:
                printf ("Enter name of author\n");
                scanf ("\n%[^\n]s",&auth);
                aut(l,num,auth);
                break;
            case 4:
                printf ("Enter acc number to get tittle of book\n");
                int a;
                scanf ("%d",&a);
                book(l,num,a);
                break;
            case 5:
                count (l,num);
                break;
            case 6:
                order(l,num);
                break;
        }
    }
    return 0;
}