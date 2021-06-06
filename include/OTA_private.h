/******************************************************/
/* Author    : Ahmed Hassan                           */
/* Date      : Jun 1, 2021                            */
/* Version   : V01                                    */
/******************************************************/

#ifndef OTA_PRIVATE_H
#define OTA_PRIVATE_H

static void OTA_vidParseRecord();
static void OTA_vidSetHighAddress(void);
static u8 getHex(u8 Copy_u8Asci);
static void OTA_vidCharReceived(u8 rec);
static void OTA_vidRunAppCode(void);


#endif