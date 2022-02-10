/**
  Copyright (c) 2022 Vicente Romero Calero. All rights reserved.
  Licensed under the MIT License.
  See LICENSE file in the project root for full license information.
 */
#include <stdarg.h>

#include "internals.h"

int vtenc_init(vtenc *handler)
{
  handler->params.allow_repeated_values = 1;
  handler->params.skip_full_subtrees    = 1;
  handler->params.min_cluster_length    = 1;
  handler->out_size                     = 0;

  return VTENC_OK;
}

int vtenc_config(vtenc *handler, int op, ...)
{
  va_list ap;
  int rc = VTENC_OK;

  va_start(ap, op);

  switch (op) {
    case VTENC_CONFIG_ALLOW_REPEATED_VALUES: {
      handler->params.allow_repeated_values = va_arg(ap, int);
      break;
    }
    case VTENC_CONFIG_SKIP_FULL_SUBTREES: {
      handler->params.skip_full_subtrees = va_arg(ap, int);
      break;
    }
    case VTENC_CONFIG_MIN_CLUSTER_LENGTH: {
      handler->params.min_cluster_length = va_arg(ap, size_t);
      break;
    }
    default: {
      rc = VTENC_ERR_CONFIG;
      break;
    }
  }

  va_end(ap);

  return rc;
}

