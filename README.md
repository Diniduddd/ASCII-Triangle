
 ASCII-Triangle

In this project  a C program (starting from the skeleton code given 
projIskel.c) which will input the co-ordinates of a triangle and output a picture of the triangle 
composed  of  stars  and  spaces  and  framed  by  other  ASCII  characters.  For  example,  if  your 
(compiled) program is called projI, its input and output might look like this: 
 
<p>$ ./proj1 <br />4 8 -2 0 2 5 -2 0 1.42 0 -0.28 5</p>
<p>+--------+ <br />
	|&nbsp;&nbsp;&nbsp;*&nbsp;&nbsp;&nbsp;&nbsp;|<br />
	|&nbsp;&nbsp;***&nbsp;&nbsp;&nbsp;|<br />
	|&nbsp;*****&nbsp;&nbsp; |<br />
	|*******&nbsp;|<br />
	+--------+</p>
 
This  program  begins  by  reading  two  integers  and  ten  floating-point  numbers  from 
standard input. We will refer to these inputs by the following names: 
  r c xmin ymin xmax ymax x1 y1 x2 y2 x3 y3 
 
The first two inputs r and c specify the number of rows and columns in the picture. The picture 
itself should be surrounded by a frame composed of the characters '+', '-' and '|' as shown 
in the example above. The character in the lower left corner of the picture (excluding the frame) 
should correspond to the point (xmin,ymin), the character in the upper right corner should 
correspond to the point (xmax,ymax) and the other characters should correspond to points at 
equal intervals in between. In simple terms, you should make up a coordinate system by dividing 
the space between xmax and xmin in to c number of columns and dividing the space between 
ymax and ymin in to r number of rows. The points (x1,y1), (x2,y2) and (x3,y3) are the co-
ordinates of the vertices of the triangle. Each character in the graph should be a star '*' if the 
corresponding point is inside the triangle, and a space ' ' if it is outside the triangle. Your 
program should behave sensibly in the case where the three points are collinear (i.e. in the 
context  of  the  test  data  provided,  where  none  of  the  plotted  points  will  lie  exactly  on  the 
boundary of the triangle, it should print a framed picture composed entirely of spaces). 
 
A set of test cases (inputs – extension .inp and expected outputs – extension .exp) are provided 
and your final program should behave exactly the same way. Your program should produce 
exactly the same output as the given executable.
 
Apart  from  the  proper  functioning  of  the  program,  this  pay  attention  to  the  error 
messages reported for wrong inputs. There are test cases given covering such instances. 
 
Apart  from  the  skeleton  code  (projIskel.c)  and  the  test  cases,  the  project  tarball 
(projI.tgz) has a Makefile. On a machine where the make utility is installed (such as the lab 
machine or a typical Linux distribution), you should be able to compile and test your program 
(with all the given test cases) using the following command: 
  $ make test 
 
  To compile only you can use: $ make 
  To clean your previous compilation files, you can use: $ make clean 
 
This command will compile your program file and perform the testing against the input/expected 
output pairs given. 
 

