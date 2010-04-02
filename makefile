DIRLIST = `find . -maxdepth 1 -type d -name 'problem*'`

.PHONY: all
all:
	@for i in $(DIRLIST) ; \
	do \
		make -k -C $$i all ; \
	done

.PHONY: clean
clean:
	@for i in $(DIRLIST) ; \
	do \
		make -k -C $$i clean ; \
	done

