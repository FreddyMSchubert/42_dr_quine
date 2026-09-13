.DEFAULT_GOAL := all

CC := cc
CFLAGS := -Wall -Wextra -Werror
PROGRAMS := Colleen Grace Sully
GREEN := \033[32m
RED := \033[31m
RESET := \033[0m

.NOTPARALLEL:
.PHONY: all build run diff colleen grace sully clean fclean re \
	announce-build announce-run announce-diff \
	run-Colleen run-Grace run-Sully diff-Colleen diff-Grace diff-Sully

all: diff

build: announce-build $(PROGRAMS)

run: build announce-run run-Colleen run-Grace run-Sully

diff: run announce-diff diff-Colleen diff-Grace diff-Sully

announce-build:
	@printf '\nCompiling all programs\n'

announce-run:
	@printf '\nRunning all programs\n'

announce-diff:
	@printf '\nComparing all outputs\n'

$(PROGRAMS): %: %.c
	@printf '  CC  %s\n' $<
	@$(CC) $(CFLAGS) $< -o $@

run-Colleen: Colleen
	@printf '  RUN Colleen\n'
	@./Colleen > Colleen.txt

run-Grace: Grace
	@printf '  RUN Grace\n'
	@./Grace

run-Sully: Sully
	@printf '  RUN Sully\n'
	@rm -f Sully_[0-5] Sully_[0-5].c
	@./Sully

diff-Colleen: run-Colleen
	@printf '  DIFF Colleen.c Colleen.txt\n'
	@if diff -u Colleen.c Colleen.txt; then printf '  $(GREEN)OUTPUT SAME: Colleen$(RESET)\n'; else printf '  $(RED)OUTPUT DIFFERENT: Colleen$(RESET)\n'; fi

diff-Grace: run-Grace
	@printf '  DIFF Grace.c Grace_kid.c\n'
	@if diff -u Grace.c Grace_kid.c; then printf '  $(GREEN)OUTPUT SAME: Grace$(RESET)\n'; else printf '  $(RED)OUTPUT DIFFERENT: Grace$(RESET)\n'; fi

diff-Sully: run-Sully
	@printf '  DIFF Sully.c Sully_5.c\n'
	@if diff -u Sully.c Sully_5.c; then printf '  $(GREEN)OUTPUT SAME: Sully -> Sully_5$(RESET)\n'; else printf '  $(RED)OUTPUT DIFFERENT: Sully -> Sully_5$(RESET)\n'; exit 1; fi

colleen: diff-Colleen

grace: diff-Grace

sully: diff-Sully

clean:
	@rm -f Colleen.txt Grace_kid.c Sully_[0-5] Sully_[0-5].c

fclean: clean
	@rm -f $(PROGRAMS)

re: fclean all
