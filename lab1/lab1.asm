.ORIG x3000

;attempt at lab 1

	AND R3, R3, #0	; clear R3
	LD R2, ASCII_offset	; load the ascii offset into R2 (#40)
	ADD R3, R3, R2  ; add offset to R3  
	OUT
	HALT	; Trap x25

	ASCII_offset .FILL x30	; ASCII chart character offset
	.END
