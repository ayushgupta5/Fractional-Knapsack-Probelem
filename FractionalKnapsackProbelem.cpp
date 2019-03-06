#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,n,W,c;
    float P,temp;
    cout<<"ENTER TOTAL NUMBER OF TESTCASES:"<<endl;
    cin>>t;
    while(t--)
    {
        cout<<"ENTER TOTAL NUMBER OF OBJECTS:"<<endl;
        cin>>n;
        float PW[n],PW1[n],w[n],p[n];;
        for(i=0;i<n;i++) PW[i]=0;
        cout<<"ENTER TOTAL CAPACITY:"<<endl;
        cin>>W;
        cout<<"ENTER WEIGHTS FOR n OBJECTS:"<<endl;
        for(i=0;i<n;i++) cin>>w[i];
        cout<<"ENTER PROFIT OF n OBJECTS:"<<endl;
        for(i=0;i<n;i++) cin>>p[i];
        for(i=0;i<n;i++)
        {
            PW[i]=p[i]/w[i];
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(PW[i]<PW[j])
                {
                    temp=PW[j];
                    PW[j]=PW[i];
                    PW[i]=temp;

                    temp=w[j];
                    w[j]=w[i];
                    w[i]=temp;

                    temp=p[j];
                    p[j]=p[i];
                    p[i]=temp;
                }
            }
        }
/*
        for(i=0;i<n;i++) cout<<w[i]<<" ";
        cout<<endl;
        for(i=0;i<n;i++) cout<<p[i]<<" ";
        cout<<endl;
        for(i=0;i<n;i++) cout<<PW[i]<<" ";
        cout<<endl;
*/
        c=0;P=0;
        for(i=0;i<n;i++)
        {
            if(w[i]<=W)
            {
                c++;
                P=P+p[i];
                W=W-w[i];
            }
            else if(W>0&&w[i]>W)
            {
                c++;
                P=P+(PW[i]*W);
                W=W-(W);
            }
            else if(W==0) break;
        }
        cout<<"MAXIMUM PROFIT:"<<P<<" "<<c<<endl;
    }
}
