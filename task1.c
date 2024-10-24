#include <stdio.h>

int choix,i,number;

struct adresse{

    char rue[50];
    char ville[30];
    int code_postal;



};

typedef struct {

    char name[30];
    int age;
   struct adresse add;

}Personne;




int main (){

    do{
    printf("\n\n #################Menu################\n");
    printf(" \n    1. add new data # \n\n");
      printf("    2. Update  data # \n\n");
        printf("    3. Read  data # \n\n");
          printf("    4. Delete  data # \n\n");

           printf(" -->Enter the number related to your choose : ");
          scanf("%d",&choix);




          switch(choix){
          case 1:

              Add();


            break;
            case 2:
              Delete();


            break;
            case 3:
              Update();


            break;
            case 4:
              Read();


            break;

          }

    }while(choix==0||choix>4);




    return 0;

}

int Add(){

      printf("\n##############Add Menu################# \n\n",i+1);
    printf(" \n  >> number  of person wanted to add :  ");
   scanf("%d",&number);

   Personne p[number];



        for(i=0;i<number;i++){
                printf("\n**************Person %d****************\n",i+1);
                printf(" -> Enter the name :  ");
          scanf("%s",&p[i].name);
         printf(" -> Enter the age :  ");
          scanf("%d",&p[i].age);
           printf("");

        printf(" -> Enter the street  :  ");
          scanf("%s",&p[i].add.rue);

           printf(" -> Enter the city  :  ");
          scanf("%s",&p[i].add.ville);
           printf(" -> Enter the code postal  :  ");
          scanf("%d",&p[i].add.code_postal);

        }




}
int Delete(){

      printf("\n Enter Name of person wanted to Delete\n",i+1);


}
int Read(){

    Personne p;
    int size=sizeof(p);


for(i=0;i<size;i++){

        printf("name is : %s age is : %d  the ");


}




}
int Update(){}
