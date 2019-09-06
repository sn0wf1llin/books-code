format ELF executable

segment readable executable

start:
push ax
pop cx
or cx,bx
and ax,bx
xor ax,0ffffh
and cx,ax
mov ax,cx
push cx
not dx
not cx
or dx,cx
xor dx,0ffffh
mov bx,dx
pop cx

mov eax, 1
mov ebx, 0
int 80h
