# Detecting OS
UNAME_S=$(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CC=g++-4.8
    GTEST_LL=-I /usr/local/opt/gtest/include/ -lgtest_main -lpthread
else
    ifeq ($(UNAME_S),Darwin)
        CC=g++
        GTEST_LL=-I /usr/local/opt/gtest/include/ -L /usr/local/opt/gtest/lib/ -lgtest_main -lgtest -lpthread
    else
        CC=g++
        GTEST_LL=-I /usr/local/opt/gtest/include/ -L /usr/local/lib/ -lgtest_main -lgtest -lpthread
    endif
endif

# Directories
HEADER_DIR = .
BIN_DIR = bin
TEST_DIR = .

# Compiler flags
CPPFLAGS = -Wall -g -I$(HEADER_DIR) -std=c++11
GTEST_CPPFLAGS = -Wall -g -I$(HEADER_DIR) -Wextra -pthread -std=gnu++0x

# rule to ensure the $(bin_dir) directory exist or it'll create it.
$(BIN_DIR)/.dirstamp:
	-@mkdir -p $(BIN_DIR) && touch $@

$(BIN_DIR)/merge_sort_test: $(BIN_DIR)/.dirstamp merge_sort_test.cpp
	$(CC) $(GTEST_CPPFLAGS) merge_sort_test.cpp $(GTEST_LL) -o $@

# Phoney targets
.PHONY: clean
.PHONY: tests

tests: $(BIN_DIR)/merge_sort_test
	-@$(BIN_DIR)/merge_sort_test
	-@echo "--- All Tested!---"

clean:
	-@rm -rf $(BIN_DIR)
	-@echo "--- All Clean!---"
