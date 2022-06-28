void * first_fit_allocator(unsigned int size) {
	/* First fit example */
	int found = 0;
	struct mem_region * current_region = free_regions;

	// Loop over regions to find a region with proper size
	do {
		if (size <= current_region->size) {
			found = 1;
		} else{
			current_region = current_region->next;
		}
	} while (!found && current_region != NULL);

	if (!found) {
	    return NULL;
	}

	// enqueue newly found region to list of used regions
    struct mem_region* tmp =
        (struct mem_region*)malloc(sizeof(struct mem_region));
    tmp->pointer = current_region->pointer;
    tmp->size = size;
    tmp->next = used_regions;
    tmp->prev = NULL;
    if (used_regions == NULL) {
        used_regions = tmp;
    } else {
        used_regions->prev = tmp;
        used_regions = tmp;
    }

    // remove newly found region from list of free regions
    if (current_region->size > size) {
        current_region->pointer += size;
        current_region->size -= size;
    }
    else {
        if (current_region == free_regions) {
            free_regions = free_regions->next;
            if (free_regions != NULL) {
                free_regions->prev = NULL;
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

    return tmp->pointer;
}