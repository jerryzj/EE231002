/* EE231002 Lab12. College Admission
   103061232.Chong-yao,Zhang Jian
   DATE :2014.12.8
*/

#include <stdio.h>
#include <string.h>
#define mat 0
#define phy 1
#define che 2
#define geo 3

typedef enum sDEPT{
	mathD, physD, chemD, geosD, none,
} DEPT;
typedef struct stu{
	int appNum;						//appllication number
	char fName[20];					//first name
	char lName[20];					//last name
	int math, phys, chem;			//test scores
	int total;						//total score
	DEPT pris[4];					//student's priority
	DEPT dept;						//admitted dept
} Stu;
void read(Stu stu[100]);			//to read data and count total score 
void analyze(int minscore[4],Stu stu[100]);//to judge department
void print(int minscore[4],Stu stu[100]);//to print result

int main(void){
	int minscore[4]={};				//record minimum score of each departmnt
	Stu stu[100];					//store information of each student
	
	read(stu);						//read student data
	analyze(minscore,stu);			//analyze data
	print(minscore,stu);			//print result

	return 0;						//program end
}

void read(Stu stu[100]){
	int i,j;						//looping index
	char title[61],temp[5];			

	gets(title);					//scan file title
	for(i=0;i<100;i++){				//scan student data
		scanf("%d %s %s %d %d %d",&stu[i].appNum,stu[i].fName,stu[i].lName
		,&stu[i].math,&stu[i].phys,&stu[i].chem);
		for(j=0;j<4;j++){			//scan priority
			scanf("%s",temp);
			switch(temp[0]){
				case'M':stu[i].pris[j]=mathD;	break;
				case'P':stu[i].pris[j]=physD;	break;
				case'C':stu[i].pris[j]=chemD;	break;
				case'G':stu[i].pris[j]=geosD;
			}
		}
		stu[i].total=stu[i].math+stu[i].phys+stu[i].chem; //count total score
		stu[i].dept=none;			//initialize dept
	}
}

void analyze(int minscore[4],Stu stu[100]){
	int i,j,stunum[4]={20,20,20,20},totalstu=0,check,score=300;
	//stuum:record avaliable quota of each department
	//totalstu:record how many students are admitted
	//score:help analyze from high score to low 

	while(score>0 && totalstu<80){
		for(i=0;i<100;i++){
			if(stu[i].total==score){
				check=0;
				for(j=0;j<4;j++){
					if(stu[i].pris[j]==mathD && stunum[mat]!=0 && check==0){
						stu[i].dept=mathD;		//student being admitted
						stunum[mat]--;			//avaliable quota-1
						totalstu++;				//admitted student+1
						minscore[mat]=score;	//update minimum score
						check=1;
					}
					 if(stu[i].pris[j]==physD && stunum[phy]!=0 && check==0){
						stu[i].dept=physD;
						stunum[phy]--;
						totalstu++;
						minscore[phy]=score;
						check=1;
					}
					if(stu[i].pris[j]==chemD && stunum[che]!=0 && check==0){
						stu[i].dept=chemD;
						stunum[che]--;
						totalstu++;
						minscore[che]=score;
						check=1;
					}
					if(stu[i].pris[j]==geosD && stunum[geo]!=0 && check==0){
						stu[i].dept=geosD;
						stunum[geo]--;
						totalstu++;
						minscore[geo]=score;
						check=1;
					}
				}
			}
		}
		score--;								//analyze next score 
	}
}

void print(int minscore[4],Stu stu[100]){
	int i,j;
 
	printf("Math Department: Minimum score %d\n",minscore[mat]);//print title
	for(i=0,j=1;i<100;i++){
		if(stu[i].dept==mathD){ 									
			printf(" %2d %d %s %s\n",j,stu[i].appNum,stu[i].fName,stu[i].lName);
			j++;
		}
	}
    printf("Phys Department: Minimum score %d\n",minscore[phy]);
    for(i=0,j=1;i<100;i++,j++){
        if(stu[i].dept==physD){ 
            printf(" %2d %d %s %s\n",j,stu[i].appNum,stu[i].fName,stu[i].lName);
			j++;
        }
    }   
    printf("Chem Department: Minimum score %d\n",minscore[che]);
    for(i=0,j=1;i<100;i++){
        if(stu[i].dept==chemD){ 
            printf(" %2d %d %s %s\n",j,stu[i].appNum,stu[i].fName,stu[i].lName);
			j++;
        }
    }   
    printf("Geos Department: Minimum score %d\n",minscore[geo]);
    for(i=0,j=1;i<100;i++){
        if(stu[i].dept==geosD){ 
            printf(" %2d %d %s %s\n",j,stu[i].appNum,stu[i].fName,stu[i].lName);
			j++;
        }
    }   
}
