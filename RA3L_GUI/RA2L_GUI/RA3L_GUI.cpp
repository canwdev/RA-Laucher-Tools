#include <tchar.h>
#include <Windows.h>

#include <fstream>
#include <iostream>
#include <cstring>

#include "resource.h"
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")

bool checkDir() {
	using namespace std;
	fstream _file;
	_file.open("RA3.exe",ios::in);
	if(!_file) {
		cout << "��Ѵ˳�����ں쾯3�ļ�����" << endl;;
		MessageBox(NULL, _T("��Ѵ˳�����ں쾯3�ļ�����\n�Ҳ����ļ� RA3.exe"), _T("����"), MB_OK);
		 _file.close();
		 return false;
      } else {
		  _file.close();
		  return true;
	}
}

BOOL CALLBACK AboutDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	switch(Message)
	{
		case WM_INITDIALOG:

		return TRUE;
		case WM_COMMAND:
			switch(LOWORD(wParam))
			{
				case IDOK:
					EndDialog(hwnd, IDOK);
				break;
				case IDCANCEL:
					EndDialog(hwnd, IDCANCEL);
				break;
			}
		break;
		default:
			return FALSE;
	}
	return TRUE;
}

INT_PTR CALLBACK RA2L_Main(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_INITDIALOG:
		{
			HWND hComBox = GetDlgItem(hwndDlg, START3);
			SendMessage(hComBox, CB_INSERTSTRING, 0, (LPARAM)_T("��������̨ -ui"));
			SendMessage(hComBox, CB_INSERTSTRING, 1, (LPARAM)_T("��������̨+���ڻ� -ui -win"));
			SendMessage(hComBox, CB_INSERTSTRING, 2, (LPARAM)_T("���ܹ��� ra3_tool.exe"));
			SendMessage(hComBox, CB_INSERTSTRING, 3, (LPARAM)_T("�������к��л�ע����޸� ra3_fix.exe"));
			SendMessage(hComBox, CB_INSERTSTRING, 4, (LPARAM)_T("�޸��� RA3Trainer.exe"));
			SendMessage(hComBox, CB_INSERTSTRING, 5, (LPARAM)_T("RA3ReplaysManager.exe"));
			HWND hComBoxRA3XYRES = GetDlgItem(hwndDlg, RA3XYRES);
			SendMessage(hComBoxRA3XYRES, CB_INSERTSTRING, 0, (LPARAM)_T("Ĭ�Ϸֱ���"));
			SendMessage(hComBoxRA3XYRES, CB_INSERTSTRING, 1, (LPARAM)_T("800x600"));
			SendMessage(hComBoxRA3XYRES, CB_INSERTSTRING, 2, (LPARAM)_T("1360x768"));
			SendMessage(hComBoxRA3XYRES, CB_INSERTSTRING, 3, (LPARAM)_T("1600x900"));
			SendMessage(hComBoxRA3XYRES, CB_INSERTSTRING, 4, (LPARAM)_T("��ǰ�ֱ���"));
			
		}
		break;
	case WM_COMMAND:
		{
		switch (wParam)
		{
		case IDRA3: {
			TCHAR szTextChangeRes[50] = {0};
			GetDlgItemText(hwndDlg, RA3XYRES, szTextChangeRes, 50);
			if (checkDir()) {
			if ( !_tcscmp(szTextChangeRes, _T("800x600")) ) {
				system("start RA3.exe -xres 800 -yres 600");
			} else if( !_tcscmp(szTextChangeRes, _T("1360x768")) ) {
				system("start RA3.exe -xres 1360 -yres 768");
			} else if( !_tcscmp(szTextChangeRes, _T("1600x900")) ) {
				system("start RA3.exe -xres 1600 -yres 900");
			}  else if( !_tcscmp(szTextChangeRes, _T("��ǰ�ֱ���")) ) {
				//��������������ȡ������ʾ��Ļ�Ĵ�С��������������������
				//int screenwidth=GetSystemMetrics(SM_CXFULLSCREEN);
				//int screenheight=GetSystemMetrics(SM_CYFULLSCREEN);
				
				//��������������ȡ����������Ļ�Ĵ�С����ʵ�ʵĴ�С
				int xres = GetSystemMetrics(SM_CXSCREEN);
				int yres = GetSystemMetrics(SM_CYSCREEN);
				
				char str[50];
				char temp[10];
				
				strcat_s(str, "start RA3.exe -xres ");
				sprintf_s(temp, "%d", xres);
				strcat_s(str, temp);
				strcat_s(str, " -yres ");
				sprintf_s(temp, "%d", yres);
				strcat_s(str, temp);
				system(str);
			} else {
				system("start RA3.exe");
			} } }
			break;
		case IDRA3WIN: {
			TCHAR szTextChangeRes[50] = {0};
			GetDlgItemText(hwndDlg, RA3XYRES, szTextChangeRes, 50);
			if (checkDir()) {
			if ( !_tcscmp(szTextChangeRes, _T("800x600")) ) {
				system("start RA3.exe -xres 800 -yres 600 -win");
			} else if( !_tcscmp(szTextChangeRes, _T("1360x768")) ) {
				system("start RA3.exe -xres 1360 -yres 768 -win");
			} else if( !_tcscmp(szTextChangeRes, _T("1600x900")) ) {
				system("start RA3.exe -xres 1600 -yres 900 -win");
			}  else if( !_tcscmp(szTextChangeRes, _T("��ǰ�ֱ���")) ) {
				int xres = GetSystemMetrics(SM_CXSCREEN);
				int yres = GetSystemMetrics(SM_CYSCREEN);
				
				char str[50];
				char temp[10];
				
				strcat_s(str, "start RA3.exe -xres ");
				sprintf_s(temp, "%d", xres);
				strcat_s(str, temp);
				strcat_s(str, " -yres ");
				sprintf_s(temp, "%d", yres);
				strcat_s(str, temp);
				strcat_s(str, " -win");
				system(str);
			} else {
				system("start RA3.exe -win");
			} }
			} break;
		case IDRA3EXIT:
			system("taskkill /f /im ra3.exe");
			system("taskkill /f /im ra3_1.12.game");
			break;
		case START3GO:
				{
					TCHAR szText[50] = {0};
					GetDlgItemText(hwndDlg, START3, szText, 50);
					if ( _tcscmp(szText, _T("��������̨ -ui")) == 0 ) {
						system("start ra3.exe -ui");
					}else if ( _tcscmp(szText, _T("��������̨+���ڻ� -ui -win")) == 0 ) {
						system("start ra3.exe -ui -win");
					}
					else if ( _tcscmp(szText, _T("���ܹ��� ra3_tool.exe")) == 0 ) {
						system("start ra3_tool.exe");
					}
					else if ( _tcscmp(szText, _T("�������к��л�ע����޸� ra3_fix.exe")) == 0 ) {
						system("start ra3_fix.exe");
					}
					else if ( _tcscmp(szText, _T("�޸��� RA3Trainer.exe")) == 0 ) {
						system("start RA3Trainer.exe");
					}
					else if ( _tcscmp(szText, _T("RA3ReplaysManager.exe")) == 0 ) {
						system("start RA3ReplaysManager.exe");
					}
					else
						MessageBox(hwndDlg, _T("δѡ����Ŀ"), _T("����"), MB_OK);
				}
				break;
		case IDHELP:
			{
				int ret = DialogBox(GetModuleHandle(NULL), 
						MAKEINTRESOURCE(IDD_ABOUT), hwndDlg, AboutDlgProc);
			//MessageBox(hwndDlg, _T("* �Ѵ˳�����ں쾯3�ļ�����\n\n* �汾���� 2016.5.21\n"), _T("����&����"), MB_OK);
			}
			break;
		case IDCLOSE:
			EndDialog(hwndDlg, IDCLOSE);
			break;
		case IDCANCEL:
			EndDialog(hwndDlg, IDCANCEL);
			break;
		}
	default:
			break;
		}
	}
	
	return 0;
}


INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	if (_tcscmp(lpCmdLine, _T("-help")) == 0) {
		DialogBox(hInstance, MAKEINTRESOURCE(IDD_ABOUT), NULL, About);
	}
	else if (_tcscmp(lpCmdLine, _T("-c")) == 0) {
		DialogBox(hInstance, MAKEINTRESOURCE(IDD_ABOUT), NULL, About);
	}
	else {
		//checkDir();
		DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, RA2L_Main);
	}
	return 0;
}



