#include "minishell.h"

void    expand_token_array(t_token_tab *tab)
{
    int new_size;
    int i;
    i = 0;
    new_size = tab->size * 2;
    t_token *new_token = malloc(sizeof(t_token) * SIZE);

    while(i < tab->index)
    {
        new_token[i] = tab->tokens[i];
        i++;
    }
    free(tab->tokens);
    tab->tokens = new_token;
    tab->size = new_size;
}

t_token_tab *create_token_tab()
{
    t_token_tab *tab;
    tab = malloc(sizeof(t_token_tab));
    tab->tokens = malloc(sizeof(t_token) * SIZE);
    tab->index = 0;
    tab->size = SIZE;
    return tab;
}

void    add_token_tab(t_token_tab *tab,char *value,t_token_type type)
{
    if(tab->index < tab->size)
        expand_token_array(tab);
    tab->tokens[tab->index].value = value;
    tab->tokens[tab->index].type = type;
    tab->index++;
}

char *read_word(char *str,int *i)
{
    int start;
    start = *i;

    while(str[*i] != ' ')
        (*i)++;
    return strndup(&str[start], *i - start);
}
t_token_tab *lexer(char *str)
{
    t_token_tab *tokens_tab = create_token_tab();
    int i;
    i = 0;
    
    while(str[i])
    {
        if(str[i] == ' ')
            i++;
        else if(str[i] == '|')
        {
            add_token_tab(tokens_tab,ft_strdup("|"),PIPE);
            i++;
        }
        else
        {
            char *word = read_word(str, &i);
            i++;
        }
    }
    return (tokens_tab);
}
int main(int argc,char **argv, char **env)
{
    t_token_tab *tokens = lexer(argv[0]);

    for(int i = 0; i < tokens->index;i++)
    {
        printf("TOKEN[%d]: %s (type%d)\n",i,tokens->tokens[i].value,tokens->tokens[i].type);
    }
}