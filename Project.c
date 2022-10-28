#include<stdio.h>
#include<string.h>

int main(void)
{
    FILE *fp;
    char c,dep[100],branch[100],firstname[100],lastname[100],ph[100],roll[100],z[1000];
    int i,x,choice,exist=0,choice1;
    long int rollno,phno;

    printf("\nEnter 1 to create a new Student Database\n");
    printf("Enter 2 to write to the existing Student Database\n");
    printf("Enter 3 to search whether a student has enrolled to the university or not\n");
    printf("Enter 4 to view the Student database\n\n");

    printf("Enter your choice here : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:

        printf("\n");
        printf("Your existing database will erased.If you still want to continue, enter 1\n");
        
        printf("\nEnter your choice here : ");
        scanf("%d",&choice1);

        switch(choice1)
        {
            case 1:

            printf("\nEnter the number of student details you want to enter : ");
            scanf("%d",&x);

            fp=fopen("StudentDatabase.txt","w+");

            fprintf(fp,"                                        STUDENT DATABASE     \n\n\n");

            for(i=1;i<=x;i++)
            {

              /*printf("\nEnter the name of student %d : ",i);
                scanf("%s",&name);
                fprintf(fp,"(%d)\n",i);
                fprintf(fp,"NAME : %s\n",name);*/

                printf("\nEnter the first name of student %d : ",i);
                scanf("%s",&firstname);
                fprintf(fp,"NAME : %s ",firstname);

                printf("Enter the last name of student %d : ",i);
                scanf("%s",&lastname);
                fprintf(fp,"%s\n",lastname);

                printf("Enter the enrollment number : ");
                scanf("%ld",&rollno);
                fprintf(fp,"ENROLLMENT NUMBER : %ld\n",rollno);

                printf("Enter the phone number : ");
                scanf("%ld",&phno);
                fprintf(fp,"PHONE NUMBER : %ld\n",phno);

                printf("Enter the department : ");
                scanf("%s",&dep);
                fprintf(fp,"DEPARTMENT : %s\n",dep);

                printf("Enter the branch : ");
                scanf("%s",&branch);
                fprintf(fp,"BRANCH : %s\n\n",branch);

            }

            fclose(fp);

            printf("\nDocument Updated and successfully logged out.");

            break;

            default:
            printf("Logged Out");

        }

        break;

        case 2 :

        printf("Document append mode!!!\n");

        printf("\nEnter the number of student details you want to enter : ");
        scanf("%d",&x);

        fp=fopen("StudentDatabase.txt","a");

        for(i=1;i<=x;i++)
        {

        printf("\nEnter the first name of student : ");
        scanf("%s",&firstname);
        fprintf(fp,"NAME : %s ",firstname);

        printf("Enter the last name of student : ");
        scanf("%s",&lastname);
        fprintf(fp,"%s\n",lastname);

        printf("Enter the enrollment number : ");
        scanf("%ld",&rollno);
        fprintf(fp,"ENROLLMENT NUMBER : %ld\n",rollno);

        printf("Enter the phone number : ");
        scanf("%ld",&phno);
        fprintf(fp,"PHONE NUMBER : %ld\n",phno);

        printf("Enter the department : ");
        scanf("%s",&dep);
        fprintf(fp,"DEPARTMENT : %s\n",dep);

        printf("Enter the branch : ");
        scanf("%s",&branch);
        fprintf(fp,"BRANCH : %s\n\n",branch);

        }

        fclose(fp);

        printf("\nDocument Updated and successfully logged out");

        break;
        
        case 3 :

        fp=fopen("StudentDatabase.txt","r");

        printf("\nEnter 1 if you want to search by enrollment number and 2 if you check by phone number\n");
        
        printf("\nEnter your choice here : ");
        scanf("%d",&choice1);

        switch(choice1)
        {
            case 1:

            printf("\nEnter the enrollment you to check\n");
            scanf("%s",&roll);

            while(fgets(z,1000,fp))
	        {
		      char *fp=strstr(z,roll);
		      if (fp!=NULL) 
		      {
			    exist=1;
			    break;
		      }
	        }

            fclose(fp);

	        if (exist==1)
	        {
		      printf("Student is already enrolled\n");
	        }
	        else 
	        {
		      printf("Student is not enrolled yet\n");
	        }

            printf("Logged out");

            break;

            case 2:

            printf("\nEnter the phone number you to check\n");
            scanf("%s",&ph);

            while(fgets(z,1000,fp))
	        {
		      char *fp=strstr(z,ph);
		      if (fp!=NULL) 
		      {
			    exist=1;
			    break;
		      }
	        }

            fclose(fp);

	        if (exist==1)
	        {
		      printf("Student is already enrolled\n");
	        }
	        else 
	        {
		      printf("Student is not enrolled yet\n");
	        }

            printf("Logged out");

            break;
            
        }

        break;

        case 4 :

        fp=fopen("StudentDatabase.txt","r");

        printf("The contents of the file are : \n");

        do 
        {
          c= fgetc(fp);
          printf("%c",c);
        } while(c!=EOF);

        printf("\n\n");
        printf("END OF FILE !!!!!!");

        fclose(fp);

        break;

        default:

        printf("\nInvalid Input!!!!\n");
        printf("To return back to the choices please press control,option and n together");
    }
}