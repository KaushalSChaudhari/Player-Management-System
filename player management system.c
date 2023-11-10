#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 typedef struct player{
		int jerseyNo;
		char name[30];
		int noOfMatches;
		int noOfRuns;
		int noOfWickets;
}player;
int ctr=0;
int ctrr=ctr;
void store( player* ,int);
void display(  player* );
void displayplayer(player );
void search( player*, int);
int searchByJn( player* ,int );
int searchByName( player* ,char*);
void deleteplayer(player*);
void update(player*);
void top3(player*);
void top3Runs(player*);
void top3Wickets(player*);
 int main()
	{int n,op;
        player * arr;
		printf("Enter no. of players: ");
		scanf("%d",&n);
		arr=(player*)malloc(sizeof(player)*n);
		do{
	    printf("\n1.Add info of player\n2.Display whole data\n3.search a player\n4.delete\n5.update\n6.top 3");
		printf("\n\nEnter your choice : ");	
		scanf("%d",&op);
	
		switch(op)
		{
			case 1:
				store(arr,n);
				break;
			case 2:
				display(arr);
				break;
					case 3:
				search(arr,n);
				break;
			case 4:
				deleteplayer(arr);
				break;
			case 5:
				update(arr);
				break;
			case 6:
				top3(arr);
				break;
            
			default:
				printf("Select correct option");
			
		}
		}
		while(op!=0);
	
}
	
	
	void store( player* arr,int n)
	{
		int i;
	
		printf("You can store only %d players",n);
		if(ctr<n)
		{   printf("\nplayer no. %d\n",ctr+1);
	    	printf("Enter name of player : ");
	    	scanf("%s",&arr[ctr].name);
			printf("Enter jersey no. of player : ");
			scanf("%d",&arr[ctr].jerseyNo);
			printf("Enter no. of matches played by a player : ");
			scanf("%d",&arr[ctr].noOfMatches);
			printf("Enter no. of runs scored by a player : ");
			scanf("%d",&arr[ctr].noOfRuns);
			printf("Enter no. of wickets taken by a player : ");
			scanf("%d",&arr[ctr].noOfWickets);
	 	ctr++;
	 	ctrr++;
		}
		else
		printf("limit is crossed");	
	}
	
void display(player* arr)
    	{int i;
    	for (i=0;i<ctr;i++)
		{ printf("\nplayer no. :%d",i+1);
			printf("\nname : %s",arr[i].name);
	    	printf("\njersey no.: %d",arr[i].jerseyNo);
			printf("\nmatches played:%d",arr[i].noOfMatches);
			printf("\nruns scored :%d",arr[i].noOfRuns);
			printf("\nwickets taken :%d \n",arr[i].noOfWickets);
		}	
	}
void displayplayer(player p)
	{
			printf("\nname : %s",p.name);
	    	printf("\njersey no.: %d",p.jerseyNo);
			printf("\nmatches played:%d",p.noOfMatches);
			printf("\nruns scored :%d",p.noOfRuns);
			printf("\nwickets taken :%d \n",p.noOfWickets);
		
	}
	void search( player* arr, int n)
	{
	int a,jn,result;
	char name[20];
	printf("Select a option to be used to search a player:");
	printf("\n1.jersey no.\n2.name:");
	scanf("%d",&a);
	if(a==1)
	{printf("Enter the jersey no. of player which is to be search:");
		scanf("%d",&jn);
		result=searchByJn(arr,jn);
		if(result==-1)
		{
			printf("Record not found");
		}
		else
		{
			displayplayer(arr[result]);
		}
		

	}
	else if(a==2)
	{
		printf("Enter the name of player which is to be search:");
		scanf("%s",name);
		result=searchByName(arr,name);
		if(result==-1)
		{
			printf("Record not found");
		}
		else
		{
			displayplayer(arr[result]);
		}
	 } 
	 else 
	{ printf("Choose appropriate option");}
		
	}
int searchByJn( player* arr,int jn)
	{
		int i;
		
		for(i=0;i<ctr;i++)
		{
			if(arr[i].jerseyNo==jn)
			{ return i;
			}	
		}
		return -1;
	}
	
int searchByName( player* arr,char* name)
 {
 	int i,a;
 		for(i=0;i<ctr;i++)
		{
			if(strcmp( arr[i].name,name)==0)	
			{ 
			return i;
				}
			
		}
		return -1;
	}
 	
void deleteplayer(player* arr)
 {int dlt;
 printf("Enter jersey no. of player to be deleted:");
 scanf("%d",&dlt);
  int i=searchByJn(arr,dlt);
  if(i==-1)
  {
  	printf("Student not found");
  	
  }
  else{
  	while(i<ctr-1)
  	{
  		arr[i]=arr[i+1];
  		i++;
	  }
	  ctr--;
  }
 }
	
void update(player* arr)
{int jn;
	printf("Enter jersey no. of a player whose data is to be updated : ");
	scanf("%d",&jn);
int i=searchByJn(arr,jn);
printf("Select what you wnat to update\n1.No. of matches\n2.No. of runs\n3.No. of wickets: ");
int ch;
scanf("%d",&ch);
switch(ch)
{
	case 1:
		{printf("Enter updated no. of matches: ");
		scanf("%d",&arr[i].noOfMatches);
		break;
	}
		case 2:
		{printf("Enter updated no. of runs: ");
		scanf("%d",&arr[i].noOfRuns);
		break;
	}
		case 3:
		{printf("Enter updated no. of wickets: ");
		scanf("%d",&arr[i].noOfWickets);
		break;}
		default:
			printf("Select appropriate option");
}
}
void top3(player* arr)
 {int ch;
 	printf("Select a option to be displayed\n1. top 3 player (runs)\n2.top 3 player(wickets): ");
 	scanf("%d",&ch);
 	switch(ch)
 	{
 		case 1:
 			top3Runs(arr);
 			break;
 		
 		case 2:
 			top3Wickets(arr);
 			break;
 		default:
 			printf("Select appropriate option");
	 }
 }
 void top3Runs(player* arr)
 { 	int i,j;
    for ( i = 0; i < ctr - 1; i++) {
        for ( j = 0; j < ctr - 1; j++) 
		{
            if (arr[j].noOfRuns < arr[j + 1].noOfRuns) 
              { player temp = arr[j];
    arr[j]=arr[j+1];
    arr[j+1] = temp;}
            
        }
    }
    printf("Top 3 run scorers are:");
 for (j=0;j<3;j++)
 {
 	printf("\nplayer:%s  runs:%d",arr[j].name,arr[j].noOfRuns);
 }
}
void top3Wickets(player* arr)
{int i,j;
	for ( i = 0; i < ctr - 1; i++) {
        for ( j = 0; j < ctr - 1; j++) 
		{
            if (arr[j].noOfWickets < arr[j + 1].noOfWickets) 
              { player temp = arr[j];
    arr[j]=arr[j+1];
    arr[j+1] = temp;}
            
        }
    }
 
 printf("Top 3 wicket taker are:");
 for (j=0;j<3;j++)
 {
 	printf("\nplayer:%s  wickets:%d",arr[j].name,arr[j].noOfWickets);
 }
 	 	
 }
 
	
	
	



