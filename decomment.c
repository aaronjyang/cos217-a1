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
    } else if (c == '\'' ||c == '\'') {
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
        putchar(c);
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
        putchar(c);
        return INCOMMENT;
    }
}

enum State outslash(int c){
    putchar(' ');
    putchar(c);
    return NORMAL;
}

enum State inasterisk(int c){
    if (c == '*') {
        return OUTASTERISK;
    } else if (c == '\n') {
        putchar(c);
        return INCOMMENT;
    } else {
        return INCOMMENT;
    }
}

enum State outasterisk(int c){
    if (c == '*') {
        return OUTASTERISK;
    } else if (c == '/') {
        return OUTSLASH;
    } else if (c == '\n') {
        putchar(c);
        return INCOMMENT;
    } else {
        return INCOMMENT;
    }
}

int main(void) {
    int c; 
    enum State curState = NORMAL;

    while ((c = getchar()) != EOF) {
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
                curState = inasterisk(c);
                break;
            case OUTASTERISK:
                curState = outasterisk(c);
                break;
        }
    }
    return 0;
}