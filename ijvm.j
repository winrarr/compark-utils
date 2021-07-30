.method main
.args 3
.locals 1
.define A=1
.define count=2
.define C=3

    bipush 1
    istore C
L:
    iload count
    ifeq End

    bipush 88
    iload C
    iload A
    invokevirtual xor
    istore A
    iload C
    dup
    iadd
    istore C
    iinc count,-1
    goto L

End:
    iload A
    ireturn
