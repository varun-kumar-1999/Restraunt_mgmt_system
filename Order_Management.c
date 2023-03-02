#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void veg();
void nonveg();
void details();
int s,repeat,t,quantity;
double total=0;

void veg(){
	int choice,repeat,quantity;
	double price=0;
	printf("                                  ##################################################\n");
	printf("                                                   Veg Menu\n");
	printf("                                  ##################################################\n");
	char v;
	FILE *vmenu;
	vmenu=fopen("vegmenu.txt","r");
	while((v=getc(vmenu))!=EOF){
        	printf("%c",v);
		}
    fclose(vmenu);
    printf("\n\nEnter What You Want :\n\n");
	scanf("%d",&choice);
	switch(choice){
	case 1: printf("Quantity :  ");
		scanf("%d",&quantity);
		total=total + 40*(quantity);
	break;
	case 2:
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 60*(quantity);
	break;
	case 3:
		printf("Quantity :  ");
		scanf("%d",&quantity);
		total=total + 45*(quantity);
	break;
	case 4:
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 35*(quantity);
	break;
	case 5:
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 150*(quantity);
	break;
	default:
		printf("Wrong Choice!!!!!!\n\n");
		if(getch())
		veg();
	break;
	}
	printf("\nPress 1 To Order again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&repeat);
		printf("\n");
		if(repeat==1){
			printf("\n\n");
			veg();
		}
		else if(repeat==2){
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
}
void nonveg(){
	int choice,repeat,quantity;
	double price=0;
	printf("                                  ##################################################\n");
	printf("                                                  Non-Veg Menu\n");
	printf("                                  ##################################################\n");
	char n;
	FILE *nmenu;
	nmenu = fopen("nonveg.txt","rt");
	while((n=getc(nmenu))!=EOF){
		printf("%c",n);
	}
	printf("\n\nEnter What You Want :\n\n");
	scanf("%d",&choice);
	switch(choice){
	case 1:
		printf("Quantity : ");
		scanf(" %d",&quantity);
		total=total + 100*(quantity);
	break;
	case 2:
		printf("Quantity :");
		scanf(" %d",&quantity);
		total=total + 200*(quantity);
	break;
	case 3:
		printf("Quantity :");
		scanf(" %d",&quantity);
		total=total + 110*(quantity);
	break;
	case 4:
		printf("Quantity :");
		scanf(" %d",&quantity);
		total=total + 50*(quantity);
	break;
	default:
		printf("Wrong Input! Re-enter THe Correct Option\n\n");
		nonveg();
	break;
	}
	printf("\nPress 1 To Order repeat :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf(" %d",&repeat);
		if(repeat==1){
			printf("\n\n");
			nonveg();
		}
		else if(repeat==2){
			printf("Your Total Amount Is :%.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
}
void details(){
	char name[20],address[40],landmark[30];;
	long int phone;
	printf("Please Enter Your Contact Details \n");
	printf(" Name : ");
	scanf("%s",name);
	printf("Phone : ");
	scanf("%ld",&phone);
	printf("Address : ");
	scanf("%s",address);
	printf("Landmark : ");
	scanf("%s",landmark);
	printf("\n\nEntered Details Are --->\n");
	FILE *cust;
	cust = fopen("order.txt","a");
	fprintf(cust,"Order Placed By : %s %s\nPhone number : %ld\n",name,phone);
	fclose(cust);
	printf("    -->First Name :  %s\n     -->Phone     :%ld \n    -->Address  :%s \n    -->Landmark  :%s \n",name,phone,address,landmark);
	printf("\n\n\n                       #######################################################################################\n");
	printf("                                             Your Order Will Be At Your Door In 30 minutes.\n");
	printf("                                                       ~~~~~~~~~~HAVE A NICE DAY~~~~~~~~~~\n");
	printf("                       #######################################################################################\n");
}
int main(){
	system("cls");
	printf("                                  ##################################################\n");
	printf("                                                  WELCOME \n");
	printf("                                  ##################################################\n\n");
	choice:
	printf("			1. Veg-Menu\n\n			2. Non-Veg Menu\n\n			Enter Your Choice  --> ");
	int ch;
	scanf("%d",&ch);
	if(ch==1){
		system("cls");
		veg();
	}
	else if(ch==2){
		system("cls");
		nonveg();
	}
	else{
		//system("cls");
		printf("\n\t\t\tPlease Re-enter The Correct Option......\n\n");
		//main();
		goto choice;
	}
}
