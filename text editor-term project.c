#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>
#define LEN 25
typedef struct node 
{
	char statement[40]; //max 40 char per line
	int next; //Points to next index (for free_head and inuse_head)
	};
struct node textbuffer[LEN]; // max. 25 lines
struct node menu[6];//Menu 6 line.



int isspace(char a[]){
	for(int i=0;i<40;i++){
		if(a[i]==NULL)
			break;
		
		
		switch(a[i]){
			case' ':
			continue;
			break;
			case'\t':
			continue;
			break;
			case'\n':
			continue;
			break;
			case'\v':
			continue;
			break;
			case'\f':
			continue;
			break;
			case'\r':
			continue;
			break;
			default:
			return 0;
	}}
	return 1;
	
	
}




void input(struct node tnode[],char* data,int line){
		
		for(int i=0;i<40;i++, tnode[line].statement[i]=NULL);
		
		for(int i=0;i<40 && i<strlen(data);i++){
			(tnode[line]).statement[i]=data[i];
}}


int free_head;
int inuse_head;

void edit(char* fname);
void insert(char* stat,int cursor);
void delete(int row);
void save(char* fname);



void insert(char* data,int cursor){
	if(!isspace(textbuffer[cursor].statement)){
		for(int i=24;i>cursor+1;i--)
			input(textbuffer,textbuffer[i-1].statement,i);
			input(textbuffer,data,cursor+1);
			return;
			}
	input(textbuffer,data,cursor);
}

 void save(char* name){
    int i;
    FILE *fp;
     fp=fopen(name,"w+"); 
     for(i=inuse_head; textbuffer[i].next != -1; i=textbuffer[i].next)
         printf("%s",textbuffer[i].statement);
     
     printf("%s",textbuffer[i].statement);
	 fclose(fp);
}
 void edit(char* fname){
	 int inuse_current=0;
	 int free_current=0;
	 int i=0,j=0;
	 FILE *fp;
	 
	 fp=fopen(fname,"r");	
	char str[40];
	if(fp==NULL){
		
		free_head=0;
		for(int i=0;i<LEN-1;textbuffer[i].next=i+1,i++);
		textbuffer[LEN-1].next=-1;
		inuse_head=-1;
		return;
	
	}
	i=0;
	while(fgets(str,40,fp)!=NULL){
	
		input(textbuffer,str,i);
		i++;
	
 }
	fclose(fp);

	i=0;
	j=0;
	for(;i<25;i++)
		if(isspace(textbuffer[i].statement)){
			free_head=i;
			free_current=i;
			break;
		}
	for(;j<25;j++)
		if(!isspace(textbuffer[j].statement)){
			inuse_head=j;
			inuse_current=j;
			break;
		}		

	
	for(;i<25;i++)
		if(isspace(textbuffer[i].statement)){
			textbuffer[free_current].next=i;
			free_current=i;
		}

	for(;j<25;j++)
		if(!isspace(textbuffer[j].statement)){
			textbuffer[inuse_current].next=j;
			inuse_current=j;	
		}	
	textbuffer[inuse_current].next=-1;
	textbuffer[free_current].next=-1;

 }
 
 
 int main(int argc, char *argv[]){
	 
  
  input(menu,"(w)/(W)Move cursor up.",0); //Fill menu
  input(menu,"(z)/(Z)Move cursor down.",1);
  input(menu,"(i)/(I)Insert a line to current line ",2);
  input(menu,"(d)/(D)Delete the current line.",3);
  input(menu,"(s)/(S)Save file end quit.",4);
  input(menu,"(x)/(X)Exit without doing nothing.",5);
  int j=0;
  char c;
  char data[40];
  if (argc>=2){
	  edit(argv[1]);
  }
	else{
		printf("No file entered exiting.\n");
		return 0;
	}

  initscr();
  while(1) {
	
	refresh();

	switch(c){
		case'w':
		case'W':
		if(j!=0)
			j--;
		break;
		case'z':
		case'Z':
		if(j!=24)
			j++;
		break;
		case'i':
		case'I':
		move(33,0);
		printw("Please enter a line.\n");
		scanw("%s",data);		
		insert(data,j);
		break;
		case'd':
		case'D':
		//delete(j);
		break;
		case's':
		case'S':
		move(33,0);
		printw("Please enter a name (with extension).\n");
		scanw("%s",data);
		save(data);
		endwin();
		return 0;
		case'x':
		case'X':
		endwin();
		return 0;
		default:
		break;		
	}
	
	clear();
	
		for(int i=0;i<LEN;i++){
		move(i,0);
		printw(textbuffer[i].statement);
	}
		for(int i=26;i<32;i++){
			move(i,0);
			printw(menu[i-26].statement);
		}
		move(j,0);
		c=getch();
	
  }
  endwin();
 }