#include <stdio.h>

enum State {NORMAL, INQUOTE, INCOMMENT, SPCHAR, CSLASH, CASTERISK};

enum State normal(int c){
    if (c == '"' || c == '\'') {
        putchar(c);
        return INQUOTE;
    } else if (c == '/') {
        return CSLASH;
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
        return CASTERISK;
    } else {
        return INCOMMENT;
    }
}

enum State spchar(int c){
    putchar(c);
    return INQUOTE;
}

enum State cslash(int c){
    if (c == '*') {
        return CASTERISK;
    } else {
        putchar('/');
        putchar(c);
        return NORMAL;
    }
}

enum State casterisk(int c){
    if (c == '*') {
        putchar('*');
        return CASTERISK;
    } else {
        putchar(c);
        return NORMAL;
    }
}

int main(void) {
    int c; 
    enum State curState = NORMAL;

    while ((c = getchar()) != EOF) {
        switch (curState) {
            case NORMAL:
                normal(c);
                break;
            case INQUOTE:
                inquote(c);
                break;
            case INCOMMENT:
                incomment(c);
                break;
            case SPCHAR:
                spchar(c);
                break;
            case CSLASH:
                cslash(c);
                break;
            case CASTERISK:
                casterisk(c);
                break;
        }
    }
    return 0;
}