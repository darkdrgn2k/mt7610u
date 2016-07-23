/*
 *************************************************************************
 * Ralink Tech Inc.
 * 5F., No.36, Taiyuan St., Jhubei City,
 * Hsinchu County 302,
 * Taiwan, R.O.C.
 *
 * (c) Copyright 2002-2010, Ralink Technology, Inc.
 *
 * This program is free software; you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation; either version 2 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program; if not, write to the                         *
 * Free Software Foundation, Inc.,                                       *
 * 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                       *
 *************************************************************************/


#ifndef __FRAME_HDR_H__
#define __FRAME_HDR_H__

#define HDR_TRANS_LEN	50

#ifdef RT_BIG_ENDIAN
typedef struct GNU_PACKED _WIFI_INFO_STRUCT{
	UINT32 more_data:1;
	UINT32 wep:1;
	UINT32 ps:1;
	UINT32 qos:1;
	UINT32 eosp:1;
	UINT32 tid:4;
	UINT32 mode:2;
	UINT32 vlan:1;
	UINT32 rev:3;
	UINT32 bssidx:4;
	UINT32 seq_num:12;
}WIFI_INFO_STRUCT;
#else
typedef struct GNU_PACKED _WIFI_INFO_STRUCT{
	UINT32 seq_num:12;
	UINT32 bssidx:4;
	UINT32 rev:3;
	UINT32 vlan:1;
	UINT32 mode:2;
	UINT32 tid:4;
	UINT32 eosp:1;
	UINT32 qos:1;
	UINT32 rdg:1;
	UINT32 ps:1;
	UINT32 wep:1;
	UINT32 more_data:1;
}WIFI_INFO_STRUCT;
#endif /* RT_BIG_ENDIAN */

WIFI_INFO_STRUCT wifi_info[] = {
	/* mode 1 -> AP, mode 2 --> STA */
	/* seq_num,	bssidx,	rsv,	vlan,	mode,	tid,	eosp,	qos,	rdg,	ps,	wep,	more_data*/
	   {0xff,   5,    	0,   	1,    	1,   	3,   	0, 		1,   	0,  	0, 	0, 		0},
};


UINT8 Input_Frame_Hdr[][HDR_TRANS_LEN] = {
/*type, len, vlan, wcid */
/************************************ AP LLC/SNAP *********************************/
/************************************ WDS LLC/SNAP ******************************/
{0, 34, 0, 1, 0x08, 0x03, 0x00, 0x00, 0x33, 0x33, 0x00, 0x00, 0x00, 0x02, 0x00, 0x11, 0x22, 0x33,
			  0x44, 0x50, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x50, 0x02, 0x00, 0xee, 0xee, 0xee,
			  0xee, 0xee, 0x00, 0x00, 0x08, 0x00}, /* AP w/o LLC - Ether II*/

};

UINT8 Hdr_Bssid[] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55};

UINT8 Hdr_Wcid[][6] = {
						{0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, //0
						{0x00, 0x77, 0x77, 0x77, 0x77, 0x77}, //1
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x01}, //2
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x02}, //3
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x03}, //4
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x04}, //5
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x05}, //6
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x06}, //7
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x07}, //8
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x08}, //9
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x09}, //a
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x0a}, //b
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x0b}, //c
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x0c}, //d
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x0d}, //e
						{0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x0e}, //f
					};
UINT8 MAC_WCID[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

//UINT32 RX_Black_List[] = {0x0d898e88}; /* EAPOL 888E, TDLS 890D */
//UINT32 RX_Black_List[] = {0x888e0800}; /* EAPOL 888E, TDLS 890D */
UINT32 RX_Black_List[] = {}; /* EAPOL 888E, TDLS 890D */
UINT32 TCI[] = {0x10021001, 0x10041003, 0x10061005, 0x10081007};
UINT32 RX_WCID_En[] = {0xFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
#endif