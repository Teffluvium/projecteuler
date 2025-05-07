#--------------------------
DIRLIST = `find src -maxdepth 1 -type d -name 'problem*' | sort`

#--------------------------
-include makefile.common

#--------------------------
.PHONY: all
all:	## Build all targets
	@for i in ${DIRLIST} ; \
	do \
		${MAKE} -k -C $$i ; \
	done

.PHONY: clean
clean:	## Clean all targets
	@for i in ${DIRLIST} ; \
	do \
		${MAKE} -k -C $$i clean ; \
	done

.PHONY: install
install: ## Install all targets
	@mkdir -p ${INSTALLDIR}
	@for i in ${DIRLIST} ; \
	do \
		${MAKE} -k -C $$i install ; \
	done

.PHONY: help
help: 	## Show this help message
	@uv run python -c "import re; \
	[[print(f'\033[36m{m[0]:<20}\033[0m {m[1]}') for m in re.findall(r'^([a-zA-Z_-]+):.*?## (.*)$$', open(makefile).read(), re.M)] for makefile in ('$(MAKEFILE_LIST)').strip().split()]"

.DEFAULT_GOAL := help

