#include "cub3d.h"


t_garbage_collector *gc_init() 
{
    t_garbage_collector *gc;
    
    gc = malloc(sizeof(t_garbage_collector));
    gc->head = NULL;
    return gc;
}

void *gc_alloc(t_garbage_collector *gc, size_t size) 
{
    void *ptr;
    t_collector_node *node;

    ptr = malloc(size);
    if (!ptr)
        return NULL;
    node = malloc(sizeof(t_collector_node));
    if (!node)
        return NULL;
    
    node->ptr = ptr; 
    node->next = gc->head;
    gc->head = node;
    return ptr;
}

void gc_free(t_garbage_collector *gc) 
{
    t_collector_node *current;
    t_collector_node *temp;
    
    current = gc->head;
    while (current != NULL) {
        free(current->ptr); 
        current->ptr = NULL;
        temp = current;
        current = current->next;
        free(temp);
    }
    free(gc);
}


void gc_double_add(t_garbage_collector *gc, void **ptr)
{
    int i;

    if (!ptr) // Vérification avant de commencer
        return;

    i = 0;
    while (ptr[i])
    {
        gc_add(gc, (void *)ptr[i]);
        i++;
    }
    gc_add(gc, (void *)ptr); // Assurez-vous que ptr lui-même est valide
}

void gc_add(t_garbage_collector *gc, void *ptr)
{
    t_collector_node *node;

    node = malloc(sizeof(t_collector_node));
    if (!node)
        return;

    node->ptr = ptr; 
    node->next = gc->head;
    gc->head = node;
}
