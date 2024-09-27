Action()
{

	web_websocket_send("ID=0", 
		"Buffer={\"messageType\":\"hello\",\"broadcasts\":{\"remote-settings/monitor_changes\":\"\\\"1727302991701\\\"\"},\"use_webpush\":true}", 
		"IsBinary=0", 
		LAST);

	/*Connection ID 0 received buffer WebSocketReceive0*/

	lr_start_transaction("HomePage");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Priority", 
		"u=0, i");

	web_add_auto_header("DNT", 
		"1");

	web_add_auto_header("Sec-GPC", 
		"1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(19);

	web_url("webtours", 
		"URL=http://localhost:1080/webtours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("HomePage",LR_AUTO);

	lr_start_transaction("Login");

	web_add_auto_header("Priority", 
		"u=4");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(27);

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		LAST);

	lr_end_transaction("Login",LR_AUTO);

	lr_start_transaction("FlightsPage");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(27);

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t3.inf", 
		LAST);

	lr_end_transaction("FlightsPage",LR_AUTO);

	lr_start_transaction("FindFlight");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(29);

	web_submit_form("reservations.pl", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Los Angeles", ENDITEM, 
		"Name=departDate", "Value=09/27/2024", ENDITEM, 
		"Name=arrive", "Value=Paris", ENDITEM, 
		"Name=returnDate", "Value=09/28/2024", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		LAST);

	lr_end_transaction("FindFlight",LR_AUTO);

	lr_think_time(25);

	lr_start_transaction("SignOff");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t5.inf", 
		LAST);

	lr_end_transaction("SignOff",LR_AUTO);

	return 0;
}