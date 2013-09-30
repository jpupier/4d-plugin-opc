/* --------------------------------------------------------------------------------
 #
 #	4DPlugin.c
 #	source generated by 4D Plugin Wizard
 #	Project : OPC
 #	author : miyako
 #	2013/09/29
 #
 # --------------------------------------------------------------------------------*/

#include "4DPlugin.h"

void PluginMain(int32_t selector, PA_PluginParameters params)
{
	try
	{
		int32_t pProcNum = selector;
		sLONG_PTR *pResult = (sLONG_PTR *)params->fResult;
		PackagePtr pParams = (PackagePtr)params->fParameters;

		CommandDispatcher(pProcNum, pResult, pParams); 
	}
	catch(...)
	{

	}
}

void CommandDispatcher (int32_t pProcNum, sLONG_PTR *pResult, PackagePtr pParams)
{
	switch(pProcNum)
	{
		case kInitPlugin :	
		case kServerInitPlugin :
			opcInitLibrary();
			break;
			
		case kDeinitPlugin :	
		case kServerDeinitPlugin :
			opcFreeLibrary();
			break;			
			
			// --- OPC Document
			
		case 1 :
			OPC_Get_document_type(pResult, pParams);
			break;
			
		case 2 :
			OPC_RESOURCE_TYPE_LIST(pResult, pParams);
			break;
			
		case 3 :
			OPC_EXTERNAL_TARGET_LIST(pResult, pParams);
			break;
			
		case 4 :
			OPC_EXTENSION_LIST(pResult, pParams);
			break;
			
		case 5 :
			OPC_Register_resource_type(pResult, pParams);
			break;
			
		case 6 :
			OPC_RELATION_TYPE_LIST(pResult, pParams);
			break;
			
			// --- OPC Resource
			
		case 7 :
			OPC_Get_resource(pResult, pParams);
			break;
			
		case 8 :
			OPC_RESOURCE_LIST(pResult, pParams);
			break;
			
		case 9 :
			OPC_Get_resource_size(pResult, pParams);
			break;
			
		case 10 :
			OPC_Delete_resource(pResult, pParams);
			break;
			
		case 11 :
			OPC_Set_resource(pResult, pParams);
			break;
			
		case 12 :
			OPC_EXTERNAL_RESOURCE_LIST(pResult, pParams);
			break;
			
			// --- OPC Relation
			
		case 13 :
			OPC_Create_relation(pResult, pParams);
			break;
			
		case 14 :
			OPC_Remove_relation(pResult, pParams);
			break;
			
		case 15 :
			OPC_Create_external_relation(pResult, pParams);
			break;
			
		case 16 :
			OPC_RELATION_LIST(pResult, pParams);
			break;
			
			// --- OPC Constants
			
		case 17 :
			OPC_Document_type(pResult, pParams);
			break;
			
		case 18 :
			OPC_Relation_type(pResult, pParams);
			break;
			
	}
}