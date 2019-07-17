#include <windows.h>
#include "menuf.h"

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

char szAppName[] = "Figure";
static int iSelection;
HMENU hMenu, hMenuPopup;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
  HWND hwnd;
  MSG msg;
  WNDCLASSEX wndclass;

  wndclass.cbSize        = sizeof (wndclass);
  wndclass.style         = CS_HREDRAW | CS_VREDRAW;
  wndclass.lpfnWndProc   = WndProc;
  wndclass.cbClsExtra    = 0;
  wndclass.cbWndExtra    = 0;
  wndclass.hInstance     = hInstance;
  wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION);
  wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW);
  wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH);
  wndclass.lpszMenuName  = szAppName;
  wndclass.lpszClassName = szAppName;
  wndclass.hIconSm       = LoadIcon (NULL, IDI_APPLICATION);

  RegisterClassEx (&wndclass);

  hwnd = CreateWindow (szAppName, "Figure",
                       WS_OVERLAPPEDWINDOW,
                       CW_USEDEFAULT, CW_USEDEFAULT,
                       CW_USEDEFAULT, CW_USEDEFAULT,
                       NULL, NULL, hInstance, NULL);

  hMenu = GetMenu (hwnd);
  hMenuPopup = CreateMenu();
  AppendMenu(hMenuPopup, MF_STRING|MF_GRAYED, IDM_ABOUT, "&About");
  AppendMenu(hMenu, MF_POPUP,(UINT) hMenuPopup, "&Help");

  ShowWindow (hwnd, iCmdShow);
  UpdateWindow (hwnd);


  while (GetMessage (&msg, NULL, 0, 0))
  {
    TranslateMessage (&msg);
    DispatchMessage (&msg);
  }
  return msg.wParam;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
  HDC hdc;
  PAINTSTRUCT ps;
  static int x, y;

  EnableMenuItem (hMenu, IDM_EXIT, MF_GRAYED);

  switch (iMsg)
  {
    case WM_SIZE:
      x = LOWORD(lParam);
      y = HIWORD(lParam);
      break;

    case WM_PAINT:
      hdc = BeginPaint(hwnd, &ps);
      SetMapMode(hdc, MM_ISOTROPIC);
      SetViewportOrgEx(hdc, x/2, y/2, NULL);

      switch (iSelection)
      {
        case IDM_RECTANGLE:
          Rectangle(hdc, 500, 200, -500, -200);
          ValidateRect(hwnd, NULL);
          EndPaint(hwnd, &ps);
          return 0;

        case IDM_ELLIPSE:
          Ellipse (hdc, -200, -500, 200, 500);
          ValidateRect(hwnd, NULL);
          EndPaint(hwnd, &ps);
          return 0;


        case IDM_PIE:
          Pie(hdc, -300, -300, 300, 300, 0, 300, -300, 0);
          ValidateRect(hwnd, NULL);
          EndPaint(hwnd, &ps);
          return 0;

        case IDM_CLEAR:
          ValidateRect(hwnd, NULL);
          EndPaint(hwnd, &ps);
          return 0;
      }
      break;

    case WM_COMMAND:

      switch (LOWORD (wParam))
      {
        case IDM_EXIT:
          SendMessage (hwnd, WM_CLOSE, 0, 0L);
          return 0;

        case IDM_CLEAR:
        case IDM_RECTANGLE:
        case IDM_ELLIPSE:
        case IDM_PIE:
          CheckMenuItem (hMenu, iSelection, MF_UNCHECKED);
          iSelection = LOWORD (wParam);
          CheckMenuItem (hMenu, iSelection, MF_CHECKED);
          InvalidateRect (hwnd, NULL, TRUE);
          return 0;

        case IDM_ABOUT:
          MessageBox (hwnd, "Figure Program. (c) Ivan Sklyaroff",
                      "About", MB_ICONINFORMATION | MB_OK);
          return 0;
      }
      break;


    case WM_DESTROY:
      PostQuitMessage (0);
      return 0;
    }

return DefWindowProc (hwnd, iMsg, wParam, lParam);
}

