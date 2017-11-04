#include "cirbuf.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

uint circle_size(const circle_header* pHeader)
{
	if (pHeader->tail < pHeader->head)
		return pHeader->len - (pHeader->head - pHeader->tail);
	else
		return pHeader->tail - pHeader->head;
}

uint circle_freesize(const circle_header* pHeader)
{
	if (pHeader->tail < pHeader->head)
		return pHeader->head - pHeader->tail -1;
	else
		return pHeader->len - (pHeader->tail - pHeader->head) -1;
}

void circle_init(circle_header* pHeader, uint len)
{
	pHeader->head = 0;
	pHeader->tail = 0;
	pHeader->len = len;
}

uint circle_get(circle_header* pHeader, void* buf, uint len)
{
	uint data_size = circle_size(pHeader);
	if (len > data_size)
	{
		len = data_size;
	}

	if (pHeader->tail < pHeader->head)
	{
		if ((pHeader->len - pHeader->head) >= len)
		{
			memcpy(buf, &pHeader->buf[pHeader->head], len);
			pHeader->head += len;
		}
		else
		{
			int _tail = pHeader->len - pHeader->head;
			char* buf1 = (char*)buf;

			memcpy(buf, &pHeader->buf[pHeader->head], _tail);
			memcpy(&buf1[_tail], pHeader->buf, len - _tail);
			pHeader->head = len - _tail;  
		}
	}
	else
	{
		memcpy(buf, &pHeader->buf[pHeader->head], len);
		pHeader->head += len;
	}
	return len;
}

uint circle_put(circle_header* pHeader, void* buf, uint len)
{
	char* buf1 = (char*)buf;

	if (len > circle_freesize(pHeader)) {
		len = circle_freesize(pHeader);
	}

	if (pHeader->tail < pHeader->head)
	{
		memcpy(&pHeader->buf[pHeader->tail], buf, len);
		
		pHeader->tail += len;
	}
	else
	{
		if ((pHeader->len - pHeader->tail) >= len)
		{
			memcpy(&pHeader->buf[pHeader->tail], buf, len);
			pHeader->tail += len;
		}
		else
		{
			int _tail = pHeader->len - pHeader->tail;
			memcpy(&pHeader->buf[pHeader->tail], buf, _tail);
			memcpy(pHeader->buf, &buf1[_tail], len - _tail);
			pHeader->tail = len - _tail;
		}
	}
	return len;
}

uint circle_put_just_size(circle_header* pHeader, uint len)
{
	if (len > circle_freesize(pHeader))
		len = circle_freesize(pHeader);
	
	if (pHeader->tail < pHeader->head)
	{
		pHeader->tail += len;
	}
	else
	{
		if ((pHeader->len - pHeader->tail) >= len)
		{
			pHeader->tail += len;
		}
		else
		{
			int _tail = pHeader->len - pHeader->tail;
			pHeader->tail = len - _tail;
		}
	}
	return len;
}

uint circle_peek(const circle_header* pHeader, void* buf, uint len)
{
	if (len > circle_size(pHeader)) 
	{
		len = circle_size(pHeader);
	}

	if (pHeader->tail < pHeader->head)
	{
		if ((pHeader->len - pHeader->head) >= len)
		{
			memcpy(buf, &pHeader->buf[pHeader->head], len);
		}
		else
		{
			int _tail = pHeader->len - pHeader->head;
			char* buf1 = (char*)buf;
			memcpy(buf, &pHeader->buf[pHeader->head], _tail);
			memcpy(&buf1[_tail], pHeader->buf, len - _tail);
		}
	}
	else
	{
		memcpy(buf, &pHeader->buf[pHeader->head], len);
	}
	return len;
}

uint circle_del(circle_header* pHeader, uint len)
{
	if (len > circle_size(pHeader))
		len = circle_size(pHeader);

	if (pHeader->tail < pHeader->head)
	{
		if ((pHeader->len - pHeader->head) >= len)
		{
			pHeader->head += len;
		}
		else
		{
			pHeader->head = len - (pHeader->len - pHeader->head);
		}
	}
	else
	{
		pHeader->head += len;
	}
	return len;
}

char* circle_getfreeAddress(circle_header* pHeader)
{
	return pHeader->tail+pHeader->buf;
}

char* circle_getuseAddress(circle_header* pHeader)
{
	return pHeader->head+pHeader->buf;
}

circle_header *circle_buff_init(unsigned int queue_size)
{
	circle_header *pheader = NULL ;
	unsigned int usize = circlebuf_size(queue_size);
	pheader = (circle_header *)malloc(usize);
	if(!pheader) {
		return NULL ;
	}

	memset(pheader , 0 , usize);
	circle_init(pheader , queue_size);
	return pheader;
}
