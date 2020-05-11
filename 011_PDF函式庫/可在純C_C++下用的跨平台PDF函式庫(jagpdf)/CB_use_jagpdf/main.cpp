#include <iostream>
#include <jagpdf/api.h>
using namespace std;
using namespace jag;

int main()
{
    cout << "Hello world!" << endl;
    pdf::Document doc(pdf::create_file("hello.pdf"));
    doc.page_start(597.6, 848.68);
    doc.page().canvas().text(50, 800, "Hello, world!");
    doc.page_end();
    doc.finalize();
    return 0;
}
