include config.mk
include make_helper/helpers.mk

SUB_DIRS := src/alg \
			src/ds \
			src/design_pattern

.PHONY: all clean install update thirdparty

all:
	@for dir in $(SUB_DIRS); do \
		$(MAKE) -C $$dir; \
	done

clean:
	@for dir in $(SUB_DIRS); do \
		$(MAKE) -C $$dir clean; \
	done

distclean:
	@rm -rf $(OUTPUT_DIR)/*

install:

update:

thirdparty: