/**
 * @file queue.c
 * @brief Implementation of a queue that supports FIFO and LIFO operations.
 *
 * This queue implementation uses a singly-linked list to represent the
 * queue elements. Each queue element stores a string value.
 *
 * Assignment for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Extended to store strings, 2018
 *
 * TODO: fill in your name and Andrew ID
 * @author XXX <XXX@andrew.cmu.edu>
 */

#include "queue.h"
#include "harness.h"

#include <stdlib.h>
#include <string.h>

#include <stdio.h>

/**
 * @brief Allocates a new queue
 * @return The new queue, or NULL if memory allocation failed
 */
queue_t *queue_new(void) {
    queue_t *q = malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
    if (q) {
        q->head = NULL;
        q->tail = NULL;
        q->queue_size = 0;
    }
    return q;
}

/**
 * @brief Frees all memory used by a queue
 * @param[in] q The queue to free
 */
void queue_free(queue_t *q) {
    /* How about freeing the list elements and the strings? */
    /* Free queue structure */

    if (q) {
        list_ele_t *cur = q->head;
        list_ele_t *prev;

        while (cur) {
            prev = cur;
            cur = cur->next;
            free(prev->value);
            free(prev);
        }
        free(q);
    }
}

/**
 * @brief Attempts to insert an element at head of a queue
 *
 * This function explicitly allocates space to create a copy of `s`.
 * The inserted element points to a copy of `s`, instead of `s` itself.
 *
 * @param[in] q The queue to insert into
 * @param[in] s String to be copied and inserted into the queue
 *
 * @return true if insertion was successful
 * @return false if q is NULL, or memory allocation failed
 */
bool queue_insert_head(queue_t *q, const char *s) {
    list_ele_t *newh;
    char *news;
    size_t length = strlen(s);
    /* What should you do if the q is NULL? */

    if (!q) {
        return false;
    }

    newh = malloc(sizeof(list_ele_t));

    if (!newh) {
        return false;
    }

    news = malloc(length + 1);

    if (!news) {
        free(newh);
        return false;
    }

    strcpy(news, s);

    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */

    newh->value = news;
    newh->next = q->head;
    q->head = newh;

    if (!q->tail) {
        q->tail = newh;
    }

    q->queue_size += 1;

    return true;
}

/**
 * @brief Attempts to insert an element at tail of a queue
 *
 * This function explicitly allocates space to create a copy of `s`.
 * The inserted element points to a copy of `s`, instead of `s` itself.
 *
 * @param[in] q The queue to insert into
 * @param[in] s String to be copied and inserted into the queue
 *
 * @return true if insertion was successful
 * @return false if q is NULL, or memory allocation failed
 */
bool queue_insert_tail(queue_t *q, const char *s) {
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */

    list_ele_t *newh;
    char *news;
    size_t length = strlen(s);
    /* What should you do if the q is NULL? */

    if (!q) {
        return false;
    }

    newh = malloc(sizeof(list_ele_t));

    if (!newh) {
        return false;
    }

    news = malloc(length + 1);

    if (!news) {
        free(newh);
        return false;
    }

    strcpy(news, s);
    newh->value = news;
    newh->next = NULL;

    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */

    if (q->tail) {
        q->tail->next = newh;
        q->tail = newh;
    } else {
        q->head = newh;
        q->tail = newh;
    }

    q->queue_size += 1;
    return true;
}

/**
 * @brief Attempts to remove an element from head of a queue
 *
 * If removal succeeds, this function frees all memory used by the
 * removed list element and its string value before returning.
 *
 * If removal succeeds and `buf` is non-NULL, this function copies up to
 * `bufsize - 1` characters from the removed string into `buf`, and writes
 * a null terminator '\0' after the copied string.
 *
 * @param[in]  q       The queue to remove from
 * @param[out] buf     Output buffer to write a string value into
 * @param[in]  bufsize Size of the buffer `buf` points to
 *
 * @return true if removal succeeded
 * @return false if q is NULL or empty
 */
bool queue_remove_head(queue_t *q, char *buf, size_t bufsize) {
    /* You need to fix up this code. */
    if (q) {
        if (q->head) {
            list_ele_t *old_head = q->head;
            q->head = q->head->next;

            if (!q->head) {
                q->tail = q->head;
            }

            if (buf) {
                strncpy(buf, old_head->value, bufsize - 1);
                buf[bufsize - 1] = '\0';
            }

            q->queue_size -= 1;
            free(old_head->value);
            free(old_head);
            return true;
        }
        return false;
    }

    return false;
}

/**
 * @brief Returns the number of elements in a queue
 *
 * This function runs in O(1) time.
 *
 * @param[in] q The queue to examine
 *
 * @return the number of elements in the queue, or
 *         0 if q is NULL or empty
 */
size_t queue_size(queue_t *q) {
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    if (q) {
        return q->queue_size;
    }

    return 0;
}

/**
 * @brief Reverse the elements in a queue
 *
 * This function does not allocate or free any list elements, i.e. it does
 * not call malloc or free, including inside helper functions. Instead, it
 * rearranges the existing elements of the queue.
 *
 * @param[in] q The queue to reverse
 */
void queue_reverse(queue_t *q) {
    /* You need to write the code for this function */
    if (q) {
        list_ele_t *next = NULL;
        list_ele_t *cur = q->head;
        while (cur) {
            list_ele_t *temp = cur->next;
            cur->next = next;
            next = cur;
            cur = temp;
        }

        list_ele_t *temp = q->head;
        q->head = q->tail;
        q->tail = temp;
    }
}
