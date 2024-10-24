#include <stdio.h>

int choix,i,number;
char del;

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


  Add();



    return 0;

}

int entery(Personne p[] ){

     do{
    printf("\n\n #################Menu################\n");

      printf("    1. Update  data # \n\n");
        printf("    2. Read  data # \n\n");
          printf("    3. Delete  data # \n\n");

           printf(" -->Enter the number related to your choose : ");
          scanf("%d",&choix);




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



            break;

          }

    }while(choix==0||choix>4);



}

int Add(){

      printf("\n##############Add Menu################# \n\n",i+1);
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

        }

        entery(p);




}
int Delete(Personne pers[]){

    printf("\n###########Delete#############\n");

      printf("\n Enter Name of person wanted to Delete\n");
      scanf("%[^\n]d",&del);

     /* for(i=0;i<number;i++){
            if(del==pers[i].name){

                    printf("A user match found");

            }







}
 */




}
int Read(Personne pers[]){

printf("\n###########Read#############\n");



for(i=0;i<number;i++){



      printf("\n\n ***The Person %d  Data ***\n \n    >>name is : %s \n    >> age is : %d \n    >> the street : %s \n    >> the city :%s \n    >> code postal : %d \n\n\n",i+1,pers[i].name,pers[i].age,pers[i].add.rue,pers[i].add.ville,pers[i].add.code_postal);


}




}
int Update(Personne pers[]){}
