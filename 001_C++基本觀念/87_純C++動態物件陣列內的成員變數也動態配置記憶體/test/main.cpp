#include <iostream>

using namespace std;
class ItemData
{
  public:
  int *Array;
  int size;
  ItemData()
  {
      size=2;
      Array=new int[size];
      for(int i=0;i<size;i++)
        Array[i]=0;
  }
  ~ItemData()
  {
      delete []Array;
  }

};
class math_test
{
    public:
        ItemData *ID;
        int size;
        math_test()
        {
            size=4;
            ID=new ItemData[size];
        }
        ~math_test()
        {
            delete [] ID;
        }
        void setValue()
        {
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<ID[i].size;j++)
                    ID[i].Array[j]=10*(i+j);
            }
        }
        void ShowValue()
        {
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<ID[i].size;j++)
                {
                 cout<<"ID["<<i<<"].Array["<<j<<"]="<<ID[i].Array[j]<<"\n";
                }
            }
        }
};
int main()
{
    cout << "Hello world!" << endl;
    math_test mt;
    mt.ShowValue();
    mt.setValue();
    mt.ShowValue();
    return 0;
}
