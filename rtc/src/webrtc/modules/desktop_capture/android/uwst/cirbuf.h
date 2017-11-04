#ifndef	AFX_CIRCLE_BUFFER_H__ADC827A9_93B1_423E_BCAD_DC5D0E65933C__INCLUDED_
#define	AFX_CIRCLE_BUFFER_H__ADC827A9_93B1_423E_BCAD_DC5D0E65933C__INCLUDED_

#ifndef uint 
#define uint unsigned int
#endif

#pragma pack(1)

typedef struct circle_header {	
	uint head;
	uint tail;
	uint len;
    char buf[0];
}circle_header,*pcircle_header;

#pragma pack()


#define headlen_circle_header	sizeof(circle_header) 
#define circlebuf_size(_s) (_s + headlen_circle_header)

void circle_init(circle_header* pHeader, uint len);
uint circle_get(circle_header* pHeader, void* buf, uint len);
uint circle_put(circle_header* pHeader, void* buf, uint len);
uint circle_put_just_size(circle_header* pHeader, uint len);
uint circle_size(const circle_header* pHeader);
uint circle_freesize(const circle_header* pHeader);
uint circle_peek(const circle_header* pHeader, void* buf, uint len);
uint circle_del(circle_header* pHeader, uint len);
char* circle_getfreeAddress(circle_header* pHeader);
char* circle_getuseAddress(circle_header* pHeader);
circle_header *circle_buff_init(unsigned int queue_size);

#undef uint

#endif // !defined AFX_CIRCLE_BUFFER_H__ADC827A9_93B1_423E_BCAD_DC5D0E65933C__INCLUDED_

