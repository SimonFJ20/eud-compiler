#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

Token* new_token(TokenType type, const char* value, size_t length) 
{
    Token* self = calloc(1, sizeof (Token));
    *self = (Token) {
        .type = type,
        .value = value,
        .length = length,
    };
    return self;
}

void delete_token(Token* self)
{
    free(self);
}

LexerIteration* new_lexer_iteration(bool done, Token* value)
{
    LexerIteration* self = calloc(1, sizeof(LexerIteration));
    *self = (LexerIteration) {
        .done = done,
        .value = value,
    };
    return self;
}

void delete_lexer_iteration(LexerIteration* self)
{
    free(self);
}

Token* lexer_iteration_unwrap(LexerIteration* self)
{
    Token* value = self->value;
    delete_lexer_iteration(self);
    return value;
}

Lexer* new_lexer(Reader* reader)
{
    Lexer* self = calloc(1, sizeof (Lexer));
    *self = (Lexer) {
        .reader = reader,
        .c = '\0',
    };
    return self;
}

void delete_lexer(Lexer* self)
{
    free(self);
}

LexerIteration* lexer_next(Lexer* self)
{
    lexer_next_char(self);
    if (self->c >= 48 && self->c <= 57) {
        return lexer_make_int(self);
    } else {
        switch (self->c) {
        case 1:
        default:
            lexer_fail_unexpected_char(self);
            exit(1);
        }
    }
}

LexerIteration* lexer_make_int(Lexer* self)
{
    return NULL;
}

void lexer_fail_unexpected_char(Lexer* self)
{
    printf("fatal: unexpected character '%c'\n", self->c);
    exit(1);
}

void lexer_next_char(Lexer* self)
{
    self->c = self->reader->getc(self->reader);
}
