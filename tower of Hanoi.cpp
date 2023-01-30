//diagram representation is not working

#include<bits/stdc++.h>

using namespace std;

class tower
{
    public:

    char name; //name of the disk
    int nod; //no. of disks
    int td; //top disk

        tower(char name_u, int nod_u, int td_u)
        {
            name=name_u;
            nod=nod_u;
            td=td_u;
        }

        void contents(tower T)
        {
            int i,j;

            cout<<"Tower "<<T.name<<"\n";

            for(i=1;i<=T.nod;i++)
            {
                for(j=1;j<=i;j++)
                cout<<"#";

                cout<<"\n";
            }
        }

};

void toh(int n, tower &A, tower &B, tower &C)
{
    int nn=n;

    if(nn==1)
    {
        cout<<"\nMove 1 from "<<A.name<<" to "<<C.name;
        A.nod=0;
        B.nod=0;
        C.nod=n;
        return;
    }

    toh(nn-1,A,C,B);
    cout<<"\nMove "<<nn<<" from "<<A.name<<" to "<<C.name;
    toh(nn-1,B,A,C);
}

int main()
{
    int n;

    tower A('A',3,1), B('B',0,0), C('C',0,0), T(' ',0,0);

    cout<<"Enter the total number of disks to be moved from A to C: ";
    cin>>n;

    cout<<"Initially:\n";

    A.contents(A);
    cout<<"\n";
    B.contents(B);
    cout<<"\n";
    C.contents(C);

    toh(n,A,B,C);

    cout<<"\n\nNow:\n";

    A.contents(A);
    cout<<"\n";
    B.contents(B);
    cout<<"\n";
    C.contents(C);

    cout<<"\n";
    return 0;
}


