CSEG segment
org 100h
Start:	jmp Go

	Mess1 db 2h, 6Bh, 27h, 24h, 3Dh, 2Eh, 6Bh
Go:     
	db 2h, 6Bh, 23h, 2Ah, 3Fh, 2Eh, 6Bh
	xor bx, bx
	mov bx,offset Mess1
	mov cx,7
	call Changer

Message:
	db 7, 34, 37, 62, 51, 106, 107, 107, 107
	mov ax, 1
	add dx, 10
	mov bx, offset Mess3; эту строку нужно исправить
	mov cx, 9
	call Changer
	int 20h

Changer proc
Hi:  	mov al, [bx]
	mov dl,al
	xor al, 7
	imul al
	mov ah,2
	xor dl, 75
	int 21h
	inc bx
	loop Hi
	ret
Changer endp
	
	Mess3 db 1Ch, 22h, 25h, 2Fh, 24h, 3Ch, 38h, 6Ah, 6Bh
	Mess4 db 32h, 24h, 3Eh, 6Bh, 9h, 22h, 27h, 27h, 6Ah
	Mess5 db "!xuniL"

CSEG ends
end Start
