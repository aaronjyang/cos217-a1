#include <stdio.h>

enum State {NORMAL, INQUOTE, INCOMMENT, SPCHAR, INSLASH, OUTSLASH, INASTERISK, OUTASTERISK};

enum State normal(int c){
    if (c == '"' || c == '\'') {
        putchar(c);
        return INQUOTE;
    } else if (c == '/') {
        return INSLASH;
    } else {
        putchar(c);
        return NORMAL;
    }
}

enum State inquote(int c){
    if (c == '\\') {
        return SPCHAR;
    } else if (c == '\'' ||c == '\"') {
        putchar(c);
        return NORMAL;
    } else {
        putchar(c);
        return INQUOTE;
    }
}

enum State incomment(int c){
    if (c == '*') {
        return OUTASTERISK;
    } else if (c == '\n') {
        putchar('\n');
        return INCOMMENT;
    } else {
        return INCOMMENT;
    }
}

enum State spchar(int c){
    putchar('\\');
    putchar(c);
    return INQUOTE;
}

enum State inslash(int c){
    if (c == '*') {
        return INASTERISK;
    } else {
        putchar('/');
        return normal(c);
    }
}

enum State outslash(int c){
    return normal(c);
}

enum State inasterisk(int c){
    putchar(' ');
    return incomment(c);
}


enum State outasterisk(int c){
    if (c == '/') {
        return OUTSLASH;
    } else {
        return incomment(c);
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
            case INQUOTE:
                curState = inquote(c);
                break;
            case INCOMMENT:
                curState = incomment(c);
                break;
            case SPCHAR:
                curState = spchar(c);
                break;
            case INSLASH:
                curState = inslash(c);
                break;
            case OUTSLASH:
                curState = outslash(c);
                break;
            case INASTERISK:
                commentStart = lineCount;
                curState = inasterisk(c);
                break;
            case OUTASTERISK:
                curState = outasterisk(c);
                break;
        }
    }

    if (curState == INCOMMENT || curState == OUTASTERISK) {
        fprintf(stderr, "Error: line %d: unterminated comment\n", commentStart);
        return 1;
    } else if (curState == INSLASH) {
        putchar('/');
    }

    return 0;
}