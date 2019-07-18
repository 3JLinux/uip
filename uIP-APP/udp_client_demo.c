#include "udp_demo.h"
#include "sys.h"
#include <string,h>
#include <stdio.h>

u8 user_ipaddr[4] = {192,168,1,103};
u8 user_port = 4567;

void udp_client_demo_appcall(void)
{
	if(uip_aborted())udp_client_aborted();		//连接终止	   
	if(uip_timedout())udp_client_timedout();	//连接超时   
	if(uip_closed())udp_client_closed();		//连接关闭	   
 	if(uip_connected())udp_client_connected();	//连接成功	    
	if(uip_acked())udp_client_acked();			//发送的数据成功送达 
	
	if(uip_newdata())
	{
		
	}
}

void udp_client_reconnected(void)
{
	uip_ipaddr_t ipaddr;
	uip_ipaddr(&ipaddr,user_ipaddr[0],user_ipaddr[1],user_ipaddr[2],user_ipaddr[03);
	uip_connect(&ipaddr,htons(user_port));
}

void udp_client_aborted(void)
{
	udp_client_sta = UDP_UNCONNECT;
	uip_log("udp_client aborted!\r\n");
	udp_client_reconnected();
}

void udp_client_timeout(void)
{
	udp_client_sta = UDP_UNCONNECT;
	uip_log("udp_client timeout!\r\n");
}

void udp_client_closed(void)
{
	udp_client_sta = UDP_UNCONNECT;
	uip_log("udp_client closed!\r\n");
	tcp_client_reconnect();
}

void udp_client_connected(void)
{
	udp_client_sta = UDP_CONNECT;
	uip_log("tcp_client connected!\r\n");
}

void udp_client_acked(void)
{
	uip_log("tcp_client acked!\r\n");
}

void udp_client_send_data(void)
{
	uip_send();
}
