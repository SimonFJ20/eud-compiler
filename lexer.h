#ifndef LEXER_H
#define LEXER_H

#include <stdlib.h>

typedef enum {
    TT_IDENTIFIER,
    TT_KEYWORD,
    TT_INT,
    TT_LPAREN,
    TT_RPAREN,
    TT_LBRACE,
    TT_RBRACE,
    TT_LBRACKET,
    TT_RBRACKET,
    TT_SEMICOLON
} TokenType;

typedef struct {
    TokenType type;
    const char* value;
    size_t length;
} Token;

Token* new_token(TokenType type, const char* value, size_t length);
void delete_token(Token* self);

#endif