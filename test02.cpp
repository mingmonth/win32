// test02.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "test02.h"
#include "Windowsx.h"
#include "stdio.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

INT_PTR CALLBACK    DlgProc(HWND, UINT, WPARAM, LPARAM);

void init() {
	AllocConsole();
	//freopen("CONIN$", "r", stdin);
	//freopen("CONOUT$", "w", stdout);
	//freopen("CONOUT$", "w", stderr);
	freopen("CONOUT$", "wt", stdout);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	init();	
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);	
	return 0;
}

// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
INT_PTR CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND hComboBox;
	static char *strMenu[] = { "�޴�1","�޴�2","�޴�3" };
	int nIndex;
	char strItem[100];
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
		hComboBox = GetDlgItem(hDlg, IDC_COMBO1);
		for (int i = 0; i < 3; i++) {
			ComboBox_AddString(hComboBox, strMenu[i]);
		}
        return (INT_PTR)TRUE;

    case WM_COMMAND:        
		if (LOWORD(wParam) == IDC_BUTTON1) {
			nIndex = GetDlgItemInt(hDlg, IDC_EDIT1, NULL, FALSE);
			GetDlgItemText(hDlg, IDC_EDIT2, strItem, 99);
			ComboBox_InsertString(hComboBox, nIndex, strItem);
		} else if (LOWORD(wParam) == IDC_BUTTON2) {
			nIndex = ComboBox_GetCurSel(hComboBox);
			char string[100];			
			ComboBox_GetLBText(hComboBox, nIndex, string);			
			printf("gettext: %s\n", string);			
			MessageBox(hDlg, string, "test", 0);			
		}

		//LOWORD(wParam) == IDOK || 
		if (LOWORD(wParam) == IDCANCEL)
		{
			FreeConsole();
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
        break;
    }
    return (INT_PTR)FALSE;
}
