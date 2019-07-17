#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void WriteStream(void);
void WriteStream2(void);

HANDLE hStream;
HANDLE hStream2;
DWORD dwRet;

char Key[4];
char Count[4];
int nCounter;
int nCounter2;

int main()
{

  char cFileSystemNameBuffer[0x80];
  DWORD dwFileSystemNameSize;

  GetVolumeInformation (NULL, NULL, NULL, NULL, NULL, 
                        NULL, cFileSystemNameBuffer, 0x80);

  if (strcmp(cFileSystemNameBuffer, "NTFS"))
  {
    MessageBox(NULL, "Please, start this program under NTFS.",  
               "Error", MB_OK);
    return 1;
  }

  hStream = CreateFile( "stream.exe:sklyaroff", GENERIC_READ, 0,
			   NULL, OPEN_EXISTING, 0, NULL);

  if (hStream == INVALID_HANDLE_VALUE)
  {
    WriteStream ();

    nCounter2=10;

    sprintf(Count, "%d", nCounter2);
    MessageBox(NULL, Count, "The trial count", MB_OK|MB_ICONASTERISK);

    nCounter2 = nCounter2 ^ nCounter;

    WriteStream2 ();

    return 1;
  }

  hStream2 = CreateFile( ":sklyaroff", GENERIC_READ, 0, NULL,  
                          OPEN_EXISTING, 0, NULL);

  ReadFile(hStream, Key, sizeof (Key), &dwRet, NULL);
  ReadFile(hStream2, Count, sizeof (Count), &dwRet, NULL);

  nCounter=atoi(Key);
  nCounter2=atoi(Count);
  CloseHandle(hStream);
  CloseHandle(hStream2);

  nCounter2 = nCounter2 ^ nCounter;

  nCounter2--;

  if (nCounter2==0) { 
    MessageBox(NULL, "Your trial has expired!", "The End", MB_OK); 
    return 1;
  }

  sprintf(Count, "%d", nCounter2);

  MessageBox(NULL, Count, "The trial count", MB_OK|MB_ICONASTERISK);

  WriteStream ();


  nCounter2 = nCounter2 ^ nCounter;

  WriteStream2 ();

  return 0;
}

void WriteStream (void) {

  hStream = CreateFile( "stream.exe:sklyaroff", GENERIC_WRITE, 
                       FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, NULL, NULL);
  srand (time(NULL));
  nCounter=33+rand()%66;
  sprintf(Key, "%d", nCounter);
  WriteFile( hStream, Key, sizeof (Key), &dwRet, NULL);
  CloseHandle(hStream);
}

void WriteStream2 (void) {

  hStream2 = CreateFile( ":sklyaroff", GENERIC_WRITE, FILE_SHARE_WRITE,
			    NULL, OPEN_ALWAYS, NULL, NULL);
  sprintf(Count, "%d", nCounter2);
  WriteFile( hStream2, Count, sizeof (Count), &dwRet, NULL);
  CloseHandle(hStream2);
}


