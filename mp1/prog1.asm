;need all of the histogram bin labels, spaces, and newlines
;have to handle loop control over bins

; ****************************************

;I looked at past histogram resources
;https://courses.grainger.illinois.edu/ece198kl/sp2013/programs/prog1.pdf

; Lost initial MP copy in the middle of the week, so this is a rushed version that was open on an online-gdb tab

; ****************************************



; ****************************************

;Use x000A as newline character not x000D

; ****************************************

; example code has character -> space -> frequency
; use left shift? to calculate amount of letters  
; need to turn 4 binary bits into 1 hex bit then print out

; R0 = output/print function
; R1 = Hold the character that needs to be printed in here
; R2 = Use this for the digit counter
; R3 = Probably need another counter for bin-to-hex conversion
; R4 = (counter for) # of rows (maybe look at ECE120 lab 11 and 13)
; R5 = use to hold address of the binary digit to be printed
; R6 = just use as a temp register to move stuff around


; DO NOT USE R7, it is used for special trap commands (Prof. Moon's notes)

	LD	R1, ASCII_AT_THE_RATE	; Load R1

	LD	R3, NUM_BINS	; Load R3

	LD	R5, HIST_ADDR	; Load R5

PRINT_NEW_ROW
; prints row
	ADD	R0,R1,#0
	OUT
; prints space
	LD	R0, ASCII_SPACE
	OUT

	AND	R4, R4,#0		; R4 (row counter)
	ADD	R4, R4, #4	; Initializing Big digit counter to be 4
	LDR	R6, R5, #0	; Initializing R6 to hold the bit number of each bin stores of the HIST

; prints 4 digit hex

PRINT_DIGIT
	AND	R0, R0, #0	; R0 (register which outputs to monitor)
	AND	R2, R2, #0	; R2 (digit counter)
	ADD	R4,R4,#4		; Initializing Small digit counter to be 4 AND R0 to be 0


LEFT_SHIFT_LOOP
	ADD	R2, R2, #0	; R2 (digit counter)
	BRz	TRANSFER	; Judge whether get 4 bits
	ADD	R0, R0, R0	; left shift so that R0 is used to be the digit that to be printed
	ADD	R6, R6, #0	
	BRzp	LSHIFT_N_REDUCE
	ADD	R0, R0, #1	;  increments R0 by 1


LSHIFT_N_REDUCE
	ADD	R6, R6, R6	; Shift bit left by mulitplying R6 by 2
	ADD	R2, R2, #-1	; decrement digit counter
	BRnzp	LEFT_SHIFT_LOOP	; goes to previous loop


TRANSFER			
	ADD	R2, R0, #-9
	BRp	BIG_TEN
	LD	R2, ASCII_ZERO	; Load R2 with the ascii value for 0
	ADD	R0, R0, R2
	OUT
	BRnzp	REDUCE_ROW_COUNT


BIG_TEN		; For digit 10 and up
	LD	R6, ASCII_CAPITAL_A
	ADD	R0, R0, R6
	ADD	R0, R0, #-10	; Decrease R0 by 10 for ascii values
	OUT

REDUCE_ROW_COUNT				
	ADD	R4, R4, #-1	; Decrement the row counter
	BRp	PRINT_DIGIT	; Loop to print the next digit
	LD	R0, ASCII_NEW_LINE_FEED
	OUT
	ADD	R5, R5, #1	; Move counter to next address for binary bits
	ADD	R1, R1, #1	; Increase 1 to hold the next character
	ADD	R3, R3, #-1	; Decrease bin-to-hex counter
	BRz	DONE		; stop the program when all 27 rows have been printed
	BRnzp	PRINT_NEW_ROW	; give a new line when done
	
	
DONE	HALT			; done


; the data needed by the program
NUM_BINS	.FILL #27	; 27 loop iterations
NEG_AT		.FILL xFFC0	; the additive inverse of ASCII '@'
AT_MIN_Z	.FILL xFFE6	; the difference between ASCII '@' and 'Z'
AT_MIN_BQ	.FILL xFFE0	; the difference between ASCII '@' and '`'
HIST_ADDR	.FILL x3F00     ; histogram starting address
STR_START	.FILL x4000	; string starting address

; need char for at the rate, space between letter and frequency, and need to have \n
ASCII_AT_THE_RATE   .FILL x0040 ; ASCII encoding for '@' symbol
ASCII_SPACE 		    .FILL x0020	; ASCII encoding for 'space'
ASCII_NEW_LINE_FEED    .FILL x000A ; ASCII break into next line

; Use x000A as newline character not x000D

ASCII_ZERO    		.FILL x0030	; ASCII encoding for '0'
ASCII_CAPITAL_A        .FILL x0041	; ASCII encoding for 'A'

; for testing, you can use the lines below to include the string in this
; program...
; STR_START	.FILL STRING	; string starting address
; STRING		.STRINGZ "This is a test of the counting frequency code.  AbCd...WxYz."

	; the directive below tells the assembler that the program is done
	; (so do not write any code below it!)

	.END
