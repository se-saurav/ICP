/*ICP Assignment
Header files are declared here*/
#include <stdio.h>
#include <conio.h>
/*All function used in the system declared here.*/
void binarymenu(void);
void matrixmenu(void);
void stringsmenu(void);
long int dectobin(long int);
long int bintodec(long int);
void matadd(void);
void matsubs(void);
void matmulti(void);
void matdet(void);
void mattrace(void);
void matinv(void);
void stradd(void);
char* add(char[], char[]);
void strdel(void);
void strrep(void);
void strchar(void);
/*main function starts*/
void main()
{
int a;
clrscr();
printf("Main Menu:\n1. Conversions\n2. Matrix Maths\n3. String Functions\n4. Exit\n");
scanf("%d", &a);
/*Switch statement to make selection from menu*/
switch(a)
{
case 1:
binarymenu();
break;
case 2:
matrixmenu();
break;
case 3:
stringsmenu();
break;
case 4:
exit();
break;
default:
printf("Please enter valid input. Try again.....");
getch();
main();
}
getch();
}
/*end of main
binarymenu: function for binary operation.*/
void binarymenu(void)
{
int b;
long int idec, ibin, odec, obin, dec1, dec2;
clrscr();
printf("Conversions:\n1. Decimal to Binary\n2. Binary to Decimal\n3. Binary Addition\n4. Binary Subtraction\n5. Back to main menu\n");
scanf("%d", &b);
fflush(stdin);
switch(b)
{
case 1:
clrscr();
printf("Enter the decimal number to be converted in binary: ");
scanf("%ld",&idec);
/*input decimal idec will be convert to output binary obin by passing it to function dectobin*/
obin=dectobin(idec);
printf("Result is %ld", obin);
getch();
binarymenu();
/*call back to binary function, to keep menu displayed*/
break;
case 2:
clrscr();
printf("Enter the binary number to be converted to decimal: ");
scanf("%ld",&ibin);
/*input binary ibin will be convert to output decimal odec by passing it to function bintodec*/
odec=bintodec(ibin);
printf("Result is: %ld", odec);
getch();
binarymenu();
break;
case 3:
clrscr();
printf("Enter 1st binary number");
scanf("%ld",&ibin);
dec1=bintodec(ibin);
printf("Enter 2nd binary number");
scanf("%ld",&ibin);
dec2=bintodec(ibin);
/*After converteing two inputed binary numbers to decimal it will be added and then converted to binary obin*/
idec=dec1+dec2;
obin=dectobin(idec);
printf("In base 2:- %ld & in base 10:- %ld", obin, idec);
getch();
binarymenu();
break;
case 4:
clrscr();
printf("Enter 1st binary number");
scanf("%ld",&ibin);
dec1=bintodec(ibin);
printf("Enter 2nd binary number");
scanf("%ld",&ibin);
dec2=bintodec(ibin);
/*After converteing two inputed binary numbers to decimal it will be subtracted and then converted to binary obin*/
idec=dec1-dec2;
/*To check either it is in limitation or not*/
if (idec>=0)
{
obin=dectobin(idec);
printf("In base 2:- %ld & in base 10:- %ld", obin, idec);
}
else printf("Sorry, this is out of limitation.");
getch();
binarymenu();
break;
case 5:
main();
break;
default:
printf("Please enter valid input. Try again.....");
getch();
binarymenu();
}
}
/*End of binarymenu function
Star of matrixmenu*/
void matrixmenu(void)
{
int c;
clrscr();
printf("Matrix Maths:\n1. Matrix Addition\n2. Matrix Substraction\n3. Matrix Multiplication\n4. Determinant of the Matrix (Square Only)\n5. Trace of the Matrix (Square Only)\n6. Inverse of the Matrix\n7. Back to main menu\n");
scanf("%d", &c);
fflush(stdin);
switch(c)
{
case 1:
matadd();
matrixmenu();
break;
case 2:
matsubs();
matrixmenu();
break;
case 3:
matmulti();
matrixmenu();
break;
case 4:
matdet();
matrixmenu();
break;
case 5:
mattrace();
matrixmenu();
break;
case 6:
matinv();
matrixmenu();
break;
case 7:
main();
default:
printf("Please enter valid input. Try again.....");
getch();
matrixmenu();
}
}
/*End of matrixmenu function
Start of stringsmenu function*/
void stringsmenu(void)
{
int d;
clrscr();
printf("String Functions:\n1. Add Strings\n2. Delete String\n3. Replace String\n4. Search Charcter\n5. Back to main menu\n");
scanf("%d", &d);
/*fflush(stdin); is used to clear contents of stdin*/
fflush(stdin);
switch(d)
{
case 1:
stradd();
stringsmenu();
break;
case 2:
strdel();
stringsmenu();
break;
case 3:
strrep();
stringsmenu();
break;
case 4:
strchar();
stringsmenu();
break;
case 5:
main();
default:
printf("Please enter valid input. Try again.....");
getch();
stringsmenu();
}
}
/*End of stringsmenu
Start of dectobin function
which will convert decimal number to binary*/
long int dectobin(long int x)
{
long int i=1,t=0,m;
/*while loop to convert decimal x to binary t*/
while(x>0)
{
m=(x%2);
x=(x/2);
t=t+m*i;
i=i*10;
}
//end of while loop
return(t);
// to return value back to calling function
}
/*End of dectobin function
Start of bintodec function
which will convert binary number to decimal*/
long int bintodec(long int x)
{
long int i=1,t=0,m;
/*while loop to convert binary x to decimal t*/
while(x>0)
{
m=(x%10);
x=(x/10);
t=t+m*i;
i=i*2;
}
//end of while loop
return(t);
}
/*End of bintodec function
Start of matadd function
which will add two matrixes*/
void matadd(void)
{
int mat1[50][50], mat2[50][50], mat3[50][50], i, j, r, c;
clrscr();
printf("Enter rows and columns for both matrixes\n");
scanf("%d%d", &r, &c);
/*This nested for loop will make all elements of matrixes mat1 and mat2 to 0*/
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
mat1[i][j]=0;
mat2[i][j]=0;
mat3[i][j]=0;
}
}
/*End of nested for loop*/
printf("Enter elements of 1st matrix\n");
/*Loop to take elements of first matrix*/
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
scanf("%d", &mat1[i][j]);
}
//end of loop
printf("Enter elements of 2nd matrix\n");
/*Loop to take elements of second matrix*/
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
scanf("%d", &mat2[i][j]);
}
/*Loop to add two corresponding elements of both matrixes*/
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
mat3[i][j]=mat1[i][j]+mat2[i][j];
}
printf("Resultant matrix is:\n");
/*Loop to print elements of resultant matrix in rows and columns*/
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
printf("%d  ", mat3[i][j]);
printf("\n");
}
printf("Dimension is %dx%d", r, c);
getch();
}
/*End of matadd function
Start of matsubs function
which will subtract two matrixes*/
void matsubs(void)
{
int mat1[50][50], mat2[50][50], mat3[50][50], i, j, r, c;
clrscr();
printf("Enter rows and columns in both matrixes\n");
scanf("%d%d", &r, &c);
/*This nested for loop will make all elements of matrixes mat1 and mat2 to 0*/
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
mat1[i][j]=0;
mat2[i][j]=0;
mat3[i][j]=0;
}
}
printf("Enter values of 1st matrix\n");
/*Loop to take elements of first matrix*/
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
scanf("%d", &mat1[i][j]);
}
printf("Enter values of 2nd matrix\n");
/*Loop to take elements of second matrix*/
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
scanf("%d", &mat2[i][j]);
}
/*Loop to subtract corresponding elements of two matrixes*/
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
mat3[i][j]=mat1[i][j]-mat2[i][j];
}
printf("Resultant matrix is:\n");
/*Loop to print elements of resultant matrix*/
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
printf("%d  ", mat3[i][j]);
printf("\n");
}
printf("Dimension is %dx%d", r, c);
getch();
}
/*End of matsubs function
Start of matmulti function
which will multiply two matrixes*/
void matmulti(void)
{
int mat1[50][50], mat2[50][50], mat3[50][50], i, j, r1, c1, r2, c2, k, sum;
clrscr();
printf("Enter rows and columns of 1st matrix\n");
scanf("%d%d", &r1, &c1);
printf("Enter rows and columns of 2nd matrix\n");
scanf("%d%d", &r2, &c2);
/*Loop to make all elements of two matrixes 0*/
for(i=0;i<50;i++)
{
for(j=0;j<50;j++)
{
mat1[i][j]=0;
mat2[i][j]=0;
mat3[i][j]=0;
}
}
if (r2!=c1)
{
printf("Matrix multiplication not defined in this case.");
}
else
{
printf("Enter elements of 1st matrix\n");
/*Loop to take elements of first matrix*/
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
scanf("%d", &mat1[i][j]);
}
printf("Enter elements of 2nd matrix\n");
/*Loop to take elements of second matrixe*/
for(i=0;i<r2;i++)
{
for(j=0;j<c2;j++)
scanf("%d", &mat2[i][j]);
}
/*Loop to perform multiplication of two matrixes*/
for(i=0;i<r1;i++)
{
for(j=0;j<c2;j++)
{
sum=0;
for(k=0;k<r2;k++)
sum=sum+mat1[i][k]*mat2[k][j];
mat3[i][j]=sum;
}
}
printf("Resultant matrix is:\n");
/*Loop to print elements of resultant matrix*/
for(i=0;i<r1;i++)
{
for(j=0;j<c2;j++)
printf("%d  ", mat3[i][j]);
printf("\n");
}
}
printf("Dimension is %dx%d", r1, c2);
getch();
}
/*End of matmulti function
Start of mattrace function
which will count trace of matrix*/
void mattrace(void)
{
int mat[50][50], i, j, d, sum;
clrscr();
printf("Enter dimension of matrix(squqre only)\n");
scanf("%d", &d);
/*Loop to make elements of matrix to 0*/
for(i=0;i<50;i++)
{
for(j=0;j<50;j++)
{
mat[i][j]=0;
}
}
printf("Enter elements of matrix\n");
/*Loop to take elements of matrix*/
for(i=0;i<d;i++)
{
for(j=0;j<d;j++)
scanf("%d", &mat[i][j]);
}
sum=0;
/*Loop to count trace of matrix*/
for(i=0;i<d;i++)
{
for(j=0;j<d;j++)
{
if(i==j)
{
sum=sum+mat[i][j];
}
}
}
printf("Trace of matrix is: %d", sum);
getch();
}
/*End of mattrace function
Start of strrep function
which will replace string from string*/
void strrep(void)
{
char str1[50], str2[50];
int i,j,l1=0, l2=0, p;
clrscr();
printf("Input string : ");
gets(str1);
fflush(stdin);
printf("Input replacement string : ");
gets(str2);
fflush(stdin);
printf("Enter position(start point) from where you want to replace the string: ");
scanf("%d", &p);
/*Loop to count length of string str1*/
for(i=0;str1[i]!='\0';i++)
{
l1=l1+1;
}
/*Loop to count length of string str2*/
for(i=0;str2[i]!='\0';i++)
{
l2=l2+1;
}
j=0;
/*Loop to cancatenate two strings str1 and str2*/
for (i=p; i<l2+p; i++)
{
str1[i]=str2[j];
j++;
}
/*condition to put NULL character at end if it comes out of first string*/
if(l2>(l1-p))
{
str1[l2+p]='\0';
}
puts(str1);
getch();
}
/*End of strrep function
Start of strdel function
which will delete string from string*/
void strdel(void)
{
char p, str1[50], str2[50];
int i,j,l1=0, l2=0;
clrscr();
printf("Input string: ");
gets(str1);
/*Loop to count length of string str1*/
for(i=0;str1[i]!='\0';i++)
{
l1=l1+1;
}
printf("How long string you want to delete: ");
scanf("%d", &l2);
fflush(stdin);
printf("Enter position (r-rear/f-front): ");
scanf("%c", &p);
switch(p)
{
case 'r':
str1[l1-l2]='\0';
puts(str1);
break;
case 'f':
j=0;
/*Loop to delete string form str1 from front*/
for(i=l2; i<=l1; i++)
{
str2[j]=str1[i];
j++;
}
puts(str2);
break;
default:
printf("You entered wrong choice. Try again......");
strdel();
}
getch();
}
/*End of strdel function
Start of stradd function
which will add string to string*/
void stradd(void)
{
char *p, str1[50], str2[50];
clrscr();
printf("Enter first string: ");
gets(str1);
printf("Enter second string: ");
gets(str2);
p=add(str1, str2);
puts(p);
getch();
}
/*End of stradd function
Start of *add function
which will delete string from string*/
char *add(char a[], char b[])
{
char* c;
int i=0, j=0, k, l;
/*while loop to count length*/
while(a[i]!='\0')
{
i++;
}
/*while loop write elements str2 in str1*/
while(b[j]!='\0')
{
a[i]=b[j];
i++;
j++;
}
/*making last character as NULL*/
a[i]='\0';
return(a);
}
/*End of add function
Start of strchar function
which will search character in string*/
void strchar(void)
{
int i=0, k=0, l;
char s[50], c;
clrscr();
printf("Enter a string: ");
gets(s);
/*while loop to count length*/
while(s[i]!='\0')
{
i++;
}
printf("Enter character to be searched : ");
scanf("%c", &c);
/*while loop to search character*/
while(s[k]!='\0')
{
if(s[k]==c)
{
printf("Character is located at %d", k);
break;
}
else if(s[k+1]=='\0')
printf("Chareacter not found");
k++;
}
getch();
}
/*End of strchar function
Start of matdet function
which will find determinant of matrix*/
void matdet(void)
{
int mat[50][50], i, j, d, det;
clrscr();
printf("Enter dimension of matrix(squqre only)\n");
scanf("%d", &d);
if(d<5)
{
/*loop to set elements of matrix as 0*/
for(i=0;i<50;i++)
{
for(j=0;j<50;j++)
{
mat[i][j]=0;
}
}
printf("Enter values of matrix\n");
/*loop to take elements of matix*/
for(i=0;i<d;i++)
{
for(j=0;j<d;j++)
scanf("%d", &mat[i][j]);
}
/*Switch statement to make selection according to dimension*/
switch(d)
{
/*case of 0x0*/
case 0:
det=0;
break;
case 1:
/*case of 1x1*/
det=mat[0][0];
break;
case 2:
/*case of 2x2*/
det=mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
break;
case 3:
/*case of 3x3*/
det=(mat[0][0]*(mat[1][1]*mat[2][2]-mat[2][1]*mat[1][2])-mat[0][1]*(mat[1][0]*mat[2][2]-mat[2][0]*mat[1][2])+mat[0][2]*(mat[1][0]*mat[2][1]-mat[1][1]*mat[2][0]));
break;
case 4:
/*case of 4x4*/
det=(mat[0][0]*(mat[1][1]*(mat[2][2]*mat[3][3]-mat[3][2]*mat[2][3])-mat[1][2]*(mat[2][1]*mat[3][3]-mat[3][1]*mat[2][3])+mat[1][3]*(mat[2][1]*mat[3][2]-mat[2][2]*mat[3][1]))-mat[0][1]*(mat[1][0]*(mat[2][2]*mat[3][3]-mat[3][2]*mat[2][3])-mat[1][2]*(mat[2][0]*mat[3][3]-mat[2][3]*mat[3][0])+mat[1][3]*(mat[2][0]*mat[3][2]-mat[2][2]*mat[3][0]))+mat[0][2]*(mat[1][0]*(mat[2][1]*mat[3][3]-mat[3][1]*mat[2][3])-mat[1][1]*(mat[2][0]*mat[3][3]-mat[3][0]*mat[2][3])+mat[1][3]*(mat[2][0]*mat[3][1]-mat[2][1]*mat[3][0]))-mat[0][3]*(mat[1][0]*(mat[2][1]*mat[3][2]-mat[3][1]*mat[2][2])-mat[1][1]*(mat[2][0]*mat[3][2]-mat[3][0]*mat[2][2])+mat[1][2]*(mat[2][0]*mat[3][1]-mat[2][1]*mat[3][0])));
break;
default:printf("Out of limitation, Try again.....");
}
printf("Determinant of matrix is: %d", det);
}
else
printf("This is out of limitation.");
getch();
matrixmenu();
}
/*End of matdet function
Start of matin function
which will find inverse of matrix*/
void matinv(void)
{
int mat[50][50], i, j, d, det, matinv[50][50];
clrscr();
printf("Enter dimension of matrix(squqre only)\n");
scanf("%d", &d);
if(d<4)
{
/*loop to set elements of matrix as 0*/
for(i=0;i<50;i++)
{
for(j=0;j<50;j++)
{
mat[i][j]=0;
}
}
printf("Enter values of matrix\n");
/*loop to take elements of matix*/
for(i=0;i<d;i++)
{
for(j=0;j<d;j++)
scanf("%d", &mat[i][j]);
}
switch(d)
{
case 0:
/*case of 0x0*/
det=0;
matinv[0][0]=0;
break;
case 1:
/*case of 1x1*/
det=mat[0][0];
matinv[0][0]=1;
break;
case 2:
/*case of 2x2*/
det=mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
matinv[0][0]=mat[1][1];
matinv[0][1]=-(mat[0][1]);
matinv[1][0]=-(mat[1][0]);
matinv[1][1]=mat[0][0];
break;
case 3:
/*case of 3x3*/
det=(mat[0][0]*(mat[1][1]*mat[2][2]-mat[2][1]*mat[1][2])-mat[0][1]*(mat[1][0]*mat[2][2]-mat[2][0]*mat[1][2])+mat[0][2]*(mat[1][0]*mat[2][1]-mat[1][1]*mat[2][0]));
matinv[0][0]=mat[2][2]*mat[1][1]-mat[2][1]*mat[1][2];
matinv[0][1]=(-(mat[2][2]*mat[0][1]-mat[2][1]*mat[0][2]));
matinv[0][2]=mat[1][2]*mat[0][1]-mat[1][1]*mat[0][2];
matinv[1][0]=(-(mat[2][2]*mat[1][0]-mat[2][0]*mat[1][2]));
matinv[1][1]=mat[2][2]*mat[0][0]-mat[2][0]*mat[0][2];
matinv[1][2]=(-(mat[1][2]*mat[0][0]-mat[1][0]*mat[0][2]));
matinv[2][0]=mat[2][1]*mat[1][0]-mat[2][0]*mat[1][1];
matinv[2][1]=(-(mat[2][1]*mat[0][0]-mat[2][0]*mat[0][1]));
matinv[2][2]=mat[1][1]*mat[0][0]-mat[1][0]*mat[0][1];
break;
default:
printf("Wrong Choice, Try again.....");
}
/*Loop to print element of resultant matrix*/
for(i=0;i<d;i++)
{
for(j=0;j<d;j++)
printf("%d/%d  ", matinv[i][j], det);
printf("\n");
}
printf("Dimension is %dx%d", d, d);
}
else
printf("This is out of limitation.");
getch();
matrixmenu();
}