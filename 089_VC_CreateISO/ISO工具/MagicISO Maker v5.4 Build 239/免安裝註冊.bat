@ECHO off 
cls 
color 0A 
ECHO ==========================================================
ECHO *         MagicISO Maker v5.4 Build 239              
ECHO *                                                        * 
ECHO *              免安裝版製作:                             *
ECHO *                                                        *
ECHO *                                                        *
ECHO ==========================================================  
pause
ECHO 程式執行中，請稍後...... 
rundll32 setupapi,InstallHinfSection DefaultInstall 128 .\setup.inf
