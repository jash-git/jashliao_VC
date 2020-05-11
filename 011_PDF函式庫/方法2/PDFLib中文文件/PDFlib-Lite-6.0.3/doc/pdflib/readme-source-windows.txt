==============================
PDFlib Lite Source for Windows
==============================

Building PDFlib with MS Visual Studio 6
---------------------------------------

To compile PDFlib with MS Visual Studio 6, open the supplied workspace
file PDFlib.dsw which contains several projects for the core library
and language bindings. Select the "pdflib" project to build a static library
pdflib.lib.

The "pdflib_dll" project can be used to build a DLL version pdflib.dll.

This will set the PDFLIB_EXPORTS #define. Client programs must define
PDFLIB_DLL before including pdflib.h in order to use the DLL.


The following configurations are supported:
- "Debug"
- "Release" will include a static version of the C runtime.
- "Release mtDLL" (only for target pdflib) builds a static library for
   use with applications which use a multithreaded DLL version of the
   C runtime (msvcrt.dll).


Sample applications:

The examples_c.dsw and examples_cpp.dsw contain targets for a few
C/C++ sample applications.

Note that not all tests will succeed because they need features which
require commercial PDFlib products.


Building PDFlib with MS Visual Studio .NET
------------------------------------------

The PDFlib packages contain solution files for use with Visual Studio
.NET 2003 (aka VS 7.1). These solution files can also be used with
Visual Studio .NET 2005 (aka VS 8).


Building PDFlib with Metrowerks CodeWarrior
-------------------------------------------

To compile PDFlib with Metrowerks CodeWarrior, open the supplied
project file PDFlib.mcp with the Metrowerks IDE. The project file
contains targets for building a static or shared PPC library. Don't worry
about "access path not found" warnings when building PDFlib.

Separate project files for building various C and C++ sample programs
can be found in bind/pdflib/c/samples.mcp and bind/pdflib/cpp/samples.mcp.
These can be used to test the newly created library. The tests create simple
command-line programs without any fancy user interface.

Note that not all tests will succeed because they need features which
require commercial PDFlib products. Also, don't worry about warnings
regarding some access path not being found.

In order to build a shared PDFlib library use the "DLL Win32" target.


Building PDFlib with other Windows compilers
--------------------------------------------

In order to build PDFlib with other compilers, observe the above
notes and make sure to define the preprocessor symbol WIN32.


Compiling the language wrappers
-------------------------------

In order to compile the C wrappers for the supported languages you
will have to install the relevant source code package
and adjust the include paths for these packages in the project files.
Since we supply prebuilt binaries for all supported languages this is
generally not required. Project files for the language wrappers are
only supplied for Microsoft Visual C++, but not any other compiler.
