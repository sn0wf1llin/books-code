VERSION 5.00
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "St. Petersburg"
   ClientHeight    =   750
   ClientLeft      =   9885
   ClientTop       =   10020
   ClientWidth     =   4095
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   750
   ScaleWidth      =   4095
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton Command1 
      Caption         =   "Enter"
      Height          =   255
      Left            =   3240
      TabIndex        =   2
      Top             =   240
      Width           =   735
   End
   Begin VB.TextBox Text2 
      Height          =   285
      Left            =   840
      TabIndex        =   1
      Top             =   240
      Width           =   2295
   End
   Begin VB.TextBox Text1 
      BeginProperty DataFormat 
         Type            =   0
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1049
         SubFormatType   =   0
      EndProperty
      Height          =   285
      Left            =   120
      MaxLength       =   3
      TabIndex        =   0
      Top             =   240
      Width           =   375
   End
   Begin VB.Label Label1 
      Caption         =   "---"
      Height          =   255
      Left            =   600
      TabIndex        =   3
      Top             =   240
      Width           =   135
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
  Dim Num As Integer
  Num = 333
  OneText = Text1.Text

  If Len(OneText) = 3 Then
    For i = 1 To 3
      Temp = Asc(Mid(OneText, i, 1)) Xor 5
      OneText1 = OneText1 + Chr(Temp)
    Next
  End If

  If OneText1 = CStr(Num) And Text2.Text = "herrings" Then
    Unload Form1
    Form2.Show
  Else
    MsgBox ("Oh, no !")
  End If

End Sub
