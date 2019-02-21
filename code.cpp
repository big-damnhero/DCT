#include <bits/stdc++.h>

using namespace std;
vector <int> run;

void printRLE(int n)
{
    for (int i = 0; i < n; i++) {

        // Count occurrences of current character
        int count = 1;
        while (i < n - 1 && run[i] == run[i + 1]) {
            count++;
            i++;
        }

        // Print character and its count
        cout << run[i] << count;
    }
}

int main()
{
    int n,m,u,v,x,y;
    cout<<"Enter rows: ";
    cin>>n;
    cout<<"Enter col: ";
    cin>>m;
    cout<<"Enter the matrix :";
    int ar[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>ar[i][j];
            ar[i][j]-=128;
        }
    }
    vector<vector<double> > c(n,vector<double>(m,0));
    double alp_u0=1/(pow(n,0.5));
    double alp_u1=alp_u0*pow(2,0.5),alpu,alpv;
    for(u=0;u<n;u++)
    {
        if(u==0)
        alpu=alp_u0;
        else
        alpu=alp_u1;
        for(v=0;v<m;v++)
        {
            if(v==0)
            alpv=alp_u0;
            else
            alpv=alp_u1;
            for(x=0;x<n;x++)
            {
                for(y=0;y<m;y++)
                {
                    c[u][v]+=ar[x][y]*cos((2*x+1)*u*M_PI/(2.0*n))*cos((2*y+1)*v*M_PI/(2.0*m));
                }
            }
            c[u][v]=c[u][v]*alpu*alpv;
            cout<<c[u][v]<<"     ";
        }
        cout<<endl;
    }

    cout<<endl;
    int q[8][8]={{16,11,10,16,24,40,51,61},
                   {12,12,14,19,26,58,60,55},
                   {14,13,16,24,40,57,69,56},
                   {14,17,22,29,51,87,80,62},
                   {18,22,37,56,68,109,103,77},
                   {24,35,55,64,81,104,113,92},
                   {49,64,78,87,103,121,120,101},
                   {72,92,95,98,112,100,103,99}};
    int qun[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            qun[i][j]= (c[i][j]/q[i][j]);
            cout<<qun[i][j]<<" ";
        }
        cout<<endl;
    }

    int  ZigZag[ n * n ][2] =
{
    {0, 0},
    {0, 1}, {1, 0},
    {2, 0}, {1, 1}, {0, 2},
    {0, 3}, {1, 2}, {2, 1}, {3, 0},
    {4, 0}, {3, 1}, {2, 2}, {1, 3}, {0, 4},
    {0, 5}, {1, 4}, {2, 3}, {3, 2}, {4, 1}, {5, 0},
    {6, 0}, {5, 1}, {4, 2}, {3, 3}, {2, 4}, {1, 5}, {0, 6},
    {0, 7}, {1, 6}, {2, 5}, {3, 4}, {4, 3}, {5, 2}, {6, 1}, {7, 0},
    {7, 1}, {6, 2}, {5, 3}, {4, 4}, {3, 5}, {2, 6}, {1, 7},
    {2, 7}, {3, 6}, {4, 5}, {5, 4}, {6, 3}, {7, 2},
    {7, 3}, {6, 4}, {5, 5}, {4, 6}, {3, 7},
    {4, 7}, {5, 6}, {6, 5}, {7, 4},
    {7, 5}, {6, 6}, {5, 7},
    {6, 7}, {7, 6},
    {7, 7}
};
   for(int i=0;i<n*n;i++)
   {
       run.push_back(qun[ZigZag[i][0]][ZigZag[i][1]]);
   }
   printRLE(n*n);
   cout<<endl;
   int temp[n][m];
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           temp[i][j]=qun[i][j]*q[i][j];
           cout<<temp[i][j]<<" ";
       }
       cout<<endl;
   }

   vector<vector<double> > c1(n,vector<double>(m,0));
    for(u=0;u<n;u++)
    {
        if(u==0)
        alpu=alp_u0;
        else
        alpu=alp_u1;
        for(v=0;v<m;v++)
        {
            if(v==0)
            alpv=alp_u0;
            else
            alpv=alp_u1;
            for(x=0;x<n;x++)
            {
                for(y=0;y<m;y++)
                {
                    c1[u][v]+=temp[x][y]*alpu*alpv*cos((2*x+1)*u*M_PI/(2.0*n))*cos((2*y+1)*v*M_PI/(2.0*m));
                }
            }
            cout<<int(c1[u][v]+128)<<"     ";
        }
        cout<<endl;
    }

    cout<<endl;







    return 0;
}

/* 154 123 123 123 123 123 123 136
   192 180 136 154 154 154 136 110
   254 198 154 154 180 154 123 123
   239 180 136 180 180 166 123 123
   180 154 136 167 166 149 136 136
   128 136 123 136 154 180 198 154
   123 105 110 149 136 136 180 166
   110 136 123 123 123 136 154 136
*/
