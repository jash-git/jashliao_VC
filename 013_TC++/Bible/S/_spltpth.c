/*
_splitpath                  ■ DOS    □ UNIX     ■ Windows
                            □ ANSI C □ C++ only
──────────────────────────────

語法:

      void _splitpath(const char *path,
                      char *drive, chart *dir,
                      char *name, char *ext);

參數說明:

      const char *path;     欲被分解的完整路徑。
      char *drive;          磁碟代碼。
      char *dir;            目錄名稱。
      char *name;           檔案名稱。
      char *ext;            延伸檔名。

功能解說:

      此函數把所傳入完整路徑分解成磁碟機代碼drive 、目錄名稱
      dir 、檔案名稱name、及延伸檔名ext 。每一個對應儲存各分
      解部分空間至少要有_MAX_DRIVE、_MAX_DIR、_MAX_FILE、 及
      _MAX_EXT個位元組, 這些常數是定義於載入檔stdlib.h中。分
      解後儲存於drive 所指向的空間為磁碟機代碼, 並且加上一個
      分號':' , 例如 "A:" , dir 所指向的為一目錄名稱, 是為在
      結尾有反除號的字串, 例如 "\BORLAND\BIN\", 而name僅儲存
      檔案名稱, 至於ext, 其所指向的內容為以句號'.'為起點的字
      串, 是檔案的延伸檔名, 例如".EXE" 。

載入檔:

      stdlib.h

傳回值:

      無。

相關函數:

      _fullpath, _makepath

範例:

      先由使用者輸入一完整的檔案及路徑名稱, 再利用_splitpath
      函數將所輸入的檔案及路徑名稱分解成磁碟機代碼、目錄路徑
      、檔名、及延伸檔名, 再將結果顯示於螢幕上。
*/
/* Program : _spltpth.c */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
   char fullpath[_MAX_PATH];
   char drive[_MAX_DRIVE];
   char directory[_MAX_DIR];
   char filename[_MAX_FNAME];
   char extension[_MAX_EXT];

   clrscr();
   printf("Please enter a full path :\n=>");
   gets(fullpath);

   _splitpath(fullpath, drive, directory, filename, extension);

   printf("Disc drive     = %s\n", drive);
   printf("Directory      = %s\n", directory);
   printf("File name      = %s\n", filename);
   printf("File extension = %s\n", extension);

   printf("\nPress any key to continue...");
   getch();
}
