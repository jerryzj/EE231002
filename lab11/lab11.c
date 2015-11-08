/*EE231002 Lab11 Word Processing
  103061232.Chong-yao,Zhang Jian
  DATE:2014/12/1
*/

#include <stdio.h>
#include <string.h>
#define LSTR 5000

int readLine(char para[LSTR]);		//to read essay
void lAlign(char *para);			//arrange essay in left form
void center(char *para);			//arrange essay in center form
void bAlign(char *para);			//arrange essay in even form
int N;								//line limit

int main (int argc, char *argv[]){	
	char para[LSTR]={};				//string to store essay
	
	if (argv[1][3]=='\0') N=100;	//transform line limit from type"char" 
	else N=(argv[1][0]-'0')*10+(argv[1][1]-'0');//to type"int"
	while(readLine(para)==0){					//when readLine return 0
		switch (argv[2][0]){					//choose what to do according
			case 'l': 							//to command line argument
				lAlign(para); 
				break;
			case 'b':
				bAlign(para);
				break;
			case 'c':
				center(para);
				break;
		}						
	}
	return 0;						//program end
}


int readLine(char para[LSTR]){
	int i=1;

	para[0]=getchar();
	while(para[i-1]!='\n'){			//when the last one word of a
	    para[i++]=getchar();		//paragraph is not read,read 
	}								//other words in the paragraph
	if(para[i-1]=='\n') para[i-1]='\0';	//set string breakpoint
	if (strcmp(para,"EOF")==0) return 1;//when "EOF" is read,return 1
	else return 0;						//otherwise,return 0
}

void lAlign(char *para){
	int i=0,ch_place,ch_num=0,str_len=0;

	str_len=strlen(para);			//find string length
	while(i<str_len){			
		ch_place=i;					//to know which one is being checked
		ch_num++;					//ch_num+1 when the char is a space
		while(para[ch_place]!=' '&& para[ch_place]!='\0'){
			ch_num++;				//record char number
			ch_place++;				//go to next one char
		}
		if(ch_num>N){				//when char number>limit
			ch_num=ch_place+1-i;	//reset for a new line	
			putchar('\n');			//go to new line
			while(i<=ch_place && i<str_len){
				putchar(para[i++]);
			}						
		}
		else {
			while(i<=ch_place && i<str_len){
				putchar(para[i++]);			
			}
		}
	}
	putchar('\n');					//blank line between paragraphs 
}

void center(char *para)
{
	int i=0,j=0,ch_num=N,str_len=0;

	str_len=strlen(para);			//find string length
	if(str_len<(N+1)){				//when the string number doesn't over			
		while(i<(N-str_len)/2){ 	//limit,print space before printing
		    putchar(' ');			//the paragraph
		    i++;
		}
		puts(para);
	}
	else{			
		while(para[ch_num] !=' '){  //set ch_num=line limit previously
		    ch_num--;  				//then find the space
		}
		para[ch_num]='\0';			//set null for string
		while(j<(N-ch_num)/2){
		    putchar(' ');			//print space to fill the line
		    j++;					
		}
		puts(para);
		center(&para[ch_num+1]);	//deal with the rest part	
	}			
}
	
void bAlign(char *para)
{
	int i=0,j=0,ch_num=N,add=0,str_len;			
	char temp[101]={};				//to store 		
	
	str_len=strlen(para);			//find string length
	if(str_len<=N){					//when the string number doesn't over	
		puts(para);					//limit,print the paragraph.
	}
	else{
		while(para[ch_num]!=' '){	//set ch_num=line limit prevously			
			ch_num--;				//then find the space
		}
		while(para[ch_num-1]==' '){	//when a space is followed by a		
			ch_num--;				//literal
		}			
		para[ch_num]='\0';			//set null for string
		add=N-ch_num;				//the number of space will be added
		while(i<ch_num){			
			temp[i+j]=para[i];
			if(j<add){
				if(temp[i+j]=='.' || temp[i+j]==',' || temp[i+j]==';' 
				    || temp[i+j]=='!' || temp[i+j]==' '){
					strncat(temp," ",add);
					j++;			//add space into temp
				}
			}
			i++;
		}
		temp[N+1]='\0';				//set null for string
		puts(temp);				
		while(para[ch_num+1]==' ')	//skip a space in the first position		
			ch_num++;				
		bAlign(para+ch_num+1);		//deal with the rest part			
	}
}
