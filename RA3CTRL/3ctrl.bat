@ECHO OFF
REM  QBFC Project Options Begin
REM  HasVersionInfo: Yes
REM  Companyname: 
REM  Productname: RedAlert3Control
REM  Filedescription: 
REM  Copyrights: 
REM  Trademarks: 
REM  Originalname: 
REM  Comments: 
REM  Productversion: 01.00.00.00
REM  Fileversion: 01.00.00.00
REM  Internalname: ra3CTRL
REM  Appicon: ..\..\..\Gallery\Icons\RA2HDICON\Ra2ICO.ico
REM  AdministratorManifest: No
REM  Embeddedfile: ra3fix.exe
REM  Embeddedfile: ra3trainer.txt
REM  Embeddedfile: ra3trainer1.12.exe
REM  QBFC Project Options End
ECHO ON
@echo OFF
title �쾯3����̨
color 4e
mode con cols=40 lines=20
:loop
cls
echo ========================================
echo        ��ɫ����3
echo ========================================
echo.
echo        1  ���� �쾯3
echo        11 ���� �쾯3 ����ģʽ

echo.
echo        2  ���� �쾯3

echo        3  �����䡣
::echo        s  �ػ�
::echo        r  ����
echo.
echo        9  ����
echo        0  �˳�  
echo.

set/p n=    ?      ��ѡ��
if %n%==1 goto ra3
if %n%==11 goto ra3win

if %n%==2 goto exitra3

if %n%==3 goto toolbox
if %n%==s goto shutdown
if %n%==r goto reboot
if %n%==00 goto test
if %n%==0 goto end
if %n%==9 goto help
goto loop

:end
exit

:ra3
start RA3.exe -ui 
goto loop

:ra3win
start RA3.exe -win -ui
goto loop

:exitra3
taskkill /f /im ra3.exe
taskkill /f /im ra3_1.12.game
goto loop

goto loop
:test
color 4c
echo ----------------------------------------
echo                   3!
echo ----------------------------------------
goto test

:shutdown
shutdown -s -t 0
exit

:reboot
shutdown -r -t 0
exit

:help
cls
echo ========================================
echo               ���������
echo ========================================
echo     ����������ں쾯3�ļ��С�
echo     �����Թ���Ա������д˳���
echo     ���Զ��򿪿���̨��
::echo     ȫ�������ֱ���1366*768��
echo     Ϊ�쾯3_1.12�汾���� ��

echo.
echo     ����ָ�
echo     ��11����������������ģʽ
echo     ��s���������������ػ�
echo     ��r������������������
::echo     ��00�������������ʵ�~
echo.
echo      2016.2
echo.
pause
goto loop

:toolbox
cls
echo ========================================
echo               �����䡣
echo ========================================
echo     1.�쾯3�޸�(�������Ա)
echo     2.�쾯3 31���޸���
echo     3.31���޸���˵��
echo     0.����
echo.
set/p y=    ?      ��ѡ��
if %y%==1 goto ra3fix
if %y%==2 goto ra3tr
if %y%==3 goto ra3trt
if %y%==0 goto loop
pause
goto toolbox
:ra3fix
start %MYFILES%\ra3fix.exe
goto toolbox

:ra3tr
start %MYFILES%\ra3trainer1.12.exe
goto toolbox

:ra3trt
start %MYFILES%\ra3trainer.txt
goto toolbox
