#include "Main.h"

//����CRC
unsigned int crcGenerator(unsigned char *crcdata,char sizeofarray)
{
	char j=0,k=0;
	//char sizeofarray=sizeof(crcdata); //�p�����
	unsigned int reg_crc=0xFFFF; //CRC��l��
	unsigned int outCRC;
	for(j=0;j<sizeofarray;j++)//CRC�B��
	{
		reg_crc ^= crcdata[j];
		for(k=0;k<8;k++)
		{
			if(reg_crc & 0x01)
				reg_crc=(reg_crc>>1) ^ 0xA001;
			else
				reg_crc=reg_crc >>1;
		}
	}
	//CRC���C�줸�洫(�����A�C)
	outCRC=((reg_crc<<8)&0xFF00)|((reg_crc>>8)&0x00FF);
	
	return outCRC;
}

//����CRC
char crcVertify(unsigned char *crcdata,char sizeofarray)
{
	unsigned int checkCRC=0,HighCRC=0,LowCRC=0,CRC=0;
	
	checkCRC=crcGenerator(crcdata,sizeofarray);//���ͶǨӪ�CRC
	HighCRC=crcdata[sizeofarray];//�C�줸CRC
	LowCRC=crcdata[sizeofarray+1];//���줸CRC
	CRC=((HighCRC<<8)&0xFF00)|(LowCRC&0x00FF);//�X�֭�lCRC
	
	if(checkCRC==CRC)//�ˬdCRC
		return 0;
	else
		return 1;
}
