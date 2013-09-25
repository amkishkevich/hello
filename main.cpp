#include<iostream.h>
#include<iomanip.h>
#include<time.h>
class Matrix{
int n,i,j;
double **mas;
public:
Matrix();
Matrix(int x);
Matrix(const Matrix & A);
Matrix operator+(Matrix A);
Matrix operator-(Matrix A);
Matrix operator*(Matrix A);
Matrix& operator =(const Matrix & A){
 if(this!=&A)
 {delete [] mas;
  n=A.n;
  mas= new double*[n];
 for(i=0;i<n;++i)
        mas[i]=new double[n];
for (int i=0;i<n;++i)
 for (int j=0;j<n;++j)
mas[i][j]=A.mas[i][j];
}
return *this;
}
~Matrix();
void Vvod();
void Vivod();
};

Matrix :: Matrix():n(0), mas(0){
 mas=new double *[n];
  for(i=0;i<n;++i)
   mas[i]=new double[n];
   }
Matrix::Matrix(int x): n(0), mas(0){
n=x;
mas = new double*[n];
 for(i=0;i<n;++i)
  mas[i]=new double[n];
 for (i=0;i<n;++i)
  for(j=0;j<n;++j)
   mas[i][j]=0;
}
Matrix::~Matrix(){
for (int i=0;i<n;++i)
 delete[] mas[i];
 delete[] mas;
}
Matrix::Matrix(const Matrix & A):n(A.n){
 mas= new double*[n];
 for (int i=0;i<n;++i)
 mas[i]=new double[n];
for (int i=0;i<n;++i)
for (int j=0;j<n;++j)
mas[i][j]=A.mas[i][j];
}
void Matrix::Vvod()
{

int i, j;
for(i=0;i<n;++i)
for(j=0;j<n;++j)
mas[i][j]=random(10);
}

void Matrix::Vivod()
{
int i, j;
for(i=0;i<n;++i){
for(j=0;j<n;++j)
cout<<setw(10)<<mas[i][j];
cout<<endl;}
cout<<endl;
}


Matrix Matrix::operator +(Matrix A){
Matrix B;
B.n=n;
int i,j;
B.mas=new double*[B.n];
for(i=0;i<n;++i)
B.mas[i]=new double[B.n];
for (int i=0;i<n;++i)
for (int j=0;j<n;++j)
B.mas[i][j] =mas[i][j]+A.mas[i][j];
return B;
}
Matrix Matrix::operator -(Matrix A){
Matrix C;
C.n=n;
int i,j;
C.mas=new double*[C.n];
for(i=0;i<n;++i)
C.mas[i]=new double[C.n];
for (int i=0;i<n;++i)
for (int j=0;j<n;++j)
C.mas[i][j]=mas[i][j]-A.mas[i][j];
return C;
}
Matrix Matrix::operator *(Matrix A){
Matrix D;
D.n=n;
int i,j,k,l;
D.mas=new double*[D.n];
for(i=0;i<n;++i)
D.mas[i]=new double[D.n];
for (int i=0;i<n;++i)
for (int j=0;j<n;++j){
D.mas[i][j]=mas[i][j]*A.mas[j][i];}
return D;
}

int main(){
double n;
srand(time(NULL));
cout<<"Vvedi razmer matrix n,n "<<endl;
cin>>n;

    int i,z;
    cout<< "Vvedi kolichestvo elementov "<<endl;
    cin>>z;

    Matrix **arr=new Matrix*[z];
    for(int i=0;i<z;i++)
        arr[i] = new Matrix(n);
    for (int i=0;i<z;++i)
        arr[i]->Vvod();
    cout<<endl;
    cout<<"Vvedi nomer matrix dlia vozvedenia v kvadrat ->"<<endl;
    int k;
    cin>>k;
    if(k<z){
        k--;
        *arr[k]=(*arr[k])*(*arr[k]);
    }
    for (int i=0;i<z;++i)
        arr[i]->Vivod();
    cout<<endl  ;
    int g,g1;
    cout<<"Vvedi nomera matrix dlia nahozhdenia summi matrix"<<endl;
    cin>>g>>g1;
    if(g<=z && g1<=z){
    ((*arr[g-1])+(*arr[g1-1])).Vivod();
            }
    cout<<"Vvedi nomera matrix dlia umnozhenia matrix"<<endl;
    cin>>g>>g1;
    if(g<=z && g1<=z){
    ((*arr[g-1])*(*arr[g1-1])).Vivod();
            }
    cout<<"Vvedi nomera dlia vicitania matric"<<endl;
    cin>>g>>g1;
    if(g<=z && g1<=z){
    ((*arr[g-1])-(*arr[g1-1])).Vivod();
            }

     for (int i=0;i<z;++i)
        delete arr[i];
     delete[]  arr;
system("pause");
}

