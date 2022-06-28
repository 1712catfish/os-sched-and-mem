


void * allocator_template(
    unsigned int size,

    int found = 1;
    void (*finder) (struct mem_region*, struct mem_region*, unsigned int)) {

    for (;current_region != NULL; current_region = current_region->next)
        if (size <= curr->size) {
            found = 1;
            // The only thing that is different between three methods
            if (first == NULL) {
                first = curr;
                return;
            }

        }


}

	if (!found)
	    return NULL;

    struct mem_region * current_region = current_region;

    tmp = new_mem_region(
        current_region->pointer,
        size, used_regions, NULL,
    )

    push(tmp, used_regions);

    if (current_region->size == size) {
        pop(free_regions, current_region);
    }
    else {
        current_region->pointer += size;
        current_region->size -= size;
    }
    return tmp->pointer;
}

void pop(struct mem_region * queue_head, struct mem_region * current_region) {
    if (current_region == queue_head) {
        queue_head = queue_head->next;
        if (queue_head != NULL) {
            queue_head->prev = NULL;
        }
    } else {
        if (current_region->prev != NULL) {
            current_region->prev->next = current_region->next;
        }
        if (current_region->next != NULL) {
            current_region->next->prev = current_region->prev;
        }
    }
    free(current_region);
}

void push(struct mem_region * queue_head, struct mem_region* tmp) {
    tmp->next = queue_head;
    tmp->prev = NULL;

    if (queue_head == NULL) {
        queue_head = tmp;
    } else {
        queue_head->prev = tmp;
        queue_head = tmp;
    }
}

struct mem_region* new_mem_region(char * pointer,
                                  size_t size,
                                  struct mem_region * next,
                                  struct mem_region * prev) {
    struct mem_region* tmp =
    (struct mem_region*)malloc(sizeof(struct mem_region));
    tmp->pointer = pointer;
    tmp->size = size;
    tmp->next = next;
    tmp->prev = next;
    return tmp
}

