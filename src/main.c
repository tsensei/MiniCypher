#include <gtk/gtk.h>
#include "rot13.h"
#include "asciiToBase64.h"
#include "baseConverter.h"
#include "analyzeText.h"
#include "reverseString.h"
#include "runLengthEncoding.h"
#include "caseConversion.h"

GtkBuilder *builder;

void on_textanalyzer_file_set(){
    char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(gtk_builder_get_object(builder, "textanalyzer_file_chooser")));
    
    char **result = analyzeText(filename);

    GtkEntry *word_count = GTK_ENTRY(gtk_builder_get_object(builder, "word_output"));
    GtkEntry *character_count = GTK_ENTRY(gtk_builder_get_object(builder, "character_output"));
    GtkEntry *line_count = GTK_ENTRY(gtk_builder_get_object(builder, "line_output"));
    GtkEntry *read_time = GTK_ENTRY(gtk_builder_get_object(builder, "read_time_output"));

    gtk_entry_set_text(word_count, result[0]);
    gtk_entry_set_text(character_count, result[1]);
    gtk_entry_set_text(line_count, result[2]);
    gtk_entry_set_text(read_time, result[3]);
    

    for (int i = 0; result[i] != NULL; i++) {
        free(result[i]);
    }
    
    free(result);
}

void on_rle_input_changed(){
    GtkEntry *rle_input = GTK_ENTRY(gtk_builder_get_object(builder, "rle_input"));
    GtkTextView *rle_output = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "rle_output"));

    char *input_text = gtk_entry_get_text(rle_input);
    char *output_text = runLengthEncoding(input_text);

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(rle_output);
    gtk_text_buffer_set_text(buffer, output_text, -1);
}

void on_cc_input_changed() {
    GtkEntry *cc_input = GTK_ENTRY(gtk_builder_get_object(builder, "cc_input"));
    GtkComboBoxText *cc_case_select = GTK_COMBO_BOX_TEXT(gtk_builder_get_object(builder, "cc_case_select"));
    GtkEntry *cc_output = GTK_ENTRY(gtk_builder_get_object(builder, "cc_output"));

    const char *input_text_const = gtk_entry_get_text(cc_input);
    char *input_text = strdup(input_text_const); 
    char *option = gtk_combo_box_text_get_active_text(cc_case_select);

    char *output_text = caseConversion(input_text, option);

    gtk_entry_set_text(cc_output, output_text);

    free(input_text);
    if (output_text != input_text) { 
        free(output_text);
    }
    g_free(option); 
}



void on_reversed_input_change(){
    GtkEntry *reversed_input = GTK_ENTRY(gtk_builder_get_object(builder, "reversed_input"));
    GtkEntry *reversed_output = GTK_ENTRY(gtk_builder_get_object(builder, "reversed_output"));

    char *input_text = gtk_entry_get_text(reversed_input);
    char *output_text = reverse(input_text);

    GtkEntry *palindrome_output = GTK_ENTRY(gtk_builder_get_object(builder, "palindrome_output"));
    if(strcmp(input_text, "") == 0){
        gtk_entry_set_text(palindrome_output, "");
    }else if(strcmp(input_text, output_text) == 0){
        gtk_entry_set_text(palindrome_output, "It is a palindrome !");
    }else{
        gtk_entry_set_text(palindrome_output, "No, it's not a palindrome.");
    }

    gtk_entry_set_text(reversed_output, output_text);
}

int main(int argc, char *argv[])
{
    GtkWidget *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);


    gtk_widget_show(window);                
    gtk_main();

    g_object_unref(builder);
    return 0;
}

void on_window_main_destroy()
{
    gtk_main_quit();
}
