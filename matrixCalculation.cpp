//NAME:MUHAMMAD FAIZAN  SUBJECT:PROGRAMMING FUNDAMENTALS
//REGISTRATION N0:L1F18BSCS0273  TEACHER:MAM FAREEHA IQBAL
//PROJECT:MATRIX CALCULATION   SECTION : D

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

//IF USE TO WANT INPUT FROM FILE THAN MAKE SURE YOU SAVE A ROW NO AND COLUMN NO OTHER WISE ERROR WILL SHOW
//USING OF STRUCTURE FOR OUTPUT

struct matrix
{
	float **a;
	int row;
	int column;
};	

//FUNCTIONS

void menu();
float **AutoGrowRow(float **row,int r,int c);
void InputMatrix(float**a,int r,int c);	//INPUT MATRIX ON CONSOLE
void InputFMatrix(float**a,int &r,int &c,ifstream &fin); //INPUT MATRIX FROM FILE
void printMatrix(float**a,int r,int c);	//OUPUT MATRIX ON CONSOLE
void printFMatrix(float**a,int r,int c);	//OUPUT MATRIX ON FILE
float SumOfMatrix(float**a,int r,int c);
float ProductOfMatrix(float**a,int r,int c);
float RowWiseAverage(float**a,int r,int c,int n);
float ColumnWiseAverage(float**a,int r,int c,int n);
float AverageWholeMatrix(float**a,int r,int c);
void SortArrayRow(float**a,int n,int r);
void SortArrayColumn(float**a,int n,int r);
void SumOfMatrices(float**a,float**b,float**z,int r,int c);
void ScalarMultiply(float**a,int r,int c,float q);
void SubOfMatrices(float**a,float**b,float**z,int r,int c);
void ScalarMatrixDivision(float**a,int r,int c,float q);
void ScalarAdd(float**a,int r,int c,float q);
void ScalarSubtract(float**a,int r,int c,float q);
void TransposeOfMatrix(float**a,float**b,int r,int c);
void MultiplyMatrices(float**a,float**b,float **z,int r1,int c1,int r2,int c2);
void  EvaulationForPersonal(int n);
void  EvaulationForFile(int n);
float determinant( float **matrix, int n);
double pow(int b,int e);
void adjoint(float **a,int n);
void createMinor(float **matrix, float **minor, int row, int col);

void out(float **a,int r,int c)
{
	int n;
	cout<<"Where You want your Output:"<<endl<<"Enter 1 for File and 0 for Console:";
	cin>>n;
	if(n==1)
	{
		printFMatrix(a,r,c);
	}
	else
	{
		if(n==0)
		{
			printMatrix(a,r,c);
		}
	}
}
//MAIN FUNCTION 

int main()
{
	cout<<"\t\t\t\t""M A T R I X \tC A C U L A T I O N""\n\n\n\n";
	int n=0,n1=0;int p=0;
	while(p==0)
	{
	cout<<"Please Enter 5 for PERSONALLY input and 6 for FILE Input:"<<endl<<endl;
	cout<<"Your Choice:";
	cin>>n;
	cout<<"\n\n\n\n";
	if(n==5)
	{	
		menu();
		cout<<"\n\n\n";
		cout<<"Your Choice:";
		cin>>n1;
		EvaulationForPersonal(n1);
	}
	else
	{
		if(n==6)
		{
			menu();
			cout<<"\n\n\n";
			cout<<"Your Choice:";
			cin>>n1;
			EvaulationForFile(n1);		
		}
	}
	cout<<"\n\n\n";
	cout<<"Please Enter 0 for More Check Otherwise System should be break";cin>>p;
	}
	
	return 0;
}

void menu(){
	cout<<"Enter 1 for Sum of Matrix (sum of all values):"<<endl
	<<"Enter 2 for Product of Matrix (product of all values):"<<endl
	<<"Enter 3 for Row-wise Average:"<<endl
	<<"Enter 4 for Column-wise Average:"<<endl
	<<"Enter 5 for Average or whole Matrix:"<<endl
	<<"Enter 6 for Row-wise sorting of Matrix:"<<endl
	<<"Enter 7 for Column-wise sorting of Matrix:"<<endl
	<<"Enter 8 for Scalar Matrix Addition:"<<endl
	<<"Enter 9 for Addition of two Matrices:"<<endl
	<<"Enter 10 for Scalar Matrix Subtraction:"<<endl
	<<"Enter 11 for Subtraction of two Matrices:"<<endl
	<<"Enter 12 for Scalar Matrix Multiplication:"<<endl
	<<"Enter 13 for Multiplication of two Matrices:"<<endl
	<<"Enter 14 for Scalar Matrix Division:"<<endl
	<<"Enter 15 for Matrix transpose:"<<endl
	<<"Enter 16 for Matrix determinant:"<<endl
	<<"Enter 17 for Matrix Inverse:"<<endl;
}

void  EvaulationForFile(int n)
{
	
	int r,c,q,r1,c1,choice;
	char filename[15];
	ifstream fin,fin1;
	cout<<"Enter FileName1:";
	cin>>filename;
	fin.open(filename);
	if(n==9||n==11||n==13)
	{
		char filename1[15];
		cout<<"Enter FileName2:";
		cin>>filename1;
		fin1.open(filename1);		
	}
	if(n==1)
	{
		fin>>r>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputFMatrix(a,r,c,fin);	
		int n;
	cout<<"Where You want your Output:"<<endl<<"Enter 1 for File and 0 for Console:";
	cin>>n;
	if(n==1)
	{
		ofstream fout;
		fout.open("output.txt");
		fout<<endl<<endl;
		fout<<"SUM of MATRIX should be:";		
		fout<<SumOfMatrix(a,r,c);
		fout.close();
	}
	else
	{
		if(n==0)
		{
		cout<<endl<<endl;
		cout<<"SUM of MATRIX should be:";
		cout<<SumOfMatrix(a,r,c);			
		}
	}			
	}
	else if(n==2)
	{
		fin>>r>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputFMatrix(a,r,c,fin);
		int n;
	cout<<"Where You want your Output:"<<endl<<"Enter 1 for File and 0 for Console:";
	cin>>n;
	if(n==1)
	{
		ofstream fout;
		fout.open("output.txt");
		fout<<endl<<endl;
		fout<<"Product of MATRIX should be:";
		fout<<ProductOfMatrix(a,r,c);
		fout.close();
	}
	else
	{
		if(n==0)
		{
		cout<<endl<<endl;
		cout<<"SUM of MATRIX should be:";
		cout<<ProductOfMatrix(a,r,c);				
		}
	}			
	}
	else if(n==3)
	{
		fin>>r>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputFMatrix(a,r,c,fin);
		int n;
	cout<<"Where You want your Output:"<<endl<<"Enter 1 for File and 0 for Console:";
	cin>>n;
	if(n==1)
	{
		ofstream fout;
		fout.open("output.txt");
		fout<<endl<<endl;
		for(int q=0;q<r;q++)
		{
			fout<<"AVERAGE OF ROW "<<q<<"=";		
			fout<<RowWiseAverage(a,r,c,q)<<endl;
		}
		fout.close();
	}
	else
	{
		if(n==0)
		{
		for(int q=0;q<r;q++)
		{
			cout<<"AVERAGE OF ROW "<<q<<"=";		
			cout<<RowWiseAverage(a,r,c,q)<<endl;	
		}				
		}
	}

	}
	else if(n==4)
	{
		fin>>r>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputFMatrix(a,r,c,fin);
		int n;
	cout<<"Where You want your Output:"<<endl<<"Enter 1 for File and 0 for Console:";
	cin>>n;
	if(n==1)
	{
		ofstream fout;
		fout.open("output.txt");
		fout<<endl<<endl;
		for(int q=0;q<r;q++)
		{
			fout<<"AVERAGE OF Column "<<q<<"=";		
			fout<<ColumnWiseAverage(a,r,c,q)<<endl;
		}
		fout.close();
	}
	else
	{
		if(n==0)
		{
		for(int q=0;q<r;q++)
		{
			cout<<"AVERAGE OF Column "<<q<<"=";		
			cout<<ColumnWiseAverage(a,r,c,q)<<endl;	
		}				
		}
	}			
	}
	else if(n==5)
	{
		fin>>r>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputFMatrix(a,r,c,fin);
		int n;
	cout<<"Where You want your Output:"<<endl<<"Enter 1 for File and 0 for Console:";
	cin>>n;
	if(n==1)
	{
		ofstream fout;
		fout.open("output.txt");
		fout<<endl<<endl;
		fout<<"WHOLE AVERAGE of MATRIX should be:";	
		fout<<AverageWholeMatrix(a,r,c);
		fout.close();
	}
	else
	{
		if(n==0)
		{
			cout<<endl<<endl;	
			cout<<"WHOLE AVERAGE of MATRIX should be:";	
			cout<<AverageWholeMatrix(a,r,c);			
		}
	}		
		
	}
	else if(n==6)
	{
		cout<<"Enter size of row and column:"<<endl<<"Enter row:";
		cin>>r;
		cout<<"Enter Column:";/////////
		cin>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputFMatrix(a,r,c,fin);
		cout<<"Enter a row which You want to sort:";
		cin>>q;
		SortArrayRow(a,q,c);	
		out(a,r,c);
	}
	else if(n==7)
	{
		cout<<"Enter size of row and column:"<<endl<<"Enter row:";
		cin>>r;
		cout<<"Enter Column:";/////////
		cin>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputFMatrix(a,r,c,fin);
		cout<<"Enter a Column which You want to sort:";
		cin>>q;
		SortArrayColumn(a,q,r);
		out(a,r,c);	
	}
	else if(n==8)
	{
		fin>>r>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputFMatrix(a,r,c,fin);
		cout<<"Enter a Number which u want to add in a Matrix::";
		cin>>q;
		ScalarAdd(a,r,c,q);
		out(a,r,c);		
	}
	else if(n==9)
	{
		fin>>r>>c;
		fin1>>r1>>c1;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		float **b=0;
		b=AutoGrowRow(b,r,c);
		float **z=0;
		z=AutoGrowRow(z,r,c);		
		InputFMatrix(a,r,c,fin);
		InputFMatrix(b,r,c,fin1);
		SumOfMatrices(a,b,z,r,c);
		out(z,r,c);		
	} 
	else if(n==10)
	{
		fin>>r>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputFMatrix(a,r,c,fin);
		cout<<"Enter a Number which u want to subtract in a Matrix::";
		cin>>q;
		ScalarSubtract(a,r,c,q);
		out(a,r,c);		
	}
	else if(n==11)
	{
		fin>>r>>c;
		fin1>>r1>>c1;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		float **b=0;
		b=AutoGrowRow(b,r,c);
		float **z=0;
		z=AutoGrowRow(z,r,c);		
		InputFMatrix(a,r,c,fin);
		InputFMatrix(b,r,c,fin1);
		SubOfMatrices(a,b,z,r,c);
		out(z,r,c);		
	}
	else if(n==12)
	{
		fin>>r>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputFMatrix(a,r,c,fin);
		cout<<"Enter a Number which u want to Multiply in a Matrix::";
		cin>>q;
		ScalarMultiply(a,r,c,q);
		out(a,r,c);			
	}
	else if(n==13)
	{
		fin>>r>>c;
		fin1>>r1>>c1;
		if(c!=r1)cout<<"Please Edit your File Column of 1st Matrix Should be equal to Row of 2nd Matrix";
		float **a=0;
		a=AutoGrowRow(a,r,c);
		float **b=0;
		b=AutoGrowRow(b,r1,c1);
		float **z=0;
		z=AutoGrowRow(z,r,r1);		
		InputFMatrix(a,r,c,fin);
		InputFMatrix(b,r1,c1,fin1);
		if(c==r1)MultiplyMatrices(a,b,z,r,c,r1,c1);
		out(z,r,r1);			
	}
	else if(n==14)
	{
		fin>>r>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputFMatrix(a,r,c,fin);
		cout<<"Enter a Number which u want to Divide in a Matrix::";
		cin>>q;
		ScalarMatrixDivision(a,r,c,q);
		out(a,r,c);		
	}
	else if(n==15)
	{
		fin>>r>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		float **b=0;
		b=AutoGrowRow(b,c,r);
		InputFMatrix(a,r,c,fin);
		TransposeOfMatrix(a,b,r,c);
		out(b,c,r);			
	}
	else if(n==16)
	{
		fin>>r>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputFMatrix(a,r,c,fin);	
		int n;
	cout<<"Where You want your Output:"<<endl<<"Enter 1 for File and 0 for Console:";
	cin>>n;
	if(n==1)
	{
		ofstream fout;
		fout.open("output.txt");
		fout<<endl<<endl;
		fout<<"DETERMINANT OF Matrix is:";
		fout<<determinant(a,r);
		fout.close();
	}
	else
	{
		if(n==0)
		{
			cout<<endl<<endl;	
			cout<<"DETERMINANT OF Matrix is:";	
			cout<<determinant(a,r);				
		}
	}	
	}
	else if(n==17)
{
		cout<<"ENTER SIZE OF MATRIX:";
		fin>>r>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputFMatrix(a,r,r,fin);
		adjoint(a,r);		
		out(a,r,r);				
}	
	else cout<<"Please Enter a Number between 1 and 17!!";	
}

void  EvaulationForPersonal(int n)
{
	int r,c,q,r1,c1;
	if(n==1)
	{
		cout<<"Enter size of row and column:"<<endl<<"Enter row:";
		cin>>r;
		cout<<"Enter Column:";
		cin>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputMatrix(a,r,c);
	int n;
	cout<<"Where You want your Output:"<<endl<<"Enter 1 for File and 0 for Console:";
	cin>>n;
	if(n==1)
	{
		ofstream fout;
		fout.open("output.txt");
		fout<<endl<<endl;
		fout<<"SUM of MATRIX should be:";		
		fout<<SumOfMatrix(a,r,c);
		fout.close();
	}
	else
	{
		if(n==0)
		{
		cout<<endl<<endl;
		cout<<"SUM of MATRIX should be:";
		cout<<SumOfMatrix(a,r,c);			
		}
	}
	}
	else if(n==2)
	{
		cout<<"Enter size of row and column:"<<endl<<"Enter row:";
		cin>>r;
		cout<<"Enter Column:";
		cin>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputMatrix(a,r,c);
		int n;
	cout<<"Where You want your Output:"<<endl<<"Enter 1 for File and 0 for Console:";
	cin>>n;
	if(n==1)
	{
		ofstream fout;
		fout.open("output.txt");
		fout<<endl<<endl;
		fout<<"Product of MATRIX should be:";
		fout<<ProductOfMatrix(a,r,c);
		fout.close();
	}
	else
	{
		if(n==0)
		{
		cout<<endl<<endl;
		cout<<"SUM of MATRIX should be:";
		cout<<ProductOfMatrix(a,r,c);				
		}
	}	
	}
	else if(n==3)
	{
		cout<<"Enter size of row and column:"<<endl<<"Enter row:";
		cin>>r;
		cout<<"Enter Column:";
		cin>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputMatrix(a,r,c);
		int n;
	cout<<"Where You want your Output:"<<endl<<"Enter 1 for File and 0 for Console:";
	cin>>n;
	if(n==1)
	{
		ofstream fout;
		fout.open("output.txt");
		fout<<endl<<endl;
		for(int q=0;q<r;q++)
		{
			fout<<"AVERAGE OF ROW "<<q<<"=";		
			fout<<RowWiseAverage(a,r,c,q)<<endl;
		}
		fout.close();
	}
	else
	{
		if(n==0)
		{
		for(int q=0;q<r;q++)
		{
			cout<<"AVERAGE OF ROW "<<q<<"=";		
			cout<<RowWiseAverage(a,r,c,q)<<endl;	
		}				
		}
	}

	}
	else if(n==4)
	{
		cout<<"Enter size of row and column:"<<endl<<"Enter row:";
		cin>>r;
		cout<<"Enter Column:";
		cin>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputMatrix(a,r,c);
		int n;
	cout<<"Where You want your Output:"<<endl<<"Enter 1 for File and 0 for Console:";
	cin>>n;
	if(n==1)
	{
		ofstream fout;
		fout.open("output.txt");
		fout<<endl<<endl;
		for(int q=0;q<r;q++)
		{
			fout<<"AVERAGE OF Column "<<q<<"=";		
			fout<<ColumnWiseAverage(a,r,c,q)<<endl;
		}
		fout.close();
	}
	else
	{
		if(n==0)
		{
		for(int q=0;q<r;q++)
		{
			cout<<"AVERAGE OF Column "<<q<<"=";		
			cout<<ColumnWiseAverage(a,r,c,q)<<endl;	
		}				
		}
	}
	}
	else if(n==5)
	{
		cout<<"Enter size of row and column:"<<endl<<"Enter row:";
		cin>>r;
		cout<<"Enter Column:";
		cin>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputMatrix(a,r,c);
		int n;
	cout<<"Where You want your Output:"<<endl<<"Enter 1 for File and 0 for Console:";
	cin>>n;
	if(n==1)
	{
		ofstream fout;
		fout.open("output.txt");
		fout<<endl<<endl;
		fout<<"WHOLE AVERAGE of MATRIX should be:";	
		fout<<AverageWholeMatrix(a,r,c);
		fout.close();
	}
	else
	{
		if(n==0)
		{
			cout<<endl<<endl;	
			cout<<"WHOLE AVERAGE of MATRIX should be:";	
			cout<<AverageWholeMatrix(a,r,c);			
		}
	}		
	}
	else if(n==6)
	{
		cout<<"Enter size of row and column:"<<endl<<"Enter row:";
		cin>>r;
		cout<<"Enter Column:";/////////
		cin>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputMatrix(a,r,c);
		cout<<"Enter a row which You want to sort:";
		cin>>q;
		SortArrayRow(a,q,c);
		out(a,r,c);	
	}
	else if(n==7)
	{
		cout<<"Enter size of row and column:"<<endl<<"Enter row:";
		cin>>r;
		cout<<"Enter Column:";
		cin>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputMatrix(a,r,c);
		cout<<"Enter a Column which You want to sort:";
		cin>>q;
		SortArrayColumn(a,q,r);
		out(a,r,c);		
	}
	else if(n==8)
	{
		cout<<"Enter size of row and column:"<<endl<<"Enter row:";
		cin>>r;
		cout<<"Enter Column:";
		cin>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputMatrix(a,r,c);
		cout<<"Enter a Number which u want to add in a Matrix::";
		cin>>q;
		ScalarAdd(a,r,c,q);
		out(a,r,c);		
	}
	else if(n==9)
	{
		cout<<"Enter size of row and column for Matrix 1:"<<endl<<"Enter row:";
		cin>>r;
		cout<<"Enter Column:";
		cin>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		float **b=0;
		b=AutoGrowRow(b,r,c);
		float **z=0;
		z=AutoGrowRow(z,r,c);		
		InputMatrix(a,r,c);
		cout<<"Enter Matrix 2:"<<endl;
		InputMatrix(b,r,c);
		SumOfMatrices(a,b,z,r,c);
		out(z,r,c);		
	}
	else if(n==10)
	{
		cout<<"Enter size of row and column:"<<endl<<"Enter row:";
		cin>>r;
		cout<<"Enter Column:";
		cin>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputMatrix(a,r,c);
		cout<<"Enter a Number which u want to subtract in a Matrix::";
		cin>>q;
		ScalarSubtract(a,r,c,q);
		out(a,r,c);			
	}
	else if(n==11)
	{
		cout<<"Enter size of row and column for Matrix 1:"<<endl<<"Enter row:";
		cin>>r;
		cout<<"Enter Column:";
		cin>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		float **b=0;
		b=AutoGrowRow(b,r,c);
		float **z=0;
		z=AutoGrowRow(z,r,c);		
		InputMatrix(a,r,c);
		cout<<"Enter Matrix 2:"<<endl;
		InputMatrix(b,r,c);
		SubOfMatrices(a,b,z,r,c);
		out(z,r,c);		
	}
	else if(n==12)
	{
		cout<<"Enter size of row and column:"<<endl<<"Enter row:";
		cin>>r;
		cout<<"Enter Column:";
		cin>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputMatrix(a,r,c);
		cout<<"Enter a Number which u want to Multiply in a Matrix::";
		cin>>q;
		ScalarMultiply(a,r,c,q);
		out(a,r,c);			
	}
	else if(n==13)
	{
		while(c!=r1){
		cout<<"Enter size of row and column for Matrix 1:"<<endl<<"Enter row:";
		cin>>r;
		cout<<"Enter Column:";
		cin>>c;
		cout<<"Enter size of row and column for Matrix 2:"<<endl<<"Enter row:";
		cin>>r1;
		cout<<"Enter Column:";
		cin>>c1;		
		}
		float **a=0;
		a=AutoGrowRow(a,r,c);
		float **b=0;
		b=AutoGrowRow(b,r1,c1);
		float **z=0;
		z=AutoGrowRow(z,r,r1);		
		InputMatrix(a,r,c);
		cout<<"Enter Matrix 2:"<<endl;
		InputMatrix(b,r1,c1);
		MultiplyMatrices(a,b,z,r,c,r1,c1);
		out(z,r,r1);			
		
	}
	else if(n==14)
	{
		cout<<"Enter size of row and column:"<<endl<<"Enter row:";
		cin>>r;
		cout<<"Enter Column:";
		cin>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		InputMatrix(a,r,c);
		cout<<"Enter a Number which u want to Divide in a Matrix::";
		cin>>q;
		ScalarMatrixDivision(a,r,c,q);
		out(a,r,c);			
	}
	else if(n==15)
	{
		cout<<"Enter size of row and column:"<<endl<<"Enter row:";
		cin>>r;
		cout<<"Enter Column:";
		cin>>c;
		float **a=0;
		a=AutoGrowRow(a,r,c);
		float **b=0;
		b=AutoGrowRow(b,c,r);
		InputMatrix(a,r,c);
		TransposeOfMatrix(a,b,r,c);
		out(b,c,r);			
	}
	else if(n==16)
	{
		cout<<"Enter size of Matrix";
		cin>>r;	
		float **a=0;
		a=AutoGrowRow(a,r,r);
		InputMatrix(a,r,r);	
		int n;
	cout<<"Where You want your Output:"<<endl<<"Enter 1 for File and 0 for Console:";
	cin>>n;
	if(n==1)
	{
		ofstream fout;
		fout.open("output.txt");
		fout<<endl<<endl;
		fout<<"DETERMINANT OF Matrix is:";
		fout<<determinant(a,r);
		fout.close();
	}
	else
	{
		if(n==0)
		{
			cout<<endl<<endl;	
			cout<<"DETERMINANT OF Matrix is:";	
			cout<<determinant(a,r);				
		}
	}
	}
	else if(n==17)
	{
		cout<<"Enter size of Matrix";
		cin>>r;	
		float **a=0;
		a=AutoGrowRow(a,r,r);
		InputMatrix(a,r,r);
		adjoint(a,r);		
		out(a,r,r);	
	}
	else cout<<"Please Enter a Number between 1 and 17!!";	
}

void InputMatrix(float**a,int r,int c)
{
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<"Enter ("<<i<<","<<j<<"):";
			cin>>a[i][j];
		}
	}
}

void printMatrix(float**a,int r,int c)
{
	struct matrix p,p1,p2;
	p.a=a;
	p1.row=r;
	p2.column=c;
	cout<<"Your Matrix Should be:"<<endl;
	for(int i=0;i<p1.row;i++)
	{
		for(int j=0;j<p2.column;j++)
		{
			cout<<p.a[i][j];
		}
		cout<<endl;
	}	
}

void printFMatrix(float**a,int r,int c)
{

	struct matrix p,p1,p2;
	p.a=a;
	p1.row=r;
	p2.column=c;	
	ofstream fout;
	fout.open("output.txt");
	for(int i=0;i<p1.row;i++)
	{
		for(int j=0;j<p2.column;j++)
		{
			fout<<p.a[i][j];
		}
		fout<<endl;
	}
	fout.close();	
}

float SumOfMatrix(float**a,int r,int c)
{
	float sum=0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			sum=sum+a[i][j];
		}
	}
	return sum;	
}

float ProductOfMatrix(float**a,int r,int c)
{
	float product=1;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			product=product*a[i][j];
		}
	}
	return product;	
}

float RowWiseAverage(float**a,int r,int c,int n)
{
	float sum=0;
		for(int j=0;j<c;j++)
		{
			sum=sum+a[n][j];
		}
	sum=sum/c;
	return sum;
}

float ColumnWiseAverage(float**a,int r,int c,int n)
{
	float sum=0;
		for(int j=0;j<r;j++)
		{
			sum=sum+a[j][n];
		}
	sum=sum/r;
	return sum;
}

float AverageWholeMatrix(float**a,int r,int c)
{
	float average=SumOfMatrix(a,r,c)/(r*c);
	return average;
}

void SortArrayRow(float**a,int n,int r)
{
	float temp;
	int in=0;
	for(int i=0;i<r;i++)
	{
		in=i;
		for(int j=i;j<r;j++)
		{
			if(a[n][j]<a[n][in]) in=j;
		}
		temp=a[n][i];
		a[n][i]=a[n][in];
		a[n][in]=temp;
	}
}

void SortArrayColumn(float**a,int n,int r)
{
	float temp;
	int in=0;
	for(int i=0;i<r;i++)
	{
		in=i;
		for(int j=i;j<r;j++)
		{
			if(a[j][n]<a[in][n]) in=j;
		}
		temp=a[i][n];
		a[i][n]=a[in][n];
		a[in][n]=temp;
	}
}

void SumOfMatrices(float**a,float**b,float**z,int r,int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			z[i][j]=a[i][j]+b[i][j];
		}
	}
}

void ScalarMultiply(float**a,int r,int c,float q)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			a[i][j]=a[i][j]*q;
		}
	}
}

void SubOfMatrices(float**a,float**b,float**z,int r,int c)
{
	ScalarMultiply(b,r,c,-1);
	SumOfMatrices(a,b,z,r, c);
	ScalarMultiply(b,r,c,-1);
}

void ScalarMatrixDivision(float**a,int r,int c,float q)
{
	ScalarMultiply(a,r,c,1/q);
}

void ScalarAdd(float**a,int r,int c,float q)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			a[i][j]=a[i][j]+q;
		}
	}
}

void ScalarSubtract(float**a,int r,int c,float q)
{
	ScalarAdd(a, r, c,-1*q);
}

void TransposeOfMatrix(float**a,float**b,int r,int c)
{
	for(int i=0;i<c;i++)
	{
		for(int j=0;j<r;j++)
		{
				b[i][j]=a[j][i];
		}
	}	
}

float **AutoGrowRow(float **row,int r,int c)
{
	float **temp=new float*[r];
	for(int i=0;i<r;i++)
	{
		temp[i]=new float [c];
	}
	delete []row;
	row=0;
	row=temp;
	return row;
}

void MultiplyMatrices(float**a,float**b,float **z,int r1,int c1,int r2,int c2)
{
	int i=0,j=0,k=0;
    for(i = 0; i < r1; ++i)
	{
        for(j = 0; j < c2; ++j)
		{
            for(k = 0; k < c1; ++k)
            {
                z[i][j] =z[i][j]+ a[i][k] * b[k][j];
            }	
        }
    }
}

float determinant( float **a, int n)
{   
   float det=0;
   float **matrix=new float *[n];
   for(int i=0;i<n;i++)
   {
   		matrix[i]=new float [n];
   }
   if (n==2)
   {
      return ((a[0][0]*a[1][1])-(a[1][0]*a[0][1]));
   }
   else
   {
   	if(n==3)
   	{
	
      for (int x=0;x<n;x++)
	  {
            int k = 0; 
            for (int i=1;i<n;i++)
			{
               int p = 0;
               for (int j=0;j<n;j++)
			   {
                  if (j == x)
                  {
						j++;
				  }
                  matrix[k][p]=a[i][j];
                  p++;
               }
               k++;
            }
            det=det+(pow(-1, x)*a[0][x]*determinant(matrix,n-1));
      }
  	}
  	else
  	{
  		cout<<"Not Possible!!";
	  }
   }
   return det;
}
void InputFMatrix(float**a,int &r,int &c,ifstream &fin)
{
	int i=0,j=0;
	while(fin>>a[i][j])
	{
		if(j==c-1)
		{
			i++;
			j=0;
		}
		else{
			j++;
		}
	}
}
double pow(int b,int e)
{
	double p=1;
	for(int i=0;i<e;i++)
	{
		p=p*b;
	}
	return p;
}
void adjoint(float **a,int n)
{
   float temp;
   float v=determinant(a,n);
   printMatrix(a,3,3);
   if (n==2)
   {
      temp=a[0][0];
      a[0][0]=a[1][1];
      a[1][1]=temp;
      a[0][1]=-a[0][1];
      a[1][0]=-a[1][0];
      ScalarMatrixDivision(a,2,2,v);
   }
   else
   {
   		if(n==3)
   		{
   			float **b=0;
			b=AutoGrowRow(b,3,3);			
   			TransposeOfMatrix(a,b,3,3);
   			printMatrix(b,3,3);
   			delete []a;
   			a=AutoGrowRow(a,3,3);
   			cout<<endl;
   			for(int i=0;i<3;i++)
   			{
   				for(int j=0;j<3;j++)
   				{
   					float **c=0;c=AutoGrowRow(c,2,2);
   					createMinor(b,c,i,j);
   					a[i][j]=determinant(c,2);
   					cout<<a[i][j]<<"             ";
   					delete []c;
   				}
   				cout<<endl;
   			}
   			delete []b;
   			ScalarMatrixDivision(a,2,2,v);
   			printMatrix(a,3,3);
   		}
   }	
}
void createMinor(float **matrix, float **minor, int row, int col) {
    int minor_row, minor_col;
    for (int i = 0; i < 3; i++) {
        minor_row = i;
        if (i>row)
            minor_row--;
        for (int j = 0; j < 3; j++) {
            minor_col = j;
            if (j>col)
                minor_col--;
            if (i != row && j != col)
                minor[minor_row][minor_col] = matrix[i][j];
        }
    }
}