// This file is only used to specify the structure of allocator.c



// pop current_region from queue
// no check if current_region not in queue
void pop(struct mem_region * queue_head, struct mem_region * region_to_pop);

// push new mem_region to queue's head
void push(struct mem_region * queue_head, struct mem_region* region_to_push);

// lazy default constructor for mem_region
struct mem_region* new_mem_region(char * pointer,
                                  size_t size,
                                  struct mem_region * next,
                                  struct mem_region * prev);


void * first_fit_allocator(unsigned int size);