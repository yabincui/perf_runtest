targets := one_function \
					 two_functions \
					 function_loop \
					 function_fork \
					 function_pthread \
					 comm_change \

exec_targets := $(addprefix runtest_,$(targets))

all : $(exec_targets)

CFLAGS := -std=c++11
LDFLAGS := -lpthread

runtest_% : %.cpp
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)
	
clean:
	rm -rf *perf.data* *perf.report