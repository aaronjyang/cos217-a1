#include <stdio.h>

enum State {NORMAL, QUOTE, CHARLIT, COMMENT, QSPCHAR, CSPCHAR, INSLASH, OUTASTERISK};

enum State normal(int c){
    if (c == '"') {
        putchar(c);
        return QUOTE;
    } else if (c == '\''){
        putchar(c);
        return CHARLIT;
    } else if (c == '/') {
        return INSLASH;
    } else {
        putchar(c);
        return NORMAL;
    }
}

enum State quote(int c){
    if (c == '\\') {
        return QSPCHAR;
    } else if (c == '"') {
        putchar(c);
        return NORMAL;
    } else {
        putchar(c);
        return QUOTE;
    }
}

enum State charlit(int c){
    if (c == '\\') {
        return CSPCHAR;
    } else if (c == '\'') {
        putchar(c);
        return NORMAL;
    } else {
        putchar(c);
        return CHARLIT;
    }
}

enum State comment(int c){
    if (c == '*') {
        return OUTASTERISK;
    } else if (c == '\n') {
        putchar('\n');
        return COMMENT;
    } else {
        return COMMENT;
    }
}

enum State qspchar(int c){
    putchar('\\');
    putchar(c);
    return QUOTE;
}

enum State cspchar(int c){
    putchar('\\');
    putchar(c);
    return CHARLIT;
}

enum State inslash(int c){
    if (c == '*') {
        putchar(' ');
        return COMMENT;
    } else {
        putchar('/');
        return normal(c);
    }
}

enum State outasterisk(int c){
    if (c == '/') {
        return NORMAL;
    } else {
        return comment(c);
    }
}
    
int main(void) {
    int c; 
    int commentStart;
    int lineCount = 1;
    enum State curState = NORMAL;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            lineCount++;
        }

        switch (curState) {
            case NORMAL:
                curState = normal(c);
                break;
            case QUOTE:
                curState = quote(c);
                break;
            case CHARLIT:
                curState = charlit(c);
                break;
            case COMMENT:
                curState = comment(c);
                break;
            case QSPCHAR:
                curState = qspchar(c);
                break;
            case CSPCHAR:
                curState = cspchar(c);
                break;
            case INSLASH:
                curState = inslash(c);
                if (curState == COMMENT) commentStart = lineCount;
                break;
            case OUTASTERISK:
                curState = outasterisk(c);
                break;
        }
    }

    if (curState == COMMENT || curState == OUTASTERISK) {
        fprintf(stderr, "Error: line %d: unterminated comment\n", commentStart);
        return 1;
    } else if (curState == INSLASH) {
        putchar('/');
    } else if (curState == QSPCHAR || curState == CSPCHAR) {
        putchar('\\');
    }

    return 0;
}