/*-------------------------------------------------------------------------
 *
 * extended_op_node_utils.h
 *	  General Citus planner code.
 *
 * Copyright (c) 2017, Citus Data, Inc.
 *-------------------------------------------------------------------------
 */

#ifndef EXTENDED_OP_NODE_UTILS_H_
#define EXTENDED_OP_NODE_UTILS_H_

#include "distributed/multi_logical_planner.h"


/*
 * ExtendedOpNodeStats is a helper structure that is used to
 * share the common information among the worker and master extended
 * op nodes.
 *
 * It is designed to be a read-only singleton object per extended op node
 * generation and processing.
 */
typedef struct ExtendedOpNodeStats
{
	bool groupedByDisjointPartitionColumn;
	bool repartitionSubquery;
	bool hasNonPartitionColumnDistinctAgg;
	bool pullDistinctColumns;
	bool pushDownWindowFunctions;
} ExtendedOpNodeStats;


extern ExtendedOpNodeStats BuildExtendedOpNodeStats(MultiExtendedOp *extendedOpNode);


#endif /* EXTENDED_OP_NODE_UTILS_H_ */