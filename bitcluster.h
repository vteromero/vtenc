/**
  Copyright (c) 2019-2020 Vicente Romero Calero. All rights reserved.
  Licensed under the MIT License.
  See LICENSE file in the project root for full license information.
 */
#ifndef VTENC_BITCLUSTER_H_
#define VTENC_BITCLUSTER_H_

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

struct BitCluster {
  size_t from;
  size_t length;
  unsigned int bit_pos;
};

/**
 * BitClusterStack is a LIFO stack with a fixed maximum size.
 */
struct BitClusterStack {
  struct BitCluster *start;
  struct BitCluster *end;
  struct BitCluster *head;
};

static struct BitClusterStack *bclstack_new(size_t max_size)
{
  struct BitClusterStack *s = (struct BitClusterStack *) malloc(sizeof(struct BitClusterStack));
  if (s == NULL) return NULL;

  s->start = (struct BitCluster *) malloc(max_size * sizeof(struct BitCluster));
  if (s->start == NULL) {
    free(s);
    return NULL;
  }

  s->end = s->start + max_size;
  s->head = s->start;

  return s;
}

static inline void bclstack_free(struct BitClusterStack **s)
{
  free((*s)->start);
  free(*s);
}

static inline int bclstack_empty(struct BitClusterStack *s)
{
  return s->head == s->start;
}

static inline size_t bclstack_length(struct BitClusterStack *s)
{
  return s->head - s->start;
}

static inline void bclstack_put(struct BitClusterStack *s, size_t cl_from,
  size_t cl_len, unsigned int bit_pos)
{
  assert(s->head < s->end);

  *(s->head++) = (struct BitCluster) {
    .from = cl_from,
    .length = cl_len,
    .bit_pos = bit_pos
  };
}

static inline struct BitCluster *bclstack_get(struct BitClusterStack *s)
{
  if (bclstack_empty(s)) return NULL;

  return --s->head;
}

/**
 * BitClusterQueue is a FIFO queue with a fixed maximum size. It is implemented
 * as a circular queue so that no extra re-allocations are required.
 */
struct BitClusterQueue {
  struct BitCluster *start;
  struct BitCluster *end;
  struct BitCluster *back;
  struct BitCluster *front;
};

static struct BitClusterQueue *bclqueue_new(size_t max_size)
{
  struct BitClusterQueue *q = NULL;
  size_t alloc_size = max_size + 1;

  assert(max_size > 0);

  q = (struct BitClusterQueue *) malloc(sizeof(struct BitClusterQueue));
  if (q == NULL) return NULL;

  q->start = (struct BitCluster *) malloc(alloc_size * sizeof(struct BitCluster));
  if (q->start == NULL) {
    free(q);
    return NULL;
  }

  q->end = q->start + alloc_size;
  q->back = q->start;
  q->front = q->start;

  return q;
}

static inline void bclqueue_free(struct BitClusterQueue **q)
{
  free((*q)->start);
  free(*q);
}

static inline size_t bclqueue_length(struct BitClusterQueue *q)
{
  if (q->front < q->back) {
    return (q->end - q->back) + (q->front - q->start);
  } else {
    return q->front - q->back;
  }
}

static inline int bclqueue_empty(struct BitClusterQueue *q)
{
  return q->front == q->back;
}

static inline void bclqueue_put(struct BitClusterQueue *q, size_t cl_from,
  size_t cl_len, unsigned int bit_pos)
{
  *(q->front) = (struct BitCluster) {
    .from = cl_from,
    .length = cl_len,
    .bit_pos = bit_pos
  };

  q->front = (++q->front == q->end) ? q->start : q->front;

  assert(q->front != q->back);
}

static inline struct BitCluster *bclqueue_get(struct BitClusterQueue *q)
{
  struct BitCluster *cluster = NULL;

  if (bclqueue_empty(q)) return NULL;

  cluster = q->back;
  q->back = (++q->back == q->end) ? q->start : q->back;

  return cluster;
}

#endif /* VTENC_BITCLUSTER_H_ */
