#include <stdio.h>

/* Defines all relevant states in DFA as constants*/
enum State {NORMAL, QUOTE, CHARLIT, COMMENT, QSPCHAR, CSPCHAR, INSLASH,
    OUTASTERISK};

/* Implements NORMAl state behavior. Checks for beginning of string, character 
   literal, or comment and returns corresponding state. Writes c to stdout 
   unless it is potentially the beginning of a comment */
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

/* Implements QUOTE state behavior. Checks for escape character \ or end of 
   string ". Returns corresponding state and writes c to stdout unless it is a 
   special char */
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

/* Implements CHARLIT state behavior. Checks for escape character \ or end of 
   character literal '. Returns corresponding state and writes c to stdout 
   unless it is a special char */
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

/* Implements COMMENT state behavior. Checks for asterisks and newline 
   characters. Only prints newline characters. */
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

/* Implements QSPCHAR (quote special character) state behavior. Prints \ and c 
   no matter what and then returns to QUOTE state */
enum State qspchar(int c){
    putchar('\\');
    putchar(c);
    return QUOTE;
}

/* Implements CSPCHAR (character literal special character) state behavior.
   Prints \ and c no matter what and then returns to QUOTE state */
enum State cspchar(int c){
    putchar('\\');
    putchar(c);
    return CHARLIT;
}

/* Implements INSLASH state behavior. Checks for start of comment and if so, 
   returns COMMENT state. Otherwise, return NORMAL. */
enum State inslash(int c){
    if (c == '*') {
        putchar(' ');
        return COMMENT;
    } else {
        putchar('/');
        return normal(c);
    }
}

/* Implements OUTASTERISK state behavior. Checks for end of comment and returns
   NORMAL if found. Else, return COMMENT */
enum State outasterisk(int c){
    if (c == '/') {
        return NORMAL;
    } else {
        return comment(c);
    }
}
    
/* Reads text from stdin. Removes comments, maintains quotes & newlines, 
   and returns error messages with line numbers when comments are unclosed. 
   Prints output to stdout and errors to stderr. Returns 1 if there is an
   unclosed comment and 1 otherwise. */
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