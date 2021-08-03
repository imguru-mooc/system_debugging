segment .data
integer1    dd  15  ; first int
integer2    dd  6   ; second int
segment .bss
result  resd    1   ; result
segment .text

global asm_main
asm_main:
enter   0,0
pusha
mov     eax, [integer1]
add     eax, [integer2]
mov     [result], eax
popa
mov eax, [result]
leave
ret

