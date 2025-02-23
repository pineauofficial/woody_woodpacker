section .text
    global ft_random

    ;extern ssize_t ft_random(void *buf, size_t buflen)
    ;rdi = buf
    ;rsi = buflen

ft_random:
    mov rdx, 0
    mov rax, 318
    syscall
    ret


section .note.GNU-stack noalloc noexec nowrite progbits