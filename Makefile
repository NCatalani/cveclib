CXX = gcc
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c99

SOURCE_DIR = ./src/
OUTPUT_DIR = ./out/
TEST_DIR = ./test/
SRC = $(SOURCE_DIR)cveclib.c
OBJ = $(SRC:.c=.o)
OUT = $(OUTPUT_DIR)libcvec.a
TEST = $(TEST_DIR)test

all: $(OUT) $(TEST)

$(OUT): $(OBJ)
	ar rcs $(OUT) $(SOURCE_DIR)cveclib.o
$(OBJ):
	$(CXX) $(CXXFLAGS) -c $(SRC) -o $@
$(TEST):
	$(CXX) $(CXXFLAGS) -o $@ $(TEST_DIR)test.c $(OUT)
clean:
	rm -rf $(OBJ) $(OUT) $(TEST_DIR)test
