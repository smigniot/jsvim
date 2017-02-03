/* Copyright (c) 1990,1991,1992,1993 Chris and John Downey */

/***

* program name:
    xvi
* function:
    Portable version of UNIX "vi" editor, with extensions.
* module name:
    mark.c
* module function:
    Routines to maintain and manipulate marks.
* history:
    STEVIE - ST Editor for VI Enthusiasts, Version 3.10
    Originally by Tim Thompson (twitch!tjt)
    Extensive modifications by Tony Andrews (onecom!wldrdg!tony)
    Heavily modified by Chris & John Downey
    Last modified by Martin Guy

***/

#include "xvi.h"

#ifdef	MEGAMAX
overlay "mark"
#endif

/*
 * A new buffer - initialise it so there are no marks.
 */
void
init_marks(buffer)
Buffer	*buffer;
{
    Mark	*mlist = buffer->b_mlist;
    int	i;

    for (i = 0; i < NMARKS; i++)
	mlist[i].m_name = '\0';

    buffer->b_pcvalid = FALSE;
}

/*
 * setmark(c) - set mark 'c' at current cursor position in given buffer.
 *
 * Returns TRUE on success, FALSE if no room for mark or bad name given.
 */
bool_t
setmark(c, buffer, pos)
int	c;
Buffer	*buffer;
Posn	*pos;
{
    Mark	*mlist = buffer->b_mlist;
    int	i;

    if (!is_alpha((unsigned char) c))
	return(FALSE);

    /*
     * If there is already a mark of this name, then just use the
     * existing mark entry.
     */
    for (i = 0; i < NMARKS; i++) {
	if (mlist[i].m_name == (unsigned char) c) {
	    mlist[i].m_pos = *pos;
	    return(TRUE);
	}
    }

    /*
     * There wasn't a mark of the given name, so find a free slot
     */
    for (i = 0; i < NMARKS; i++) {
	if (mlist[i].m_name == '\0') {	/* got a free one */
	    mlist[i].m_name = c;
	    mlist[i].m_pos = *pos;
	    return(TRUE);
	}
    }
    return(FALSE);
}

/*
 * setpcmark() - set the previous context mark to the current position
 */
void
setpcmark(window)
Xviwin	*window;
{
    window->w_buffer->b_pcmark.m_pos = *(window->w_cursor);
    window->w_buffer->b_pcvalid = TRUE;
}

/*
 * getmark(c) - find mark for char 'c' in given buffer
 *
 * Return pointer to Position or NULL if no such mark.
 * Note that we return a pointer to an internal static structure.
 */
Posn *
getmark(c, buffer)
int	c;
Buffer	*buffer;
{
    static Posn	retpos;
    Mark	*mlist;
    int		i;

    retpos.p_line = NULL;

    /*
     * Previous context mark.
     */
    if (c == '\'' || c == '`') {
	if (buffer->b_pcvalid) retpos = buffer->b_pcmark.m_pos;
    } else for (mlist = buffer->b_mlist, i = 0; i < NMARKS; i++) {
	if (mlist[i].m_name == (unsigned char) c) {
	    retpos = mlist[i].m_pos;
	    break;
	}
    }

    return((retpos.p_line != NULL) ? &retpos : NULL);
}

/*
 * clrmark(line) - clear any marks for 'line'
 *
 * Used any time a line is deleted so we don't have marks pointing to
 * non-existent lines.
 */
void
clrmark(line, buffer)
Line	*line;
Buffer	*buffer;
{
    Mark	*mlist = buffer->b_mlist;
    int	i;

    for (i = 0; i < NMARKS; i++) {
	if (mlist[i].m_pos.p_line == line) {
	    mlist[i].m_name = '\0';
	}
    }
    if (buffer->b_pcvalid && (buffer->b_pcmark.m_pos.p_line == line)) {
	buffer->b_pcvalid = FALSE;
    }
}
