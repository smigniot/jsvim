#ifndef ERR
# define ERR (-1)
#endif

#ifndef JSVIM_TERM_H
# define JSVIM_TERM_H

int tputs(const char *str, int affcnt, int (*putc)(int));
int tgetflag(char *id);
int tgetent(char *bp, const char *name);
int tgetnum(char *id);
char *tgetstr(char *id, char **area);
char *tgoto(char *cap, int col, int row);
int kbgetc();

#endif

