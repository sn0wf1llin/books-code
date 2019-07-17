CSEG segment
org 100h

Start:  jmp Go                   	
	
Mess1 DB "LAMER$&%*#"

Mess2 DB "A C  R  ECH H H CRH HRE",0Dh,0Ah
             DB "A K E H A   R A K   A H",0Dh, 0Ah
             DB "CHR ACA C   AH  RC  KC",0Dh,0Ah
             DB "R K C C K   R K A   C K",0Dh,0Ah
             DB "E E K K AEA A R ERE E H$"

Go:	
  	mov al, [bx]
	xor al, 7
	mov cx, 80

	mov bx, offset Mess1
	mov ah, 9
	mov dx,bx
	int 21h
	
	int 20h

CSEG ends
end Start
