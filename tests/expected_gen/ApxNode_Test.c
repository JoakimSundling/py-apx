/* Test has been autogenerated by py-apx generator 0.4.1 */

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include <string.h>
#include <stdio.h>
#include "ApxNode_Test.h"
#include "ApxNode_Test_Cbk.h"
#include "pack.h"

//////////////////////////////////////////////////////////////////////////////
// CONSTANTS AND DATA TYPES
//////////////////////////////////////////////////////////////////////////////
#define APX_DEFINITON_LEN 493u
#define APX_IN_PORT_DATA_LEN 22u
#define APX_OUT_PORT_DATA_LEN 20u

#define APX_RX_LEN_RU8FIRSTPORT 1u
#define APX_RX_LEN_RU8PORT 1u
#define APX_RX_LEN_RU8LASTPORT 1u
#define APX_RX_LEN_RU8ARPORT 3u
#define APX_RX_LEN_LIGHTREQUEST 3u
#define APX_RX_LEN_SOUNDREQUEST 3u
#define APX_RX_LEN_RS32PORT 4u
#define APX_RX_LEN_RS16ARPORT 6u

#define APX_RX_OFFSET_RU8FIRSTPORT 0u
#define APX_RX_OFFSET_RS16ARPORT 1u
#define APX_RX_OFFSET_RS32PORT 7u
#define APX_RX_OFFSET_RU8PORT 11u
#define APX_RX_OFFSET_RU8ARPORT 12u
#define APX_RX_OFFSET_LIGHTREQUEST 15u
#define APX_RX_OFFSET_SOUNDREQUEST 18u
#define APX_RX_OFFSET_RU8LASTPORT 21u

//////////////////////////////////////////////////////////////////////////////
// LOCAL FUNCTIONS
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// LOCAL VARIABLES
//////////////////////////////////////////////////////////////////////////////
static const uint8_t m_outPortInitData[APX_OUT_PORT_DATA_LEN]= {
   255, 255, 255, 255, 255, 255, 1, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255
};

static uint8_t m_outPortdata[APX_OUT_PORT_DATA_LEN];
static uint8_t m_outPortDirtyFlags[APX_OUT_PORT_DATA_LEN];
static const uint8_t m_inPortInitData[APX_IN_PORT_DATA_LEN]= {
   12, 255, 127, 1, 0, 0, 0, 1, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 210
};

static uint8_t m_inPortdata[APX_IN_PORT_DATA_LEN];
static uint8_t m_inPortSyncedFlags[APX_IN_PORT_DATA_LEN];
static apx_nodeData_t m_nodeData;
static const char *m_apxDefinitionData=
"APX/1.2\n"
"N\"Test\"\n"
"T\"T0\"{\"HapticId\"S\"Intensity\"C}\n"
"T\"T1\"{\"LightId\"S\"Intensity\"C}\n"
"T\"T2\"{\"SoundId\"S\"Volume\"C}\n"
"P\"SoundRequestAck\"T[2]:={65535,255}\n"
"P\"HapticRequest\"T[0]:={65535,255}\n"
"P\"PS8ARPort\"c[1]:={1}\n"
"P\"PS8Port\"c:=0\n"
"P\"PU16ARPort\"S[4]:={65535, 65535, 65535, 65535}\n"
"P\"PU32Port\"L:=4294967295\n"
"R\"RU8FirstPort\"C:=12\n"
"R\"RS16ARPort\"s[3]:={32767, 1, 0}\n"
"R\"RS32Port\"l:=1\n"
"R\"RU8Port\"C:=255\n"
"R\"RU8ARPort\"C[3]:={255, 255, 255}\n"
"R\"LightRequest\"T[1]:={65535,255}\n"
"R\"SoundRequest\"T[2]:={65535,255}\n"
"R\"RU8LastPort\"C:=210\n"
"\n";

//////////////////////////////////////////////////////////////////////////////
// GLOBAL FUNCTIONS
//////////////////////////////////////////////////////////////////////////////
apx_nodeData_t * ApxNode_Init_Test(void)
{
   apx_nodeDataHandlerTable_t nodeDataHandler;
   memcpy(&m_inPortdata[0], &m_inPortInitData[0], APX_IN_PORT_DATA_LEN);
   memset(&m_inPortSyncedFlags[0], 0, sizeof(m_inPortSyncedFlags));
   memcpy(&m_outPortdata[0], &m_outPortInitData[0], APX_OUT_PORT_DATA_LEN);
   memset(&m_outPortDirtyFlags[0], 0, sizeof(m_outPortDirtyFlags));
   apx_nodeData_create(&m_nodeData, "Test", (uint8_t*) &m_apxDefinitionData[0], APX_DEFINITON_LEN, &m_inPortdata[0], &m_inPortSyncedFlags[0], APX_IN_PORT_DATA_LEN, &m_outPortdata[0], &m_outPortDirtyFlags[0], APX_OUT_PORT_DATA_LEN);
   memset(&nodeDataHandler, 0, sizeof(nodeDataHandler));
   nodeDataHandler.inPortDataWritten = Test_inPortDataWritten;
   apx_nodeData_setHandlerTable(&m_nodeData, &nodeDataHandler);
   return &m_nodeData;
}

apx_nodeData_t * ApxNode_GetNodeData_Test(void)
{
   return &m_nodeData;
}

bool ApxNode_IsConnected_Test(void)
{
   return ( apx_nodeData_isInPortDataOpen(&m_nodeData) && apx_nodeData_isOutPortDataOpen(&m_nodeData) );
}

Std_ReturnType ApxNode_Read_Test_RU8FirstPort(uint8 *val)
{
   *val = (uint8_t) m_inPortdata[0];
   return E_OK;
}

Std_ReturnType ApxNode_Read_Test_RS16ARPort(sint16 *val)
{
   uint8_t *p;
   uint8_t i;
   apx_nodeData_lockInPortData(&m_nodeData);
   p=&m_inPortdata[1];
   for(i=0;i<3;i++)
   {
      val[i] = (int16_t) unpackLE(p,(uint8_t) sizeof(int16_t));
      p+=sizeof(int16_t);
   }
   apx_nodeData_unlockInPortData(&m_nodeData);
   return E_OK;
}

Std_ReturnType ApxNode_Read_Test_RS32Port(sint32 *val)
{
   apx_nodeData_lockInPortData(&m_nodeData);
   *val = (int32_t) unpackLE(&m_inPortdata[7],(uint8_t) sizeof(int32_t));
   apx_nodeData_unlockInPortData(&m_nodeData);
   return E_OK;
}

Std_ReturnType ApxNode_Read_Test_RU8Port(uint8 *val)
{
   *val = (uint8_t) m_inPortdata[11];
   return E_OK;
}

Std_ReturnType ApxNode_Read_Test_RU8ARPort(uint8 *val)
{
   uint8_t *p;
   uint8_t i;
   apx_nodeData_lockInPortData(&m_nodeData);
   p=&m_inPortdata[12];
   for(i=0;i<3;i++)
   {
      val[i] = (uint8_t) *p;
      p++;
   }
   apx_nodeData_unlockInPortData(&m_nodeData);
   return E_OK;
}

Std_ReturnType ApxNode_Read_Test_LightRequest(LightRequest_T *val)
{
   uint8_t *p;
   apx_nodeData_lockInPortData(&m_nodeData);
   p=&m_inPortdata[15];
   val->LightId = (uint16_t) unpackLE(p,(uint8_t) sizeof(uint16_t));
   p+=sizeof(uint16_t);
   val->Intensity = (uint8_t) *p;
   p++;
   apx_nodeData_unlockInPortData(&m_nodeData);
   return E_OK;
}

Std_ReturnType ApxNode_Read_Test_SoundRequest(SoundRequest_T *val)
{
   uint8_t *p;
   apx_nodeData_lockInPortData(&m_nodeData);
   p=&m_inPortdata[18];
   val->SoundId = (uint16_t) unpackLE(p,(uint8_t) sizeof(uint16_t));
   p+=sizeof(uint16_t);
   val->Volume = (uint8_t) *p;
   p++;
   apx_nodeData_unlockInPortData(&m_nodeData);
   return E_OK;
}

Std_ReturnType ApxNode_Read_Test_RU8LastPort(uint8 *val)
{
   *val = (uint8_t) m_inPortdata[21];
   return E_OK;
}

Std_ReturnType ApxNode_Write_Test_SoundRequestAck(SoundRequest_T *val)
{
   uint8_t *p;
   apx_nodeData_lockOutPortData(&m_nodeData);
   p=&m_outPortdata[0];
   packLE(p,(uint32_t) val->SoundId,(uint8_t) sizeof(uint16_t));
   p+=sizeof(uint16_t);
   *p=(uint8_t) val->Volume;
   p++;
   apx_nodeData_outPortDataWriteNotify(&m_nodeData, 0, 3, false);
   return E_OK;
}

Std_ReturnType ApxNode_Write_Test_HapticRequest(HapticRequest_T *val)
{
   uint8_t *p;
   apx_nodeData_lockOutPortData(&m_nodeData);
   p=&m_outPortdata[3];
   packLE(p,(uint32_t) val->HapticId,(uint8_t) sizeof(uint16_t));
   p+=sizeof(uint16_t);
   *p=(uint8_t) val->Intensity;
   p++;
   apx_nodeData_outPortDataWriteNotify(&m_nodeData, 3, 3, false);
   return E_OK;
}

Std_ReturnType ApxNode_Write_Test_PS8ARPort(sint8 *val)
{
   uint8_t *p;
   uint8_t i;
   apx_nodeData_lockOutPortData(&m_nodeData);
   p=&m_outPortdata[6];
   for(i=0;i<1;i++)
   {
      *p=(uint8_t) val[i];
      p++;
   }
   apx_nodeData_outPortDataWriteNotify(&m_nodeData, 6, 1, false);
   return E_OK;
}

Std_ReturnType ApxNode_Write_Test_PS8Port(sint8 val)
{
   apx_nodeData_lockOutPortData(&m_nodeData);
   m_outPortdata[7]=(uint8_t) val;
   apx_nodeData_outPortDataWriteNotify(&m_nodeData, 7, 1, false);
   return E_OK;
}

Std_ReturnType ApxNode_Write_Test_PU16ARPort(uint16 *val)
{
   uint8_t *p;
   uint8_t i;
   apx_nodeData_lockOutPortData(&m_nodeData);
   p=&m_outPortdata[8];
   for(i=0;i<4;i++)
   {
      packLE(p,(uint32_t) val[i],(uint8_t) sizeof(uint16_t));
      p+=sizeof(uint16_t);
   }
   apx_nodeData_outPortDataWriteNotify(&m_nodeData, 8, 8, false);
   return E_OK;
}

Std_ReturnType ApxNode_Write_Test_PU32Port(uint32 val)
{
   apx_nodeData_lockOutPortData(&m_nodeData);
   packLE(&m_outPortdata[16],(uint32_t) val,(uint8_t) sizeof(uint32_t));
   apx_nodeData_outPortDataWriteNotify(&m_nodeData, 16, 4, false);
   return E_OK;
}

void Test_inPortDataWritten(void *arg, apx_nodeData_t *nodeData, uint32_t offset, uint32_t len)
{
   union data_tag
   {
      sint16 RS16ARPort[3];
      uint8 RU8Port;
      SoundRequest_T SoundRequest;
   } data;
   uint32_t endOffset = offset + len;

   (void)arg;
   (void)nodeData;

   if (offset < APX_RX_OFFSET_RS16ARPORT)
   {
      offset = APX_RX_OFFSET_RS16ARPORT;
   }
   while (offset < endOffset)
   {
      switch(offset)
      {
      case APX_RX_OFFSET_RS16ARPORT:
         (void) ApxNode_Read_Test_RS16ARPort(&data.RS16ARPort[0]);
         RS16ARPort_cb_func(&data.RS16ARPort[0]);
         offset += APX_RX_LEN_RS16ARPORT;
         break;
      case APX_RX_OFFSET_RS32PORT:
         offset += APX_RX_LEN_RS32PORT;
         break;
      case APX_RX_OFFSET_RU8PORT:
         (void) ApxNode_Read_Test_RU8Port(&data.RU8Port);
         RU8Port_cb_func(data.RU8Port);
         offset += APX_RX_LEN_RU8PORT;
         break;
      case APX_RX_OFFSET_RU8ARPORT:
         offset += APX_RX_LEN_RU8ARPORT;
         break;
      case APX_RX_OFFSET_LIGHTREQUEST:
         offset += APX_RX_LEN_LIGHTREQUEST;
         break;
      case APX_RX_OFFSET_SOUNDREQUEST:
         (void) ApxNode_Read_Test_SoundRequest(&data.SoundRequest);
         SoundRequest_cb_func(&data.SoundRequest);
         offset += APX_RX_LEN_SOUNDREQUEST;
         break;
      //case APX_RX_OFFSET_RU8LASTPORT:
      default:
         offset = endOffset;
      }
   }
}
//////////////////////////////////////////////////////////////////////////////
// LOCAL FUNCTIONS
//////////////////////////////////////////////////////////////////////////////
