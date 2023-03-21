/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: eucho <eucho@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 14:24:30 by eucho         #+#    #+#                 */
/*   Updated: 2023/03/21 14:31:32 by eucho         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_node	*lst_last(t_node *lst)
{
	t_node	*tmp;

	tmp = lst;
	if (!tmp)
		return (tmp);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_node	*lst_front(t_node *lst)
{
	t_node	*tmp;

	tmp = lst;
	if (!tmp)
		return (tmp);
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}

void	push_swap(t_stack *stack, char **argv, int size)
{
	int		i;
	int		tmp;
	t_node	*current;

	i = 0;
	while (i < size)
	{
		tmp = pusw_atoi(argv[i], stack->a);
		if (!stack->a)
		{
			stack->a = new_node(pusw_atoi(argv[i], stack->a), -1);
			current = stack->a;
		}
		else
		{
			add_after(current, new_node(tmp, -1));
			current = current->next;
		}
		i++;
	}
	stack->size_a = size;
	duplication_check(stack->a);
	sort(stack);
	free_stack(stack);
}

// void	leak_check(void)
// {
// 	system("leaks -q push_swap");
// }

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**tmp;
	int		size;
	int		i;

	// atexit(leak_check);
	tmp = argv;
	if (argc > 1)
	{
		tmp++;
		if (argc == 2)
		{
			tmp = ft_split(*tmp, ' ');
		}
		size = pusw_strlen(tmp);
		stack = malloc(sizeof(t_stack));
		if (!stack)
			return (0);
		stack->a = NULL;
		stack->b = NULL;
		push_swap(stack, tmp, size);
		i = 0;
		if (argc == 2)
		{
			while(tmp && tmp[i])
			{	
				free(tmp[i]);
				i++;
			}
			if (tmp)
				free(tmp);
		}
	}
	return (0);
}
