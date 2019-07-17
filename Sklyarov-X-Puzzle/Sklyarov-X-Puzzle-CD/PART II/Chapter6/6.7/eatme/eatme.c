#include <windows.h>
#include "resource.h"
#define BUFSIZE 1024

LPTSTR lpszSystemInfo;      
DWORD cchBuff = BUFSIZE; 
TCHAR tchBuffer[BUFSIZE];

WNDPROC prevEditProc = NULL;

LRESULT CALLBACK nextEditProc(HWND hEdit, UINT msg, WPARAM wParam, LPARAM lParam)
{
  switch(msg)
  {
    case WM_KEYDOWN:
	  if(VK_RETURN == wParam)
	  {
	    HWND hParent = GetParent(hEdit);
	    SendMessage( hParent, msg, wParam, lParam);
	    SetFocus(GetNextDlgTabItem( hParent, hEdit, FALSE));
	    return 0;
	  }
	break;
	
	case WM_CHAR:
      if(VK_RETURN == wParam)
        return 0;
	break;
  }
	return CallWindowProc(prevEditProc, hEdit, msg, wParam, lParam);
}

BOOL CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
  int i, RegCode;
  char Reg[256];

  static char ed_Text1[256] = "";
  static char ed_Text2[256] = "";

  lpszSystemInfo = tchBuffer;   
  RegCode=0;

  switch(msg)
  {
    case WM_INITDIALOG:

      prevEditProc = (WNDPROC) SetWindowLong(
									GetDlgItem(hDlg, IDC_EDIT1),
									GWL_WNDPROC, (LONG)nextEditProc);
    break;

    case WM_COMMAND:

	  if( wParam == IDOK) 
	  {
	    GetUserName(lpszSystemInfo, &cchBuff);

		for (i=0;i<strlen(lpszSystemInfo);i++)
		{
		  RegCode += lpszSystemInfo[i]+100000;
		}

		GetDlgItemText(hDlg, IDC_EDIT1, ed_Text1, 256);
            
		for (i=0;i<strlen(ed_Text1);i++)
		{
		  RegCode += ed_Text1[i]+100000;
		}

		RegCode += 31337;

        sprintf(Reg, "%d", RegCode);


		GetDlgItemText(hDlg, IDC_EDIT2, ed_Text2, 256);

		if (!strcmp(ed_Text2, Reg))
		{
		  MessageBox (NULL, "OK", "Eat me", MB_OK);
		  EndDialog(hDlg, 0);
		} else {
		  MessageBox (NULL, "Wrong?", "Eat me", MB_OK);
		}

	  }

	  if(wParam == IDCANCEL)
	    EndDialog(hDlg, 0);

    break;

  }
  return 0;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{

  DialogBox(hInstance, "EATME", HWND_DESKTOP, (DLGPROC)DlgProc);
  return 0;
}
