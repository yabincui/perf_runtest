#!/bin/bash

set -x
set -e

PERF=nperf

TEST_LIST=(one_function
          two_functions
          function_loop
          function_fork
          function_pthread
          comm_change)

# Run perf record and perf report on a test.
# arg1: PERF executable file.
# arg2: test name.
function run_record_report {
  PERF=$1
  TESTNAME=$2
  # -c seems more stable than -f.
  ${PERF} record -c 100000 -e cpu-cycles:u -o ${PERF}_${TESTNAME}_perf.data ./runtest_${TESTNAME}
  ${PERF} report -i ${PERF}_${TESTNAME}_perf.data >${PERF}_${TESTNAME}_perf.report
}

for test in ${TEST_LIST[@]}; do
  run_record_report perf ${test}
done

for test in ${TEST_LIST[@]}; do
  run_record_report nperf ${test}
done

for test in ${TEST_LIST[@]}; do
  run_record_report simpleperf ${test}
done