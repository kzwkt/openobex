/*********************************************************************
 *                
 * Filename:      obex_test_cable.h
 * Version:       
 * Description:   
 * Status:        Experimental.
 * Author:        Pontus Fuchs <pontus.fuchs@tactel.se>
 * Created at:    Wed Nov 17 22:05:16 1999
 * Modified at:   Sun Aug 13 10:55:20 PM CEST 2000
 * Modified by:   Pontus Fuchs <pontus.fuchs@tactel.se>
 * 
 *     Copyright (c) 1999, 2000 Pontus Fuchs, All Rights Reserved.
 *      
 *     This library is free software; you can redistribute it and/or
 *     modify it under the terms of the GNU Lesser General Public
 *     License as published by the Free Software Foundation; either
 *     version 2 of the License, or (at your option) any later version.
 *
 *     This library is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *     Lesser General Public License for more details.
 *
 *     You should have received a copy of the GNU Lesser General Public
 *     License along with this library; if not, write to the Free Software
 *     Foundation, Inc., 59 Temple Place, Suite 330, Boston, 
 *     MA  02111-1307  USA
 *     
 ********************************************************************/

#ifndef OBEX_TEST_CABLE_H
#define OBEX_TEST_CABLE_H

#include <glib.h>
#include <termios.h>
#include <openobex/obex.h>

struct cobex_context
{
	const char *portname;
	int ttyfd;
	char inputbuf[500];
	struct termios oldtio, newtio;
	gboolean r320;
};

/* User function */
struct cobex_context *cobex_open(const gchar *port, gboolean r320);
void cobex_close(struct cobex_context *gt);
int cobex_do_at_cmd(int fd, char *cmd, char *rspbuf, int rspbuflen);

/* Callbacks */
gint cobex_handle_input(obex_t *handle, gpointer userdata);
gint cobex_write(obex_t *self, gpointer userdata, guint8 *buffer, gint length);
gint cobex_connect(obex_t *handle, gpointer userdata);
gint cobex_disconnect(obex_t *handle, gpointer userdata);

/* Internally only */
void cobex_cleanup(struct cobex_context *gt, gboolean force);

#endif