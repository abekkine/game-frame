#!/bin/bash
BINFILE=$1
SUPPFILE=$2

valgrind \
    --leak-check=full \
    --track-origins=yes \
    --show-reachable=yes \
    --show-leak-kinds=all \
    --error-limit=no \
    --suppressions=$SUPPFILE \
    --gen-suppressions=all \
    --log-file=valgrind.log \
    $BINFILE

