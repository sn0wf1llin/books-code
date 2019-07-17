CSEG segment
assume CS:CSEG,DS:CSEG,ES:CSEG,SS:CSEG
org 100h

Begin:
  mov cx,3
  Label1:
    call Procedure1
  loop Label1

  push ax

  inc cx; эту команду нужно исправить на pop cx
  inc cx
  inc cx
  Label2:
    call Procedure2
  loop Label2

  int 20h

  Message db "Cool Hacker!",0Dh,0Ah,'$'

  Procedure1 proc
    add ax, 1
    ret
  Procedure1 endp

  Procedure2 proc
    mov ah, 9
    mov dx, offset Message
    int 21h
    ret
  Procedure2 endp

CSEG ends
end Begin
