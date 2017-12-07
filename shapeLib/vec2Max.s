vec2Max:
    mov #0, r15;
  while:
  cmp #2, r15;
  jc done;
  add r15, r13;
  mov r13, r17;
  add r11, r7;
  add r15, r7; 
  mov r7, r10; 
  mov r14, r8;
  mpv r11, r8;
  mov r15, r8;
  mov r8, r10;
  jmp while:
  done:
