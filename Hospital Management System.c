//Developed By : Muhammad Ehtasham Arif 
// #Fast National University.
//E-mail  : ahtashamarif001@gmail.com

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Header files 
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
//functions
    void search_record();
    void Login();
    void Admit_patient();
    void Patient_record();
    void Patient_List();
    void delete_data();
    void Doctor_record();
    void display_doctor_record();
    void Remove_doctor();
    void home_page();
   
  /************************************************/
// function to Display title
/************************************************/ 
void title()
{
    printf("\n\n\n");
    printf("\n\t\t\t  */////////////////////////////////////////////////////////*\n");
    printf("  \t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                    TO                     =");
    printf("\n\t\t\t        =                 HOSPITAL                  =");
    printf("\n\t\t\t        =                 MANAGEMENT                =");
    printf("\n\t\t\t        =                  SYSTEM                   =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  *////////////////////////////////////////////////////////*\n");
  
 }
 
 /************************************************/
// function to Login into the system
/************************************************/
 void Login()
 {
      int try=3;
  do
    {
  		 char id[100];
  		 char id_1[100]="test";
  		 char password[100];
 		 char password1[100]="fast123";
 		 title();
 		 printf("\n\t\t\t----------LOGIN PAGE------------\n\n");
  		 printf("\n\t\t\tENTER YOUR USERNAME :");
  		 scanf("%s",id);
 		 printf("\n\t\t\tENTER YOUR PASSWORD :");
  		 scanf("%s",password);
  		
          if(strcmp(password,password1)==0 && strcmp(id,id_1)==0)
  	   {
  	         system("clear");//To clear the screen
  	         sleep(1);
  	         break;
  	   }  
  	  else 
  	  
  	   {
   		try--;
 		printf("\t\t\tERROR!\n WRONG USERNAME OR PASSWORD! try again\n");
 	    }
 	if(try==0)
 	{
 	Login();
 	}
      }
 	while(try!=0);
  }
 /************************************************/
// function to Display Home Page Content.
/************************************************/
 void home_page()
 {
      system("clear");//To clear the screen
      int opt;
      int choice;
      title();
      printf("\n\t\t\tChoose One of The following:\n");
      printf("\t\t\t1):Admit Patient:");
      printf("\n\t\t\t2):Patient List:");
      printf("\n\t\t\t3):Discharge Patient:");
      printf("\n\t\t\t4):Add Doctor:");
      printf("\n\t\t\t5):Doctor List:");
      printf("\n\t\t\t6):Remove Doctor:");
      printf("\n\t\t\t7):Exit:\n\n");
      scanf("%d",&choice);
      getchar();
			switch(choice)//using switch case.
			{
			
				case 1:
				{	
				Admit_patient();
				break;
				}
				case 2:
				{
				Patient_List();
				break;
				}
				case 3:
				{
				delete_data();
				break;      
				}	
				case 4:
				{
				Doctor_record();
				break;
				}
				case 5:
				{
				display_doctor_record();
				break;
				}
				case 6:
				{
				Remove_doctor();
				}
				case 7:
				{
                                  break;
                                }
				default:
				{
				printf("ERROR!\nINVALID INPUT\n");
				}
			}
}

/************************************************/
// function to Search the Records.
/************************************************/
 void search_record()
 {
            int opt;
            char User_name[11];
            char opt1;
            printf("\n\t\tDO You Want To Search\n\t\t1:Yes\n\t\t2:N0\n");
            scanf("%d",&opt);
            getchar();
  	if(opt==1)
 	{ 
 	    printf("\n\t\tPlease Enter The first Name of the Patient:");
	    scanf("%s",User_name);
	    getchar();
	    FILE *patient_file=fopen("patient.txt","r");
	    char name1[10];
 	    char name2[10];
 	    int test=0;
 	    int age;
	    char gender;
	    char disease[10];
	    char phone_no[11];
	    while(fscanf(patient_file,"%s %s %d %c %s %s",name1,name2,&age,&gender,disease,phone_no)!=EOF)
	      {
	      	if(strcmp(name1,User_name)==0)
	      	{
	      	  test=2;
      			printf("\n\t\tRecord Found\n\n");
      			printf("Here's the Record that you or searching for....\n\n");
      			printf("---------------------------------------------------------------------------\n");
      			printf("\nName\t\t\t\tAge\t\t Gender\t\tDisease\t\tPhone_no\n");
      			printf("----------------------------------------------------------------------------\n");
      			printf("\n%s%s\t\t\t%d\t\t%c\t\t%s\t\t%s\n",name1,name2,age,gender,disease,phone_no);
      			
     		 }
      	      }
      	      if(test==0)
      	      {
                  printf("\n\t\t\tRECORD NOT FOUND!\n\t");
                  
                  }
      	  }
	else
	{
	                printf("EXITING....\n\n");
	                sleep(2);
      	                Admit_patient();
	}
                 do{
                        printf("\n\t\tEnter E to exit\n");
      		        scanf(" %c",&opt1);
      		        if(opt1=='e' || opt1=='E')
      		        {
      		        Admit_patient();
      		        break;
      		        }
      		        printf("ERROR! INVALID INPUT\n");
      		     }
      		        while(opt1!='e' || opt1!='E');
  }

/************************************************/
// function to delete a data from a file
/************************************************/
void delete_data() 
{
        system("clear");
        char opt;
        char User_name1[10];
        char User_name2[10];
        char name1[10];
        char name2[10];
        int age;
        char gender;
        char disease[10];
        char phone_no[11];
        int status = 0;

        FILE *patient_file = fopen("patient.txt", "r");
        FILE *temp_file = fopen("temp.txt", "w");

        if (patient_file == NULL) 
        {
        printf("\n\t\tNo Patient Record\n");
         } 
        else 
        {
            printf("\n\t\tWhich Patient Record do you Want to Delete(Discharge):\n");
            printf("\n\t\tEnter First Name of the Patient:");
            scanf("%s",User_name1);
            printf("\n\t\tEnter Last Name of the Patient:");
            scanf("%s",User_name2);

        while (fscanf(patient_file, "%s %s %d %c %s %s\n", name1, name2, &age, &gender, disease,phone_no) != EOF) 
        {
            if (strcmp(User_name1, name1) == 0 && strcmp(User_name2, name2) == 0)
             {
                status = 1;
            } 
            else 
            {
                fprintf(temp_file, "%s %s %d %c %s %s\n", name1, name2, age, gender, disease,phone_no);
            }
        }
        
        if (status == 1) 
        {
              printf("\n\t\tRecord of %s %s Deleted Successfully....", User_name1, User_name2);
        } 
        else 
        {
              printf("\n\t\tRecord not found.");
        }

              fclose(patient_file);
              fclose(temp_file);
              remove("patient.txt");
              rename("temp.txt", "patient.txt");
        }
    do{
              printf("\n\t\tENTER 'E' TO EXIT \n\t\t\n ");
              scanf(" %c",&opt);
    if(opt=='e' || opt=='E')
    {
              home_page();
              break;
    }
    else
    {
              printf("\t\tERROR!\n\t\tINVALID CHOICE ");
    }
    }
    while(opt!='e' || opt!='E');
}

/*************************************************/
 // function that admit patient records.
 /*************************************************/
 void Admit_patient()
{
            sleep(1);
            system("clear");
            int opt;
            char opt2;
            printf("\t\t\tChoose One of The following\n");
            printf("\t\t\t1:Add Patient Record\n");
            printf("\t\t\t2:Search Patient Record\n");
            printf("\t\t\t3:Delete Patient Record\n");
            printf("\t\t\t4:Exit(Home Page)\n\n");
            scanf("%d",&opt);
            getchar();
            switch(opt)
		{  
		case 1:
 		{
 		Patient_record();
 		break;
 		}
		case 2:
 		{
 		 search_record();
 		break;
 		}
 		case 3:
 		{
 		delete_data();
 		}
 		case 4:
 		{
 		home_page();
 		break;
 		}
		default:
 		{
 		printf("ERROR!\nINVALID INPUT CHOICE");
  		break;
 		}
 		}
}

 /************************************************/
 // function that show list of admitted patients.
 /************************************************/
 void Patient_List()
 {
           char opt;
 	   char name1[10];
 	   char name2[10];
 	   int age;
	   char gender;
	   char disease[10];
	   char phone_no[11];
	   FILE *patient_file;
	   patient_file=fopen("patient.txt","r");
	   if(patient_file==NULL)
	   {
	    printf("Error");
	   }
	   printf("_____________________________________________________________________\n");
	   printf("\nName\t\t\tAge   Gender  Disease       Phone_no\n");
	   printf("_____________________________________________________________________\n");
           while(fscanf(patient_file,"%s %s %d %c %s %s\n",name1,name2,&age,&gender,disease,phone_no)!=EOF)
           {
    	    printf("\n%s%s\t\t%d\t%c\t%s\t\t%s\n",name1,name2,age,gender,disease,phone_no);
	   }
	  fclose(patient_file);
	
           do{
               printf("\n\t\tENTER 'E' TO EXIT \n\t\t\n ");
               scanf(" %c",&opt);
               if(opt=='e' || opt=='E')
               {
               home_page();
               break;
               }
               else
               {
               printf("\t\tERROR!\n\t\tINVALID CHOICE ");
               }
               }
               while(opt!='e' || opt!='E');
 }
 
 /*************************************************/
 // function take information of patient from user
 /*************************************************/
 void Patient_record()
 {
            system("clear");
            sleep(1);
            char opt;
            char name1[10];
            char name2[10];
            int age;
	    char gender;
	    char disease[10];
	    char phone_no[11];
            FILE *patient_file;
            patient_file=fopen("patient.txt","a");
            if(patient_file==NULL)
            {
                       printf("FIle cannot be created\n");
            }
  	
              printf("\n\t\tEnter Name of Patient:");
              scanf("%s",name1);
              getchar();
              printf("\n\t\tEnter Last Name:");
              scanf("%s",name2);
              getchar();
              printf("\n\t\tEnter Age:");
              scanf("%d",&age);
	      getchar();
	      printf("\n\t\tEnter Gender(M or F):");
	      scanf(" %c",&gender);
	      getchar();
	      printf("\n\t\tEnter Disease:");
	      scanf("%s",disease);
	      getchar();
	      printf("\n\t\tEnter contact Number:");
	      scanf("%s",phone_no);
	      getchar();
              fprintf(patient_file,"%s %s %d %c %s %s\n",name1,name2,age,gender,disease,phone_no);
              fclose(patient_file);
              do{
               printf("\n\t\tENTER 'E' TO EXIT \n\t\t\n ");
               scanf(" %c",&opt);
               if(opt=='e' || opt=='E')
               {
               home_page();
               break;
               }
               else
               {
               printf("\t\tERROR!\n\t\tINVALID CHOICE ");
               }
    }
               while(opt!='e' || opt!='E');
}
/*********************************************/
//Function to remove the information of doctor.
/***********************************************/
void Remove_doctor()
{
           char opt;
           int test=0;
           char first_Name[15];
           char second_Name[15];
           char Specialization[15];
           int experience;
           char graduation[10];
           char Assistant_no[11];
           char User_name1[10];
           char User_name2[10];
	   FILE *doctor_file=fopen("doctor.txt","r");
	   FILE *temp=fopen("temp2.txt","w");
	   if(doctor_file==NULL)
	   {
	   printf("\n\t\tStruggling while opening the file\n");
	   }
           else
	   {
	  printf("\n\t\tWhich Doctor do you Want to Remove\n\n");
	  printf("\n\t\tEnter First Name:");
	  scanf("%s",User_name1);
	  printf("\n\t\tEnter Last Name:");
	  scanf("%s",User_name2);
          while(fscanf(doctor_file,"%s %s %s %d %s %s",first_Name,second_Name,Specialization,&experience,graduation,Assistant_no)!=EOF)
          {
          if (strcmp(User_name1,first_Name)==0 && strcmp(User_name2,second_Name)==0)
     	    {
     	     // if record found so that can be skiped 
     	      test=1;
     	    }
          else 
           {
           fprintf(temp,"%s %s %s %d %s %s\n",first_Name,second_Name,Specialization,experience,graduation,Assistant_no);
           }
         }
     	  if(test==1)
    	  {
    	  printf("\n\t\tRecord of %s %s doctor Removed Successfully\n",User_name1,User_name2);
    	  printf("\n\t\tGOOD BYE DOCTOR %s %s WE WILL NEVER FORGET YOUR SERVICE FOR US\n",User_name1,User_name2);
    	  }
    	  else
    	  {
    	  printf("\n\t\tThe Record are not Found in our data base\n");
    	   }
    	 
          fclose(doctor_file);
          fclose(temp);
          remove("doctor.txt");
          rename("temp2.txt","doctor.txt");
          }
          do{
            printf("ENTER E TO Exit:");
            scanf(" %c",&opt);
            if(opt=='e' || opt=='E')
            {
            home_page();
            break;
            }
            {
            printf("\n\t\tERROR!\n\t\tINVALID INPUT \n");
            }
            }
            while(opt!='e' || opt!='E');
}

/*********************************************/
//Function to Add Doctor Record.
/***********************************************/
void Doctor_record()
{
            char opt;
            char first_Name[15];
            char second_Name[15];
            char Specialization[15];
            int experience;
            char graduation[10];
            long long int Assistant_no;

            FILE *doctor_file=fopen("doctor.txt","a");
	    printf("\n\t\tENTER FIRST NAME:");
	    scanf("%s",first_Name);
	    getchar();
	    printf("\n\t\tENTER LAST NAME:");
	    scanf("%s",second_Name);
	    getchar();
	    printf("\n\t\tENTER SPECIALIZATION:");
	    scanf("%s",Specialization);
	    getchar();
	    printf("\n\t\tPLEASE ENTER EXPERIENCE IN THE FIELD:");
	    scanf("%d",&experience);
	    printf("\n\t\tENTER UNIVERSITY NAME:");
	    scanf("%s",graduation);
	    getchar();
	    printf("\n\t\tENTER ASSISTANT NUMBER:");
	    scanf("%Ld",&Assistant_no);
	
            fprintf(doctor_file,"%s %s %s %d %s %Ld\n",first_Name,second_Name,Specialization,experience,graduation,Assistant_no);
            fclose(doctor_file);
            do{
                printf("ENTER E TO Exit:");
                scanf(" %c",&opt);
             if(opt=='e' || opt=='E')
              {
                 home_page();
                 break;
               }
              {
                 printf("\n\t\tERROR!\n\t\tINVALID INPUT \n");
               }
 }
             while(opt!='e' || opt!='E');
 }
/************************************************/
//Function to Display the Doctor record.
/***********************************************/
void display_doctor_record()
{
             char opt;
             char first_Name[10];
             char second_Name[10];
             char Specialization[20];
             int experience;
             char graduation[100];
             long long int  Assistant_no;
             FILE *doctor_file=fopen("doctor.txt","r");
             if(doctor_file==NULL)
             {
               printf("ERROR\n");
             }
             printf("____________________________________________________________________________________________\n");
             printf("Name\t\t\tSpecialization\tExperince\tGraduation\tAssistant Number\n");
             printf("____________________________________________________________________________________________\n");

              while(fscanf(doctor_file,"%s %s %s %d %s %Ld\n",first_Name,second_Name,Specialization,&experience,graduation,&Assistant_no)!=EOF)
              {
               printf("%s%s\t\t%s\t\t%d\t\t%s\t\t%Ld\t\t\n",first_Name,second_Name,Specialization,experience,graduation,Assistant_no);
              }
             fclose(doctor_file);
             do{
              printf("ENTER E TO Exit:");
              scanf(" %c",&opt);
              if(opt=='e' || opt=='E')
              {
              home_page();
              break;
              }
              {
              printf("\n\t\tERROR!\n\t\tINVALID INPUT \n");
              }
              }
              while(opt!='e' || opt!='E');

 }
 /************************************************/ 
//Main Function
 /************************************************/
 int main(void)
 {
              Login();
              title();
              home_page();
 
              return 0;
 
 }
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
