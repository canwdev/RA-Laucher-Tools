@echo OFF
title �쾯2����̨ 1.1
color 4e
mode con cols=40 lines=20
:loop
cls
echo ========================================
echo       ����������: ��ɫ����2 ����̨
echo ========================================
echo.
echo        1  ���� �쾯2
::echo        11 ���� �쾯2 ����ģʽ
echo        2  ���� ����ĸ���
::echo        22 ���� ���︴�� ����ģʽ
echo.
echo        3  ���� �쾯2
echo        4  ���� ����ĸ���

::echo        s  �ػ�
::echo        r  ����
echo.
echo        9  ����
echo        0  �˳�  
echo.

set/p n=    ?      ��ѡ��
if %n%==1 goto ra2
if %n%==11 goto ra2win
if %n%==2 goto yuri
if %n%==22 goto yuriwin
if %n%==3 goto exitra2
if %n%==4 goto exityuri
if %n%==s goto shutdown
if %n%==r goto reboot
if %n%==00 goto test
if %n%==0 goto end
if %n%==9 goto help
goto loop
:end

exit
:ra2
start ra2.exe -speedcontrol
goto loop
:ra2win

start ra2.exe -win -speedcontrol
goto loop
:yuri
start ra2md.exe -speedcontrol
goto loop
:yuriwin

start ra2md.exe -win -speedcontrol
goto loop
:exitra2
taskkill /f /im ra2.exe
taskkill /f /im game.exe
goto loop
:exityuri
taskkill /f /im ra2md.exe
taskkill /f /im gamemd.exe
goto loop
:test
color 5a
echo ----------------------------------------
echo          BE ONE WITH YURI��
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
echo     �����Թ���Ա������д˳���
echo     ����ģʽ��Ҫ������ɫ���Ϊ16λɫ��
echo.
echo     ����ָ�
echo     ��11����22��������ģʽ
echo     ��s���������������ػ�
echo     ��r������������������
::echo     ��00�������������ʵ�~
echo.
echo.
pause
goto loop