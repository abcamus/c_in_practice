ifneq ($(LIB),)
PREFIX := $(LIB)
else
ifneq ($(BIN),)
PREFIX := $(BIN)
endif
endif

LOCAL_OUTPUT_DIR := $(OUTPUT_DIR)/$(PREFIX)
OBJS := $(patsubst %.c, %.o, $(filter %.c, $(SRC)))
OBJS += $(patsubst %.cpp, %.o, $(filter %.cpp, $(SRC)))
OBJS := $(addprefix $(LOCAL_OUTPUT_DIR)/, $(OBJS))
DEPS := $(patsubst %.c, %.d, $(filter %.c, $(SRC)))
DEPS += $(patsubst %.cpp, %.d, $(filter %.cpp, $(SRC)))
DEPS := $(addprefix $(LOCAL_OUTPUT_DIR)/, $(DEPS))
INC_DIRS ?= inc include
INCLUDE := $(addprefix -I, $(INC_DIRS))
CFLAGS := $(INCLUDE)
CXXFLAGS := -std=c++11 $(CFLAGS)
LDFLAGS := $(LINKER_FLAGS) -lstdc++
RM := rm -rf

.PHONY: build clean depends

ifneq ($(LIB),)
TARGET := $(LOCAL_OUTPUT_DIR)/lib$(LIB).so
CFLAGS += -fpic
LDFLAGS += -shared
endif
ifneq ($(BIN),)
TARGET := $(LOCAL_OUTPUT_DIR)/$(BIN)
endif

build: $(TARGET)

$(TARGET): $(OBJS) | $(LOCAL_OUTPUT_DIR)
	@echo "Building target $@"
	@$(CC) $(OBJS) $(LDFLAGS) -o $@
	@echo "Build $(TARGET) done"

$(LOCAL_OUTPUT_DIR):
	@echo "make dir"
	@mkdir -p $@

# vpath %.cpp $(SRC_DIRS)

$(LOCAL_OUTPUT_DIR)/%.o:%.cpp | $(LOCAL_OUTPUT_DIR)
	@echo "Compiling $<"
	@$(CC) $(CXXFLAGS) -c $< -o $@

$(LOCAL_OUTPUT_DIR)/%.o:%.c | $(LOCAL_OUTPUT_DIR)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LOCAL_OUTPUT_DIR)/%.d:%.cpp | $(LOCAL_OUTPUT_DIR)
	@echo "make depends of $<"
	@$(CC) $(CXXFLAGS) -MM $< > $@

$(LOCAL_OUTPUT_DIR)/%.d:%.c | $(LOCAL_OUTPUT_DIR)
	@echo "make depends of $<"
	@$(CC) $(CFLAGS) -MM $< > $@

clean:
	@-$(RM) $(OBJS) $(LOCAL_OUTPUT_DIR)/* $(DEPS)

-include $(DEPS)