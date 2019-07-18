#ifndef _UDP_DEMO_H
#define _UDP_DEMO_H

#include "uipopt.h"
#include "psock.h"
#include "sys.h"

void udp_demo_appcall(void);

#ifndef UIP_UDP_APPCALL
#define UIP_UDP_APPCALL udp_demo_appcall
#endif

struct udp_demo_appstate
{
	u8_t state;
	u8_t *textptr;
	int textlen;
};	 
typedef struct udp_demo_appstate uip_udp_appstate_t;


//void uip_log(char *m);
void udp_demo_send(u8* send_ack_buf,u32 send_data_len);
void udp_demo_newdata(void);
void udp_int(void);
#endif


