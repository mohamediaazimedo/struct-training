#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEFT(str, w) \
    ({int m = w + strlen(str); m % 2 ? (m + 1) / 2 : m / 2;})

#define RIGHT(str, w) \
({ int m = w - strlen(str); m % 2 ? (m - 1) / 2 : m / 2; })

#define STR_CENTER(str, width) \
    LEFT(str, width), str, RIGHT(str, width), ""







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

    int Add();
    int Delete(Personne p[]);
    int Update(Personne p[]);
    int Read(Personne p[]);


int main (){

// caling add function first to add data
// inside data after finishing adding data we are going to show up a menu to update delete ...




    Add();

    return 0;

}

int entery(Personne p[] ){

    // Menu the select what users want to do more  it comes after add() function
     do{
    printf("\n\n #################Menu################\n");

      printf("    1. Update  data # \n\n");
        printf("    2. Read  data # \n\n");
          printf("    3. Delete  data # \n\n");
           printf("    4. Add new data  data # \n\n");

           printf(" -->Enter the number related to your choose : ");
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
            default: printf("You should Enter a number Related to The Tabel");


          }

    }while(choix==0||choix>4);



}

int Add(){

     printf("%*s%*s\n\n", STR_CENTER("<<<<<<<<<< Add >>>>>>>>>>", 40));

// printf("\n <<<<<<<<<< Add >>>>>>>>>>\n\n",i+1);
    printf(" \n  >> number  of person wanted to add :  ");

   scanf("%d",&number);


   Personne p[number];


        for(i=0;i<number;i++){

            printf("\n**************Person %d****************\n",i+1);
                printf(" -> Enter the name :  ");
          scanf(" %[^\n]s",&p[i].name);
         printf(" -> Enter the age :  ");
          scanf("%d",&p[i].age);
           printf("");

        printf(" -> Enter the street  :  ");
          scanf("%s",&p[i].add.rue);

           printf(" -> Enter the city  :  ");
          scanf("%s",&p[i].add.ville);
           printf(" -> Enter the code postal  :  ");
          scanf("%d",&p[i].add.code_postal);
          p[i].id=i+1;

          Size=Size+i+1;


        }

        entery(p);




}
int Delete(Personne pers[]){
    found=-1;

    printf("\n  <<<<<<<<<<<Delete>>>>>>>>>>\n");

    if(Size==0){

            printf("      No Data to Display Add new    \n ");

    Add();
}

else{




      printf("\n Enter Name of person wanted to Delete : ");
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
        printf("<<<<<<<<<person %d Deleted >>>>>>>>>>",pers[i].id);

        entery(pers);
      }

      else {
            printf("<<<<<<<<<No Person Find>>>>>>>>>>>>>>");
      entery(pers);
      }






}


}





int Read(Personne pers[]){

printf("\n  <<<<<<<<<< Read >>>>>>>>>>\n");

if(Size==0){

            printf("      No Data to Display Add new    \n ");

    Add();
}

else {
for(i=0;i<number;i++){



      printf("\n\n ***The Person %d  Data ***\n \n    >>name is : %s \n    >> age is : %d \n    >> the street : %s \n    >> the city :%s \n    >> code postal : %d \n\n\n",pers[i].id,pers[i].name,pers[i].age,pers[i].add.rue,pers[i].add.ville,pers[i].add.code_postal);


}
}
entery(pers);
}


int Update(Personne pers[]){


    if(Size==0){

            printf("      No Data to Display Add new    \n ");

       Add();

    }

   else{

 found=-1;

    printf("Enter Id of table you want to Update : ");
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

             printf("\n**************Update of Person %d****************\n",found+1);
                printf(" -> Enter the name :  ");
          scanf("%s",&pers[found].name);
         printf(" -> Enter the age :  ");
          scanf("%d",&pers[found].age);
           printf("");

        printf(" -> Enter the street  :  ");
          scanf("%s",&pers[found].add.rue);

           printf(" -> Enter the city  :  ");
          scanf("%s",&pers[found].add.ville);
           printf(" -> Enter the code postal  :  ");
          scanf("%d",&pers[found].add.code_postal);
          pers[found].id=i+1;

          entery(pers);

        }

        else {
                printf("The Id Entered has no Data \n\n\n");

                Add();

                }

   }


    }








