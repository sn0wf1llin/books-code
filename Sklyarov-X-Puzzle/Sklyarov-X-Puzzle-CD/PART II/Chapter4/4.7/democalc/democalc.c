#include <windows.h>
#include <string.h>
#include "resource.h"

WNDPROC prevEditProc = NULL;
HWND   hwndEdit;

BOOL CALLBACK EnumChildProc1(HWND hWnd, LPARAM lParam)
{
  int id;
  id=GetDlgCtrlID(hWnd);

  if (id == 88 || id == 92 || id == 125)
  { 
    ShowWindow(hWnd, SW_HIDE);
  } 
  return TRUE;
} 

BOOL CALLBACK EnumChildProc2(HWND hWnd, LPARAM lParam)
{
  int id;
  id=GetDlgCtrlID(hWnd);

  if (id == 88 || id == 92 || id == 125)
  { 
    ShowWindow(hWnd, SW_SHOW);
  }

  return TRUE;
} 

LRESULT CALLBACK nextEditProc(HWND hEdit, UINT msg, WPARAM wParam, LPARAM lParam)
{
  switch(msg)
  {
  case WM_CHAR:
    if(VK_RETURN == wParam)
      return 0;
  break;
  }
  return CallWindowProc(prevEditProc, hEdit, msg, wParam, lParam);
}

BOOL CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
  static char ed_Text[255] = "";

  switch(msg)
  {
  case WM_INITDIALOG:
    prevEditProc = (WNDPROC) SetWindowLong(
									GetDlgItem(hDlg, IDC_EDIT1),
									GWL_WNDPROC, (LONG)nextEditProc);
  break;

  case WM_COMMAND:
    if( wParam == IDOK) {
      GetDlgItemText(hDlg, IDC_EDIT1, ed_Text, 255);
      if (!strcmp(ed_Text, "sklyaroff")) {
        EnumChildWindows(FindWindow("SciCalc", NULL), EnumChildProc2, 0);
	  } 
	  EndDialog(hDlg, TRUE);		
	}
  break;

  }
  return 0;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
  Sleep(100);
  EnumChildWindows(FindWindow("SciCalc", NULL), EnumChildProc1, 0);
  DialogBox(hInstance, "IDD_DIALOG1", HWND_DESKTOP, (DLGPROC)DlgProc);
  return 0;
}
