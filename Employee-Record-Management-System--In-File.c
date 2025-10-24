#include<stdio.h>

struct Employee{
	
	int id;
	char name[50];
	float salary;
	
};

void addEmployee(const char *fname){
	
	struct Employee s1;
	
	FILE* ptr;
	ptr = fopen(fname,"a");
	
	if(ptr == NULL){
		printf("Error in file Opening");
	}
	
	printf("\n\n-- Enter the Employee Record --\n\n");
	
	printf("\nEnter Employee ID :");
	scanf("%d",&s1.id);
	
	printf("\nEnter Employee Name :");
	scanf("%s",&s1.name);
	
	printf("\nEnter Employee Salary :");
	scanf("%f",&s1.salary);
	
	fprintf(ptr," %d %s %f\n\n",s1.id,s1.name,s1.salary);
	
	fclose(ptr);
	
	printf("\n\nEmployee Record Store in File Successfully !!\n\n");
	
}
 
 void viewAllEmployee(const char *fname){
 	
 	FILE* ptr;
 	struct Employee s1;
 	
 	ptr = fopen(fname,"r");
 	
 	printf("\n\n------ Display All Employee ------\n\n");
 	
 	if(ptr == NULL){
 		printf("Error in File Opening ");
	 }
	 
	 int found = 0;
	 int count = 0;
	 
	 while(fscanf(ptr,"\n %d  %s  %f \n",&s1.id,s1.name,&s1.salary) == 3){
	 	
		 printf("\n Id : %d\n Name : %s\n salary : %f\n",s1.id,s1.name,s1.salary);
	 
	 	found = 1;
	 	
	 	count++;
	 }
	 
	  if (!found){
	  	
	  		 printf("No records in file.\n");
		}else{
			printf("\nTotal records: %d\n", count);
		}
		
	 fclose(ptr);
 	
 }
 
 void deleteEmployeeById(const char *filename) {
 	
    struct Employee s;
    FILE *fp = fopen(filename, "r");
    FILE *temp = fopen("Temp.txt", "w");
    int id, found = 0;

    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("Enter id to delete: ");
    scanf("%d", &id);

    // Copy all records except the one to delete
    while (fscanf(fp, "%d %49s %f", &s.id, s.name, &s.salary) == 3) {
        if (s.id != id)
            fprintf(temp, "%d %s %.2f\n", s.id, s.name, s.salary);
        else
            found = 1;
    }

    fclose(fp);
    fclose(temp);

    // Replace old file with new one
    remove(filename);
    rename("Temp.txt", filename);

    if (found)
        printf("Record with id %d deleted successfully!\n", id);
    else
        printf("Record not found!\n");
}


int main(){

	printf("\n\n******* Welcome to Employee Record Management *******\n\n");
	
	const char *fileName="EmployeeInfo.txt";
	
	int choice;
	
	do{
			printf("\n -- Menu --\n");
			printf("\n1. Add Employee  \n2. View All Employee \n3. Delete Employee \n4. Exit ");
			printf("\n\n Enter your Choice :");
			scanf("\n%d",&choice);
			
			switch(choice){
				case 1:
					addEmployee(fileName);
					break;
				case 2:
					viewAllEmployee(fileName);
					break;
				case 3:
					deleteEmployeeById(fileName);
					break;
				case 4:
					printf("Exited ...");
					break;
				default:
					printf("Invalide choice :\n");
			}
			
				
		}while(choice != 4);

	return 0;
}