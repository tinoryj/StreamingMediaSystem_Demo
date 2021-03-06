TARGET_EXEC = segmenter
BUILD_DIR = ./build
SRC_DIRS = ./
LIB_DIR = ./lib

CC = gcc
CXX = gcc

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.cc)
OBJS := $(SRCS:$(SRC_DIRS)/%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(LIB_DIR) -type d -and -name *include)
INC_LIB := $(shell find $(LIB_DIR) -name *.a)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
INC_FLAGS += $(INC_LIB)

CPPFLAGS = -g -O3 -Wall 
LDFLAGS = -lavformat -lavcodec -lavutil

all: $(TARGET_EXEC)

$(TARGET_EXEC): $(OBJS)
	$(eval FILTER := $(filter-out $@, $(TARGET_EXEC)))
# hard code
	$(eval TAR_DEPS := $(filter-out $(addsuffix .cc.o, $(addprefix %, $(FILTER))), $(OBJS))) 
	$(CXX) $(TAR_DEPS) -o $@  $(INC_FLAGS) $(LDFLAGS) 

# c source
$(BUILD_DIR)/%.c.o: $(SRC_DIRS)/%.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS)  -c $< -o $@ $(LDFLAGS)

# c++ source
$(BUILD_DIR)/%.cpp.o: $(SRC_DIRS)/%.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS)  -c $< -o $@ $(INC_FLAGS) $(LDFLAGS) 
$(BUILD_DIR)/%.cc.o: $(SRC_DIRS)/%.cc
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS)  -c $< -o $@ $(INC_FLAGS) $(LDFLAGS)

.PHONY: all clean 

clean:
#	$(RM) -r $(BUILD_DIR)
	# hard code 
	$(RM) -r $(OUTPUT_DIRS)
	$(RM) $(TARGET_EXEC)

-include $(DEPS)

MKDIR_P = mkdir -p

