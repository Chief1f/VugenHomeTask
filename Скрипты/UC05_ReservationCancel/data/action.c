Action()
{

	web_websocket_send("ID=0", 
		"Buffer={\"messageType\":\"hello\",\"broadcasts\":{\"remote-settings/monitor_changes\":\"\\\"1727354172685\\\"\"},\"use_webpush\":true}", 
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

	lr_think_time(23);

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

	lr_think_time(24);

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

	lr_think_time(43);

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t3.inf", 
		LAST);

	lr_end_transaction("FlightsPage",LR_AUTO);

	lr_start_transaction("FindFlights");

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	lr_think_time(31);

	web_submit_form("reservations.pl", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Portland", ENDITEM, 
		"Name=departDate", "Value=09/27/2024", ENDITEM, 
		"Name=arrive", "Value=Los Angeles", ENDITEM, 
		"Name=returnDate", "Value=09/28/2024", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		LAST);

	lr_end_transaction("FindFlights",LR_AUTO);

	lr_think_time(25);

	lr_start_transaction("ChooseFlight");

	web_submit_form("reservations.pl_2", 
		"Snapshot=t5.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=530;198;09/27/2024", ENDITEM, 
		"Name=reserveFlights.x", "Value=32", ENDITEM, 
		"Name=reserveFlights.y", "Value=6", ENDITEM, 
		LAST);

	lr_end_transaction("ChooseFlight",LR_AUTO);

	lr_start_transaction("FillThePaymentDetails");

	web_revert_auto_header("Origin");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(29);

	web_submit_form("reservations.pl_3", 
		"Snapshot=t6.inf", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=rrt", ENDITEM, 
		"Name=address2", "Value=rtyrty", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=45643643", ENDITEM, 
		"Name=expDate", "Value=23", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		LAST);

	lr_end_transaction("FillThePaymentDetails",LR_AUTO);

	lr_start_transaction("GoToItinerary");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(38);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t7.inf", 
		LAST);

	lr_end_transaction("GoToItinerary",LR_AUTO);

	lr_start_transaction("CancelReservation");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(39);

	web_submit_form("itinerary.pl", 
		"Snapshot=t8.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=2", "Value=<OFF>", ENDITEM, 
		LAST);

	lr_end_transaction("CancelReservation",LR_AUTO);

	lr_think_time(35);

	lr_start_transaction("SignOff");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t9.inf", 
		LAST);

	lr_end_transaction("SignOff",LR_AUTO);

	return 0;
}