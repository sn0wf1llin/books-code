CSEG segment
assume CS:CSEG,DS:CSEG,ES:CSEG,SS:CSEG
org 100h

Start:
	xor ax, ax
	daa
	pushf
	pop ax
	and ax,0h
	jz NormalRun
	DB 0EAh
NormalRun:
	call SecretRoutine

	int 20h

SecretRoutine proc

	mov dx, offset Message
 	mov ah, 9
	int 21h

	mov ah, 0Ah
	mov dx, offset Password
	int 21h

	mov dx, offset crlf
	mov ah, 9
	int 21h

	xor di,di
	xor cx,cx
	mov cl, Blength
	mov si, cx
	xor al, al

Next: 
	mov bl, byte ptr bcontents[di]
	xor bl, 13
	
	add al, bl	
	
	inc di

	cmp di, si
	jb Next

	add al, 99

	cmp al, 4Ah
	jz OK

	mov dx, offset Message3
	mov ah, 9
	int 21h

	ret

SecretRoutine endp

OK:    
	mov ah, 9
	mov dx, offset Message2
	int 21h
	ret

	Message    DB "Password:$"
	Message2   DB "OK!$"
	Message3   DB "WRONG!$"

	crlf       DB 0Dh, 0Ah,'$'
	Password   DB 10
	Blength    DB ?
	Bcontents:

CSEG ends
end Start
