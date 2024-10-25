#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define color codes
#define RESET "\x1b[0m"           // Reset all colors to default
#define RED "\x1b[31m"       // Red text
#define GREEN "\x1b[32m"     // Green text








int choix,i,number,found,Size=0;
char del[30];


// address structure

struct adresse{

    char rue[50];
    char ville[30];
    int code_postal;

};

// personne structure

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


int main (){
     system("color 0");


// caling add function first to add data
// inside data after finishing adding data we are going to show up a menu to update delete ...



   Personne p[Size];
    entery(p);

    return 0;

}

int entery(Personne p[] ){



    // Menu the select what users want to do more  it comes after add() function
     do{






    printf(GREEN"\n\n \t\t\t#################Menu################\n"RESET);


      printf("\n\t\t\t\t1. Update  data # \n\n");
        printf("\t\t\t\t2. Read  data # \n\n");
          printf("\t\t\t\t3. Delete  data # \n\n");
           printf("\t\t\t\t4. Add new data  data # \n\n");

           printf("\n\n\t\t -->Enter the number related to your choose : ");
          scanf("%d",&choix);
// check choix and move to funtions

          switch(choix){
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
                number=number+1;
                break;
            default: printf(RED"\n\n\t\tYou should Enter a number Related to The Tabel"RESET);


          }

    }while(choix==0||choix>4);



}

int Add(Personne p[]){


 printf(GREEN"\n\n\t\t\t\t<<<<<<<<<< Add >>>>>>>>>>\n\n"RESET);
    printf(" \n\t\t  ->> number  of person wanted to add :  ");


   scanf("%d",&number);

        number=Size+number;





        for(i=Size;i<number;i++){

            printf(GREEN"\n\t\t\t**************Person %d****************\n"RESET,i+1);
                printf("\n\n\t\t  >>> Enter the name :  ");
          scanf(" %[^\n]s",&p[i].name);
         printf("\t\t  >>> Enter the age :  ");
          scanf("%d",&p[i].age);


        printf("\t\t  >>> Enter the street  :  ");
          scanf("%s",&p[i].add.rue);

           printf("\t\t  >>> Enter the city  :  ");
          scanf("%s",&p[i].add.ville);
           printf("\t\t  >>> Enter the code postal  :  ");
          scanf("%d",&p[i].add.code_postal);
          p[i].id=i+1;

          Size=Size+i+1;


        }

        entery(p);




}
int Delete(Personne pers[]){
    found=-1;

    printf(GREEN"\n\t\t\t\t<<<<<<<<<<Delete>>>>>>>>>>\n"RESET);

    if(Size==0){

            printf(RED"\n\n\t\t\t\tNo Data to Display Add new    \n "RESET);

    Add(pers);
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
        printf(GREEN"\t\t\t\t<<<<<<<<<person %d Deleted >>>>>>>>>>"RESET,pers[i].id);

        entery(pers);
      }

      else {
            printf(GREEN"\t\t\t\t<<<<<<<<<No Person Find>>>>>>>>>>>>>>"RESET);
      entery(pers);
      }






}


}





int Read(Personne pers[]){

printf(GREEN"\n\t\t\t\t<<<<<<<<<< Read >>>>>>>>>>\n"RESET);

if(Size==0){

            printf(RED"\t\t\t\tNo Data to Display Add new    \n "RESET);

    Add(pers);
}

else {
for(i=0;i<number;i++){



      printf("\n\n\t\t\t\t ***The Person %d  Data ***\n \n    >>name is : %s \n    >> age is : %d \n    >> the street : %s \n    >> the city :%s \n    >> code postal : %d \n\n\n",pers[i].id,pers[i].name,pers[i].age,pers[i].add.rue,pers[i].add.ville,pers[i].add.code_postal);


}
}
entery(pers);
}


int Update(Personne pers[]){


    if(Size==0){

            printf("\n\n\t\t\t\tNo Data to Display Add new    \n\n ");

       Add(pers);

    }

   else{

 found=-1;

    printf("\n\t\tEnter Id of table you want to Update : ");
    scanf("%d",&choix);


    for(i=0;i<number;i++){
            if(pers[choix-1].id==choix)
            {
                found=i+1;
            }

            break;



    }

    printf("%d",found);



    if(found>=0){

            found=found-1;

             printf(GREEN"\n\t\t\t\t**********Update of Person %d**********\n"RESET,found+1);
                printf(" -> Enter the name :  ");
          scanf("%s",&pers[found].name);
         printf("\t\t-> Enter the age :  ");
          scanf("%d",&pers[found].age);


        printf("\t\-> Enter the street  :  ");
          scanf("%s",&pers[found].add.rue);

           printf("\t\-> Enter the city  :  ");
          scanf("%s",&pers[found].add.ville);
           printf("\t\-> Enter the code postal  :  ");
          scanf("%d",&pers[found].add.code_postal);
          pers[found].id=i+1;

          entery(pers);

        }

        else {
                printf(RED"\t\t\t\tThe Id Entered has no Data \n\n\n"RESET);

                Add(pers);

                }

   }


    }








