/* #include <stdio.h>
#include <stdlib.h>
 */

#include <stddef.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list != NULL)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

/* int main()
{
	t_list	*node1 = malloc(sizeof(t_list));
	t_list	*node2 = malloc(sizeof(t_list));
	t_list	*node3 = malloc(sizeof(t_list));
	t_list	**lst = &node1;

	node1->data = "um";
	node1->next = node2;
	node2->data = "dois";
	node2->next = node3;
	node3->data = "tres";
	node3->next = NULL;

	printf("%d", ft_list_size(*lst));
} */