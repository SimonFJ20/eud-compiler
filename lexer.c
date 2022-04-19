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

Lexer* new_lexer(Reader reader)
{
    Lexer* self = calloc(1, sizeof (Lexer));
    *self = (Lexer) {
        .index = 0,
        .reader = reader,
    };
    return self;
}

void delete_lexer(Lexer* self)
{
    free(self);
}

LexerIteration* lexer_next(Lexer* self)
{
    return NULL;
}
