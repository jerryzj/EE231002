/*EE231002 Lab15 String Encoding
  103061232.Chong-yao,Zhang Jian
  Date:2014.12.25
*/
#include <stdio.h>
#include <string.h>

int decode(char code[4],int count);				//to decode and print result

int main (void){
	int i,count;
	char length,begin[6],code[4];

	gets(begin);								//read begin
	while(1){
		count=0;								//reset count
		scanf("%c%c",&length,&code[0]);			//scan line length,code[0]
		while(count<length && code[0]!='\n'){	//code[0] checks whether '\n'
			for(i=1;i<4;i++){					//is avoided or not
				scanf("%c",&code[i]);			//read code
			}	
			if(length=='e' && strncmp(code,"nd",2)==0){
				return 0;						//if end is read,program end
			}
			else{
				count=decode(code,count);		//start decoding
				scanf("%c",&code[0]);			//scan next code to check'\n'
			}
		}
	}
}
int decode(char code[4],int count){
	int i;
	char word[3];

	for(i=0;i<4;i++){							//shift to remove the first two
    	code[i]=code[i]&63;						//bits
    }   
    word[0]=(code[0]<<2)|(code[1]>>4);			//decodeing
    word[1]=(code[1]<<4)|(code[2]>>2);
    word[2]=(code[2]<<6)|(code[3]);
    for(i=0;i<3;i++,count++){
    	printf("%c",word[i]);					//print result
        if(word[i]=='\0') --count;				//if null is printed,count-1
	}
	return count;
}
