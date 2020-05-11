/************************************************************************/
/*	synFlood.h															*/
/*	2013-3-18															*/
/************************************************************************/
typedef unsigned short ushort;
typedef unsigned long ulong;
typedef unsigned int uint;
typedef unsigned char uchar;
 
//ip首部
typedef struct ip_hdr 
{
	uchar h_verlen; //4位首部长度,4位IP版本号
	uchar tos; //8位服务类型TOS
	ushort total_len; //16位总长度（字节）
	ushort ident; //16位标识
	ushort frag_and_flags; //3位标志位(另外13位为片偏移)
	uchar ttl; //8位生存时间 TTL
	uchar protocols; //8位协议 (如ICMP，TCP等)
	ushort chksum; //16位IP首部校验和
	uint sourceIP; //32位源IP地址
	uint destIP; //32位目的IP地址
}IP_HDR;
//tcp首部
typedef struct tcp_hdr
{
	ushort sourcePort;//16位源端口号
	ushort destPort;//16位目的端口号
	uint seq;//32位序号
	uint ack;//32位确认序号
	uchar h_lenres;//4位首部长度，6位保留			
	uchar flag;	//6位标识
	ushort win;//16位窗口大小
	ushort chksum;//16位校验和
	ushort urgpoint;//16位紧急指针
}TCP_HDR;
//tcp伪首部,用于校验和的计算
typedef struct pre_tcp_hdr
{
	ulong sourceAddr; //32位源地址
	ulong destAddr; //32位目的地址
	char mbz;
	uchar ptcl; //8位协议类型
	ushort tcplen; //16位TCP长度
}PRE_HDR;
