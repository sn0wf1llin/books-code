CSEG segment
assume CS:CSEG,DS:CSEG,ES:CSEG,SS:CSEG
org 100h

Begin:

   xor ax,ax

   call Xorer

   mov ah, 9	
   mov dx, offset Mess1
   int 21h	

   int 20h

Xorer proc
                      
   mov bx, offset Mess1
   mov cx, 48

Hi:mov ax, [bx]
   xor ax, 1  
   mov [bx],ax
   inc bx

   loop Hi
      
   ret
Xorer endp

Mess1 db "Fnne!e`x-!M`lds %"
Mess2 db "Ih-!ohffds %"
Mess3 db "Idmmn-!I`bjds %Doe/"

CSEG ends
end Begin
