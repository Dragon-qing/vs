#include<iostream>
using namespace std;
void MatrixChain(int *p,int n,int **m,int **s)
{
    for(int i=1;i<=n;i++){
        m[i][i]=0;
        s[i][i]=0;
    }
    for(int r=2;r<=n;r++){
        for(int i=1;i<=n-r+1;i++){
            int j=i+r-1;
            m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
            s[i][j]=i;
            for(int k=i+1;k<j;++k)
            {
                int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(t<m[i][j])
                {
                    m[i][j]=t;
                    s[i][j]=k;
                }
            }
        }
    }
}
void Traceback(int i,int j,int **s)
{
    if(i==j)return;
    Traceback(i,s[i][j],s);
    Traceback(s[i][j]+1,j,s);
    cout<<"A"<<"["<<i<<":"<<s[i][j]<<"]"<<"ГЫвд"<<"A["<<s[i][j]+1<<':'<<j<<"]"<<endl;
}
int main()
{
    int n=5;
    int p[n+1]={6,2,3,4,5,8};
    int s[n+1][n+1];
    int m[n+1][n+1];
    int *M[n+1],*S[n+1];
    for(int i=1;i<6;i++){
        for (int j=1;j<6;j++){
            s[i][j]=0;
            m[i][j]=0;
        }
        
    }
    for(int i=0;i<=n;i++)
        {
            M[i]=m[i];
            S[i]=s[i];
        }
    MatrixChain(p,n,M,S);
    Traceback(1,5,S);
    cout<<endl;
    for(int i=1;i<6;i++){
        for (int j=1;j<6;j++){
            cout<<M[i][j]<<'\t';
        }
        cout<<endl;
    }
    cout<<"s"<<endl;
    for(int i=1;i<6;i++){
        for (int j=1;j<6;j++){
            cout<<S[i][j]<<'\t';
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}