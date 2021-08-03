%include "asm_io.inc"
;
; 초기화 된 데이터는 .data 세그먼트에 들어간다.

segment .data
;
; 아래 라벨들은 출력을 위한 문자열들을 가리킨다.
;
prompt1 db "Enter a number: ", 0 ; 널 종료 문자임을 잊지 말라!
prompt2 db "Enter another number: ", 0
outmsg1 db "You entered ", 0
outmsg2 db " and ", 0
outmsg3 db ", the sum of these is ", 0

;
; 초기화 되지 않은 데이터는 .bss 세그먼트에 들어간다.
;
segment .bss
;
; 이 라벨들은 입력 값들을 저장하기 위한 더블워드를 가리킨다.
input1 resd 1
input2 resd 1

;
; 코드는 .text 세그먼트에 들어간다.
;
segment .text
global asm_main
asm_main:
	enter 0,0 ; 셋업(set up) 루틴
	pusha

	mov eax, prompt1 ; prompt 를 출력
	call print_string

	call read_int ; 정수를 읽는다.
	mov [input1], eax ; input1 에 저장.

	mov eax, prompt2 ; prompt 를 출력
	call print_string

	call read_int ; 정수를 읽는다.
	mov [input2], eax ; input2 에 저장.

	mov eax, [input1] ; eax = input1 에 위치한 dword
	add eax, [input2] ; eax += input2 에 위치한 dword
	mov ebx, eax ; ebx = eax

	;
	; 아래 단계별로 메세지를 출력한다.
	;
	mov eax, outmsg1
	call print_string ; 첫 번째 메세지를 출력
	mov eax, [input1]
	call print_int ; input1 을 출력
	mov eax, outmsg2
	call print_string ; 두 번째 메세지를 출력
	mov eax, [input2]
	call print_int ; input2 를 출력
	mov eax, outmsg3
	call print_string ; 세 번째 메세지를 출력
	mov eax, ebx
	call print_int ; 합을 출력 (ebx)
	call print_nl ; 개행문자를 출력

	popa
	mov eax, 0 ; C 로 리턴된다.
	leave
	ret
