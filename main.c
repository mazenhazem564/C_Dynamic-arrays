#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //this library is included to read malloc
//constants
#define Max_name 20
#define Max_stud 2
#define Max_subj 3
struct Students{
    int reg_id;
    char name[Max_name];
    float subj_grades[Max_subj];
};
void struct_func()
{
  struct Students arr_students[Max_stud];
  float sum=0;

  for(int i=0;i<Max_stud;i++)
    {
    printf("\nEnter data of Student %d",i+1);
    printf("\nEnter Name: ");
    scanf("%s",arr_students[i].name);//fgets(arr_students[i].name,Max_name,stdin);   /*scanf("%[^\n]%*c",arr_students[i].name);//to get input with spaces normally //%[^\n]: match anything that's not break line //%*c: match any size of it*/  //scanf("%s",arr_students[i].name);
    printf("Enter Reg_ID: ");
    scanf("%d",&arr_students[i].reg_id);

    for(int j=0;j<Max_subj;j++){
    printf("Enter Subj_grades %d: ",j+1);
    scanf("%f",&arr_students[i].subj_grades[j]); //N.B //in case you use double do the following scanf("%lf"
    }
    }



printf("\nStud_Name \t Reg_ID \t Subj_Grades\n");

  for(int i=0;i<Max_stud;i++)
    {
        //sum=0;
        for(int j=0;j<Max_subj;j++){

            sum+=arr_students[i].subj_grades[j];
        }
    printf("%s \t\t %d \t\t %.2f\n",arr_students[i].name,arr_students[i].reg_id,/*arr_students[i].subj_grades*/sum/Max_subj); //kda ana taba3t pointer gwa pointer (subj_grades array)
    }

}

//pointer,dynamic allocation implementation
void dynamic_array()
{
    int rows,cols;
printf("Enter number of rows: ");
scanf("%d",&rows);
printf("\nEnter number of columns: ");
scanf("%d",&cols);
/*
//1D dynamic array
int size;
int ar[30];
scanf("%d",&size)
scanf("%d",&ar[size]);
printf("array: %d",ar);
*/

//2D dynamic array
//int * arr/*[][]*/=malloc(rows*sizeof(int));//here we make a 1D array (we reserved only for row by using this line
                                                                        //but in the next line we used this sizeof(int*)) because we still didn't use the 2nd pointer (which is made for columns)

int ** arr/*[][]*/=malloc(rows*sizeof(int*)); //malloc means allocate(put in memory)         //we have created a pointer(**) in which it points to a row(*) and a column(*)

//int *** arr/*[][]*/=malloc(rows*sizeof(int**)); //in case of 3D
//reserve number of columns for each row
for(int i=0;i<rows;i++)
{
    arr[i]=malloc(cols * sizeof(int)); //now i reserved columns so i removed * in sizeof(int*)

    //if it was 3D we would ha written the next lines in the remark instead of the previous line
    /*
      arr[i]=malloc(cols * sizeof(int*));
      for(int i=0;i<rows;i++)
        {
            arr[i]=malloc(cols * sizeof(int)); //now i reserved columns so i removed * in sizeof(int*)
        }        */
}
printf("Enter array elements: \n");
for(int i=0;i<rows;i++)
{
    for(int j=0;j<cols;j++)
        {
            printf("Enter Element [%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
}

printf("Your Array elements are: \n");
for(int i=0;i<rows;i++)
{
    for(int j=0;j<cols;j++)
        {
            printf("%d  ",arr[i][j]);

        }
        printf("\n");
}
printf("\n");
}
int main()
{
    //int x=3 //means i reserved a place in memory with size 4 byte
    //struct_func();
    dynamic_array();
    return 0;
}
