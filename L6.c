#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Debug 0
struct node {
	char name[51];
	int mid;
	int final;
    struct node *next_node;
 };
void main(){
	int i=0;
	int j;
	int k;

	scanf("%d", &k);
	while(getchar()!='\n');
	FILE *john=fopen("records.txt", "r");
	char lines[50][50];
	int  storemid[51];
	int  storefinal[51];
	//printf("%d\n", k);
	
	struct node storenode[k];

	for (i=0;i<k;i++){
	  	storenode[i].mid=-1;
		storenode[i].next_node=NULL;

				}
		
	int sum=0;
	int mod;
	//forgot to reset i
	i=0;

	int tester=0;
	while(fgets(lines[i],51,john)){
		fscanf(john, "%d\n%d", &storemid[i],&storefinal[i]);
			while(fgetc(john)!='\n');
		
		i++;
		tester++;	
	}
	#if Debug
	i=0;
	for(i=0;i<tester; i++){
	 printf("Midterm:%d final:%d \n",storemid[i],storefinal[i]);
			}	
	#endif

	

	i=0;
	j=0;
	for(j=0;j<tester;j++){
		 sum=0;
		for (i=0; lines[j][i]!='\n'; i++){
         		sum+=(int)lines[j][i];
				}
   		mod=sum%k;
	lines[j][strlen(lines[j])-1]=0;
   	if(storenode[mod].mid==-1){
			
   	   		storenode[mod].mid=storemid[j];
   	   		storenode[mod].final=storefinal[j];
   	   		strcpy(storenode[mod].name,lines[j]); 
   				}
	else{                            //memorize this all
   	   	struct node *ptr; 
   	   	ptr=&storenode[mod];              //points to first node
		
   	   	while(ptr-> next_node != NULL){         //points to next node until end
   	   			ptr= ptr->next_node;   
   	   			}  
                                  
   	   	struct node *newnode=(struct node*)malloc(sizeof(struct node));
   	   	newnode->mid=storemid[j];
   	   	newnode->final=storefinal[j];
		
   	   	strcpy(newnode->name,lines[j]);
   	   	ptr->next_node = newnode;                 //till here   	     	     	  
   	}		
    
   
						 }


//printf("it gets here\n"); 
	char fullname[51];
	struct node *loop_node;

	while(fgets(fullname, 50, stdin)){
	fullname[strlen(fullname)-1]=0;
	int counter=1;
	int boolean=0;
	for (i=0; i<k; i++){
	if(storenode[i].mid!=-1){
	if (strcmp(fullname, storenode[i].name)==0){
			boolean=1;
			printf("%d %d %d\n", storenode[i].mid, storenode[i].final, 1);
			break;
	        }
	  else  {
	           	counter=0;
	           loop_node=&storenode[i];
               while(loop_node != NULL){
               		counter++;
		      if(strcmp(loop_node->name, fullname)==0){
		       	   boolean=1;
		       	   printf("%d %d %d\n", loop_node->mid, loop_node->final, counter);
		           break;
		       						}

		       loop_node=loop_node->next_node; 
		          	   	}	
    		} }
	}  if(boolean==0){
	printf("The name does not exist in the file\n");
	}
							}
}

