CSEG segment
assume CS:CSEG, DS:CSEG, ES:CSEG, SS:CSEG
org 100h

Start:

  jmp Go
  Fraza db 'Pack my box with five dozen liquor jugs.','$'
	          
Go:

  lea bx,Fraza
  mov cx,40
	
Hi:

  mov ah,[bx]
  push cx
  mov cl,04
  ror ah,cl
  mov [bx],ah
  pop cx
	
  inc bx

  loop Hi

  mov ah,09
  lea dx,Fraza
  int 21h
	
  int 20h

CSEG ends
end Start

