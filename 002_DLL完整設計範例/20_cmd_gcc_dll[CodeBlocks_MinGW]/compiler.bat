:: gcc create dll windows
REM https://forums.ni.com/t5/LabVIEW/create-a-dll-for-windows-with-gcc/td-p/332736
"C:\Program Files (x86)\CodeBlocks\MinGW\bin\gcc" -c hello.c
"C:\Program Files (x86)\CodeBlocks\MinGW\bin\gcc" -c -DBUILD_DLL dllfct.c
"C:\Program Files (x86)\CodeBlocks\MinGW\bin\gcc" -shared -o tst.dll -Wl,--out-implib,libtstdll.a dllfct.o
"C:\Program Files (x86)\CodeBlocks\MinGW\bin\gcc" -o hello.exe hello.o -L./ -ltstdll
pause
   