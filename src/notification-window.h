/*
 * This file is part of mate-notification-theme-solus
 *
 * Copyright © 2016 Ikey Doherty <ikey@solus-project.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */

#pragma once

#include "engine-api.h"
#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef struct _SolNotificationWindow SolNotificationWindow;
typedef struct _SolNotificationWindowClass SolNotificationWindowClass;

#define SOL_TYPE_NOTIFICATION_WINDOW sol_notification_window_get_type()
#define SOL_NOTIFICATION_WINDOW(o)                                                                 \
        (G_TYPE_CHECK_INSTANCE_CAST((o), SOL_TYPE_NOTIFICATION_WINDOW, SolNotificationWindow))
#define SOL_IS_NOTIFICATION_WINDOW(o)                                                              \
        (G_TYPE_CHECK_INSTANCE_TYPE((o), SOL_TYPE_NOTIFICATION_WINDOW))
#define SOL_NOTIFICATION_WINDOW_CLASS(o)                                                           \
        (G_TYPE_CHECK_CLASS_CAST((o), SOL_TYPE_NOTIFICATION_WINDOW, SolNotificationWindowClass))
#define SOL_IS_NOTIFICATION_WINDOW_CLASS(o)                                                        \
        (G_TYPE_CHECK_CLASS_TYPE((o), SOL_TYPE_NOTIFICATION_WINDOW))
#define SOL_NOTIFICATION_WINDOW_GET_CLASS(o)                                                       \
        (G_TYPE_INSTANCE_GET_CLASS((o), SOL_TYPE_NOTIFICATION_WINDOW, SolNotificationWindowClass))

GtkWidget *sol_notification_window_new(UrlClickedCb url_clicked);

GType sol_notification_window_get_type(void);

void sol_notification_window_set_text(SolNotificationWindow *window, const char *summary,
                                      const char *body);

void sol_notification_window_set_pixbuf(SolNotificationWindow *window, GdkPixbuf *pixbuf);

void sol_notification_window_set_url_callback(SolNotificationWindow *window, UrlClickedCb cb);

void sol_notification_window_add_action(SolNotificationWindow *window, const char *label,
                                        const char *key, GCallback cb);

void sol_notification_window_clear_actions(SolNotificationWindow *window);

void sol_notification_window_set_hints(SolNotificationWindow *window, GHashTable *hints);

G_END_DECLS

/*
 * Editor modelines  -  https://www.wireshark.org/tools/modelines.html
 *
 * Local variables:
 * c-basic-offset: 8
 * tab-width: 8
 * indent-tabs-mode: nil
 * End:
 *
 * vi: set shiftwidth=8 tabstop=8 expandtab:
 * :indentSize=8:tabSize=8:noTabs=true:
 */
