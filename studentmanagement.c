#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
struct date{
int day,month,year;
};

struct student{
int roll;
char name[50];
struct date DOB;
float marks;
};

int calculateAge(struct date DOB)
{
    time_t t = time(NULL);
    struct tm *today = localtime(&t);
    int currentDay = today->tm_mday;
    int currentMonth = today->tm_mon + 1; // tm_mon is 0-11
    int currentYear = today->tm_year + 1900;

    int age = currentYear - DOB.year;

    // If birthday has not occurred yet this year
        if (currentMonth < DOB.month || (currentMonth == DOB.month && currentDay < DOB.day))
            {
        age--;
    }

  return age;
}

int main()
{
    struct student s[100];
  int choice,count=0;
 printf("\n\n1.Enter student details:");
 printf("\n2.display student details:");
 printf("\n3.search student details:");
 printf("\n4.Exit\n\n");

 do{
    printf("Enter choice:");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        printf("\nROLL NO.:");
         scanf("%d",&s[count].roll);
          printf("NAME:");
         scanf("%s",&s[count].name);
        // fgets(s[count].name);
          printf("MARKS:");
         scanf("%f",&s[count].marks);
         printf("Enter date of birth:");
         scanf("%d %d %d",&s[count].DOB.day,&s[count].DOB.month,&s[count].DOB.year);
         count++;
         printf("Student added sucessfully!\n\n");
         break;

         case 2:
         if(count==0){
             printf("Student is not available for display!\n");
         }
         else{
             for(int i=0;i<count;i++)
             {
                 printf("Roll No.=%d\n",s[i].roll);
                 printf("Name=%s\n",s[i].name);
                 printf("Marks=%.2f\n",s[i].marks);
                 printf("Birth Date=%02d/%02d/%04d\n",s[i].DOB.day,s[i].DOB.month,s[i].DOB.year);
                 printf("Age  :%d years\n\n",calculateAge(s[i].DOB));
             }
         }
         break;
         case 3:
         {
          int roll,found=0;
             printf("Enter the roll no. to be search:");
             scanf("%d",&roll);

      for(int i=0;i<count;i++){
        // printf("Enter the roll no. to be search:");
         //scanf("%d",&roll);

         if(roll==s[i].roll)
         {
             printf("Student is found!\n");
             printf("Roll No.=%d\n",s[i].roll);
             printf("Name=%s\n",s[i].name);
             printf("Marks=%.2f\n",s[i].marks);
             printf("Age  :%02d years\n\n",calculateAge (s[i].DOB));
                 found=1;
                 break;
         }
        }

      if(found==0) {
        printf("student is not found!\n\n");}
       break;
     }
       case 4:
       printf("---EXIT---");
       break;

       default:
       printf("INVALID CHOICE.\n");
     }

 }while(choice!=4);
    return 0;
}
