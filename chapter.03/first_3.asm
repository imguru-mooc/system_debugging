%include "asm_io.inc"

segment .data	
    bytes	dd	06C697665h	; "live"
    end	db	0	        	; null

segment .text
    global asm_main
asm_main:
    enter		0,0
    pusha
    mov		eax, bytes		; bytes는 주소를 나타냄
    call	print_string	; 해당 주소의 문자열 출력
    call	print_nl		; 새로운 라인 출력
    mov		eax, [bytes]	; 4바이트 값을 eax에 로드
    dump_mem	0, bytes, 1	; 메모리 출력
    dump_regs	0		    ; 레지스터 출력
    pusha
    popa
    mov		eax, 0
    leave
    ret

