#include <windows.h>
#define ID_Edit 101

HINSTANCE hInst;
LRESULT CALLBACK EditDemoWndProc (HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
  static char szClassName[] = "E-Book";
  HWND hwnd ;
  MSG msg ;
  WNDCLASS WndClass;

  hInst = hInstance;

  WndClass.style         = CS_HREDRAW | CS_VREDRAW ;
  WndClass.lpfnWndProc   = EditDemoWndProc;
  WndClass.cbClsExtra    = 0;
  WndClass.cbWndExtra    = 0;
  WndClass.hInstance     = hInstance ;
  WndClass.hIcon         = LoadIcon (NULL, IDI_APPLICATION);
  WndClass.hCursor       = LoadCursor (NULL, IDC_WAIT);
  WndClass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH);
  WndClass.lpszMenuName  = NULL;
  WndClass.lpszClassName = szClassName;
  WndClass.hIcon       = LoadIcon (NULL, IDI_WINLOGO);

  if (!RegisterClass (&WndClass))
  {
    MessageBox(NULL,"Cannot register class", "Error", MB_OK);
    return 0;
  }

  hwnd = CreateWindow (szClassName,            // window class name
		         "E-Book",               // window caption
                       WS_OVERLAPPEDWINDOW,    // window style
                       CW_USEDEFAULT,          // initial x position
                       CW_USEDEFAULT,          // initial y position
                       CW_USEDEFAULT,          // initial x size
                       CW_USEDEFAULT,          // initial y size
                       NULL,                   // parent window handle
                       NULL,                   // window menu handle
                       hInstance,              // program instance handle
		         NULL);		     // creation parameters

  ShowWindow (hwnd, iCmdShow);
  UpdateWindow (hwnd);

  while (GetMessage (&msg, NULL, 0, 0))
  {
    TranslateMessage (&msg);
    DispatchMessage (&msg);
  }
  return msg.wParam;
}

LRESULT CALLBACK EditDemoWndProc (HWND hWnd, UINT Message, UINT wParam, LONG lParam)
{

  static HWND hEditWnd;
  RECT Rect;

  CHAR lpszTrouble[] = "The Beatles 'Back in the U.S.S.R.'\r\n"	    
                       "(Lennon/McCartney)\r\n"
                       "---------------------------------------\r\n"
	                "\r\nFlew in from Miami Beach BOAC\r\n"
	                "Didn't get to bed last night\r\n"
                       "On the way the paper bag was on my knee\r\n"
                       "Man I had a dreadful flight\r\n"
                       "I'm back in the U.S.S.R.\r\n"
                       "You don't know how lucky you are boy\r\n"
                       "Back in the U.S.S.R.\r\n\r\n"

                       "Been away so long I hardly knew the place\r\n"
                       "Gee it's good to be back home\r\n"
                       "Leave it till tomorrow to unpack my case\r\n"
                       "Honey disconnect the phone\r\n"
                       "I'm back in the U.S.S.R.\r\n"
                       "You don't know how lucky you are boy\r\n"
                       "Back in the U.S.S.R.\r\n\r\n"

                       "Well the Ukraine girls really knock me out\r\n"
                       "They leave the West behind\r\n"
                       "And Moscow girls make me sing and shout\r\n"
                       "That Georgia's always on my mind.\r\n\r\n"

                       "I'm back in the U.S.S.R.\r\n"
                       "You don't know how lucky you are boys\r\n"
                       "Back in the U.S.S.R.\r\n\r\n"

            "Show me round your snow peaked mountains way down south\r\n"
	                "Take me to your daddy's farm\r\n"
                       "Let me hear your balalaika's ringing out\r\n"
                       "Come and keep your comrade warm.\r\n"
                       "I'm back in the U.S.S.R.\r\n"
                       "You don't know how lucky you are boys\r\n"
                       "Back in the U.S.S.R.\r\n\r\n";

  OpenClipboard(NULL);
  EmptyClipboard();
  CloseClipboard();

  SendMessage(hEditWnd, EM_SETSEL, 0, 0);

  switch (Message)
  {		
  case WM_CREATE:
    GetClientRect(hWnd, &Rect);
    hEditWnd=CreateWindow("edit",NULL,
                           WS_CHILD|WS_VISIBLE|
                           WS_HSCROLL|WS_VSCROLL|
                           WS_BORDER|ES_LEFT|
                           ES_MULTILINE|ES_AUTOHSCROLL|
                           ES_AUTOVSCROLL|ES_READONLY,
                           0,0,0,0,
                           hWnd,
                           (HMENU) ID_Edit,
                           hInst,
                           NULL);

    SendMessage(hEditWnd, WM_SETTEXT, 0, (LPARAM) lpszTrouble); 
    return 0;

  case WM_SIZE:
    MoveWindow(hEditWnd,0,0,LOWORD(lParam),HIWORD(lParam),TRUE);
    return 0;

  case WM_SETFOCUS:
    SetFocus(hEditWnd);
    return 0;

  case WM_DESTROY:
    PostQuitMessage(0);
    return 0;
  }
return DefWindowProc(hWnd,Message,wParam,lParam);
}


