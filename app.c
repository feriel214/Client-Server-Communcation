#include <gtk/gtk.h> 
#include <stdio.h>
 
  GtkWidget *window,*label1,*btn1,*btn2,*btn3;
 int main (int argc, char argv[])
 {	
 	GtkBuilder *builder; //GTK Builder variable
 	gtk_init(&argc, &argv); //Start GTK
 	builder=gtk_builder_new(); // Create GTK UI Builder
 	gtk_builder_add_from_file(builder,"myui.glade",NULL); //Load our Ui file
 	window=GTK_WIDGET(gtk_builder_get_object(builder,"mywindow"));  //Load our window
 	label1=GTK_WIDGET(gtk_builder_get_object(builder,"label1"));	//Load our label
 	btn1=GTK_WIDGET(gtk_builder_get_object(builder,"btn1"));	//Load our btn1
 	btn2=GTK_WIDGET(gtk_builder_get_object(builder,"btn2"));	//Load our btn2
 	btn3=GTK_WIDGET(gtk_builder_get_object(builder,"btn3"));	//Load our btn3
 	// Essential for a GTK based program
 	gtk_builder_connect_signals(builder,NULL);
 	g_object_unref(builder);
 	
 	gtk_widget_show_all(window); //show our window
	gtk_main(); 		     // run our program
    
 return 0;
 }
 
 void exit_app()
 {
 	printf("Exit app \n");
 	gtk_main_quit();
 }

 void btn1_clicked()
 {
 	execl("./scriptTnomme.sh","./scriptTnomme.sh",0);
 }
 void btn2_clicked()
 {
 	execl("./scriptTcp.sh","./scriptTcp.sh",0);
 }
 void btn3_clicked()
 {
 	execl("./scriptUdp.sh","./scriptUdp.sh",0);	
 }
