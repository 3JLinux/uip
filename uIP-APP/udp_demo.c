#include "sys.h"
#include "usart.h"
#include "uip.h"
#include "enc28j60.h"
#include "udp_demo.h"
#include "string.h"

//u8 user_ipaddr[4] = {139,159,220,138};
u8 user_ipaddr[4] = {192,168,1,65};
u32 user_port = 8080;
u32 my_poet = 5000;

void udp_demo_appcall(void)
{
//	struct uip_udp_conn *c;
//	uip_ipaddr_t ipaddr;
//	uip_ipaddr(&ipaddr,user_ipaddr[0],user_ipaddr[1],user_ipaddr[2],user_ipaddr[3]);	
//	c = uip_udp_new(&ipaddr,htons(user_port));
//	if(c != NULL)
//	{
//		uip_udp_bind(c, HTONS(my_poet));
//		printf("bind success");
//	}
	udp_demo_newdata();
}

void udp_int(void)
{
	struct uip_udp_conn *c;
	uip_ipaddr_t ipaddr;
	uip_ipaddr(&ipaddr,user_ipaddr[0],user_ipaddr[1],user_ipaddr[2],user_ipaddr[3]);	
	c = uip_udp_new(&ipaddr,htons(user_port));
	if(c != NULL)
	{
		uip_udp_bind(c, HTONS(my_poet));
		printf("bind success\r\n");
	}
	
}

void udp_demo_send(u8* send_ack_buf,u32 send_data_len)
{
	uip_send(send_ack_buf,send_data_len);
	printf("send_ack_buf:%s\r\n",send_ack_buf);
}

void udp_demo_newdata(void)
{
	u32 len = 0;
	u8 *rec_buf = NULL;
	u8 send_buf[] = "send ok\r\n";
	//printf("rec_check\r\n");
	if(uip_newdata())
	{
		printf("rec_ok\r\n");
		len = uip_datalen();
		rec_buf = uip_appdata;
		if(len > 0)
		{
			uip_send(rec_buf,len);
			uip_log((char *)rec_buf);
			udp_demo_send(send_buf,strlen((char*)send_buf));
		}
	}
}

/*
void uip_log(char *m)
{			    
	printf("uIP log:%s\r\n",m);
}*/
