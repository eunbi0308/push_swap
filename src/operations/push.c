/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eucho <eucho@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:20:02 by eucho         #+#    #+#                 */
/*   Updated: 2023/03/20 18:46:08 by eucho         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
/*push a : Take the first element at the top of b 
		and put it at the top of a.*/
void	pa(t_stack *stack)
{
	t_node	*tail;
	t_node	*new;

	tail = lst_last(stack->a);
	new = new_node(stack->b->data, stack->b->index);
	stack->size_a++;
	add_before(stack->a, new);
	stack->a = new;
	del_node(&stack->b, &tail, stack->b);
	if (stack->b)
		stack->size_b--;
	ft_printf("pa\n");
}

/*push b : Take the first element at the top of a
		and put it at the top of b.*/
void	pb(t_stack *stack)
{
	t_node	*tail;
	t_node	*new;

	tail = lst_last(stack->a);
	new = new_node(stack->a->data, stack->a->index);
	stack->size_b++;
	add_before(stack->b, new);
	stack->b = new;
	del_node(&stack->a, &tail, stack->a);
	stack->size_a--;
	ft_printf("pb\n");
}
