#include <stdlib.h>

struct s_node {
    void *content;
    struct s_node *next;
};

struct s_queue {
    struct s_node *first;
    struct s_node *last;
};

struct s_queue *init(void)
{
    struct s_queue		*queue;

	queue = (struct s_queue *)malloc(sizeof(struct s_queue));
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

void enqueue(struct s_queue *queue, void *content)
{
	struct s_node		*new;

	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->content = content;
    new->next = NULL;

	if (!queue)
		return ;
	if (!queue->first)
	{
		queue->first = new;
        queue->last = new;
		new->next = NULL;
		return ;
	}
	queue->last->next = new;
	queue->last = new;
}

void *dequeue(struct s_queue *queue)
{
	void		*content;

	if (!queue || !queue->first)
		return (NULL);
	content = queue->first->content;
	queue->first = queue->first->next;
    if (queue->first == NULL)
        queue->last = NULL;
	return (content);
}

void *peek(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return (NULL);
	return (queue->first->content);
}

int isEmpty(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return (1);
	return (0);
}

/*
#include <stdio.h>

void    print_queue(struct s_queue *queue)
{
    struct s_node *tmp;

    if (!queue)
    {
        printf("Queue doesn't exist\n");
        return ;
    }
    tmp = queue->first;
    while (tmp)
    {
        printf("[%s]->", (char *)tmp->content);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

int		main()
{
	struct s_queue		*queue;
	void				*content;

	queue = NULL;
	
	printf("isEmpty = %d\n", isEmpty(queue));
    print_queue(queue);

	printf("init\n");
	queue = init();

	printf("push (1)\n");
	enqueue(queue, "1");
	printf("isEmpty = %d peek = %s\n", isEmpty(queue), (char *)peek(queue));
    print_queue(queue);

	printf("push (2)\n");
	enqueue(queue, "2");
	printf("isEmpty = %d peek = %s\n", isEmpty(queue), (char *)peek(queue));
    print_queue(queue);

	printf("push (3)\n");
	enqueue(queue, "3");
	printf("isEmpty = %d peek = %s\n", isEmpty(queue), (char *)peek(queue));
    print_queue(queue);


	printf("\npop\n");
	content = dequeue(queue);
	printf("isEmpty = %d peek = %s pop = %s\n", isEmpty(queue), (char *)peek(queue), (char *)content);
    print_queue(queue);

	printf("pop\n");
	content = dequeue(queue);
	printf("isEmpty = %d peek = %s pop = %s\n", isEmpty(queue), (char *)peek(queue), (char *)content);
    print_queue(queue);

	printf("pop\n");
	content = dequeue(queue);
	printf("isEmpty = %d peek = %s pop = %s\n", isEmpty(queue), (char *)peek(queue), (char *)content);
    print_queue(queue);
}
*/