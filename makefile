#--------------------------
DIRLIST = `find . -maxdepth 1 -type d -name 'problem*' | sort`

#--------------------------
-include makefile.common

#--------------------------
.PHONY: all
all:
	@for i in ${DIRLIST} ; \
	do \
		make -k -C $$i ; \
	done

.PHONY: clean
clean:
	@for i in ${DIRLIST} ; \
	do \
		make -k -C $$i clean ; \
	done

.PHONY: install
install:
	@mkdir -p ${INSTALLDIR}
	@for i in ${DIRLIST} ; \
	do \
		make -k -C $$i install ; \
	done

