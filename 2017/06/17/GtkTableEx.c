#include <gtk/gtk.h>
int main(int argc, char *argv[]) {
    int i;
    int j;
    int pos = 0;
    GtkWidget *window;
    GtkWidget *table;
    GtkWidget *button;
    gchar *values[20] = { "7", "8", "9", "/", "~",
			  "4", "5", "6", "*", "!",
			  "1", "2", "3", "-", "@",
			  "0", ".", "=", "+", "#"
    };
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    gtk_window_set_title(GTK_WINDOW(window), "GtkTable");
    gtk_container_set_border_width(GTK_CONTAINER(window), 5);
    table = gtk_table_new(4, 5, TRUE);
    gtk_table_set_row_spacings(GTK_TABLE(table), 1);
    gtk_table_set_col_spacings(GTK_TABLE(table), 1);
    for (i = 0; i < 4; i++) {
	for (j = 0; j < 5; j++) {
	    button = gtk_button_new_with_label(values[pos]);
	    gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);
	    pos++;
	}
    }
    gtk_container_add(GTK_CONTAINER(window), table);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
