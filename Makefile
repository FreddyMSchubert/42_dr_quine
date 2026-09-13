.DEFAULT_GOAL := all

TARGETS := all build run diff colleen grace sully clean fclean re

.PHONY: $(TARGETS)

$(TARGETS):
	@$(MAKE) --no-print-directory -C C $@
