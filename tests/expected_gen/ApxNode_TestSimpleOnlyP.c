/* TestSimpleOnlyP has been autogenerated by py-apx generator 0.4.1 */

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include <string.h>
#include <stdio.h>
#include "ApxNode_TestSimpleOnlyP.h"
#include "pack.h"

//////////////////////////////////////////////////////////////////////////////
// CONSTANTS AND DATA TYPES
//////////////////////////////////////////////////////////////////////////////
#define APX_DEFINITON_LEN 44u
#define APX_IN_PORT_DATA_LEN 0u
#define APX_OUT_PORT_DATA_LEN 1u

//////////////////////////////////////////////////////////////////////////////
// LOCAL FUNCTIONS
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// LOCAL VARIABLES
//////////////////////////////////////////////////////////////////////////////
static const uint8_t m_outPortInitData[APX_OUT_PORT_DATA_LEN]= {
   255
};

static uint8_t m_outPortdata[APX_OUT_PORT_DATA_LEN];
static uint8_t m_outPortDirtyFlags[APX_OUT_PORT_DATA_LEN];
static apx_nodeData_t m_nodeData;
static const char *m_apxDefinitionData=
"APX/1.2\n"
"N\"TestSimpleOnlyP\"\n"
"P\"PS8Port\"c:=-1\n"
"\n";

//////////////////////////////////////////////////////////////////////////////
// GLOBAL FUNCTIONS
//////////////////////////////////////////////////////////////////////////////
apx_nodeData_t * ApxNode_Init_TestSimpleOnlyP(void)
{
   memcpy(&m_outPortdata[0], &m_outPortInitData[0], APX_OUT_PORT_DATA_LEN);
   memset(&m_outPortDirtyFlags[0], 0, sizeof(m_outPortDirtyFlags));
   apx_nodeData_create(&m_nodeData, "TestSimpleOnlyP", (uint8_t*) &m_apxDefinitionData[0], APX_DEFINITON_LEN, 0, 0, 0, &m_outPortdata[0], &m_outPortDirtyFlags[0], APX_OUT_PORT_DATA_LEN);
   return &m_nodeData;
}

apx_nodeData_t * ApxNode_GetNodeData_TestSimpleOnlyP(void)
{
   return &m_nodeData;
}

bool ApxNode_IsConnected_TestSimpleOnlyP(void)
{
   return apx_nodeData_isOutPortDataOpen(&m_nodeData);
}

Std_ReturnType ApxNode_Write_TestSimpleOnlyP_PS8Port(sint8 val)
{
   apx_nodeData_lockOutPortData(&m_nodeData);
   m_outPortdata[0]=(uint8_t) val;
   apx_nodeData_outPortDataWriteNotify(&m_nodeData, 0, 1, false);
   return E_OK;
}

//////////////////////////////////////////////////////////////////////////////
// LOCAL FUNCTIONS
//////////////////////////////////////////////////////////////////////////////