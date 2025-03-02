section .text
    global fast_atoi  ; Делаем функцию доступной в C++

; int fast_atoi(const char* str);
fast_atoi:
    xor eax, eax         ; Обнуляем результат (EAX = 0)
    mov rsi, rdi         ; Переносим указатель str в RSI (Linux) / RCX (Windows)

atoi_loop:
    movzx ecx, byte [rsi]  ; Загружаем текущий символ
    test ecx, ecx          ; Проверяем конец строки (нулевой символ)
    je atoi_done
    sub ecx, '0'           ; Преобразуем ASCII в число
    imul eax, eax, 10      ; Умножаем текущее число на 10
    add eax, ecx           ; Добавляем новую цифру
    inc rsi                ; Двигаемся к следующему символу
    jmp atoi_loop

atoi_done:
    ret                    ; Возвращаем результат (EAX)
