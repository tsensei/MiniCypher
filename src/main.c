#include <gtk/gtk.h>
#include "rot.h"
#include "baseConverter.h"
#include "analyzeText.h"
#include "reverseString.h"
#include "runLengthEncoding.h"
#include "caseConversion.h"
#include "morseCodeEncoding.h"
#include "urlEncode.h"
#include "urlDecode.h"
#include "vigenereEncrypt.h"
#include "vigenereDecrypt.h"
#include "XORcipher.h"
#include "railFence.h"
#include "randomPass.h"
#include "romanToDecimal.h"
#include "decimalToRoman.h"
#include "binaryToGrayCode.h"
#include "grayToBinary.h"
#include "bitwiseAND_OR_NOT.h"


GtkBuilder *builder;

void on_base_conversion_input_changed(){
    GtkEntry *base_conversion_input = GTK_ENTRY(gtk_builder_get_object(builder, "base_conversion_text_input"));
    GtkEntry *base_conversion_output = GTK_ENTRY(gtk_builder_get_object(builder, "base_conversion_text_output"));
    GtkComboBoxText *base_conversion_from = GTK_COMBO_BOX_TEXT(gtk_builder_get_object(builder, "base_conversion_combo_input"));
    GtkComboBoxText *base_conversion_to = GTK_COMBO_BOX_TEXT(gtk_builder_get_object(builder, "base_conversion_combo_output"));

    const char *input_text_const = gtk_entry_get_text(base_conversion_input);
    char *input_text = strdup(input_text_const); 

    char *from = gtk_combo_box_text_get_active_text(base_conversion_from);
    char *to = gtk_combo_box_text_get_active_text(base_conversion_to);

    Converter converter;

    initConverter(&converter, input_text, from);

    char *output_text;

    if (strcmp(to, "decimal") == 0) {
        output_text = converter.toDecimal(&converter);
    } else if (strcmp(to, "binary") == 0) {
        output_text = converter.toBinary(&converter);
    } else if (strcmp(to, "octal") == 0) {
        output_text = converter.toOctal(&converter);
    } else if (strcmp(to, "hexadecimal") == 0) {
        output_text = converter.toHexadecimal(&converter);
    }


    gtk_entry_set_text(base_conversion_output, output_text);

    // free(input_text);

    // if (output_text != input_text) { 
    //     free(output_text);
    // }

    // g_free(from); 
    // g_free(to); 
}

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

void on_vignere_encrypt_input_changed(){
    GtkEntry *vignere_encrypt_input = GTK_ENTRY(gtk_builder_get_object(builder, "vignere_encrypt_text_input"));
    GtkEntry *vignere_encrypt_key = GTK_ENTRY(gtk_builder_get_object(builder, "vignere_encrypt_key_input"));
    GtkEntry *vignere_encrypt_output = GTK_ENTRY(gtk_builder_get_object(builder, "vignere_encrypt_output"));

    const char *input_text = gtk_entry_get_text(vignere_encrypt_input);
    const char *key_text = gtk_entry_get_text(vignere_encrypt_key);

    char *output_text = vigenereEncrypt(input_text, key_text);

    gtk_entry_set_text(vignere_encrypt_output, output_text);
}

void on_vignere_decrypt_input_changed(){
    GtkEntry *vignere_decrypt_input = GTK_ENTRY(gtk_builder_get_object(builder, "vignere_decrypt_text_input"));
    GtkEntry *vignere_decrypt_key = GTK_ENTRY(gtk_builder_get_object(builder, "vignere_decrypt_key_input"));
    GtkEntry *vignere_decrypt_output = GTK_ENTRY(gtk_builder_get_object(builder, "vignere_decrypt_output"));

    const char *input_text = gtk_entry_get_text(vignere_decrypt_input);
    const char *key_text = gtk_entry_get_text(vignere_decrypt_key);

    char *output_text = vigenereDecrypt(input_text, key_text);

    gtk_entry_set_text(vignere_decrypt_output, output_text);
}

void on_xor_encrypt_input_changed(){
    GtkEntry *xor_encrypt_input = GTK_ENTRY(gtk_builder_get_object(builder, "xor_encrypt_text_input"));
    GtkEntry *xor_encrypt_key = GTK_ENTRY(gtk_builder_get_object(builder, "xor_encrypt_key_input"));
    GtkEntry *xor_encrypt_output = GTK_ENTRY(gtk_builder_get_object(builder, "xor_encrypt_output"));

    const char *input_text = gtk_entry_get_text(xor_encrypt_input);
    const char *key_text = gtk_entry_get_text(xor_encrypt_key);

    char *output_text = xorcipher(input_text, key_text[0]);

    gtk_entry_set_text(xor_encrypt_output, output_text);
}

void on_xor_decrypt_input_changed(){
    GtkEntry *xor_decrypt_input = GTK_ENTRY(gtk_builder_get_object(builder, "xor_decrypt_text_input"));
    GtkEntry *xor_decrypt_key = GTK_ENTRY(gtk_builder_get_object(builder, "xor_decrypt_key_input"));
    GtkEntry *xor_decrypt_output = GTK_ENTRY(gtk_builder_get_object(builder, "xor_decrypt_output"));

    const char *input_text = gtk_entry_get_text(xor_decrypt_input);
    const char *key_text = gtk_entry_get_text(xor_decrypt_key);

    char *output_text = xorcipher(input_text, key_text[0]);

    gtk_entry_set_text(xor_decrypt_output, output_text);
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

void on_railfence_encrypt_input_changed(){
    GtkEntry *railfence_encrypt_input = GTK_ENTRY(gtk_builder_get_object(builder, "railfence_encrypt_text_input"));
    GtkEntry *railfence_encrypt_key = GTK_ENTRY(gtk_builder_get_object(builder, "railfence_encrypt_key_input"));
    GtkEntry *railfence_encrypt_output = GTK_ENTRY(gtk_builder_get_object(builder, "railfence_encrypt_output"));

    const char *input_text = gtk_entry_get_text(railfence_encrypt_input);
    const char *key_text = gtk_entry_get_text(railfence_encrypt_key);
    int key = atoi(key_text); // Convert key_text to an integer

    char *output_text = railFenceEncrypt(input_text, key); // Call the correct function

    if (output_text) {
        gtk_entry_set_text(railfence_encrypt_output, output_text);
        free(output_text); // Free the dynamically allocated output_text
    } else {
        gtk_entry_set_text(railfence_encrypt_output, "Error: Invalid input or key");
    }
}

void on_railfence_decrypt_input_changed(){
    GtkEntry *railfence_decrypt_input = GTK_ENTRY(gtk_builder_get_object(builder, "railfence_decrypt_text_input"));
    GtkEntry *railfence_decrypt_key = GTK_ENTRY(gtk_builder_get_object(builder, "railfence_decrypt_key_input"));
    GtkEntry *railfence_decrypt_output = GTK_ENTRY(gtk_builder_get_object(builder, "railfence_decrypt_output"));

    const char *input_text = gtk_entry_get_text(railfence_decrypt_input);
    const char *key_text = gtk_entry_get_text(railfence_decrypt_key);
    int key = atoi(key_text); // Convert key_text to an integer

    char *output_text = railFenceDecrypt(input_text, key); // Correctly call railFenceEncrypt

    if (output_text) {
        gtk_entry_set_text(railfence_decrypt_output, output_text);
        free(output_text); // Free the dynamically allocated output_text
    } else {
        // Handle error or invalid input
        gtk_entry_set_text(railfence_decrypt_output, "Error: Invalid input or key");
    }
}

void on_random_password_button_clicked(){
    // get the value from GtkSpinButton with id random_password_input and convert to integer
    GtkSpinButton *random_password_input = GTK_SPIN_BUTTON(gtk_builder_get_object(builder, "random_password_input"));
    int length = gtk_spin_button_get_value_as_int(random_password_input);

    char *password = randomPass(length);

    GtkEntry *random_password_output = GTK_ENTRY(gtk_builder_get_object(builder, "random_password_output"));
    gtk_entry_set_text(random_password_output, password);
}

void on_dtor_input_changed(){
    GtkEntry *dtor_input = GTK_ENTRY(gtk_builder_get_object(builder, "dtor_input"));
    GtkEntry *dtor_output = GTK_ENTRY(gtk_builder_get_object(builder, "dtor_output"));

    const char *input_text = gtk_entry_get_text(dtor_input);

    // Convert input_text to an integer and call decimalToRoman
    int input = atoi(input_text);

    char *output_text = decimalToRoman(input);

    gtk_entry_set_text(dtor_output, output_text);
}

void on_rtod_input_changed(){
    GtkEntry *rtod_input = GTK_ENTRY(gtk_builder_get_object(builder, "rtod_input"));
    GtkEntry *rtod_output = GTK_ENTRY(gtk_builder_get_object(builder, "rtod_output"));

    const char *input_text = gtk_entry_get_text(rtod_input);

    // Call romanToDecimal
    long int output = romanToDecimal(input_text);

    char output_text[100];
    sprintf(output_text, "%ld", output);

    gtk_entry_set_text(rtod_output, output_text);
}

void on_btog_input_changed(){
    GtkEntry *btog_input = GTK_ENTRY(gtk_builder_get_object(builder, "btog_input"));
    GtkEntry *btog_output = GTK_ENTRY(gtk_builder_get_object(builder, "btog_output"));

    const char *input_text = gtk_entry_get_text(btog_input);

    unsigned long long int input = strtoull(input_text, NULL, 10);

    unsigned long long int output = binaryToGrayCode(input);

    char output_text[100];

    sprintf(output_text, "%llu", output);

    gtk_entry_set_text(btog_output, output_text);
}

void on_gtob_input_changed(){
    // Gray to binary
    GtkEntry *gtob_input = GTK_ENTRY(gtk_builder_get_object(builder, "gtob_input"));
    GtkEntry *gtob_output = GTK_ENTRY(gtk_builder_get_object(builder, "gtob_output"));

    const char *input_text = gtk_entry_get_text(gtob_input);

    char *output_text = grayToBinary(input_text);

    gtk_entry_set_text(gtob_output, output_text);
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

void on_rle_input_changed(){
    GtkEntry *rle_input = GTK_ENTRY(gtk_builder_get_object(builder, "rle_input"));
    GtkTextView *rle_output = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "rle_output"));

    char *input_text = gtk_entry_get_text(rle_input);
    char *output_text = runLengthEncoding(input_text);

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(rle_output);
    gtk_text_buffer_set_text(buffer, output_text, -1);
}

void on_atom_ascii_input_changed(){
    GtkEntry *ascii_input = GTK_ENTRY(gtk_builder_get_object(builder, "atom_ascii_input"));
    GtkTextView *morse_output = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "atom_morse_output"));


    char *input_text = gtk_entry_get_text(ascii_input);
    char *output_text = asciiToMorse(input_text);

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(morse_output);
    gtk_text_buffer_set_text(buffer, output_text, -1);
}

void on_mtoa_morse_input_changed(){
    GtkEntry *morse_input = GTK_ENTRY(gtk_builder_get_object(builder, "mtoa_morse_input"));
    GtkTextView *ascii_output = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "mtoa_ascii_output"));

    char *input_text = gtk_entry_get_text(morse_input);
    char *output_text = morseToAscii(input_text);

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(ascii_output);
    gtk_text_buffer_set_text(buffer, output_text, -1);
}

void on_rot_input_changed(){
    GtkEntry *rot_input = GTK_ENTRY(gtk_builder_get_object(builder, "rot_text_input"));
    GtkEntry *rot_key = GTK_ENTRY(gtk_builder_get_object(builder, "rot_key_input"));
    GtkEntry *rot_output = GTK_ENTRY(gtk_builder_get_object(builder, "rot_output"));

    const char *input_text = gtk_entry_get_text(rot_input);
    const char *key_text = gtk_entry_get_text(rot_key);

    int key = 0;
    char *endptr;

    key = strtol(key_text, &endptr, 10);

    if (key_text == endptr || *endptr != '\0') {
        gtk_entry_set_text(rot_output, "Error: Key must be a number");
        return;
    }

    char *output_text = rot(input_text, key);

    gtk_entry_set_text(rot_output, output_text);

}

void on_url_encode_input_changed(){
    GtkEntry *url_encode_input = GTK_ENTRY(gtk_builder_get_object(builder, "url_encode_input"));
    GtkEntry *url_encode_output = GTK_ENTRY(gtk_builder_get_object(builder, "url_encode_output"));

    char *input_text = gtk_entry_get_text(url_encode_input);
    char *output_text = urlEncode(input_text);

    gtk_entry_set_text(url_encode_output, output_text);
}

void on_url_decode_input_changed(){
    GtkEntry *url_decode_input = GTK_ENTRY(gtk_builder_get_object(builder, "url_decode_input"));
    GtkEntry *url_decode_output = GTK_ENTRY(gtk_builder_get_object(builder, "url_decode_output"));

    char *input_text = gtk_entry_get_text(url_decode_input);
    char *output_text = urlDecode(input_text);

    gtk_entry_set_text(url_decode_output, output_text);
}

void on_bitwise_input_changed(){
    // get the bitwise_first_input, bitwise_second_input and convert it int
    GtkEntry *bitwise_first_input = GTK_ENTRY(gtk_builder_get_object(builder, "bitwise_first_input"));
    GtkEntry *bitwise_second_input = GTK_ENTRY(gtk_builder_get_object(builder, "bitwise_second_input"));

    const char *first_input_text = gtk_entry_get_text(bitwise_first_input);
    const char *second_input_text = gtk_entry_get_text(bitwise_second_input);

    int first_input = atoi(first_input_text);
    int second_input = atoi(second_input_text);

    int and_result = bitwiseAND(first_input, second_input);
    int or_result = bitwiseOR(first_input, second_input);
    int not_result = bitwiseNOT(first_input);

    char and_result_text[100];
    char or_result_text[100];
    char not_result_text[100];

    sprintf(and_result_text, "%d", and_result);
    sprintf(or_result_text, "%d", or_result);
    sprintf(not_result_text, "%d", not_result);

    GtkEntry *bitwise_and_output = GTK_ENTRY(gtk_builder_get_object(builder, "bitwise_and_output"));
    GtkEntry *bitwise_or_output = GTK_ENTRY(gtk_builder_get_object(builder, "bitwise_or_output"));
    GtkEntry *bitwise_not_output = GTK_ENTRY(gtk_builder_get_object(builder, "bitwise_not_output"));

    gtk_entry_set_text(bitwise_and_output, and_result_text);
    gtk_entry_set_text(bitwise_or_output, or_result_text);
    gtk_entry_set_text(bitwise_not_output, not_result_text);


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
