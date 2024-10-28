#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>


// Define color codes
#define RESET "\x1b[0m"           // Reset all colors to default
#define RED "\x1b[31m"       
#define GREEN "\x1b[32m"   
#define BLUE "\x1b[34m"  

// var
int choix,i,number,found,Size=0;
bool saved;
char del[30],left,check[30];
	FILE *pfile;

//address structure
struct adresse{

    char rue[50];
    char ville[30];
    int code_postal;

};

//personne structure 

typedef struct {
    int id;
    char name[30];
    int age;
   struct adresse add;

}Personne;
    int Add(Personne p[]);
    int Delete(Personne p[]);
    int Update(Personne p[]);
    int Read(Personne p[]);
    int Menu(Personne p[]);
        int Save(Personne p[]);

    
int main (){
     system("color 0");


// caling add function first to add data
// inside data after finishing adding data we are going to show up a menu to update delete ...

   Personne p[Size];
    Menu(p);

    return ;

}

int Menu(Personne p[] ){
	




    // Menu the select what users want to do more  it comes after add() function
     do{
    printf(GREEN"\n\n \t\t\t#################Menu################\n"RESET);
    printf("\n\n\t\t\t\tEnter (0) To Exit  # \n\n");
    printf("\t\t\t\tEnter (1) To Update  data # \n\n");
    printf("\t\t\t\tEnter (2) To Read  data # \n\n");
    printf("\t\t\t\tEnter (3) To Delete  data # \n\n");
    printf("\t\t\t\tEnter (4) To Add new data  data # \n\n");
        printf("\t\t\t\tEnter (5) To Save File # \n\n");

    printf("\n\n\t\t --> Go To : $ ");
    scanf("%d",&choix);
    
      // check choix and move to funtions

          switch(choix){
          	case 0:
          		Exit(p);
          		break;
          case 1:
              Update(p);
            break;
            case 2:
              Read(p);
            break;
            case 3:
              Delete(p);
            break;
            case 4:
                Add(p);
                break;
                case 5:
                	Save(p);
          		break;
            default: printf(RED"\n\n\t\tYou should Enter a number Related to The Tabel"RESET);


          }

    }while(choix<0||choix>5);


return;
}

int Add(Personne p[]){
	

printf(GREEN"\n\n\t\t\t\t<<<<<<<<<< Add >>>>>>>>>>\n\n"RESET);
 
  printf(RED"\n\n\t\t  $$$$ Enter (0)  To Back To Main Menu In any time $$$ \n\n"RESET);

 
    printf(" \n\t\t  ->> number  of person wanted to add $   ");


   scanf("%d",&number);
   
  
   
    number=Size+number;


        for(i=Size;i<number;i++){
        


            printf(GREEN"\n\t\t\t**************Person %d****************\n"RESET,i+1);
             printf(RED"\n\n\t\t  $$$$ Note : Enter (0)  To Back To Main  $$$ \n\n"RESET);
                printf("\n\n\t\t  >>> Enter the name :  ");
                
                
          scanf(" %[^\n]s",p[i].name);
          	if(strcmp(p[i].name,"0")==0)
          	{
          		
          		number=i+1;
          		 Menu(p);
          		 break;
          		
			  }
			  else{
			
        	       
         printf("\t\t  >>> Enter the age :  ");
          scanf("%d",&p[i].age);


        printf("\t\t  >>> Enter the street  :  ");
          scanf(" %[^\n]s",p[i].add.rue);

          printf("\t\t  >>> Enter the city  :  ");
          scanf(" %[^\n]s",p[i].add.ville);
          printf("\t\t  >>> Enter the code postal  :  ");
          scanf("%d",&p[i].add.code_postal);
          p[i].id=i+1;
                  Size=Size+i+1;

          printf(BLUE"\n\n\t\t\t\t* Note You Should Save Befor Exit  * \n\n"RESET);

          
          

  }

        }
        
        Menu(p);

return;



}

int Delete(Personne pers[]){
    found=-1;

    printf(GREEN"\n\t\t\t\t<<<<<<<<<<Delete>>>>>>>>>>\n"RESET);

    if(Size==0){

            printf(RED"\n\n\t\t\t\tNo Data to Delete Add new !    \n "RESET);

    Add(pers);
    return;
}

else{




      printf("\n\t\tEnter Name of person wanted to Delete : ");
      scanf(" %[^\n]s",&del);



      for(i=0;i<number;i++){

            if(Size>=0&&strcmp(del,pers[i].name)==0)
            {
                found=i;
                break;
            }


      }

      if(found>=0){



        for(i=found;i<number-1;i++)
        {
            pers[i]=pers[i+1];
            
        }

        number--;
        Size--;
        printf(BLUE"\n\n\t\t\t\t<<<<<<<<<person %d Deleted >>>>>>>>>>"RESET,pers[i].id);
        saved==false;
		Save(pers);  
        return;
      }

      else {
            printf(RED"\t\t\t\t<<<<<<<<<No Person Find >>>>>>>>>>>>>>"RESET);
      Menu(pers);
      return;
      }






}


}

int Read(Personne pers[]){

printf(GREEN"\n\t\t\t\t<<<<<<<<<< Read >>>>>>>>>>\n"RESET);

if(Size==0){

            printf(RED"\n\n\t\t\t\tNo Data to Display Add new    \n "RESET);

    Add(pers);
    return;
}

else {
for(i=0;i<number;i++){



      printf("\n\n\t\t\t\t ***The Person %d  Data ***\n \n    \t\t\t\t>>name is : %s \n    \t\t\t\t>> age is : %d \n    \t\t\t\t>> the street : %s \n    \t\t\t\t>> the city :%s \n    \t\t\t\t>> code postal : %d \n\n\n",pers[i].id,pers[i].name,pers[i].age,pers[i].add.rue,pers[i].add.ville,pers[i].add.code_postal);


}
}
Menu(pers);
return;
}

int Update(Personne pers[]){


    if(Size==0){

            printf(RED"\n\n\t\t\t\tNo Data to Update Add new    \n\n "RESET);

       Add(pers);
       return;

    }

   else{

 found=-1;

    printf("\n\n\n\t\tEnter Id of table you want to Update $ ");
    scanf("%d",&choix);


    for(i=0;i<number;i++){
            if(pers[choix-1].id==choix)
            {
                found=i+1;
                 break;

            }

            break;
    }

    printf("%d",found);



    if(found>=0){

            found=found-1;

             printf(GREEN"\n\t\t\t\t**********Update of Person %d**********\n"RESET,found+1);
                printf(" -> Enter the name :  ");
          scanf(" %[^\n]s",&pers[found].name);
         printf("\t\t-> Enter the age :  ");
          scanf("%d",&pers[found].age);


        printf("\t -> Enter the street  :  ");
          scanf(" %[^\n]s",&pers[found].add.rue);

           printf("\t-> Enter the city  :  ");
          scanf(" %[^\n]s",&pers[found].add.ville);
           printf("\t-> Enter the code postal  :  ");
          scanf("%d",&pers[found].add.code_postal);
          pers[found].id=i+1;
          
          saved=false;
          Save(pers);
          return;

        }

        else {
                printf(RED"\t\t\t\tThe Id Entered has no Data \n\n\n"RESET);

                Add(pers);
                return;

                }

   }


    }

int Save(Personne pers[]){
	if(Size==0)
	{	
	printf(RED"\n\n\t\t\t\tNo Data to Save Add new  !  \n "RESET);
    Add(pers);
    return;
	}
	if(saved==false){
			pfile=fopen("personne","w");
	}
	else {
    pfile=fopen("personne","a");

	}
	
	if(saved){
		
			
	printf(RED"\n\n\t\t\t\t* Its Already Saved *   \n "RESET);
    Menu(pers);
	
    return;
	

		
	}
	else{
	
	
	for(i=0;i<number;i++)
	{
		saved=true;
	
	fprintf(pfile,"\n\n\t\t\t\t ***The Person %d  Data ***\n \n    \t\t\t\t>>name is : %s \n    \t\t\t\t>> age is : %d \n    \t\t\t\t>> the street : %s \n    \t\t\t\t>> the city :%s \n    \t\t\t\t>> code postal : %d \n\n\n",i+1,pers[i].name,pers[i].age,pers[i].add.rue,pers[i].add.ville,pers[i].add.code_postal);
		
	}



	fclose(pfile);
	
		printf(BLUE"\n\n\t\t\t\t\t * Saved *   \n "RESET);

	Menu(pers);
	return;
	
}
	
	
}

int Exit(Personne p[]){
	if(saved||number==0)
	
	{
			printf(RED"\n\n\t\t\t\t$ Exit  $ "RESET);
		}
		else {
				printf(RED"\n\n\t\t\t\t$ Exit Without Saving ! $ "RESET);
		}
	
		printf("\n\n\t\t  Want so Exit y/n :  ");
		scanf(" %[^\n]s",&left);
		
		
		switch(left)
		{
		
			case 'y':
			case 'Y':
				exit(number);
				
				break;
				case 'n':
				case 'N':
					Menu(p);
					break;
					default: printf(GREEN"\n\n\t\t\t\tYou should Enter a Y OR N "RESET);
					Exit(p);
				
			
		}

	
}
