#ifndef CPPNAMESPACE_H_INCLUDED
#define CPPNAMESPACE_H_INCLUDED
namespace N_A
{
    class A
    {
      public:
            A();
            int a;
    };
    namespace N_B
    {
        class B
        {
          public:
                B();
                int b;
        };
        namespace N_C
        {
            class C
            {
              public:
                    C();
                    int c;
            };
        }
    }
}


#endif // CPPNAMESPACE_H_INCLUDED
