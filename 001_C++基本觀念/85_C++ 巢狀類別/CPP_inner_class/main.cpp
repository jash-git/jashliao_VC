#include <iostream>

#include "include\PointDemo.h"
using namespace std;
////////////////////////////////////
const int Maximum = 100;
class TListOfStudents
{
public:
    class TStudent
    {
    private:
        string FullName;
        int    Age;
        char   Gender;
    public:
        void   setFullName(const string Name) { FullName = Name; }
        string getFullName() const { return FullName; }
        void   setAge(const int a) { Age = a; }
        int    getAge() const { return Age; }
        void   setGender(const char g) { Gender = g; }
        char   getGender() const { return Gender; }
        TStudent();
        TStudent(string FName, int a, char g);
        inline virtual ~TStudent() {}
    };
private:
    TStudent Item[Maximum];
public:
    TListOfStudents() : Count(0){}
    inline ~TListOfStudents() {}
    void Add(const TStudent& d);
    TStudent Retrieve(const int n);
    int Count;
};
TListOfStudents::TStudent::TStudent()
{
    FullName = "";
    Age      = 0.00;
    Gender   = 'M';
}
TListOfStudents::TStudent::TStudent(string FName, int a, char g)
{
    FullName = FName;
    Age      = a;
    Gender   = g;
}
TListOfStudents::TStudent TListOfStudents::Retrieve(const int n)
{
    return Item[n];
}
void  DisplayList(TListOfStudents &List);
void  CreateList(TListOfStudents &List);
void CreateList(TListOfStudents &ListOfItems)
{
 TListOfStudents::TStudent Pupil;
 Pupil.setFullName("Harry Seamen");
 Pupil.setAge(12);
 Pupil.setGender('M');
 ListOfItems.Add(Pupil);
 Pupil.setFullName("Hermine Grand");
 Pupil.setAge(14);
 Pupil.setGender('F');
 ListOfItems.Add(Pupil);
 Pupil.setFullName("Ronald Hannah");
 Pupil.setAge(18);
 Pupil.setGender('M');
 ListOfItems.Add(Pupil);
 Pupil.setFullName("Johnny Hancock");
 Pupil.setAge(16);
 Pupil.setGender('M');
 ListOfItems.Add(Pupil);
}
void DisplayList(TListOfStudents &ListOfItems)
{
 cout << "Full Name\tAge\tGender";
 string Gender[] = { "Male", "Female", "Unknown" };
 for(int i = 0; i < ListOfItems.Count; i++)
 {
  cout << "\n" << ListOfItems.Retrieve(i).getFullName()
       << "\t" << ListOfItems.Retrieve(i).getAge()
       << "\t";
  switch(ListOfItems.Retrieve(i).getGender())
  {
  case 'm':
  case 'M':
   cout << Gender[0];
   break;
  case 'f':
  case 'F':
   cout << Gender[1];
   break;
  default:
   cout << Gender[2];
  }
 }
}
void TListOfStudents::Add(const TStudent& d)
{
    if( Count < Maximum )
    {
  Item[Count] = d;
  Count++;
    }
}
/////////////////////////////////////////////////
int main()
{
    ///////////////////////////////////////////
    //http://openhome.cc/Gossip/CppGossip/NestedClasses.html
    PointDemo demo(10);
    demo.show();
    //////////////////////////////////////////
    //http://idns.blog.163.com/blog/static/2004533772011111324444700/
    TListOfStudents ListOfItems;
    CreateList(ListOfItems);
    DisplayList(ListOfItems);
    return 0;
}
