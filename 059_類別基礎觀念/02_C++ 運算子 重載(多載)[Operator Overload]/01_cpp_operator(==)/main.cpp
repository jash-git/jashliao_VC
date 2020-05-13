#include <iostream>
#include <cstdio>
/*
C++ 運算子 重載(多載) ex==
*/
using namespace std;
class point2D
{
public:
    int m_x;
    int m_y;

    point2D(int x,int y )
    {
        m_x=x;
        m_y=y;
    }
    point2D()
    {
        m_x=0;
        m_y=0;
    }

    //error: no match for 'operator==' in 'A == B'
    bool operator==(point2D T)
    {
        bool Ans=false;
        if((m_x==T.m_x) && (m_y==T.m_y))
        {
            Ans=true;
        }
        return Ans;
    }
};
void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main()
{
    point2D A,B,C(1,2);
    //cout << "Hello world!" << endl;
    cout <<"A("<<A.m_x<<","<<A.m_y<<")" << endl;
    cout <<"B("<<B.m_x<<","<<B.m_y<<")" << endl;
    cout <<"C("<<C.m_x<<","<<C.m_y<<")" << endl;
    if(A==B)
    {
        cout <<"A=B"<< endl;
    }
    else
    {
        cout <<"A!=B"<< endl;
    }
     if(A==C)
    {
        cout <<"A=C"<< endl;
    }
    else
    {
        cout <<"A!=C"<< endl;
    }
    Pause();
    return 0;
}
