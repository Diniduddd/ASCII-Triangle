/* ******************************************************************
 *                      Project I: ASCII Triangle
 *  Author:H.P.D.B. Handunpathirana(E/10/119) 
 * 
 *  CO212: Computer Programming, 
 *      Department of Computer Engineering, University of Peradeniya
 * *****************************************************************/

/* For ploting, we  suggest you to use an integer coordinate system.
   Therefore, you  should round your floating point representations
   to integers before performing the "ploting" operation.
 */
 
/* include the header files here */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* include the definitions here */
#define INPUT_LENGTH 256
#define NO_OF_INPUTS 12

/* declare the function prototypes here */
int chackco(float inputsFloat[12],int,int,float,float,float,float,float,float,float,float,float,float);
void plot(int,int,float,float,float,float,float,float,float,float,float,float);
char chackpoints(int,int,int,int,int,int,int,int);
int main()
{
	/* declare local variables */
	
	
	char  inputString[INPUT_LENGTH]; // input from the user as a string
	float inputsFloat[NO_OF_INPUTS]; // Separated 12 input values 
	
	int countInput = 0,ch,r,c;
	float xmin,ymin,xmax,ymax,x1,y1,x2,y2,x3,y3;
	

	/* YOU SHOULD NOT MODIFY THE FOLLOWING */
	
	/* read the input from a user as a string */
	fgets (inputString, INPUT_LENGTH, stdin);
	
	/* 	extract the inputs while checking whether we have exactly have
		12 at the end of this section, the 12 inputs will be available
		in a floating point array named inputsFloat
	*/
 	char *separatedInput, *tail;
	
	/* break the inputString at white spaces. */
	separatedInput = strtok(inputString, " ");
	while(separatedInput != NULL)
	{
		if(countInput == 12)
		{
			printf("Too many inputs! Redundant inputs will be ignored\n");
			break;	
		}
		
		/* convert to float and store. */
		inputsFloat[countInput] = strtod(separatedInput, &tail); 

		if(*tail != '\0' && *tail != '\n' )
		{
			printf("Error in the input! Terminating\n");
			return 0;	
		} 
		separatedInput = strtok(NULL," ");
		countInput++;		
	} 

	if(countInput < 11 )
	{
		printf("%d\n",countInput);
		printf("Please enter all 12 inputs to calculate!\n");
		return -1;
	}

	/* 	extracting the inputs is done and the inputs are in a floating
		point array named inputsFloat 
	*/
	
	/* WRITE YOU CODE HERE */
	/* 	You are advised to break your program into smaller functions
		and call them in the main function, instead of writing all 
		your code in the main function
	*/
	
	
	/* assign inputs to variables from floating point array*/
	r=inputsFloat[0];
	c=inputsFloat[1];
	xmin=inputsFloat[2];
	ymin=inputsFloat[3];
	xmax=inputsFloat[4];
	ymax=inputsFloat[5];
	x1=inputsFloat[6];
	y1=inputsFloat[7];
	x2=inputsFloat[8];
	y2=inputsFloat[9];
	x3=inputsFloat[10];
	y3=inputsFloat[11];
	
	/* chacking condition of the variables using chackco function*/
	ch=chackco(inputsFloat,r,c,xmin,ymin,xmax,ymax,x1,y1,x2,y2,x3,y3);
	if (ch==1){
	/*if the inputs are correct printting picture of the triangle*/
		plot(r,c,xmin,ymin,xmax,ymax,x1,y1,x2,y2,x3,y3);
		}
	return 0;
}


int chackco(float inputsFloat[12],int r,int c,float xmin,float ymin,float xmax,float ymax,float x1,float y1,float x2,float y2,float x3,float y3){
	/* chacking condition of the coordinates */
	if((r<=0)||(c<=0)){
		printf("Row and column numbers should be non-zero positive values!\n");
		return 0;
	}
	else if((xmin>xmax)||(ymin>ymax)){
		printf("Minimum value cannot exceed the maximum value!\n");
		return 0;
	}
	else if((xmin>x1)||(xmin>x2)||(xmin>x3)||(ymin>y1)||(ymin>y2)||(ymin>y3)||(xmax<x1)||(xmax<x2)||(xmax<x3)||(ymax<y1)||(ymax<y2)||(ymax<y3)){
		printf("The value given is out of range\n");
		return 0;
	}
	else if((inputsFloat[0]!=lroundf(inputsFloat[0]))||(inputsFloat[1]!=lroundf(inputsFloat[1]))){
		printf("rows and columns should be integers. So they are truncated\n");
		return 1;
	}	
	return 1;
	}
	/*printting picture of the triangle*/
void plot(int r,int c,float xmin,float ymin,float xmax,float ymax,float bx1,float by1,float bx2,float by2,float bx3,float by3){
		
		int x1,x2,x3,y1,y2,y3,i=0,j=0,p,t;
		int matrix[r][c];
		r=r-1;
		c=c-1;
		/* converting x1,y1,x2,y2,x3,y3 in to make up a coordinate system */
		bx1=(c)*(bx1-xmin)/(xmax-xmin);
		bx2=c*(bx2-xmin)/(xmax-xmin);
		bx3=c*(bx3-xmin)/(xmax-xmin);
		by1=r*(by1-ymin)/(ymax-ymin);
		by2=r*(by2-ymin)/(ymax-ymin);
		by3=r*(by3-ymin)/(ymax-ymin);
		/* rounding them off to integers*/
		x1=lroundf(bx1);
		x2=lroundf(bx2);
		x3=lroundf(bx3);
		y1=lroundf(by1);
		y2=lroundf(by2);
		y3=lroundf(by3);
		
		r=r+1;
		c=c+1;
		/*chacking weather the 3 points are collinear*/
		t=(x2-x1)*y3+(y1-y2)*x3+(y2*x1-y1*x2);
		if (t==0){
			for(i=0;i<r;i++){
				for(j=0;j<c;j++){
					matrix[i][j]=' ';
				}
			}
			}
		else{
			for(i=0;i<r;i++){
				for(j=0;j<c;j++){
				/*chacking all points to find points in triangle*/
					p=chackpoints(j,i,x1,x2,x3,y1,y2,y3);
					matrix[i][j]=p;
				}
			}
			}
		/* printting the pictuer*/
		for(i=0;i<r+2;i++){
			for(j=0;j<c+2;j++){
				if((i==0&&j==0)||(i==0&&j==c+1)||(i==r+1&&j==0)||(i==r+1&&j==c+1))
					printf("+");
				else if(i==0||i==r+1)
					printf("-");
				else if(j==0||j==c+1)
					printf("|");
				else{
					printf("%c",matrix[r-i][j-1]);
				}
			}
			printf("\n");
			}
		
}

char chackpoints(int x,int y,int x1,int x2,int x3,int y1, int y2, int y3){
	/*chacking points to find points in the triangle*/
	int s1,s2,s3;
	s1=((x2-x1)*y+(y1-y2)*x+(y2*x1-y1*x2))*((x2-x1)*y3+(y1-y2)*x3+(y2*x1-y1*x2));
	s2=((x3-x1)*y+(y1-y3)*x+(y3*x1-y1*x3))*((x3-x1)*y2+(y1-y3)*x2+(y3*x1-y1*x3));
	s3=((x2-x3)*y+(y3-y2)*x+(y2*x3-y3*x2))*((x2-x3)*y1+(y3-y2)*x1+(y2*x3-y3*x2));
	if((s1>=0)&&(s2>=0)&&(s3>=0)){
		return '*';
	}
	else
		return ' ';
	}