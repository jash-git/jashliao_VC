#include <iostream>

using namespace std;
class parent
{
    public:
        parent();
        int m_a;
    protected:
        int m_b;
    private:
        int m_c;
};
parent::parent()
{
    m_a=0;
    m_b=0;
    m_c=0;
}
//============================================================
class public_son : public parent
{
    public:
        public_son();
        void setvalue(int,int,int);
        void showvalue();
};
public_son::public_son():parent()
{

}
void public_son::setvalue(int a,int b,int c)
{
    m_a=a;
    m_b=b;
    //m_c=c;//必須利用父類別的公有函數才可存取

}
void public_son::showvalue()
{
    cout <<"m_a="<<m_a<<endl;
    cout <<"m_b="<<m_b<<endl;
    //cout <<"m_c="<<m_c<<endl;//必須利用父類別的公有函數才可存取
}
//============================================================
//============================================================
class protected_son : protected parent
{
    public:
        protected_son();
        void setvalue(int,int,int);
        void showvalue();
};
protected_son::protected_son():parent()
{

}
void protected_son::setvalue(int a,int b,int c)
{
    m_a=a;
    m_b=b;
    //m_c=c;//必須利用父類別的公有函數才可存取

}
void protected_son::showvalue()
{
    cout <<"m_a="<<m_a<<endl;
    cout <<"m_b="<<m_b<<endl;
    //cout <<"m_c="<<m_c<<endl;//必須利用父類別的公有函數才可存取
}
//============================================================
//============================================================
class private_son : private parent
{
    public:
        private_son();
        void setvalue(int,int,int);
        void showvalue();
};
private_son::private_son():parent()
{

}
void private_son::setvalue(int a,int b,int c)
{
    m_a=a;
    m_b=b;
    //m_c=c;//必須利用父類別的公有函數才可存取

}
void private_son::showvalue()
{
    cout <<"m_a="<<m_a<<endl;
    cout <<"m_b="<<m_b<<endl;
    //cout <<"m_c="<<m_c<<endl;//必須利用父類別的公有函數才可存取
}
//============================================================
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
