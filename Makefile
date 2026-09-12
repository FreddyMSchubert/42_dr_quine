.DEFAULT_GOAL := all

TARGETS := all build run diff colleen coline grace clean fclean re

.PHONY: $(TARGETS)

$(TARGETS):
	@$(MAKE) --no-print-directory -C C $@
