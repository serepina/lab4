#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>

typedef struct _Data Data;
struct _Data {
	GtkWidget *window;
	GtkWidget *bnum9;
	GtkWidget *bnum8;
	GtkWidget *bnum7;
	GtkWidget *bnum6;
	GtkWidget *bnum5;
	GtkWidget *bnum4;
	GtkWidget *bnum3;
	GtkWidget *bnum2;
	GtkWidget *bnum1;
	GtkWidget *bnum0;
	GtkWidget *badd;
	GtkWidget *bclear;
	GtkWidget *bsub;
	GtkWidget *bresult;
	GtkWidget *bdiv;
	GtkWidget *bmul;
	GtkWidget *textview1;            
	GtkTextBuffer *textbuffer1;
}; 

//char *text = (char *)malloc(sizeof(char)*50);
char text[50] = "\0";
int cal = 0;
int num1;
int num2;

G_MODULE_EXPORT void quit(GtkWidget *window, gpointer data) {
	gtk_main_quit ();
}

G_MODULE_EXPORT void on_bnum9_clicked(GtkButton *button, Data *data) {
	strcat(text,"9\0");
	gtk_text_buffer_set_text(data->textbuffer1, text, -1);
}

G_MODULE_EXPORT void on_bnum8_clicked(GtkButton *button, Data *data) {
	strcat(text,"8\0");
	gtk_text_buffer_set_text(data->textbuffer1, text, -1);
}

G_MODULE_EXPORT void on_bnum7_clicked(GtkButton *button, Data *data) {
	strcat(text,"7\0");
	gtk_text_buffer_set_text(data->textbuffer1, text, -1);
}

G_MODULE_EXPORT void on_bnum6_clicked(GtkButton *button, Data *data) {
	strcat(text,"6\0");
	gtk_text_buffer_set_text(data->textbuffer1, text, -1);
}

G_MODULE_EXPORT void on_bnum5_clicked(GtkButton *button, Data *data) {
	strcat(text,"5\0");
	gtk_text_buffer_set_text(data->textbuffer1, text, -1);
}


G_MODULE_EXPORT void on_bnum4_clicked(GtkButton *button, Data *data) {
	strcat(text,"4\0");
	gtk_text_buffer_set_text(data->textbuffer1, text, -1);
}

G_MODULE_EXPORT void on_bnum3_clicked(GtkButton *button, Data *data) {
	strcat(text,"3\0");
	gtk_text_buffer_set_text(data->textbuffer1, text, -1);
}

G_MODULE_EXPORT void on_bnum2_clicked(GtkButton *button, Data *data) {
	strcat(text,"2\0");
	gtk_text_buffer_set_text(data->textbuffer1, text, -1);
}

G_MODULE_EXPORT void on_bnum1_clicked(GtkButton *button, Data *data) {
	strcat(text,"1\0");
	gtk_text_buffer_set_text(data->textbuffer1, text, -1);
}

G_MODULE_EXPORT void on_bnum0_clicked(GtkButton *button, Data *data) {
	strcat(text,"0\0");
	gtk_text_buffer_set_text(data->textbuffer1, text, -1);
}

G_MODULE_EXPORT void on_badd_clicked(GtkButton *button, Data *data) {
	num1 = atoi(text);
	cal = 1;
	printf("%d %d", num1, cal);
	strcat(text,"+\0");
	gtk_text_buffer_set_text(data->textbuffer1, text, -1);
}


G_MODULE_EXPORT void on_bsub_clicked(GtkButton *button, Data *data) {
	num1 = atoi(text);
	cal = 2;
	strcat(text,"-\0");
	gtk_text_buffer_set_text(data->textbuffer1, text, -1);
}

G_MODULE_EXPORT void on_bmul_clicked(GtkButton *button, Data *data) {
	num1 = atoi(text);
	cal = 3;
	strcat(text,"*\0");
	gtk_text_buffer_set_text(data->textbuffer1, text, -1);
}

G_MODULE_EXPORT void on_bdiv_clicked(GtkButton *button, Data *data) {
	num1 = atoi(text);
	cal = 4;
	strcat(text,"/\0");
	gtk_text_buffer_set_text(data->textbuffer1, text, -1);
}

G_MODULE_EXPORT void on_bclear_clicked(GtkButton *button, Data *data) {
	strcpy(text,"\0");
	cal = 0;
	gtk_text_buffer_set_text(data->textbuffer1, text, -1);
}

G_MODULE_EXPORT void on_bresult_clicked(GtkButton *button, Data *data) {
	char result[20] = "\0";
	char *ptr;
	char stext[50] = "/0";
	strcpy(stext,text);
	if(cal == 1){
		ptr = strtok(stext, "+");
		ptr = strtok(NULL, "+");
		num2 = atoi(ptr);
		sprintf(result, "%d", num1+num2);
	}
	if(cal == 2){
		ptr = strtok(stext, "-");
		ptr = strtok(NULL, "-");
		num2 = atoi(ptr);
		sprintf(result, "%d", num1-num2);
	}
	if(cal == 3){
		ptr = strtok(stext, "*");
		ptr = strtok(NULL, "*");
		num2 = atoi(ptr);
		sprintf(result, "%d", num1*num2);
	}
	if(cal == 4){
		ptr = strtok(stext, "/");
		ptr = strtok(NULL, "/");
		num2 = atoi(ptr);
		sprintf(result, "%d", (int)num1/num2);
	}
	strcat(text,"=\0");
	strcat(text,result);
	gtk_text_buffer_set_text(data->textbuffer1, text, -1);
}


int main (int argc, char *argv[]) { 
	GtkBuilder *builder;
	GError *error = NULL;
	Data *data; 
	gtk_init (&argc, &argv);
	const char *input_ip = (const char *)malloc(20);
	const char *input_port = (const char *)malloc(20);
	const char *input_name = (const char *)malloc(20);
	const char *input_connect = (const char *)malloc(20);

	/* 빌더 생성 및 UI 파일 열기 */
	builder = gtk_builder_new ();
	if (!gtk_builder_add_from_file (builder, "cal.xml", &error)) {
		g_print ("UI 파일을 읽을 때 오류 발생!\n");
		g_print ("메시지: %s\n", error->message);
		g_free (error);
		return (1);
	} 
	data = g_slice_new (Data);
	data->window = GTK_WIDGET(gtk_builder_get_object(builder, "window_cal"));
	data->bnum9 = GTK_WIDGET(gtk_builder_get_object(builder, "bnum9"));
	data->bnum8 = GTK_WIDGET(gtk_builder_get_object(builder, "bnum8"));
	data->bnum7 = GTK_WIDGET(gtk_builder_get_object(builder, "bnum7"));
	data->bnum6 = GTK_WIDGET(gtk_builder_get_object(builder, "bnum6"));
	data->bnum5 = GTK_WIDGET(gtk_builder_get_object(builder, "bnum5"));
	data->bnum4 = GTK_WIDGET(gtk_builder_get_object(builder, "bnum4"));
	data->bnum3 = GTK_WIDGET(gtk_builder_get_object(builder, "bnum3"));
	data->bnum2 = GTK_WIDGET(gtk_builder_get_object(builder, "bnum2"));
	data->bnum1 = GTK_WIDGET(gtk_builder_get_object(builder, "bnum1"));
	data->bnum0 = GTK_WIDGET(gtk_builder_get_object(builder, "bnum0"));
	data->badd = GTK_WIDGET(gtk_builder_get_object(builder, "badd"));
	data->bclear = GTK_WIDGET(gtk_builder_get_object(builder, "bclear"));
	data->bsub = GTK_WIDGET(gtk_builder_get_object(builder, "bsub"));
	data->bresult = GTK_WIDGET(gtk_builder_get_object(builder, "bresult"));
	data->bdiv = GTK_WIDGET(gtk_builder_get_object(builder, "bdiv"));
	data->bmul = GTK_WIDGET(gtk_builder_get_object(builder, "bmul"));
	data->textview1 = GTK_WIDGET(gtk_builder_get_object(builder, "textview1"));
	data->textbuffer1 = GTK_TEXT_BUFFER(gtk_builder_get_object(builder, "textbuffer1"));

	gtk_builder_connect_signals (builder, data);
	g_object_unref(G_OBJECT(builder));
	gtk_widget_show_all(data->window);
	gtk_main ();
	g_slice_free (Data, data);
	return (0);
} 
