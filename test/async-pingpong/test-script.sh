#!/bin/bash

RV=2

DIR=`dirname $0`
cd $DIR
./test -c ./test.conf >/dev/null 2>&1 &
LOOP=5
OUT=""
while [ "$LOOP" -gt 0 -a "x$OUT" = "x" ]; do
	OUT=`curl -s http://127.0.0.1:8888/test`
        if [ -n "$OUT" ]; then
		RV=0
	else
		sleep 1
        fi
        LOOP=$(($LOOP - 1))
done

echo "$OUT"
kill -9 %1
exit $RV
