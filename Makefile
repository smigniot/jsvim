all:
	(cd xvi-2.50.3 && $(MAKE) \
		all)

clean:
	(cd xvi-2.50.3 && $(MAKE) \
		clean)

ctags:
	/opt/local/bin/ctags -R \
		xvi-2.50.3/src/*.c \
		xvi-2.50.3/src/jsvim* \
		terminal.js \
		jsvim* \
		jsxvi*

