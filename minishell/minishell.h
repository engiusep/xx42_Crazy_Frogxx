#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 8

typedef enum e_token_type
{
    WORD,
    PIPE,
    REDIR_IN,
    REDIR_OUT,
    REDIR_APPEND,
    HEREDOC
}t_token_type;

typedef struct s_token
{
    char *value; // valeur dans du token
    t_token_type type; // WORD PIPE 
}t_token;
typedef struct s_token_tab
{
    t_token *tokens;
    int index;
    int size;
}t_token_tab;



char *ft_strdup(char *str);