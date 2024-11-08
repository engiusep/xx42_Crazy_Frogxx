/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listechaine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:50:23 by engiusep          #+#    #+#             */
/*   Updated: 2024/11/07 17:29:57 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    int value;
    struct s_list *next;         
}   s_list;       

void    create_node(s_list *start, int value)
{
    s_list *new;
    s_list *move;
    new = malloc(sizeof(s_list));
    new->next = NULL;
    new->value = value;
    move = start;
    while(move->next != NULL)
        move = move->next;   
    move->next = new;
}
    
int main(void)
{
    s_list *start;
    s_list *move;
    start = malloc(sizeof(s_list));
    move = start;
    start->next = NULL;
    start->value = 40;
    create_node(start,6);
    create_node(start,63);
    create_node(start,61);
    create_node(start,26);
    while(move->next != NULL)
    {
        printf("%d\n",move->value);
        move = move->next;
    }
    printf("%d",move->value);       
}
