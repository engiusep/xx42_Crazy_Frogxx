#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node { // given
    enum { ADD, MULTI, VAL } type;
    int val;
    struct node *l;
    struct node *r;
} node;

void unexpected(char c) // given
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");
}

void destroy_tree(node *n) // given
{
    if (!n)
        return;
    destroy_tree(n->l);
    destroy_tree(n->r);
    free(n);
}

node *new_node(node n) // given
{
    node *ret = calloc(1, sizeof(node));
    if (!ret)
        return NULL;
    *ret = n;
    return ret;
}

int accept(char **s, char c) // given
{
    if (**s == c)
    {
        (*s)++;
        return 1;
    }
    return 0;
}

int expect(char **s, char c) // given
{
    if (accept(s, c))
        return 1;
    // unexpected(**s); // to remove
    return 0;
}

int eval_tree(node *t) // given
{
    if (t->type == VAL)
        return t->val;
    if (t->type == ADD)
        return eval_tree(t->l) + eval_tree(t->r);
    if (t->type == MULTI)
        return eval_tree(t->l) * eval_tree(t->r);
    return 0;
}

node *parse_expr(char **s)
{
    node *left = parse_term(s);

    while(accept(s, '+'))
    {
        node *right = parse_term()
    }
}

node *parse(char *s)
{
    node *tree = parse_expr(&s);

    if(!tree || *s)
    {
        unexpected(*s ? *s : 0);
        destroy_tree(tree);
        return NULL;
    }
    return tree;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    node *tree = parse(argv[1]);
    if (!tree)
        return 1;
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
    return 0;
}